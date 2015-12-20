public class ProducerConsumer{
    public static void main(String[] args){
        Box b = new Box();//共享对象
        Thread p= new Thread(new Producer(b));
        p.start();
        Thread c= new Thread(new Consumer(b));
        //t.setDaemon(true);//设置为后台线程， 没有生产者也不必有消费者了
        c.start();
    }
}

class Producer implements Runnable {
    Box box;
    Producer(Box b){
        box=b;
    }
    public void run(){
        int i=0;
        while(i<10){
            box.setInfo(Math.random());
            i++;
        }
    }
}

class Consumer implements Runnable{
    Box box;
    Consumer(Box b){
        box=b;
    }
    public void run(){
        int i=0;
        while(i<10){
            box.getInfo();
            i++;
        }
    }
}

class Box{
    boolean full;//标志 Box的空间是否已满
    double info;

    public synchronized void getInfo(){
        while(!full){//没有信息可取
            try{
                wait();
            }catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }

        System.out.println("消费 "+this.info);
        full=false;
        notifyAll();
    }

    public synchronized void setInfo(double info){
        while(full){//空间已满
            try{
                wait();
            }catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
        full=true;
        this.info=info;
        System.out.println("生产 "+this.info);
        notifyAll();
    }
}
