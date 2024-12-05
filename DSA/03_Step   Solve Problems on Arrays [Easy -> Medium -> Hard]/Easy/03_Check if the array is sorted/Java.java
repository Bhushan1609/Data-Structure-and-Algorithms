import java.util.*;
public class Java{
    
    public static void main(String args[]){
        boolean ans=true;
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,2,1,3,4));
        for(int i=1;i<arr.size();i++){
            if(arr.get(i)<arr.get(i-1)){
                ans=false;
                break;
            }
        }
        System.out.println(ans);
    }
}