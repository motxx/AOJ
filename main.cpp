#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>
#include <cstring>
#include "picojson.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>

namespace {
std::string const CodeHtmlURLPrefix  = "http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=";
std::string const CodeHtmlFile = "__working_code__";
std::string const CodeBeginSign = "name=\"code\" id=\"code\">";//name="code" id="code">
std::string const CodeEndSign = "</pre>";
}

void command(std::string const& s) {
  assert(!system(s.c_str()));
}

namespace compiler::suffix {
std::string const ExtCpp0x = ".cpp";
std::string const ExtCpp11 = ".cpp";
std::string const ExtCpp14 = ".cpp";
std::string const ExtPython3 = ".py";
std::string const ExtOCaml = ".ml";
}

namespace compiler::name {
std::string const C = "C";
std::string const Cpp = "C++";
std::string const Java = "JAVA";
std::string const Cpp11 = "C++11";
std::string const CSharp = "C#";
std::string const D = "D";
std::string const Ruby = "Ruby";
std::string const Python = "Python";
std::string const Python3 = "Python3";
std::string const PHP = "PHP";
std::string const JavaScript = "JavaScript";
std::string const Scala = "Scala";
std::string const Haskell = "Haskell";
std::string const OCaml = "OCaml";
}

namespace {
std::string const SaveDirectoryName = "repository";
}

namespace compiler {
std::string change_extension(std::string const& s) {
  using namespace compiler::name;
  using namespace compiler::suffix;
  if(s == C)
    return ".c";
  if(s == Cpp)
    return ExtCpp0x;
  if(s == Java)
    return ".java";
  if(s == Cpp11)
    return ExtCpp11;
//  if(s == "C++14") return ExtCpp14;
  if(s == CSharp)
    return ".cs";
  if(s == D)
    return ".d";
  if(s == Ruby)
    return ".rb";
  if(s == Python)
    return ".py";
  if(s == Python3)
    return ExtPython3;
  if(s == PHP)
    return ".php";
  if(s == JavaScript)
    return ".js";
  if(s == Scala)
    return ".scala";
  if(s == Haskell)
    return ".hs";
  if(s == OCaml)
    return ExtOCaml;
  return ".unknown";
}

// format-style-option
// http://algo13.net/clang/clang-format-style-oputions.html
bool use_format = false;
std::string format_style = "google";

std::vector<std::string> const style_names = {
"allman",
"ansi",
"bsd",
"break",
"java",
"attach",
"kr",
"k&r",
"k/r",
"stroustrup",
"whitesmith",
"banner",
"gnu",
"linux",
"knf",
"horstmann",
"1tbs",
"otbs",
"google",
"pico",
"lisp",
};

namespace detail {
std::string const FName = "__working_code_format__";
void cpp_format(std::string& code) {
  {
    std::ofstream ofs(FName);
    ofs << code << std::flush;
  }

  command("clang-format -i " + FName + " --style=" + format_style);

  {
    std::ifstream ifs(FName);
    code.clear();
    std::string k;
    bool first_line = false;
    while(std::getline(ifs, k)) {
      if(first_line) code += "\n";
      first_line = true;
      code += k;
    }
  }

  command("rm " + FName);
}
}

void format(std::string& code, std::string const& cpl) {
  using namespace name;
  using namespace detail;
  if(cpl == C)
    cpp_format(code);
  if(cpl == Cpp)
    cpp_format(code);
  if(cpl == Cpp11)
    cpp_format(code);
}

}

void change_escape(std::string& s) {
  using boost::algorithm::replace_all;
  replace_all(s, "&quot;", "\"");
  replace_all(s, "&lt;", "<");
  replace_all(s, "&gt;", ">");
  replace_all(s, "&amp;", "&");
  replace_all(s, "&nbsp;", " ");
}


void args_settings(int argc, char** argv) {

  for(int i=0; i<argc; i++) {
    if(argv[i][0] == '-' && argv[i][1] == '-') {
      char const* a = argv[i] + 2;
      for(auto && e: compiler::style_names)
        if(0==std::strcmp(a, ("style=" + e).c_str()))
          compiler::format_style = e;
    }
    else if(argv[i][0] == '-') {
      char const* a = argv[i] + 1;
      if(0==std::strcmp(a, "t"))
        compiler::use_format = true;
      if(0==std::strcmp(a, "A14"))
        compiler::format_style = "google";
    }
  }

}

int main(int argc, char** argv) {

  args_settings(argc, argv);

  using boost::algorithm::replace_all;

  std::ifstream ifs("data.json", std::ios::in);

  std::string json, k;
  while(std::getline(ifs, k))
    json += k;

  replace_all(json, "\n", "");
  replace_all(json, "{no:\"", "{\"no\":\"");
  replace_all(json, "submitDate:\"", "\"submitDate\":\"");
  replace_all(json, "problemID:\"", "\"problemID\":\"");
  replace_all(json, "language:\"", "\"language\":\"");
  replace_all(json, "cpu:\"", "\"cpu\":\"");
  replace_all(json, "memory:\"", "\"memory\":\"");
  replace_all(json, "size:\"", "\"size:\":\"");
  replace_all(json, "jid:\"", "\"jid\":\"");

  std::ofstream ofs("out.json");
  ofs << json << std::endl;

  picojson::value v;
  auto r = parse(v, json);
  if(!r.empty())
    std::cout << std::string(r.begin(), r.begin() + std::min(100, (int)r.size())) << std::endl;
  assert(r.empty());

  for(auto& u: v.get<picojson::array>()) {
    auto o = u.get<picojson::object>();
    auto jid = o["jid"].get<std::string>();
    command("curl " + CodeHtmlURLPrefix + jid + " > " + CodeHtmlFile);
    std::ifstream ifs(CodeHtmlFile, std::ios::in);
    command("rm " + CodeHtmlFile);
    std::string code_html;
    while(getline(ifs, k))
      code_html += k + "\n";
    auto begin = code_html.find(CodeBeginSign);
    code_html = code_html.substr(begin + CodeBeginSign.size());
    auto code = code_html.substr(0, code_html.find(CodeEndSign));

    change_escape(code);

    if(compiler::use_format)
      compiler::format(code, o["language"].get<std::string>());

    std::ofstream ofs(SaveDirectoryName + "/" + o["problemID"].get<std::string>() + compiler::change_extension(o["language"].get<std::string>()));
    ofs << code << std::flush;
    
    // !!! 注意して使用せよ !!!
    sleep(2);
  }
    
  return 0;
}