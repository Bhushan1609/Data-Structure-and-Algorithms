import java.util.*;
public class Java{
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(6,7,8,4,1));
        int key=4;
        for(int i=0;i<v.size();i++){
            if(v.get(i)==key){
                System.out.println(i);
                break;
            }
        }
    }
}