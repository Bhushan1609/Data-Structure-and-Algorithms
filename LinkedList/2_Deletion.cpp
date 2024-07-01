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
Node* convertArraytoLL(vector <int> vec){
    Node* head = new Node(vec[0] , NULL);
    Node* mover = head;
    for (int i =  1 ; i < vec.size() ; i++){
        Node* temp = new Node(vec[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}
void printLinkedList(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
    return ;
}
// Removing Head From Linked List
Node* removeHead(Node* head){
    if(head == NULL) return head; 
    Node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}
// Removing Tail From Linked List
Node* removeTail(Node* head){
    if(head == NULL or head -> next == NULL) return NULL; 
    Node* temp = head;
    while( (temp ->next ) -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
    return head;
}
// Removing Kth Postions Element in the Linked List
Node* removekth(Node* head , int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            free(temp);
            prev -> next = (prev->next)->next; 
            break;
        }
        prev = temp; 
        temp = temp -> next; 
    }
    return head; 
}
// Removing Value Element in the Linked List
Node* removeEl(Node* head , int el){
    if(head == NULL) return NULL;
    if(head -> data == el){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == el){
            free(temp);
            prev -> next = (prev->next)->next; 
            break;
        }
        prev = temp; 
        temp = temp -> next; 
    }
    return head; 
}
int main (){
    vector <int> vec = {1 , 2 , 3 , 4 ,5 };
    Node* head = convertArraytoLL(vec);
    cout << "Intial Linked List" << endl;
    printLinkedList(head);
    // head = removeHead(head);
    // cout << "After Deleting Head Node Linked List" << endl;
    // printLinkedList(head);
    // head = removeTail(head);
    // cout << "After Deleting Tail Node Linked List" << endl;
    // printLinkedList(head);
    // int k = 0;cout << "Enter Kth Position Too Delete " << endl;cin >> k; 
    // head = removekth(head , k);
    // cout << "After Deleting " << k << "th Node Linked List" << endl;
    // printLinkedList(head);
    int k = 0;cout << "Enter Value Too Delete " << endl;cin >> k; 
    head = removeEl(head , k);
    cout << "After Deleting " << k << " Node Linked List" << endl;
    printLinkedList(head);
    return 0;
}