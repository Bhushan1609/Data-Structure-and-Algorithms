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
Node* callbrute(Node* head){
    Node* temp = head;
    unordered_map<Node* , int> mapp;
    while(temp){
        if(mapp.find(temp) != mapp.end()) return temp;
        mapp[temp]++;
        temp = temp -> next; 
    }
    return NULL;
}
// returing length of the Loop in the LL
int bruteLengthLoop(Node* head){
    Node* temp = head;
    int len = 0;
    unordered_map<Node* , int> mapp;
    while(temp){
        if(mapp.find(temp) != mapp.end()) {
            return (len) - mapp[temp];
        }
        mapp[temp] = (len++);
        temp = temp -> next; 
    }
    return 0;
}
int findlenght(Node* slow , Node* fast){
    int cnt = 1;
    fast = fast -> next;
    while(fast != slow){
        cnt++;
        fast = fast -> next;
    }
    return cnt;
}
int optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return findlenght(slow,fast);
        }
    }
    return 0;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    return 0;
}
