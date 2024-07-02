import java.util.*;
public class J{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter 2 Integer");
        int a=sc.nextInt();
        int b=sc.nextInt();
        System.out.println("1.Add\n2.Sub\n3.Mul\n4.Div\n");
        sc.nextLine();
        String choice=sc.nextLine();
        switch (choice){
            case "1":
                System.out.println(a+b);
                break;
            case "2":
                System.out.println(a-b);
                break;
            case "3":
                System.out.println(a*b);
                break;
            case "4":
                System.out.println(a/b);
                break;
            default:
                System.out.println("Wrong Input");
        }
    }
}