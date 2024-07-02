import java.util.*;
public class J{
    static void rec(int i ,int j , Vector<Integer>a){
        if(i>j)return ;
        int temp=a.get(i);
        a.set(i,a.get(j));
        a.set(j,temp);
        rec(i+1,j-1,a);
    }
    public static void main(String args[]){
        Vector<Integer>a=new Vector<>();
        a.add(1);
        a.add(2);
        a.add(3);
        a.add(4);
        a.add(5);
        a.add(6);
        a.add(7);
        a.add(8);
        a.add(9);
        rec(0,a.size()-1,a);
        System.out.println(a);
    }
}
