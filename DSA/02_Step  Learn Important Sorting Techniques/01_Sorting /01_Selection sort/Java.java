import java.util.*;
import java.io.*;

public class Java{

	static void selectionSort(List<Integer>arr){
		int n=arr.size();
        for(int i=0;i<n;i++){
            int minIndex=i;
            int minValue=arr.get(i);
            for(int j=i+1;j<n;j++){
                if(minValue>arr.get(j)){
                    minIndex=j;
                    minValue=arr.get(j);
                }
            }
            int temp=arr.get(i);
            arr.set(i,arr.get(minIndex));
            arr.set(minIndex,temp);
        }
        return ;
	}

	public static void main(String args[]) throws FileNotFoundException{
		try(
			Scanner in=new Scanner(new File("input.txt"));
            PrintWriter out=new PrintWriter("output.txt")
		){
			List<Integer>arr=new ArrayList<>(Arrays.asList(13,46,24,52,20,9));
			out.println("Before Sorting : ");
			for(int i:arr)
				out.print(i+" ");
			out.println();

			selectionSort(arr);

			out.println("After Sorting : ");
			for(int i:arr)
				out.print(i+" ");
			out.println();
		}
	}

}
//Problem Link : https://www.geeksforgeeks.org/problems/selection-sort/1