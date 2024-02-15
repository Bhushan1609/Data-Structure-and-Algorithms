#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data ;
    Node* next ;
    Node* prev ;
    Node(int data1 , Node* prev1 , Node* next1){
        data = data1;
        next = prev1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        prev = NULL;
        next = NULL;
    }
};
Node* convertArray2DLL(vector <int>& arr ){
    int n = arr.size();
    Node* head = new Node(arr[0] , NULL , NULL);
    Node* mover = head;
    for (int i = 1; i < n ; i++){
        Node* temp = new Node(arr[i] , NULL ,NULL);
        mover->next = temp;
        temp -> prev = mover;
        mover = temp;
    }
    return head;
}
void traversal_DLL(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return ;
}
Node* deleteKey(Node* head , int key){
    Node* temp = head;
    while(temp){
        if((temp -> data) == key){
            if(temp == head){
                head = temp -> next;
            }
            Node* nextNode = temp -> next;
            Node* prevNode = temp -> prev;
            if(nextNode){
                nextNode -> prev = prevNode;
            }
            if(prevNode){
                prevNode -> next = nextNode;
            }
            free(temp);
            temp = nextNode;
        }
        else temp = temp -> next;
    }
    return head;
}
int main(){
    vector <int> arr = {10,4,10,10,6,10};
    Node* head = convertArray2DLL(arr);
    cout << "DLL  : ";cout << endl;
    traversal_DLL(head);
    cout << "After Deleting all Occurences Of Key(10) DLL : " << endl;
    head = deleteKey(head , 10);
    traversal_DLL(head);
    return 0;
}