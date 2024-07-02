import java.util.*;
public class J{
    static void merge(Vector<Integer>v ,int low,int mid, int high){
        int i=low;
        int j=mid+1;
        Vector<Integer>temp=new Vector<>();
        while(i<=mid && j<=high){
            if(v.get(i)<=v.get(j))temp.add(v.get(i++));
            else temp.add(v.get(j++));
        }
        while(i<=mid)temp.add(v.get(i++));
        while(j<=high)temp.add(v.get(j++));
        for(i=low;i<=high;i++)v.set(i,temp.get(i-low));
    }
    static void mergeSort(Vector<Integer>v,int low ,int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        merge(v,low,mid,high);
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
        mergeSort(v,0,v.size()-1);
        System.out.println(v);
    }
}