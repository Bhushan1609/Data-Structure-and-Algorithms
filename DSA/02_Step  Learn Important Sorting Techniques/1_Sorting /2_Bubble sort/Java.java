import java.util.*;
public class Java{
    static void bubbleSort(Vector<Integer>arr){
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int didSwaps=0;
            for(int j=0;j<i;j++){
                if(arr.get(j) > arr.get(j+1)){
                    int temp=arr.get(j);
                    arr.set(j,arr.get(j+1));
                    arr.set(j+1,temp);
                    didSwaps+=1;
                }
            }
            if(didSwaps == 0){
                break;
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(arr.get(i)+" ");
        }
        System.out.println();
        return ;
    }
    public static void main(String[] args){
        Vector<Integer>arr=new Vector<>();
        arr.add(13);
        arr.add(46);
        arr.add(24);
        arr.add(52);
        arr.add(20);
        arr.add(9);
        bubbleSort(arr);
    }
}