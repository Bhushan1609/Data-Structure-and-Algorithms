#include <bits/stdc++.h>
using namespace std;
#define d double
//O(n1+n2) + O((n1+n2)log(n1+n2))
//O(n1+n2)
d callbrute1(vector <int>& vec1 , vector <int>& vec2){
    int n1 = vec1.size();
    int n2 = vec2.size();
    vector <int> answer;//space O (n1 + n2)
    for (int i = 0 ; i < n1 ; i++){ // time O(n1)
        answer.push_back(vec1[i]);
    }
    for (int i = 0 ; i < n2 ; i++){ // time O(n2)
        answer.push_back(vec2[i]);
    }
    sort(answer.begin() , answer.end()); // time O((n1+n2)log(n1+n2))
    int mid = answer.size() / 2;
    if(answer.size() % 2 == 0){ 
        return (answer[mid] + answer[mid-1]) / 2.0;
    }
    else{
        return answer[mid];
    }
    return -1.0;
}
//O(n1+n2) 
//O(n1+n2)
d callbrute2(vector <int>& vec1 , vector <int>& vec2){
    int n1 = vec1.size();
    int n2 = vec2.size();
    vector <int> answer;
    int i = 0 ;
    int j = 0;
    while(i < n1 and j < n2){
        if(vec1[i] <= vec2[j]){
            answer.push_back(vec1[i]);
            i++;
        }
        else{
            answer.push_back(vec2[j]);
            j++;
        }
    }
    while(i < n1){
        answer.push_back(vec1[i]);
        i++;
    }
    while(j < n2){
        answer.push_back(vec2[j]);
        j++;
    }
    int mid = answer.size() / 2;
    if(answer.size() % 2 == 0){ 
        return (answer[mid] + answer[mid-1]) / 2.0;
    }
    else{
        return answer[mid] / 1.0;
    }
    return -1.0;
}
//O(n1+n2) 
//O(1)
d callbetter(vector <int>& vec1 , vector <int>& vec2){
    int n1 = vec1.size();
    int n2 = vec2.size();
    int mid = (n1+n2)/2 + 1;
    int cnt = 0 ,ele1 = 0 , ele2 = 0;
    int i = 0 ;
    int j = 0;
    while(i < n1 and j < n2){
        if(vec1[i] <= vec2[j]){
            cnt++;
            if(cnt == (mid - 1)){
                ele1 = vec1[i];
            }
            else if(cnt == mid){
                ele2 = vec1[i];
            }
            if(cnt >= mid){
                if((n1+n2) & 1){
                    return (d) (ele2/1.0);
                }
                else{
                    return (d) (((d)(ele1+ele2))/2.0) ;
                }
            }
            i++;
        }
        else{
            cnt++;
            if(cnt == (mid - 1)){
                ele1 = vec2[j];
            }
            else if(cnt == mid){
                ele2 = vec2[j];
            }
            if(cnt >= mid){
                if((n1+n2) & 1){
                    return (d) (ele2/1.0);
                }
                else{
                    return (d) (((d)(ele1+ele2))/2.0) ;
                }
            }
            j++;
        }
        
    }
    while(i < n1){
        cnt++;
        if(cnt == (mid - 1)){
            ele1 = vec1[i];
        }
        else if(cnt == mid){
            ele2 = vec1[i];
        }
        if(cnt >= mid){
            if((n1+n2) & 1){
                return (d) (ele2/1.0);
            }
            else{
                return (d) (((d)(ele1+ele2))/2.0) ;
            }
        }
        i++;
    }
    while(j < n2){
        cnt++;
        if(cnt == (mid - 1)){
            ele1 = vec2[j];
        }
        else if(cnt == mid){
            ele2 = vec2[j];
        }
        if(cnt >= mid){
            if((n1+n2) & 1){
                return (d) (ele2/1.0);
            }
            else{
                return (d) (((d)(ele1+ele2))/2.0) ;
            }
        }
        j++;
    }
    return -1.0;
}
int main(){
    vector <int> vec1 ={1,3,4,7,10,12};
    vector <int> vec2 ={2,3,6,15};
    cout << (d) callbrute1(vec1 , vec2) << endl ;
    cout << (d) callbrute2(vec1 , vec2) << endl;
    cout << (d) callbetter(vec1 , vec2) << endl;
    return 0;
}