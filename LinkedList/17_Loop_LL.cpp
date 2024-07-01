#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* next ;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};
Node* convertArray2LL(vector <int>& arr ){
    int n = arr.size();
    Node* head = new Node(arr[0] , NULL);
    Node* mover = head;
    for (int i = 1; i < n ; i++){
        Node* temp = new Node(arr[i] , NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void traversal_LL(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return ;
}
bool callbrute(Node* head){
    Node* temp = head;
    if(!temp) return false;
    unordered_map<Node* , int>mapp;
    while(temp){
        if(mapp.find(temp) != mapp.end()) return true;
        mapp[temp]++;
        temp = temp -> next;
    }
    return false;
}
bool calloptimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(!fast and !fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    return 0;
}
