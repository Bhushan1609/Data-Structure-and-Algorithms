import java.util.*;
public class Java{
    static void recursion(int i,Vector<Integer>arr){
        if(i>=arr.size())return;
        int j=i;
        while(j>0 && arr.get(j-1) > arr.get(j)){
            int temp=arr.get(j-1);
            arr.set(j-1,arr.get(j));
            arr.set(j,temp);
            j-=1;
        }
        recursion(i+1,arr);
    }
    static void recursiveInsertionSort(Vector<Integer>arr){
        recursion(0,arr);
        return;
    }
    public static void main(String[] args){
        Vector<Integer>arr=new Vector<>();
        arr.add(13);
        arr.add(46);
        arr.add(24);
        arr.add(52);
        arr.add(20);
        arr.add(9);
        recursiveInsertionSort(arr);
        System.out.println(arr);
    }
}