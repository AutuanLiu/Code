import java.awt.*;
import java.awt.event.*;
class ShopFrame extends Frame implements ActionListener
{ Label label1,label2,label3,label4;
    Button button1,button2,button3,button4,button5;
    TextArea text;
    Panel panel1,panel2;
    static float sum=0.0f;
    ShopFrame(String s)
    { super(s);
        setLayout(new BorderLayout());
        label1=new Label("面纸：3元",Label.LEFT);
        label2=new Label("钢笔：5元",Label.LEFT);
        label3=new Label("书：10元",Label.LEFT);
        label4=new Label("袜子：8元",Label.LEFT);
        button1=new Button("加入购物车");
        button2=new Button("加入购物车");
        button3=new Button("加入购物车");
        button4=new Button("加入购物车");
        button5=new Button("查看购物车");
        text=new TextArea("商品有："+"\n",5,10);
        text.setEditable(false);
        addWindowListener(new WindowAdapter()
                { public void windowClosing(WindowEvent e)
                    { System.exit(0);
                    }
                }
                );
        button1.addActionListener(this);
        button2.addActionListener(this);
        button3.addActionListener(this);
        button4.addActionListener(this);
        button5.addActionListener(this);
        panel1=new Panel();
        panel2=new Panel();
        panel1.add(label1);
        panel1.add(button1);
        panel1.add(label2);
        panel1.add(button2);
        panel1.add(label3);
        panel1.add(button3);
        panel1.add(label4);
        panel1.add(button4);
        panel2.setLayout(new BorderLayout());
        panel2.add(button5,BorderLayout.NORTH);
        panel2.add(text,BorderLayout.SOUTH);
        this.add(panel1,BorderLayout.CENTER);
        this.add(panel2,BorderLayout.SOUTH);
        setBounds(100,100,350,250);
        setVisible(true);
        validate();
    }
    public void actionPerformed(ActionEvent e)
    { if(e.getSource()==button1)
        { text.append("一个面纸、");
            sum=sum+3;
        }
        else if(e.getSource()==button2)
        { text.append("一只钢笔、");
            sum=sum+5;
        }
        else if(e.getSource()==button3)
        { text.append("一本书、");
            sum=sum+10;
        }
        else if(e.getSource()==button4)
        { text.append("一双袜子、");
            sum=sum+8;
        }
        else if(e.getSource()==button5)
        {
            text.append("\n"+"总价为："+"\n"+sum);
        }
    }

}

public class Shopping {
    public static void main(String[] args) {
        new ShopFrame("购物车");

    }

}

