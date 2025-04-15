import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.lang.*;
import java.util.Vector;
import java.util.Arrays;

public class Java{
    static void insertionSort(Vector<Integer>arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr.get(j)<arr.get(j-1)){
                int temp=arr.get(j);
                arr.set(j,arr.get(j-1));
                arr.set(j-1,temp);
                --j;
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
            insertionSort(arr);
            op.println("Before Sorting : ");
            for(int i=0;i<arr.size();i++)
                op.print(arr.get(i)+" ");
        }
    }
}
// https://www.geeksforgeeks.org/problems/insertion-sort/1