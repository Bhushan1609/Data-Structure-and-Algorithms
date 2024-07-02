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
Node* removeDuplicate(Node* head){
    Node* temp = head;
    while(temp and temp -> next){
        Node* nextNode = temp -> next;
        while(nextNode and nextNode -> data == temp -> data){
            Node* duplicates = nextNode;
            nextNode = nextNode -> next;
            free(duplicates);
        }
        temp -> next = nextNode;
        if(nextNode) nextNode -> prev = temp;
        temp = temp -> next;
    }
    return head;
}
int main(){
    vector <int> arr = {1,1,1,2,3,3,4};
    Node* head = convertArray2DLL(arr);
    cout << "DLL  : ";cout << endl;
    traversal_DLL(head);
    cout << "After Removing Duplicates :" << endl;
    head = removeDuplicate(head);
    traversal_DLL(head);
    return 0;
}
