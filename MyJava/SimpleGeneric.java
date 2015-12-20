//关于泛型的使用与例子
public class SimpleGeneric<E> {
    private E a;
    public void set(E x){
        a=x;
    }
    public E get(){
        return a;
    }
    public void func(int k){
        System.out.println(k);
    }

    public static void main(String[] args){
        SimpleGeneric<String> a=new SimpleGeneric<String>();
        a.set(new String("abc"));
        System.out.println(a.get());

        SimpleGeneric<Integer> b=new SimpleGeneric<Integer>();
        b.set(10);
        System.out.println(b.get());
    }
}

