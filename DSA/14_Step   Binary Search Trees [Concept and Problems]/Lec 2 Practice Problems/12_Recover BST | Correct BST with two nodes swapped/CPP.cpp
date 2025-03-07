#include<bits/stdc++.h>
using namespace std;

template<class T> 
class TreeNode{
public:
    T data;
    TreeNode *left , *right;
    TreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode(T data , TreeNode* left, TreeNode* right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
    void LEVEL_ORDER(){
        cout<<"Level Order : "<<endl;
        queue<TreeNode*>q;
        q.push(this);
        while(!q.empty()){
            int q_size=q.size();
            for(int i=0;i<q_size;i++){
                TreeNode* temp=q.front();q.pop();
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            cout<<endl;
        }
        return ;
    }
    TreeNode* CREATE_BINARY_SEARCH_TREE(){
        function<TreeNode*(TreeNode*,T)>recursion=[&](TreeNode* node,T data) -> TreeNode*{
            if(!node)
                return new TreeNode(data);
            if(data < node->data)
                node->left=recursion(node->left,data);
            else
                node->right=recursion(node->right,data);
            return node;
        };
        TreeNode* root=this;
        while(1){
            T data;
            cout<<"Enter data to Add to BST : "<<endl;cin>>data;
            if(data != 0){
                root=recursion(root,data);
            }else{
                break;
            }
        }
        return root;
    }
};

class BSTIterator {
    stack<TreeNode<int>*>st;
    bool reverseORnot;
public:
    BSTIterator(TreeNode<int>* root,bool reverseORnot){
        this->reverseORnot=reverseORnot;
        pushAll(root);
    }
    
    int next() {
        TreeNode<int>* node=st.top();
        st.pop();
        if(reverseORnot==false)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode<int>* root){
        while(root){
            st.push(root);
            if(reverseORnot==false)
                root=root->left;
            else
                root=root->right;
        }
        return ;
    }
};

void recoverTree(TreeNode* root) {
    TreeNode<int> *first,*middle,*last,*prev;
    first=middle=last=prev=NULL;
    function<void(TreeNode<int>*)>inorder=[&](TreeNode<int>* root) -> void {
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    };
    inorder(root);
    if(first && last)
        swap(first->val,last->val);
    else
        swap(first->val,middle->val);
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_BINARY_SEARCH_TREE();
    root->LEVEL_ORDER();
    // recoverTree(root); Basically in the tree 2 node are swapped ALWAYS
    return 0;

}