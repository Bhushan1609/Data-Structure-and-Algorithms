#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};
void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return ;
}
Node* convertArraytoLL(vector <int>& vec){
    Node* head = new Node(vec[0]);
    Node* mover = head;
    for (int i = 1 ; i < vec.size() ; i++){
        Node* temp = new Node(vec[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;      
}
Node* insertAtHead(Node* head , int val){
    return new Node(val , head);
}
Node* insertAtRTail(Node* head , int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp -> next  != NULL){
        temp = temp -> next;
    }
    temp -> next = new Node(val);
    return head;
}
Node* insertAtK(Node* head , int el , int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else return NULL;
    }
    if(k == 1){
        return new Node(el , head);
    }
    int cnt = 0; 
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            Node* newNode = new Node(el , temp->next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    if(k > cnt) cout << "K is Not valid!!" << endl;
    return head;
}
Node* insertBeforeValue(Node* head , int el , int val){
    if(head == NULL) return head;
    if(head -> data == val){
        return new Node(el , head);
    }
    Node* temp = head;
    while(temp -> next != NULL){
        if(temp -> next -> data == val){
            Node* newNode = new Node(el , temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head; 
}
int main(){
    vector <int> vec = {1,2,3,4,5};
    Node* head = convertArraytoLL(vec);
    cout << "Intial Liniked List " << endl;
    printLinkedList(head);
    // cout << "Linked List After New Head Inserted " << endl;
    // head = insertAtHead(head , -1);
    // printLinkedList(head);
    // cout << "Linked List After New Tail Inserted " << endl;
    // head = insertAtRTail(head , -1);
    // printLinkedList(head);
    // int k = 0;cout << "Enter Position where Ele ment Want To Insert : " ; cin >> k;
    // cout << "Linked List After Element Inserted at " << k << "th Position " << endl;
    // head = insertAtK(head , -1, k);
    // printLinkedList(head);
    int k = 0;cout << "Enter too Insert Before That Element in LL : " ; cin >> k;
    cout << "Linked List After  Inserted " << endl;
    head = insertBeforeValue(head , -1, k);
    printLinkedList(head);
    return 0;
}