import java.util.*;
public class J{
    static void insertionSort(Vector<Integer>v){
        for(int i=0;i<v.size();i++){
            int j=i;
            while(j>0 && v.get(j-1)>v.get(j)){
                int temp=v.get(j);
                v.set(j,v.get(j-1));
                v.set(j-1,temp);
                j-=1;
            }
        }
    }
    public static void main(String args[]){
        Vector<Integer>v=new Vector<>();
        v.add(43);
        v.add(12);
        v.add(4);
        v.add(566);
        v.add(2);
        v.add(33);
        v.add(78);
        insertionSort(v);
        System.out.println(v);
    }
}

