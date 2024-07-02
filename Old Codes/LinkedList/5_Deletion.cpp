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
Node* DeletionOfHead(Node* head){
    if(head == NULL or head -> next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head -> next;
    head -> back = NULL;
    temp -> next = NULL;
    delete temp; 
    return head;
}
Node* DeletionOfTail(Node* head){
    if(head == NULL or head -> next == NULL){
        return NULL;
    }
    Node* temp = head ;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    Node* tail = temp -> next;
    temp -> next = NULL;
    tail -> back = NULL;
    delete tail;
    return head; 
}
Node* DeletionAtKth(Node* head , int k){
    if(head == NULL ){
        return NULL;
    }
    Node* temp = head;
    int cnt = 0   ;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* front = temp -> next;
    //Only one Node 
    if(prev == front and prev == NULL){
        delete temp;
        return NULL;
    }
    //Head Node
    else if(prev == NULL){
        head = head -> next;
        head -> back = NULL;
        temp -> next = NULL;
        delete temp; 
        return head; 
    }
    //Tail Node
    else if(front == NULL){
        prev -> next = NULL;
        temp -> back = NULL;
        delete temp;
        return head;
    } 
    // Middle Element 
    else{
        prev -> next = front;
        front -> back = prev;
        temp -> back = NULL;
        temp -> next = NULL;
        delete temp;
        return head;
    }
    return head;
}
void DeletionOfNode(Node* temp){
    Node* prev = temp -> back;
    Node* front = temp -> next;
    if(front == NULL){
        prev -> next = NULL;
        temp -> back = NULL;
        free(temp);
        return ;
    }
    prev -> next = front;
    front -> back = prev;
    temp -> back = temp -> next = NULL;
    free(temp);
    return ;
}
int main(){ 
    vector <int> vec = {1 , 2 , 3  , 4 , 5};
    Node* head = convertArray2DLL(vec).first;
    Node* tail = convertArray2DLL(vec).second;
    cout << endl;
    cout << "Priting The Doubly Linked List From Head to Tail : " << endl;
    printDLLfromlefttoright(head);
    cout << endl;
    // cout << "Priting The Doubly Linked List From Tail to Head : " << endl;
    // printDLLfromrighttoleft(tail);
    // cout << "After Deletion of the Head Node in the DLL " << endl;
    // head = DeletionOfHead(head);
    // printDLLfromlefttoright(head);
    // cout << "After Deletion of the Tail Node in the DLL " << endl;
    // head = DeletionOfTail(head);
    // printDLLfromlefttoright(head);
    // cout << "After Deletion of the Kth Node in the DLL " << endl;
    // head = DeletionAtKth(head , 5);
    // printDLLfromlefttoright(head);
    cout << "After Deletion of the  Node in the DLL " << endl;
    DeletionOfNode(head->next);
    printDLLfromlefttoright(head);
    return 0;
}