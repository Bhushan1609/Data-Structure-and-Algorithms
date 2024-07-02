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
//TC : O(2N)
//SC : O(N)
Node* callbrute(Node* head){
    stack <int> st;
    Node* temp = head ;
    while(temp != NULL){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        temp -> data = st.top();
        st.pop();
        temp = temp -> next;
    }
    return head;
}
//TC : O(N)
//SC : O(1)
Node* calloptimal(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* last = temp -> back;
        temp -> back = temp -> next;
        temp -> next = last;
        head = temp;
        temp = temp -> back;
    }
    return head;
}
int main(){
    vector <int> vec = {1 , 2 , 3  , 4 , 5};
    Node* head = convertArray2DLL(vec).first;
    // head = callbrute(head);
    head = calloptimal(head);
    printDLLfromlefttoright(head);
    return 0;
}