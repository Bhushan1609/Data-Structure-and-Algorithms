import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.lang.*;
import java.util.Vector;
import java.util.Arrays;

public class Java{
    static void bubbleSort(Vector<Integer>arr){
        int n=arr.size();
        for(int j=n-1;j>=0;j--){
            for(int i=1;i<=j;i++){
                if(arr.get(i)<arr.get(i-1)){
                    int temp=arr.get(i);
                    arr.set(i,arr.get(i-1));
                    arr.set(i-1,temp);
                }
            }
        }
        return ;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");
        try(Scanner ip = new Scanner(new File("input.txt"));
            PrintWriter op = new PrintWriter(f);){
            Vector<Integer>arr=new Vector<>(Arrays.asList(13,46,24,52,20,9));
            op.println("Before Sorting : ");
            for(int i=0;i<arr.size();i++)
                op.print(arr.get(i)+" ");
            op.println();
            bubbleSort(arr);
            op.println("Before Sorting : ");
            for(int i=0;i<arr.size();i++)
                op.print(arr.get(i)+" ");
        }
    }
}
//Problem Link : https://www.geeksforgeeks.org/problems/bubble-sort/1