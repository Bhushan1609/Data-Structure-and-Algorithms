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

int giveMin(TreeNode<int>* root){
    int minEle=root->data;
    while(root){
        minEle=min(minEle,root->data);
        root=root->left;
    }
    return minEle;
}

TreeNode<int>* deleteNode(TreeNode<int>* root, int key) {
    if(!root) return NULL;
    if(root->data == key){
        if(!root->left && !root->right){
            root=NULL;
        }else if(!root->left && root->right){
            TreeNode<int>* dummy=root->right;
            root->right=NULL;
            root=dummy;
        }else if(root->left && !root->right){
            TreeNode<int>* dummy=root->left;
            root->left=NULL;
            root=dummy;
        }else{
            int findMin=giveMin(root->right);
            root->right=deleteNode(root->right,findMin);
            root->data=findMin;
        }
        return root;
    }
    root->left=deleteNode(root->left,key);
    root->right=deleteNode(root->right,key);
    return root;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_BINARY_SEARCH_TREE();
    root->LEVEL_ORDER();
    root=deleteNode(root,1);
    root->LEVEL_ORDER();
    return 0;
}