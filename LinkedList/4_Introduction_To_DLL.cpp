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
int main(){
    vector <int> vec = {1 , 2 , 3  , 4 , 5};
    Node* head = convertArray2DLL(vec).first;
    Node* tail = convertArray2DLL(vec).second;
    cout << endl;
    cout << "Priting The Doubly Linked List From Head to Tail : " << endl;
    printDLLfromlefttoright(head);
    cout << endl;
    cout << "Priting The Doubly Linked List From Tail to Head : " << endl;
    printDLLfromrighttoleft(tail);
    return 0;
}