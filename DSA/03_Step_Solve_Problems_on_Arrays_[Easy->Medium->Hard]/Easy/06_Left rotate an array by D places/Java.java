import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr,int d){
        int n=arr.size(),j=0;
        d%=n;
        Vector<Integer>temp=new Vector<>();
        for(int i=0;i<d;i++) temp.add(arr.get(i));
        for(int i=d;i<n;i++) {
            arr.set(i-d,arr.get(i));
        }
        for(int i=n-d;i<n;i++){
            arr.set(i,temp.get(j++));
        }
        System.out.println(arr);
    }
    static void callOptimal(Vector<Integer>arr,int d){
        int n=arr.size();
        d%=n;
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
        System.out.println(arr);
    }
    static void reverse(Vector<Integer>arr, int i,int j){
        while(i<j){
            int temp=arr.get(i);
            arr.set(i,arr.get(j));
            arr.set(j,temp);
            i+=1;
            j-=1;
        }
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,2,3,4,5));
        int d=4;
        callBrute(arr,d);
        callOptimal(arr,d);
    }
}
