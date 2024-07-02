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
Node* searchFor3Element(Node* firstHead){
    Node* temp = firstHead;
    while(temp){
        if(temp -> data == 3){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}
Node* callbrute(Node* firstHead , Node* secondHead){
    Node* ans = NULL;
    unordered_map<Node* , int> mapp;
    while(firstHead){
        mapp[firstHead] ++;
        firstHead = firstHead -> next;
    }
    while(secondHead){
        if(mapp.find(secondHead) != mapp.end()){
            ans = secondHead;
            break;
        }
        secondHead = secondHead -> next;
    }
    return ans;
}
Node* collisionPoint(Node* t1 , Node* t2 , int dist){
    while(dist--){
        t2 = t2 -> next;
    }
    while(t1 or t2){
        if(t1 == t2) return t1;
        else if(!t1) return NULL;
        else if(!t2) return NULL;
        t1 = t1 -> next;
        t2 = t2 -> next;
    }
    return NULL;
}
Node* callbetter(Node* firstHead , Node* secondHead){
    int n1 = 0 , n2 = 0;
    Node* t1 = firstHead , *t2 = secondHead;
    while(t1 or t2){
        if(t1) {
            n1++;
            t1 = t1 -> next;
        }
        if(t2){
            n2++;
            t2 = t2 -> next;
        }
    }
    if(n1 < n2){
        return collisionPoint(firstHead , secondHead , n2-n1);
    }
    else{
        return collisionPoint(secondHead , firstHead , n1-n2);
    }
}
Node* calloptimal(Node* firstHead , Node* secondHead){
    if(!firstHead or !secondHead) return NULL;
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    while(temp1 != temp2){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
        if(temp1 == temp2) return temp1;
        if(!temp1) temp1 = secondHead;
        if(!temp2) temp2 = firstHead;

    }
    return temp1;
}
int main(){
    vector <int> arr = {1,2,3,4,5,6};
    Node* firstHead = convertArray2LL(arr);
    Node* connect = searchFor3Element(firstHead);
    vector <int> arr1 = {1 ,2 };
    Node* secondHead = new Node(1 , NULL);
    Node* second = new Node(2 , connect);
    secondHead -> next = second;
    cout << "LL  : ";cout << endl;
    traversal_LL(firstHead);
    Node* ans = calloptimal(firstHead , secondHead);
    if(ans == connect){
        cout << "Common Node " << endl;
    }
    else{
        cout << "Their is no Common Node" << endl;
    }
    return 0;
}
