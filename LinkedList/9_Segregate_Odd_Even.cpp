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
Node* callbrute(Node* head){
    vector <int> vec;
    Node* temp = head;
    while(temp != NULL and temp -> next != NULL){
        vec.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp){
        vec.push_back(temp -> data);
    }
    temp = head -> next;
    while(temp != NULL and temp -> next != NULL){
        vec.push_back(temp -> data);
        temp = temp -> next -> next;
    }
    if(temp){
        vec.push_back(temp -> data);
    }
    temp = head;
    int i = 0;
    while(temp != NULL){
        temp -> data = vec[i];
        i++;
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head){
    Node* odd = head ;
    Node* even = head -> next;
    Node* memoiz = head -> next;
    while(even != NULL and even -> next != NULL){
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;
        odd = odd -> next;
        even = even -> next;
    }
    odd -> next = memoiz;
    return head;
}
int main(){
    vector <int> arr = {1 ,2, 3 , 4 , 5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Segregated  LL : " << endl;
    // Node* head1 = callbrute(head);
    Node* head1 = calloptimal(head);
    traversal_LL(head1);
    cout << endl;
    return 0;
}