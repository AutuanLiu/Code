public class BC
{
    public static void main(String args[])
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
}
