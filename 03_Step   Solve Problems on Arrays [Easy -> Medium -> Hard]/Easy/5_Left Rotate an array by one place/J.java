import java.util.*;
public class J{
    
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(1,2,3,4,5));
        for(int i=0;i<v.size()-1;i++){
           int temp=v.get(i);
           v.set(i,v.get(i+1));
           v.set(i+1,temp);
        }
        System.out.println(v);
    }
}