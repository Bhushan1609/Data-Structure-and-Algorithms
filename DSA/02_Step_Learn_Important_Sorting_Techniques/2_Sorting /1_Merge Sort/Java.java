import java.util.*;
public class Java{
    static void merge(Vector<Integer>arr,int low,int mid,int high){
        int left=low,right=mid+1,index=0;
        Vector<Integer>temp=new Vector<>();
        while(left<=mid && right<=high){
            if(arr.get(left)<arr.get(right)){
                temp.add(arr.get(left));
                left+=1;
            }else{
                temp.add(arr.get(right));
                right+=1;
            }
        }
        while(left<=mid) {temp.add(arr.get(left));left+=1;}
        while(right<=high) {temp.add(arr.get(right));right+=1;}
        for(int i=low;i<=high;i++){
            arr.set(i,temp.get(index));
            index+=1;
        }
        return ;
    }
    static void mergeSort(Vector<Integer>arr,int low,int high){
        if(low>=high) return;
        int mid=(low+high)>>1;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    public static void main(String[] args){
        Vector<Integer>arr=new Vector<>();
        arr.add(13);
        arr.add(46);
        arr.add(24);
        arr.add(52);
        arr.add(20);
        arr.add(9);
        int n=arr.size();
        mergeSort(arr,0,n-1);
        System.out.println(arr);
    }
}

