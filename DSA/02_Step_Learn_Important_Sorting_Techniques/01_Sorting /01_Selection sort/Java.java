import java.io.*;
import java.util.*;

class Java{
	static void selectionSort(List<Integer>arr){
		int n=arr.size();
		for(int i=0;i<n;i++){
			int minIndex=i;
			for(int j=i+1;j<n;j++){
				if(arr.get(j)<arr.get(minIndex))
					minIndex=j;
			}
			Collections.swap(arr, i, minIndex);
		}
	}
	public static void main(String args[]) throws FileNotFoundException{
		{
			try(
				Scanner in=new Scanner(new File("input.txt"));
				PrintWriter out=new PrintWriter("output.txt")
			){
				List<Integer>arr=new ArrayList<>(Arrays.asList(13,46,24,52,20,9));
				out.print("Before Sorting : ");
				for(int i:arr)
					out.print(i+" ");
				out.println(); 

				selectionSort(arr);  

				out.print("After Sorting  : ");
				for(int i:arr)
					out.print(i+" ");
				out.println();         
			}
		}
	}
}
//Problem Link : https://www.geeksforgeeks.org/problems/selection-sort/1