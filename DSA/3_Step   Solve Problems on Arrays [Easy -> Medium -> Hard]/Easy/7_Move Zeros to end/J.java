import java.util.*;
public class J{
    static void brute(Vector<Integer>v){
        Vector<Integer>temp=new Vector<>();
        for(int i=0;i<v.size();i++){
            if(v.get(i)!=0) temp.add(v.get(i));
        }
        for(int i=0;i<temp.size();i++){
            v.set(i,temp.get(i));
        }
        for(int i=temp.size();i<v.size();i++) v.set(i,0);
        System.out.println(v);
    }
    static void optimal(Vector<Integer>v1){
        int i=0;
        for(i=0;i<v1.size();i++){
            if(v1.get(i)==0){
                break;
            }
        }
        int j=i+1;
        while(j<v1.size()){
            if(v1.get(j)!=0){
                int temp=v1.get(i);
                v1.set(i,v1.get(j));
                v1.set(j,temp);
                i++;
            }
            j++;
        }
        System.out.println(v1);
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        Vector<Integer>v1=new Vector<>();
        v.addAll(Arrays.asList(1,2,0,0,0,3,0,0,4,5,0,0));
        v1.addAll(Arrays.asList(1,2,0,0,0,3,0,0,4,5,0,0));
        brute(v);
        optimal(v1);
    }
}