import java.io.*;
public class Talk
{
 public void print() throws IOException
 {
   BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
   System.out.println("Please enter your charcter:");
   String msg=bf.readLine();
   while(msg!=null)
   {
    if(msg.equals("bye!"))
    {
    	System.out.println("See you next time!");
    	System.exit(0);
        break;
    }
    else
    {
    	System.out.println("your input string is: "+msg);
   break;
    }
   }
 }
public static void main(String args[])throws IOException
 {
 while(true)
 {
 new Talk().print();
 }
}
}
