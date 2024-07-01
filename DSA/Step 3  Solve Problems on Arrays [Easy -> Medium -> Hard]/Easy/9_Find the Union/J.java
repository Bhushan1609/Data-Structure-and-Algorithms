import java.util.*;
public class J{
    static void brute(Vector<Integer>a,Vector<Integer>b){
        HashSet<Integer>s=new HashSet<>();
        for(int i=0;i<a.size();i++)s.add(a.get(i));
        for(int i=0;i<b.size();i++)s.add(b.get(i));
        Vector<Integer>ans=new Vector<>();
        for(Integer i:s) ans.add(i);
        System.out.println(ans);
        return;
    }
    static void optimal(Vector<Integer>a,Vector<Integer>b){
        int i=0;
        int j=0;
        int n=a.size(),m=b.size();
        Vector<Integer>ans=new Vector<>();
        while(i<n && j<m){
            if(a.get(i) <= b.get(j)){
                if(ans.size()==0 || ans.lastElement() != a.get(i)){
                    ans.add(a.get(i));
                }
                i++;
            }
            else{
                if(ans.size()==0 || ans.lastElement() != b.get(j)){
                    ans.add(b.get(j));
                }
                j++;
            }
        }
        while(i<n){
            if(ans.size()==0 || ans.lastElement() != a.get(i)){
                ans.add(a.get(i));
            }
            i++;
        }
        while(j<m){
            if(ans.size()==0 || ans.lastElement() != b.get(j)){
                ans.add(b.get(j));
            }
            j++;
        }
       System.out.println(ans);
    }
    public static void main(String args[]){
        Vector<Integer>a=new Vector<>();
        Vector<Integer>a1=new Vector<>();
        Vector<Integer>b=new Vector<>();
        Vector<Integer>b1=new Vector<>();
        a.addAll(Arrays.asList(1,1,2,3,3,4,5));
        a1.addAll(Arrays.asList(1,1,2,3,3,4,5));
        b.addAll(Arrays.asList(1,2,2,3,5));
        b1.addAll(Arrays.asList(1,2,2,3,5));
        brute(a,b);
        optimal(a1,b1);
    }
}