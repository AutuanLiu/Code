public class SynMethod implements Runnable{
    private int shares = 20;
    private String s="a";
    public synchronized void func() {
        if(shares > 0){
            try{
                Thread.sleep(300);
            }catch(InterruptedException e){
                e.printStackTrace();
            }
            System.out.println(
                    Thread.currentThread().getName()+ "ticket    "+shares--);
        }
    }
    public void run(){
        while(true){
            func();
            if(shares<=0){
                break;
            }
        }
    }

    public static void main(String[] args){
        SynMethod obj = new SynMethod();
        new Thread(obj,"A").start();//命名当前线程为A
        new Thread(obj,"B").start();
        new Thread(obj,"C").start();
    }
}
