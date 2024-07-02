class Person {
    String name;
    public Person(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
}
public class J{
    static void functionByPassValue(int a){
        a+=5;
        System.out.println("Value a in Value Function is : "+ a);
        return ;
    }
    static void changeName(Person p){
        p.name="Bhushan Thombare";
    }
    public static void main(String args[]){

        int a=10;
        System.out.println("Intial Value in parent Function is : "+ a);
        functionByPassValue(a);
        System.out.println("Intial Value in parent Function after Pass by Value Funcion is : "+ a);
        /* 
        While Java does not support pass-by-reference as understood in languages like C++,
        understanding how references work in Java allows you to modify objects and have those 
        modifications visible outside the method.
        */
        Person person1=new Person("Bhushan");
        System.out.println(person1.name);
        changeName(person1);
        System.out.println(person1.name);
    }
}
