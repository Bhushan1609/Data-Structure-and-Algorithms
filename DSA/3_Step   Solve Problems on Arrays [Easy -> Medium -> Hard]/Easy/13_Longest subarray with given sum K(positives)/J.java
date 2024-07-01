import java.util.*;
public class J{
    static void brute(Vector<Integer>v,int k){
        int ans=0;
        for(int i=0;i<v.size();i++){
            for(int j=i;j<v.size();j++){
                int sum=0;
                for(int l=i;l<=j;l++)sum+=v.get(l);
                if(sum==k)ans=Math.max(ans,j-i+1);
            }
        }
        System.out.println(ans);
    }
    static void brute1(Vector<Integer>v,int k){
        int ans=0;
        for(int i=0;i<v.size();i++){
            int sum=0;
            for(int j=i;j<v.size();j++){
                sum+=v.get(j);
                if(sum==k)ans=Math.max(ans,j-i+1);
            }
        }
        System.out.println(ans);
    }
    static void better(Vector<Integer> v, int k) {
        HashMap<Integer, Integer> mapp = new HashMap<>();
        int prefSum = 0;
        mapp.put(prefSum, 1);
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            prefSum += v.get(i);
            
            if (prefSum == k) {
                ans = Math.max(ans, i + 1);
            }
            int remaining = prefSum - k;
            if (mapp.containsKey(remaining)) {
                ans = Math.max(ans, i - mapp.get(remaining));
            }
            
            if (!mapp.containsKey(prefSum)) {
                mapp.put(prefSum, i);
            }
        }
        System.out.println(ans);
    }
    static void optimal(Vector<Integer>v , int k){
        int n = v.size();
        int sum =v.get(0);
        int left , right ;
        left = right = 0;
        int ans = 0;
        while(right < n){
            while(left <= right && sum > k){
                sum -= v.get(left);
                left++;
            }
            if(sum == k) {
                ans = Math.max(ans , right - left + 1);
            }
            right++;
            if(right < n) sum += v.get(right);
        }
        System.out.println(ans);
    }
    public static void main(String args[]){
        Vector<Integer>v1=new Vector<>();
        v1.addAll(Arrays.asList(1,2,3,1,1,1,1,4,2,3));

        Vector<Integer>v2=new Vector<>();
        v2.addAll(Arrays.asList(1,2,3,1,1,1,1,4,2,3));

        Vector<Integer>v3=new Vector<>();
        v3.addAll(Arrays.asList(1,2,3,1,1,1,1,4,2,3));

        Vector<Integer>v4=new Vector<>();
        v4.addAll(Arrays.asList(1,2,3,1,1,1,1,4,2,3));
        

        int k=3;
        brute(v1,k);
        brute1(v2,k);
        better(v3,k);
        optimal(v4,k);
    }
}