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

bool search_IN_BST(TreeNode<int>* root,int data){
    if(!root) return false;
    if(root->data==data)
        return true;
    return search_IN_BST(root->left,data) or search_IN_BST(root->right,data);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_BINARY_SEARCH_TREE();
    root->LEVEL_ORDER();
    cout<<"Data present or not : "<<search_IN_BST(root,1)<<endl;
    return 0;
}