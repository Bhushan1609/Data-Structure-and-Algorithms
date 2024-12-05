import java.util.*;
public class Java{
    static void selectionSort(Vector<Integer>arr){
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int mini=i;
            for(int j=i;j<n;j++){
                if(arr.get(j) < arr.get(mini)){
                    mini=j;
                }
            }
            int temp=arr.get(i);
            arr.set(i, arr.get(mini));
            arr.set(mini,temp);
        }
        for(int i=0;i<n;i++){
            System.out.print(arr.get(i)+" ");
        }
        System.out.println();
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
        selectionSort(arr);
    }
}