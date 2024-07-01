import java.util.*;
public class J{
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.addAll(Arrays.asList(1,1,2,3,3));
        int key=3;
        for(int i=0;i<v.size();i++){
            if(v.get(i)==key){
                System.out.println(i);
                break;
            }
        }
    }
}