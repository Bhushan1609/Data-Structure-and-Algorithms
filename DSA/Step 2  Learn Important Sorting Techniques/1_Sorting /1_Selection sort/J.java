import java.util.*;
public class J{
    static void selectionSort(Vector<Integer>v){
        for(int i=0;i<v.size();i++){
            int minindex=i;
            for(int j=i+1;j<v.size();j++){
                if(v.get(j) < v.get(minindex))minindex=j;
            }
            int temp=v.get(i);
            v.set(i,v.get(minindex));
            v.set(minindex,temp);
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
        selectionSort(v);
        System.out.println(v);
    }
}