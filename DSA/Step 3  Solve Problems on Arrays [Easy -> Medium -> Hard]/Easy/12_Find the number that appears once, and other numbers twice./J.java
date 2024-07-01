import java.util.*;
public class J{
    static void brute(Vector<Integer>v){
        for(int i=0;i<v.size();i++){
            int cnt=0;
            for(int j=0;j<v.size();j++){
                if(v.get(i)==v.get(j))cnt++;
            }
            if(cnt==1){
                System.out.println(v.get(i));
                return;
            }
        }
    }
    static void better(Vector<Integer>v){
        HashMap<Integer,Integer>mapp=new HashMap<>();
        for(Integer i: v){
            mapp.put(i, mapp.getOrDefault(i, 0) + 1);
        }
        for(Map.Entry<Integer,Integer> it : mapp.entrySet()){
            if(it.getValue()==1){
                System.out.println(it.getKey());
                return;
            }
        }
    
    }
    static void optimal(Vector<Integer>v){
        int xorr=0;
        for(Integer i:v)xorr ^= i;
        System.out.println(xorr);
        return;
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(1,2,1,3,4,3,4));

        Vector<Integer>v1=new Vector<>();
        v1.addAll(Arrays.asList(1,2,1,3,4,3,4));

        Vector<Integer>v2=new Vector<>();
        v2.addAll(Arrays.asList(1,2,1,3,4,3,4));
        brute(v);
        better(v1);
        optimal(v2);
    }
}