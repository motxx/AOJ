import java.util.*;

class aoj0002
{
    public void solve()
    {
	Scanner sc = new Scanner(System.in);
	while(sc.hasNext())
	    {
		System.out.println(new Integer(sc.nextInt() + sc.nextInt()).toString().length());
	    }
    }
}

public class Main
{
    public static void main(String[] arg)
    {
	new aoj0002().solve();
    }
}

