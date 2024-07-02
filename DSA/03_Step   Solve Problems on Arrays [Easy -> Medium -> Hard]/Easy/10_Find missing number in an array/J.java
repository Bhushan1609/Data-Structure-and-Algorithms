import java.util.*;
public class J{
    static void brute(Vector<Integer>v,int n){
        for(int i=1;i<=n;i++){
            boolean flag=false;
            for(int j=0;j<v.size();j++){
                if(i==v.get(j))flag=true;
            }
            if(flag==false){
                System.out.println(i);
                return ;
            }
        }
    }
    static void better(Vector<Integer>v,int n){
        Vector<Integer> hash = new Vector<>(Collections.nCopies(n + 1, 0));
        for(int i=0;i<v.size();i++) hash.set(v.get(i), hash.get(v.get(i)) + 1);
        for(int i=1;i<hash.size();i++){
            if(hash.get(i)==0){
                System.out.println(i);
                return ;
            }
        }
    }
    static void optimal1(Vector<Integer>v,int n){
        int sum=n*((n+1)>>1);
        for(int i=0;i<v.size();i++)sum-=v.get(i);
        System.out.println(sum);
    }
    static void optimal2(Vector<Integer>v,int n){
        int xor1=0,xor2=0;
        for(int i=0;i<v.size();i++)xor1 ^= v.get(i);
        for(int i=1;i<=n;i++)xor2^=i;
        System.out.println(xor1^xor2);
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        Vector<Integer>v1=new Vector<>();
        Vector<Integer>v2=new Vector<>();
        Vector<Integer>v3=new Vector<>();
        v.addAll(Arrays.asList(1,2,4,5));
        v1.addAll(Arrays.asList(1,2,4,5));

        v2.addAll(Arrays.asList(1,2,4,5));
        v3.addAll(Arrays.asList(1,2,4,5));
        int n=v.size()+1;
        brute(v,n);
        better(v1,n);
        optimal1(v2,n);
        optimal2(v3,n);
    }
}
/*
 

void itachi_1609(){
    int n=5;
    vector<int>v={1,2,4,5};
    
    return;
}
 */