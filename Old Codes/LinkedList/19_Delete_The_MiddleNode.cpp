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
Node* callbrute(Node* head){
    if(!head -> next or !head) {
        return NULL;
    }
    int cnt = 0 ;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp -> next;
    }
    cnt = (cnt/2);
    temp = head;
    while(temp){
        cnt--;
        if(cnt == 0){
            Node* middle = temp -> next;
            temp -> next  = temp -> next -> next;
            free(middle);
            break;
        }
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head){
    if(!head or !head -> next){
        return NULL;
    }
    Node* slow = head , *fast = head -> next -> next;
    while(!fast and !fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    Node* middle = slow -> next;
    slow -> next = slow -> next -> next;
    free(middle);
    return head;
}
int main(){
    vector <int> arr = {1,2,3,4,5};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    head = calloptimal(head);
    cout << "After Removing The Middle Element of the LL " << endl;
    traversal_LL(head);
    cout << endl;
    return 0;
}
