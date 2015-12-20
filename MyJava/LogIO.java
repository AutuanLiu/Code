import java.io.*;
public class LogIO 
{
   int chi;
   File log=new File("record.txt");
	public void fprint(String s)throws IOException 
   {
	   try
	   {
		   PrintWriter fout=new PrintWriter(new FileWriter(log,true));
		   fout.println(s);
		   fout.close();
	   }
	   catch(IOException e)
	   {
		   e.printStackTrace();
	   }
   }
	public void fwrite() throws IOException
	{
		try
		{
			FileInputStream fin=new FileInputStream(log);
			while((chi=fin.read())!=-1)
			{
				System.out.print((char)chi);
			}
			fin.close();
		}
		catch(FileNotFoundException e)
		{
			System.err.println(e);
		}
		catch(IOException e1)
		{
			System.err.println(e1);
		}
	}
    public static void main(String[] args)
    {
     LogIO l=new LogIO();
     l.fprint("yiiyiyiy+\n+kniuib5156151\n");
     l.fwrite();
    }
}
