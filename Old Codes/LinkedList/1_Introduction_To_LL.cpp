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
int lengthOfLL(Node* head){
    int cnt = 0;
    while(head != NULL){
        head = head -> next;
        cnt++;
    }
    return cnt;
}
int checkIfPresent(int data , Node* head){
    while(head != NULL){
        if(head -> data == data) return 1;
        head = head -> next;
    }
    return 0;
}
int main(){
    vector <int> arr = {1 ,2, 3 , 4 , 5};
    Node* head = convertArray2LL(arr);
    traversal_LL(head) ;
    cout << "Length of the LL : " << (int)lengthOfLL(head) << endl;
    cout << checkIfPresent(6 , head) << endl;
    cout << endl;
    return 0;
}