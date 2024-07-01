import java.util.*;
public class J{
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(1,0,1,1,1,1,0,0,00,00,0,1,1,1));
        int cnt=0,maxi=Integer.MIN_VALUE;
        for(int i=0;i<v.size();i++){
            if(v.get(i)==1)cnt++;
            else cnt=0;
            maxi=Math.max(maxi,cnt);
        }
        System.out.println(maxi);
    }
}