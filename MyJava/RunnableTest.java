public class RunnableTest implements Runnable {
 public void run(){
 System.out.println("Hello");
 }

public static void main(String[] args){
 Thread t = new Thread(new RunnableTest());
 t.start();
 }
 }
