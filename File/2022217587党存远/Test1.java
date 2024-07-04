package Javaproject;

public class Test1 {
    public static void main(String args[])

{
    Cat A1=new Cat();
    
    A1.Hello();
    A1.Happy();
    A1.Scared();
    A1.Habit2();//调用接口时不能使用父类的引用来指向子类的对象
    A1.EATing();
    A1.Types();
    A1.meat();
    System.out.println(" \n");
    Dog A2=new Dog();
    A2.Hello();
    A2.Happy();
    A2.Scared();
    A2.Habit2();
    A2.EATing();
    A2.Types();
    A2.meat();
    System.out.println(" \n");
    Frog A3=new Frog();
    A3.Hello();
    A3.Happy();
    A3.Scared();
    A3.Habit1();
    A3.Habit2();
    A3.EATing();
    A3.type();
    System.out.println(" \n");

}



}

   abstract class Animal
{
    abstract void Happy();
    abstract void Scared();
    abstract void Hello();
}
 interface   Water
{
    void Habit1();
}
 interface Land
{
    void Habit2();
}
 interface Eat
{
    void EATing();
}
 interface Mammalia
{
    void Types();
}
 interface Eatmeat
{
    void meat();
}
 interface Amphibian
{
    void type();
}
  class Cat extends Animal implements Land,Eat,Mammalia,Eatmeat
{
    public void Happy()
    {
        System.out.println("咕噜咕噜");
    }
    public void Scared()
    {
        System.out.println("嘶嘶");
    }
  
    @Override
    public void Habit2() {
        // TODO Auto-generated method stub
        System.out.println("live on the land,and then help people catch the mice");
    }
    @Override
    public void Hello() {
        // TODO Auto-generated method stub
        System.out.println("喵~~~~~");
    }
    public void EATing()
    {
        System.out.println("吃fish");
    }
    @Override
    public void meat() {
        // TODO Auto-generated method stub
        System.out.println("食肉性动物");
    }
    @Override
    public void Types() {
        // TODO Auto-generated method stub
        System.out.println("小猫是哺乳动物");
    }
}
  class Dog extends Animal implements Land,Eat,Mammalia,Eatmeat
{
    public void Happy()
    {
        System.out.println("汪汪汪");
    }
    public void Scared()
    {
        System.out.println("呜呜");
    }
  
    @Override
    public void Habit2() {
        // TODO Auto-generated method stub
        System.out.println("live on the land,and keep people safe");
    }
    @Override
    void Hello() {
        // TODO Auto-generated method stub
        System.out.println("摇摇尾巴");
    }
    @Override
    public void EATing() {
        // TODO Auto-generated method stub
        System.out.println("吃骨头");
    }
    @Override
    public void meat() {
        // TODO Auto-generated method stub
        System.out.println("肉食性动物");
    }
    @Override
    public void Types() {
        // TODO Auto-generated method stub
        System.out.println("小狗是哺乳动物");
    }
}
  class Frog extends Animal implements Water,Land,Eat,Amphibian
{
    public void Happy()
    {
        System.out.println("呱呱呱");
    }
    public void Scared()
    {
        System.out.println("Jump into the water");
    }
    public void Hello()
    {
        System.out.println("吐舌头");
    }
    @Override
    public void type() {
        // TODO Auto-generated method stub
        System.out.println("青蛙是两栖类动物");
    }
    @Override
    public void EATing() {
        // TODO Auto-generated method stub
        System.out.println("吃害虫");
    }
    @Override
    public void Habit2() {
        // TODO Auto-generated method stub
        System.out.println("青蛙晒太阳");
    }
    @Override
    public void Habit1() {
        // TODO Auto-generated method stub
        System.out.println("live in the water,enjoy the happy time ");
    }
    

}
