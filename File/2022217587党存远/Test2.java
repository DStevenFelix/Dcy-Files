

public class Test2 {

    
        public static void main(String[] args) {
            Test2_Fan fan0 = new Test2_Fan();
            fan0.setSpeed(Test2_Fan.FAST);
            fan0.setradius(10);
            fan0.setColor("yellow");
            fan0.setOn(true);
            
    
            Test2_Fan fan1 = new Test2_Fan();
            fan1.setSpeed(Test2_Fan.MEDIUM);
            fan1.setradius(5);
            fan1.setColor("blue");
            fan1.setOn(false);
    
            System.out.println(fan0.toString());
            System.out.print("\n");
            System.out.println(fan1.toString());
            System.out.print("\n");
        }
    
    
    
}
  class Test2_Fan {
    static  int SLOW = 1, MEDIUM = 2, FAST = 3;

    private int speed = SLOW;

    private boolean on = false;

    private double radius  = 5.0;

    String color = "blue";

    // getter and setter

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public boolean isOn() {
        return on;
    }

    public void setOn(boolean on) {
        this.on = on;
    }

    public double getradius() {
        return radius;
    }

    public void setradius(double radius) {
        this.radius = radius;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // 无参构造方法
    public Test2_Fan(){}

    // 返回字符串
    public String toString(){
        if (on) {
            return speed + " " + color + " " + radius;
        } 
        else 
        {
            return "fan is off,"+" "+color+" "+radius;
        }
    }
}
