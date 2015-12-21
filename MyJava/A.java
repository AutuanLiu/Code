import java.io.*;
public class A
{
 public static void main(String args[]) throws IOException
 {
   try
   {
    File f1=new File("log.txt");
    PrintWriter fout=new PrintWriter(new FileWriter(f1,true));
    fout.println("java is goog");
    fout.close();
   }
   catch(IOException e)
   {
    e.printStackTrace();
   }
 }
}

class What
{
    public static void public static void main(String[] args) {
        System.out.println("What is your name?");
    }
}
