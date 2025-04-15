import java.util.*;
public class Java{
    static void insertionSort(Vector<Integer>arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr.get(j-1) > arr.get(j)){
                int temp=arr.get(j-1);
                arr.set(j-1,arr.get(j));
                arr.set(j,temp);
                j-=1;
            }
        }
        System.out.println(arr);
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.add(13);
        arr.add(46);
        arr.add(24);
        arr.add(52);
        arr.add(20);
        arr.add(9);
        insertionSort(arr);
        
    }
}

