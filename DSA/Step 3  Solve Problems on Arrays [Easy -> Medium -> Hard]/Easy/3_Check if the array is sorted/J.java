import java.util.*;
public class J{
    
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(5, 67, 890, 1, 23, 345));
        for(int i=0;i<v.size()-1;i++){
            if(v.get(i)>v.get(i+1)){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}