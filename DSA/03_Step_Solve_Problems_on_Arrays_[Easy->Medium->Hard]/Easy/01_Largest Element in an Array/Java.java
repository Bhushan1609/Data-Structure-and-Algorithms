import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr){
        Collections.sort(arr);
        System.out.println(arr.get(arr.size()-1));
        return ;
    }
    static void callOptimal(Vector<Integer>arr){
        int maxi=Integer.MIN_VALUE;
        for(int i=0;i<arr.size();i++) maxi=Math.max(arr.get(i),maxi);
        System.out.println(maxi);
        return ;
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.add(3);
        arr.add(2);
        arr.add(1);
        arr.add(5);
        arr.add(2);
        callBrute(arr);
        callOptimal(arr);

    }
}