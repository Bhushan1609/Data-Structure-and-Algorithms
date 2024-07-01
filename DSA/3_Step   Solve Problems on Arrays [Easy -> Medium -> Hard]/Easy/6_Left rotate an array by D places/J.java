import java.util.*;
public class J{
    static void reverse(int low,int high,Vector<Integer>v){
        while(low<=high){
            int temp=v.get(low);
            v.set(low,v.get(high));
            v.set(high,temp);  
            low++;
            high--;      
        }
    }
    static void brute(Vector<Integer>v,int d){
        Vector<Integer>temp=new Vector<>();
        for(int i=0;i<d;i++)temp.add(v.get(i));
        for(int i=d;i<v.size();i++){
            v.set(i-d,v.get(i));
        }
        for(int i=v.size()-d;i<v.size();i++){
            v.set(i,temp.get(i - (v.size()-d)));
        }
        System.out.println(v);
        return ;
    }
    static void optimal(Vector<Integer>v1,int d){
        reverse(0,d-1,v1);
        reverse(d,v1.size()-1,v1);
        reverse(0,v1.size()-1,v1);
        System.out.println(v1);
        return ;
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        Vector<Integer>v1=new Vector<>();
        v.addAll(Arrays.asList(1,2,3,4,5,6,7,8));
        v1.addAll(Arrays.asList(1,2,3,4,5,6,7,8));
        int d=5;
        d=d%v.size();
        brute(v,d);
        optimal(v1,d);
    }
}