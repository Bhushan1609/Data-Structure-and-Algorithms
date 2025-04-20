import java.io.*;
import java.util.*;

public class Java{

	static void bubbleSort(List<Integer>arr){
		int n=arr.size();
        for(int i=n-1;i>=0;i--){
        	boolean swapHappens=false;
        	for(int j=0;j<=i-1;j++){
        		if(arr.get(j)>arr.get(j+1)){
        			int temp=arr.get(j);
        			arr.set(j,arr.get(j+1));
        			arr.set(j+1,temp);
        			swapHappens|=true;
        		}
        	}
        	if(!swapHappens)
        		break;
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

			bubbleSort(arr);

			out.println("After Sorting : ");
			for(int i:arr)
				out.print(i+" ");
			out.println();
		}
	}

}
//Problem Link : http://geeksforgeeks.org/problems/bubble-sort/1