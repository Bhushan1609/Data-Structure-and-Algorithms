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
Node* callbrute(Node* head ){
    Node* temp = head;
    stack <int> st;
    while(temp){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    Node* front = NULL;
    while(temp){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
//calling recursion for the reverse the LL
Node* callrecursion(Node* head){
    if(!head or !head -> next) return head;
    Node* newHead = callrecursion(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newHead;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Reversing LL : " << endl;
    // Node* head1 = callbrute(head);
    // Node* head1 = calloptimal(head);
    Node* head1 = callrecursion(head);
    traversal_LL(head1);
    return 0;
}
