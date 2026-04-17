import java.io.*;
import java.util.*;

class Java{
	static void merge(int start,int mid,int end,List<Integer>arr){
	    int i=start,j=mid+1;
	    List<Integer>temp=new ArrayList<>();
	    while(i<=mid && j<=end){
	        if(arr.get(i)<=arr.get(j)){
	            temp.add(arr.get(i));
	            i++;
	        }else{
	            temp.add(arr.get(j));
	            j++;
	        }
	    }
	    while(i<=mid)
	        temp.add(arr.get(i++));
	    while(j<=end)
	        temp.add(arr.get(j++));

	    for(i=start;i<=end;i++)
	        arr.set(i,temp.get(i-start));
	    
	    return ;
	}

	static void divide(int start,int end,List<Integer>arr){
	    if(start>=end)
	        return;
	    int mid=(start+end)>>1;
	    divide(start,mid,arr);
	    divide(mid+1,end,arr);
	    merge(start,mid,end,arr);
	}

	static void mergeSort(List<Integer>arr){
		int n=arr.size();
    	divide(0,n-1,arr);
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

				mergeSort(arr);  

				out.print("After Sorting  : ");
				for(int i:arr)
					out.print(i+" ");
				out.println();         
			}
		}
	}
}
//Problem Link : https://www.geeksforgeeks.org/problems/merge-sort/1