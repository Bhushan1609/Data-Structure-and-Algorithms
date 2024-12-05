import java.util.*;
public class Java{
    static void recursion(int i,Vector<Integer>arr){
        if(i<0)return;
        for(int j=0;j<i;j++){
            if(arr.get(j)>arr.get(j+1)){
                int temp=arr.get(j+1);
                arr.set(j+1,arr.get(j));
                arr.set(j,temp);
            }
        }
        recursion(i-1,arr);
    }
    static void recursiveBubbleSort(Vector<Integer>arr){
        recursion(arr.size()-1,arr);
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
        recursiveBubbleSort(arr);
        System.out.println(arr);
    }
}