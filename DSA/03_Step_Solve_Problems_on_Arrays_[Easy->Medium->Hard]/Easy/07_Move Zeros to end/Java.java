import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr){
        Vector<Integer>temp=new Vector<>();
        for(int i=0;i<arr.size();i++){
            if(arr.get(i)>0)temp.add(arr.get(i));
        }
        for(int i=temp.size();i<arr.size();i++)temp.add(0);
        System.out.println(temp);
    }
    static void callOptimal(Vector<Integer>arr){
        int left=-1,right=0;
        while(right<arr.size()){
            if(arr.get(right)>0){
                if(left!=-1){
                    int temp=arr.get(left);
                    arr.set(left,arr.get(right));
                    arr.set(right,temp);
                    left++;
                }
                right++;
            }else{
                if(left==-1)left=right;
                right+=1;
            }
        }
        System.out.println(arr);
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,0,2,3,2,0,0,4,5,1));
        callBrute(arr);
        callOptimal(arr);
    }
}