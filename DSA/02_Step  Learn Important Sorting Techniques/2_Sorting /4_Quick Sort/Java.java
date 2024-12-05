import java.util.*;
public class Java{
    static int givePartitionIndex(Vector<Integer>arr ,int low ,int high){
        int pivot=arr.get(low);
        int i=low;
        int j=high;
        while(i < j){
            while(arr.get(i)<=pivot && i<high)i++;
            while(arr.get(j)>pivot && j>low)j--; 
            if(i<j){
                int temp=arr.get(i);
                arr.set(i,arr.get(j));
                arr.set(j,temp);
            }
        }
        int temp=arr.get(low);
        arr.set(low,arr.get(j));
        arr.set(j,temp);
        return j;
    }
    static void qs(Vector<Integer>arr,int low ,int high){
        if(low < high){
            int partitionIndex=givePartitionIndex(arr,low,high);
            qs(arr,low,partitionIndex-1);
            qs(arr,partitionIndex+1,high);
        }
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.add(13);
        arr.add(46);
        arr.add(24);
        arr.add(52);
        arr.add(20);
        arr.add(9);
        qs(arr,0,arr.size()-1);
        System.out.println(arr);
    }
}