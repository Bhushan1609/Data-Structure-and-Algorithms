import java.util.*;
public class J{
    static int partition(Vector<Integer>v ,int low ,int high){
        int pivot=v.get(low);
        int i=low;
        int j=high;
        while(i < j){
            while(v.get(i)<=pivot && i<high)i++;
            while(v.get(j)>pivot && j>low)j--; 
            if(i<j){
                int temp=v.get(i);
                v.set(i,v.get(j));
                v.set(j,temp);
            }
        }
        int temp=v.get(low);
        v.set(low,v.get(j));
        v.set(j,temp);
        return j;
    }
    static void quickSort(Vector<Integer>v,int low ,int high){
        if(low < high){
            int partitionIndex=partition(v,low,high);
            quickSort(v,low,partitionIndex-1);
            quickSort(v,partitionIndex+1,high);
        }
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.add(43);
        v.add(12);
        v.add(4);
        v.add(566);
        v.add(2);
        v.add(33);
        v.add(78);
        quickSort(v,0,v.size()-1);
        System.out.println(v);
    }
}