#include <bits/stdc++.h>
using namespace std;
//O(n*n)
//O(1)
void callbrute(vector<int>a) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    cout << "The number of inversions is: " << cnt << endl;
    return ;
}
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   
    int cnt = 0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; 
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high); 
    cnt += merge(arr, low, mid, high);  
    return cnt;
}
//O(n*logn)
//O(n)
void calloptimal(vector<int>a) {
    int cnt = mergeSort(a, 0, a.size() - 1);
    cout << "The number of inversions is: " << cnt << endl;
    return ;
}
int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    callbrute(a);
    calloptimal(a);
    return 0;
}
