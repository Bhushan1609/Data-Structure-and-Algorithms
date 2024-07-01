import java.util.*;
public class J{
    static void brute(Vector<Integer>v){
        HashSet<Integer>s=new HashSet<>();
        for(int i=0;i<v.size();i++) s.add(v.get(i));
        int index=0;
        for (Integer i : s) {
            v.set(index,i);
            index++;
        }
        System.out.println(v);
    }
    static void optimal(Vector<Integer>v){
        int i=0;
        int j=0;
        while(j<v.size() && i<v.size()){
            while(j<v.size() && v.get(i) == v.get(j)){
                j++;
            }
            i++;
            if(j<v.size() && i<v.size()){
                int temp=v.get(i);
                v.set(i,v.get(j));
                v.set(j,temp);
                j++;
            }
        }
        System.out.println(v);
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        Vector<Integer>v1=new Vector<>();
        v.addAll(Arrays.asList(1,1,2,3,3));
        v1.addAll(Arrays.asList(1,1,2,3,3));
        brute(v);
        optimal(v1);
    }
}