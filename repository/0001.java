import java.util.*;

class aoj0001
{
    public void solve()
    {
        int[] list = new int[10];
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<10; i++)
            list[i] = sc.nextInt();
        Arrays.sort(list);
        for(int i=0; i<3; i++)
            System.out.println(list[9-i]);
    }
}

class Main
{
    public static void main(String...args)
    {
        new aoj0001().solve();
    }
}

