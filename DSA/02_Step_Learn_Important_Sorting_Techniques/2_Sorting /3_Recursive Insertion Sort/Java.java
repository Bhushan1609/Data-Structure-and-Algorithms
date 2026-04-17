import java.io.*;
import java.util.*;

class Java{

	static void insertionSort(List<Integer>arr){
		int n=arr.size();
        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr.get(j)<arr.get(j-1)){
                Collections.swap(arr,j,j-1);
                j--;
            }
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

				insertionSort(arr);  

				out.print("After Sorting  : ");
				for(int i:arr)
					out.print(i+" ");
				out.println();         
			}
		}
	}
}
//Problem Link : https://www.geeksforgeeks.org/problems/insertion-sort/1