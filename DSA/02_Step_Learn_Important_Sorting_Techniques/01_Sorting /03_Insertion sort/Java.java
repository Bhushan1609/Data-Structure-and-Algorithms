import java.io.*;
import java.util.*;

public class Java{

	static void insertionSort(List<Integer>arr){
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

			insertionSort(arr);

			out.println("After Sorting : ");
			for(int i:arr)
				out.print(i+" ");
			out.println();
		}
	}

}
//Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort/1