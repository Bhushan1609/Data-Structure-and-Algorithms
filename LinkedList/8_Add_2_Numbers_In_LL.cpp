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
Node *addTwoNumbers(Node *num1, Node *num2)
{
    int carry = 0 , sum = 0;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    while(num1 != NULL or num2 != NULL){
        sum = carry;
        if(num1 != NULL){
            sum += num1 -> data ;
            num1 = num1 -> next;
        }
        if(num2 != NULL){
            sum += num2 -> data;
            num2 = num2 -> next;
        }
        Node* temp = new Node(sum%10);
        current -> next = temp;
        current = current -> next;
        carry = sum/10;
    }
    if(carry){
        current -> next = new Node(carry%10);
        return dummyNode -> next;
    }
    current -> next = NULL;
    return dummyNode -> next;
}
int main(){
    vector <int> arr1 = {1 ,2, 3 , 4 , 5};
    vector <int> arr2 = {5 , 4 , 3 , 2 ,1};
    Node* head1 = convertArray2LL(arr1);
    Node* head2 = convertArray2LL(arr2);
    cout << "Two LL Are : ";cout << endl;
    traversal_LL(head1);
    traversal_LL(head2);
    cout << "After Added Two LL : " << endl;
    Node* head = addTwoNumbers(head1 , head2);
    traversal_LL(head);
    cout << endl;
    return 0;
}