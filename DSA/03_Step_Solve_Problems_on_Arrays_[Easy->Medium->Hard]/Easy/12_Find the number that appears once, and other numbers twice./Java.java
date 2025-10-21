import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr){
        for(int i=0;i<arr.size();i++){
            int cnt=0;
            for(int j=0;j<arr.size();j++){
                if(arr.get(i)==arr.get(j))cnt++;
            }
            if(cnt==1){
                System.out.println(arr.get(i));
                return;
            }
        }
    }
    static void callBetter(Vector<Integer>arr){
        HashMap<Integer,Integer>mapp=new HashMap<>();
        for(Integer i: arr){
            mapp.put(i, mapp.getOrDefault(i, 0) + 1);
        }
        for(Map.Entry<Integer,Integer> it : mapp.entrySet()){
            if(it.getValue()==1){
                System.out.println(it.getKey());
                return;
            }
        }
    
    }
    static void callOptimal(Vector<Integer>arr){
        int xorr=0;
        for(Integer i:arr)xorr ^= i;
        System.out.println(xorr);
        return;
    }
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,1,2,3,3,4,4));
        callBrute(arr);
        callBetter(arr);
        callOptimal(arr);
    }
}