import java.util.*;
public class J{
    static void brute(Vector<Integer>v){
        Collections.sort(v);
        int i=v.size()-1,ans=-1;
        while(i>0){
            if(v.get(i-1) != v.get(i)){
                ans=v.get(i-1);
                break;
            }
            i--;
        }
        System.out.println(ans);
    }
    static void better(Vector<Integer>v){
        int ans=Integer.MIN_VALUE,ans2=Integer.MIN_VALUE;
        for(int i=0;i<v.size();i++) ans=Math.max(ans,v.get(i));
        for(int i=0;i<v.size();i++){
            if(v.get(i) != ans)ans2=Math.max(ans2,v.get(i));
        }
        System.out.println(ans2);
    }
    static void optimal(Vector<Integer>v){
        int ans=Integer.MIN_VALUE,ans2=Integer.MIN_VALUE;
        for(int i=0;i<v.size();i++){
            if(v.get(i)>ans){
                ans2=ans;
                ans=v.get(i);
            }
            else{
                if(v.get(i)>ans2)ans2=v.get(i);
            }
        }
        System.out.println(ans2);
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(5, 67, 890, 1, 23, 345));
        brute(v);
        better(v);
        optimal(v);
    }
}