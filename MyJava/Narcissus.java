public class Narcissus
{
    public static void main(String args[])
    {
        int i,j,k,n=100,m=1;
        while(n<1000)
        {
            i=n/100;
            j=(n-i*100)/10;
            k=n%10;
            if((Math.pow(i,3)+Math.pow(j,3)+Math.pow(k,3))==n)
                System.out.println("Find the"+m+++"number:"+n);
            n++;
        }
    }
}
