#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* back;
    Node* next;
    public:
    Node(int data1 , Node* back1 , Node* next1){
        data = data1;
        back = back1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        back = NULL;
        next = NULL;
    }
};
pair<Node*,Node*> convertArray2DLL(vector <int> vec){
    Node* head = new Node(vec[0]);
    Node* tail = NULL;
    Node* mover = head;
    for (int i = 1 ; i < vec.size() ; i++){
        Node* temp = new Node(vec[i],mover,NULL);
        mover -> next = temp;
        mover = temp;
        tail = mover;
    }
    return {head , tail};
}
void printDLLfromlefttoright(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl; 
    return ;
}
void printDLLfromrighttoleft(Node* tail){
    while(tail != NULL){
        cout << tail -> data << " ";
        tail = tail -> back;
    }
    cout << endl;
    return ;
}
Node* insertBeforeHead(Node* head , int data){
    Node* newNode = new Node(data , NULL , head);
    head -> back = newNode;
    return newNode;
}
Node* insertBeforeTail(Node* head , int data){
    if(head -> next == NULL){
        Node* newNode = new Node(data);
        head -> next = newNode;
        newNode -> back = head;
        return head;
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next; 
    }
    Node* newNode = new Node(data , temp->back , temp);
    temp->back -> next = newNode;
    temp -> back = newNode;
    return head;
} 
Node* insertBeforeKthElement(Node* head , int k , int data){
    if(k == 1){
        Node* newNode = new Node(data , NULL , head);
        head -> back = newNode;
        return newNode;
    }
    Node* temp = head ;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(data ,prev , temp);
    prev -> next = newNode;
    temp -> back  = newNode;
    return head;
}
void insertBeforeNode(Node* node , int data){
    Node* prev = node -> back;
    Node* newNode = new Node(data , prev , node);
    prev -> next = newNode;
    node -> back = newNode; 
    return ;
}
int main(){
    vector <int> vec = {1 , 2  , 3  , 4 , 5};
    Node* head = convertArray2DLL(vec).first;
    Node* tail = convertArray2DLL(vec).second;
    cout << endl;
    cout << "Priting The Doubly Linked List From Head to Tail : " << endl;
    printDLLfromlefttoright(head);
    cout << endl;
    // cout << "Priting The Doubly Linked List From Tail to Head : " << endl;
    // printDLLfromrighttoleft(tail);
    // cout << "Doubly Linked List After New Head Inserted " << endl;
    // head = insertBeforeHead(head , -1);
    // printDLLfromlefttoright(head);
    // cout << "Doubly Linked List After New Tail Inserted " << endl;
    // head = insertBeforeTail(head , -1);
    // printDLLfromlefttoright(head);
    // int k = 0;cout << "Enter Position where Element Want To Insert : " ; cin >> k;
    // cout << "Doubly Linked List After Element Inserted at " << k << "th Position " << endl;
    // head = insertAtK(head , -1, k);
    // printDLLfromlefttoright(head);
    // cout << "Doubly Linked List before Inserted At kth Element" << endl;
    // head = insertBeforeKthElement(head ,3, -1);
    // printDLLfromlefttoright (head);
    // cout << "Doubly Linked List Before Inserted At the Given Node " << endl;
    // insertBeforeNode(head->next->next->next->next ,-1);
    // printDLLfromlefttoright (head);
    return 0;
}