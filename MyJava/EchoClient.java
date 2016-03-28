import java.net.*;
import java.io.*;
import java.util.*;
public class EchoClient{
    public static void main(String args[])throws IOException{
        System.out.println("Note: input 'bye' then quit the client");
        new EchoClient2().talk();
    }
}
 class EchoClient2 {
    private String host="localhost";
    private int port=8000;
    private Socket socket;

    public EchoClient2()throws IOException{
        socket=new Socket(host,port);
    }

    private PrintWriter getWriter(Socket socket)throws IOException{
        OutputStream socketOut = socket.getOutputStream();
        return new PrintWriter(socketOut,true);
    }
    private BufferedReader getReader(Socket socket)throws IOException{
        InputStream socketIn = socket.getInputStream();
        return new BufferedReader(new InputStreamReader(socketIn));
    }
    public void talk()throws IOException {
        try{
            BufferedReader br=getReader(socket);
            PrintWriter pw=getWriter(socket);
            BufferedReader localReader=new BufferedReader(new InputStreamReader(System.in));
            String msg=null;
            while((msg=localReader.readLine())!=null){

                pw.println(msg);
                System.out.println(br.readLine());

                if(msg.equals("bye"))
                    break;
            }
        }catch(IOException e){
            e.printStackTrace();
        }finally{
            try{socket.close();}catch(IOException e){e.printStackTrace();}
        }
    }
}


/****************************************************
 * ���ߣ�������                                     *
 * ��Դ��<<Java�������̾���>>                       *
 * ����֧����ַ��www.javathinker.org                *
 ***************************************************/
