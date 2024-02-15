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
Node* callbrute(Node* head , int K){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp -> next;
    }
    if(cnt == K){
        return head -> next;
    }
    int ans = cnt - K;
    temp = head;
    cnt = 0;
    while(temp){
        ans--;
        if(ans==0){
            Node* del = temp -> next;
            temp -> next = temp -> next -> next;
            free(del);
            break;
        }
        temp = temp -> next;
    }
    return head;
}
Node* calloptimal(Node* head , int k){
    Node* fast = head ;
    Node* slow = head;
    for (int i = 0 ; i < k ; i++) fast = fast -> next;
    if(!fast) return head -> next;
    while(fast -> next){
        fast = fast -> next;
        slow = slow -> next;
    }
    Node* del = slow -> next;
    slow -> next = slow -> next -> next;
    free(del);
    return head;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* head = convertArray2LL(arr);
    cout << "LL  : ";cout << endl;
    traversal_LL(head);
    cout << "After Removing Kth Node in LL : " << endl;
    // Node* head1 = callbrute(head , 6);
    Node* head1 = calloptimal(head , 1);
    traversal_LL(head1);
    return 0;
}
