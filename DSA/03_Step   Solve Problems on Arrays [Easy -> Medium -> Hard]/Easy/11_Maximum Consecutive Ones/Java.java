import java.util.*;
public class Java{
    public static void main(String args[]){
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,1,0,1,1,1,0,1,1));
        int cnt=0,maxi=-1;
        for(int i=0;i<arr.size();i++){
            if(arr.get(i)==1)cnt++;
            else {
                maxi=Math.max(maxi,cnt);
                cnt=0;
            }
        }
        System.out.println(maxi);
    }
}