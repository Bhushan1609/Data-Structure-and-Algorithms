import java.util.*;
public class Java{
    static void rotateOneSpace(Vector<Integer>arr){
        int n=arr.size(), temp=arr.get(0);
        for(int i=1;i<n;i++)arr.set(i-1,arr.get(i));
        arr.set(n-1, temp);
        System.out.println(arr);
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,2,3,4,5));
        rotateOneSpace(arr);
    }
}