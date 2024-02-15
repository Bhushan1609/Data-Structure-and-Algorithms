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
Node* reverse(Node* head){
    if(!head or !head -> next) return head;
    Node* newHead = reverse(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newHead;
}
Node* callbrute(Node* head){
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp){
        temp -> data = temp -> data + carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            carry = 1;
            temp -> data = 0;
        }
        temp = temp -> next;
    }
    head = reverse(head);
    if(carry == 1){
        Node* newHead = new Node(carry , head);
        return newHead;
    }
    return head;
}
int main(){
    vector <int> arr = {9,9,9,9};
    Node* head = convertArray2LL(arr);
    cout << "LL  : " << endl;
    traversal_LL(head);
    cout << "After Adding 1 To LL " << endl;
    head = callbrute(head);
    traversal_LL(head);
    return 0;
}
