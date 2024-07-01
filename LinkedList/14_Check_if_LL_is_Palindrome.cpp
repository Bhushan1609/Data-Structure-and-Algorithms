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
Node* reverse(Node* ptr) {
    Node* pre=NULL;
    Node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
bool callbrute(Node* head ){
    stack<int>st;
    Node* temp = head;
    while(temp){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp){
        if(temp -> data != st.top()){
            return 0;
        }
        temp = temp -> next;
        st.pop();
    }
    return 1;
}
bool calloptimal(Node* head){
    if(head==NULL||head->next==NULL) return true;
    Node* slow = head;
    Node* fast = head;   
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second) {
        if(first->data != second->data) {
            reverse(newHead);
            return false;
        }
        first = first -> next;
        second = second -> next;
    }
    reverse(newHead);
    return true;
}
int main(){
    vector <int> arr = {1,2,3,3,2,1};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Reversing LL : " << endl;
    if(calloptimal(head)) cout << "YES" << endl;
    else{
        cout << "NO" << endl;
    }
    return 0;
}