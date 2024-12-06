import java.util.*;
public class Java{
    static void brute(Vector<Integer>arr){
        HashSet<Integer>st=new HashSet<>();
        Vector<Integer>newArr=new Vector<>();
        newArr=arr;
        for(int i=0;i<newArr.size();i++) st.add(newArr.get(i));
        int index=0;
        for (Integer i : st) {
            newArr.set(index,i);
            index++;
        }
        System.out.println(newArr);
    }
    static void optimal(Vector<Integer>arr){
        int i=0,currValue=Integer.MIN_VALUE;
        Vector<Integer>newArr=new Vector<>();
        newArr=arr;
        for(int j=0;j<newArr.size();j++){
            if(newArr.get(j) != currValue){
                newArr.set(i,newArr.get(j));
                i+=1;
                currValue=newArr.get(j);
            }
        }
        System.out.println(newArr);
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,1,2,2,2,3,3));
        brute(arr);
        optimal(arr);
    }
}
