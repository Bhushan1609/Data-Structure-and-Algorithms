import java.util.*;
public class J{
    static void brute(Vector<Integer>v){
        Collections.sort(v);
        System.out.println(v.get(v.size()-1));
    }
    static void optimal(Vector<Integer>v){
        int ans=Integer.MIN_VALUE;
        for(int i=0;i<v.size();i++)ans=Math.max(ans,v.get(i));
        System.out.println(ans);
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(5, 67, 890, 1, 23, 345));
        brute(v);
        optimal(v);
    }
}