import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr){
        int n=arr.size();
        Collections.sort(arr);
        int largest=arr.get(n-1),secondLargest=Integer.MIN_VALUE;
        for(int i=n-2;i>=0;i--){
            if(arr.get(i) != largest){
                secondLargest=arr.get(i);
                break;
            }
        }
        System.out.println(secondLargest);
    }
    static void callBetter(Vector<Integer>arr){
        int n=arr.size(),largest=Integer.MIN_VALUE,secondLargest=Integer.MIN_VALUE;
        for(int i=0;i<n;i++) largest=Math.max(largest,arr.get(i));
        for(int i=0;i<n;i++){
            if(largest != arr.get(i)){
                secondLargest=Math.max(secondLargest,arr.get(i));
            }
        }
        System.out.println(secondLargest);
    }
    static void callOptimal(Vector<Integer>arr){
        int n=arr.size(),largest=Integer.MIN_VALUE,secondLargest=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if(arr.get(i)>largest){
                secondLargest=largest;
                largest=arr.get(i);
            }
        }
        System.out.println(secondLargest);
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.add(1);
        arr.add(2);
        arr.add(4);
        arr.add(7);
        arr.add(7);
        arr.add(5);
        callBrute(arr);
        callBetter(arr);
        callOptimal(arr);
    }
}