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
    if(!head or !(head -> next)) return head;
    int cnt0 = 0 , cnt1 = 0 ,  cnt2 = 0;
    Node* temp = head;
    while(temp){
        if(temp -> data == 0) cnt0++;
        else if(temp -> data == 1) cnt1++;
        else cnt2++;
        temp = temp -> next;
    }
    temp = head;
    while(cnt0--){
        temp -> data = 0;
        temp = temp -> next;
    }
    while(cnt1--){
        temp -> data = 1;
        temp = temp -> next;
    }
    while(cnt2--){
        temp -> data = 2;
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head){
    if(!head or !(head -> next)) return head;
    Node* zeroHead = new Node(-1);
    Node* zero = zeroHead;
    Node* oneHead = new Node(-1);
    Node* one = oneHead;
    Node* twoHead = new Node(-1);
    Node* two = twoHead;
    Node* temp = head;
    while(temp){
        if(temp -> data == 0){
            zeroHead -> next = new Node(0);
            zeroHead = zeroHead -> next;
        }
        else if(temp -> data == 1){
            oneHead -> next = new Node(1);
            oneHead = oneHead -> next;
        }
        else{
            twoHead -> next = new Node(2);
            twoHead = twoHead -> next;
        }
        temp = temp -> next;
    }
    zeroHead->next  = (one->next) ? one -> next : two->next;
    oneHead -> next = two -> next;
    return zero -> next;
}
int main(){
    vector <int> arr = {1 ,0, 1 , 2 ,0, 2, 1};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Sorting  LL : " << endl;
    // Node* head1 = callbrute(head);
    Node* head1 = calloptimal(head);
    traversal_LL(head1);
    return 0;
}
