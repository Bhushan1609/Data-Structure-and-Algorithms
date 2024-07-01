import java.util.*;
public class J{
    static boolean rec(int i,int j,String ar){
        if(i>j)return true;
        if(ar.charAt(i) != ar.charAt(j))return false;
        return rec(i+1,j-1,ar);
    }
    public static void main(String args[]){
        String a="Bhushan";
        System.out.println(rec(0,a.length()-1,a));
    }
}
