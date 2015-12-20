public class ThreadTest extends Thread {
    static int millionsecond=500;
    @Override
   public  void run(){
        while(true){
            try{
                Thread.sleep(millionsecond);//
            }catch(InterruptedException e){
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName());
        }
    }

    public static void main(String[] args){
        ThreadTest t1 = new ThreadTest();
        t1.start();    //启动了一个线程
        ThreadTest t2 = new ThreadTest();
        t2.start();    //启动另一个线程

        while(true){
            try{
                Thread.sleep( millionsecond);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
            System.out.println("hello, main");
        }
    }
}
