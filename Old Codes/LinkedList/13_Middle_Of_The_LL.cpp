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
    int cnt = 0 ;
    Node* temp = head;
    while(temp){
        temp = temp -> next;
        cnt++;
    }
    temp = head;
    int mid = cnt/2 + 1;
    while(temp){
        mid--;
        if(!mid){
            return temp;
        }
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head){
    Node* slow = head , *fast = head;
    while(fast and fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "Middle Node of the LL " ;
    Node* temp = calloptimal(head);
    cout << (int)temp -> data << endl;
    return 0;
}
