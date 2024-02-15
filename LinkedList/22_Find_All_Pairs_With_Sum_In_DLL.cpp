#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* next ;
    Node* prev ;
    Node(int data1 , Node* prev1 , Node* next1){
        data = data1;
        next = prev1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        prev = NULL;
        next = NULL;
    }
};
Node* convertArray2DLL(vector <int>& arr ){
    int n = arr.size();
    Node* head = new Node(arr[0] , NULL , NULL);
    Node* mover = head;
    for (int i = 1; i < n ; i++){
        Node* temp = new Node(arr[i] , NULL ,NULL);
        mover->next = temp;
        temp -> prev = mover;
        mover = temp;
    }
    return head;
}
void traversal_DLL(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return ;
}
vector <pair <int , int>> callbrute(Node* head , int sum ){
    vector <pair <int , int >> answer;
    if(!head or !head -> next) return answer;
    Node* temp1 = head;
    while(temp1){
        if((temp1 -> data) > sum) break;
        Node* temp2 = temp1 -> next;
        while(temp2){
            int addIt = temp1 -> data + temp2 -> data ; 
            if(addIt == sum){
                answer.push_back({temp1 -> data , temp2 -> data});
            }
            else if(addIt > sum) break;
            temp2 = temp2 -> next;
        }
        temp1 = temp1 -> next; 
    }
    return answer;
}
vector <pair <int , int>> calloptimal(Node* head , int sum ){
    vector <pair <int , int >> answer;
    if(!head or !head -> next) return answer;
    Node* tail = head;
    while(tail -> next){
        tail = tail -> next;
    }
    while((head -> data) < (tail -> data)){
        int addIt = head -> data + tail -> data;
        if(addIt == sum){
            answer.push_back({head -> data , tail -> data});
        }
        if(addIt > sum){
            tail = tail -> prev;
        }
        else{
            head = head -> next;
        }
    }
    return answer;
}
int main(){
    vector <int> arr = {1,2,3,4,9};
    Node* head = convertArray2DLL(arr);
    cout << "DLL  : ";cout << endl;
    traversal_DLL(head);
    vector <pair <int , int >> answer;
    answer = calloptimal(head , 5);
    for (auto i : answer){
        cout << "{" << i.first << "," << i.second << "}" << endl; 
    }
    return 0;
}
