import java.util.*;
public class J{
    public static void main(String args[]){
        Vector<Integer>a=new Vector<>();
        a.add(1);
        a.add(1);

        a.add(2);
        a.add(2);

        a.add(3);
        a.add(3);
        Map<Integer,Integer>m=new HashMap();
        for(int i=0;i<a.size();i++) {

            int key = a.get(i);
            m.put(key, m.getOrDefault(key, 0) + 1);

        }

        for(Map.Entry<Integer,Integer> it : m.entrySet()){
            System.out.println(it.getKey()+" "+it.getValue());
        }
    }
}