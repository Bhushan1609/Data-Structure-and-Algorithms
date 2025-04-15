import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.lang.*;
import java.util.Vector;
import java.util.Arrays;

public class Java {

    static void selectionSort(Vector<Integer>arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            int minIndex=i;
            int minValue=arr.get(i);
            for(int j=i+1;j<n;j++)
                if(minValue>arr.get(j)){
                    minValue=arr.get(j);
                    minIndex=j;
                }
            int temp=arr.get(i);
            arr.set(i,arr.get(minIndex));
            arr.set(minIndex,temp);
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
            selectionSort(arr);
            op.println("Before Sorting : ");
            for(int i=0;i<arr.size();i++)
                op.print(arr.get(i)+" ");
        }
    }
}