public class SynBlock implements Runnable{
    private int shares = 20;
    private String s="a";
    public void run(){
        while(true){
            synchronized(s){
                if(shares > 0){
                    try{
                        Thread.sleep(300);
                    }catch(InterruptedException e){
                        e.printStackTrace();
                    }
                    System.out.println(
                            Thread.currentThread().getName()+ "tickets "+shares--);
                }else{
                    break;
                }
            }
        }
    }

    public static void main(String[] args){
        SynBlock obj = new SynBlock();

        new Thread(obj,"A").start();//命名当前线程为A
        new Thread(obj,"B").start();
        new Thread(obj,"C").start();
    }
}
