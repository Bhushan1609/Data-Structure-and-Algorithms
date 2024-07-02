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
Node* rotateLL(Node* head, int k){
    if(k == 0) return head;
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp -> next;
    }
    k %= cnt;
    if(k == 0) return head;
    cnt -= k;
    temp = head;
    Node* newHead = head;
    while(temp){
        cnt--;
        if(cnt==0){
            newHead = temp -> next;
            temp -> next = NULL;
            Node* temp2 = newHead;
            while(temp2 -> next){
                temp2 = temp2 -> next;
            }
            temp2 -> next = head;
            break;
        }
        temp = temp -> next;
    }
    return newHead;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Rotating LL by k : " << endl;
    head = rotateLL(head , 3);
    traversal_LL(head);
    return 0;
}
