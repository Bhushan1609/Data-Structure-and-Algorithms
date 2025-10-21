import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr1,Vector<Integer>arr2){
        Vector<Integer>temp=new Vector<>();
        HashSet<Integer>st=new HashSet<>();
        for(int i=0;i<arr1.size();i++)st.add(arr1.get(i));
        for(int i=0;i<arr2.size();i++)st.add(arr2.get(i));
        for(Integer i : st)temp.add(i);
        System.out.println(temp);
    }
    static void callOptimal(Vector<Integer>arr1,Vector<Integer>arr2){
        int i=0,j=0;
        Vector<Integer>temp=new Vector<>();
        while(i<arr1.size() && j<arr2.size()){
            if(arr1.get(i)<arr2.get(j)){
                if(temp.size() > 0){
                    int nn=temp.size();
                    if(temp.get(nn-1) != arr1.get(i)){
                        temp.add(arr1.get(i));
                    }
                }else temp.add(arr1.get(i));
                i+=1;
            }else{
                if(temp.size() > 0){
                    int nn=temp.size();
                    if(temp.get(nn-1) != arr2.get(j)){
                        temp.add(arr2.get(j));
                    }
                }else temp.add(arr2.get(j));
                j+=1;
            }
        }
        while(i<arr1.size()){
            if(temp.size() > 0){
                int nn=temp.size();
                if(temp.get(nn-1) != arr1.get(i)){
                    temp.add(arr1.get(i));
                }
            }else temp.add(arr1.get(i));
            i+=1;
        }
        while(j<arr2.size()){
            if(temp.size() > 0){
                int nn=temp.size();
                if(temp.get(nn-1) != arr2.get(j)){
                    temp.add(arr2.get(j));
                }
            }else temp.add(arr2.get(j));
            j+=1;
        }
        System.out.println(temp);
    }
    public static void main(String args[]){
        Vector<Integer>arr1=new Vector<>();
        Vector<Integer>arr2=new Vector<>();
        arr1.addAll(Arrays.asList(1,1,2,3,4,5));
        arr2.addAll(Arrays.asList(2,3,4,4,5,6));
        callBrute(arr1,arr2);
        callOptimal(arr1,arr2);
    }
}