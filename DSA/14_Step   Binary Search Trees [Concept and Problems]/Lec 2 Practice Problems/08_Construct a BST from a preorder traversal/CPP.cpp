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

TreeNode<int>* makeTree(vector<int>&inorder,vector<int>&preorder){
    unordered_map<int,int>mapp;
    for(int i=0;i<inorder.size();i++)
        mapp[inorder[i]]=i;
    function<TreeNode<int>*(int,int,int,int)>recursion=[&](int ps,int pe,int is,int ie) -> TreeNode<int>* {
        if(is>ie or ps>pe) return NULL;
        TreeNode<int>* root=new TreeNode(preorder[ps]);
        int index=mapp[ preorder[ps] ];
        root->left=recursion(ps+1,ps+index-is,is,index-1);
        root->right=recursion(ps+1+index-is,pe,index+1,ie);
        return root;
    };
    return recursion(0,preorder.size()-1,0,inorder.size()-1);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<int>preorder={8,5,1,7,10,12};
    vector<int>inorder=preorder;
    sort(inorder.begin() , inorder.end());
    TreeNode<int>*root=makeTree(inorder,preorder);
    root->LEVEL_ORDER();
    return 0;
}