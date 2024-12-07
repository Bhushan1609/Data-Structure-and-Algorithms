import java.util.*;
public class Java{
    static void callBrute(Vector<Integer>arr,int target){
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=arr.get(k);
                }
                if(sum==target)ans=Math.max(ans,j-i+1);
            }
        }
        System.out.println(ans);
    }
    static void optimizedBrute(Vector<Integer>arr,int target){
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr.get(j);
                if(sum==target)ans=Math.max(ans,j-i+1);
            }
        }
        System.out.println(ans);
    }
    static void callBetter(Vector<Integer>arr,int target){
        int n=arr.size(),ans=0,sum=0;
        HashMap<Integer,Integer>prefixSum=new HashMap<>();
        for(int i=0;i<n;i++){
            sum+=arr.get(i);
            if(arr.get(i)==target)ans=Math.max(ans,i+1);
            if(sum==target)ans=Math.max(ans,i+1);
            int needSum=sum-target;
            if(prefixSum.containsKey(needSum)){
                ans=Math.max(ans,i-prefixSum.get(needSum));
            }
            if(!prefixSum.containsKey(needSum)){
                prefixSum.put(sum,i);
            }
        }
        System.out.println(ans);
    }
    static void callOptimal(Vector<Integer>arr,int target){
        int left=0,right=0,ans=0,sum=arr.get(0);
        while(right<arr.size()){
            while(left <= right && sum>target){
                sum-=arr.get(left);
                left++;
            }
            if(sum==target) ans=Math.max(ans,right-left+1);
            right++;
            if(right<arr.size()) sum+=arr.get(right);
        }
        System.out.println(ans);
    }
    public static void main(String args[]){
        int target=3;
        Vector<Integer>arr=new Vector<>();
        arr.addAll(Arrays.asList(1,2,3,1,1,1,1,4,2,3));
        callBrute(arr,target);
        optimizedBrute(arr,target);
        callBetter(arr,target);
        callOptimal(arr,target);
    }
}