import java.io.*;
import java.util.*;

class Java{
	static int f(int low,int high,List<Integer>arr){
	    int pivot=arr.get(low);
	    int i=low;
	    int j=high;

	    while(i<j){
	        while(i<high && arr.get(i)<=pivot)
	            i++;

	        while(j>low && arr.get(j)>pivot)
	            j--;

	        if(i<j){
	        	int temp=arr.get(i);
	        	arr.set(i,arr.get(j));
	        	arr.set(j,temp);	   
	        }
	    }
	    int temp=arr.get(low);
    	arr.set(low,arr.get(j));
    	arr.set(j,temp);	
	    return j;
	}

	static void quickSort(int low,int high,List<Integer>arr){
	    if(low<high){
	        int partitionIndex=f(low,high,arr);
	        quickSort(low,partitionIndex-1,arr);
	        quickSort(partitionIndex+1,high,arr);
	    }
	    return ;
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

				quickSort(0,arr.size()-1,arr);

				out.print("After Sorting  : ");
				for(int i:arr)
					out.print(i+" ");
				out.println();         
			}
		}
	}
}
//Problem Link : https://www.geeksforgeeks.org/problems/quick-sort/1