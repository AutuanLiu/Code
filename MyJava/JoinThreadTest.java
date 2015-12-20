public class JoinThreadTest implements Runnable {
    static int a = 100;

    public void run() {
        int i=0;
        while(i<a){
            System.out.println("JoinThreadTest "+i++);
        }
    }

    public static void main(String[] args) throws Exception {
        Thread t = new Thread(new JoinThreadTest());
        t.start(); 
        //t.join(); //线程t被合并到main中， 这是合并
        int i=0;

        while(i<a){
            System.out.println("main "+i++);
        }
    }
}
