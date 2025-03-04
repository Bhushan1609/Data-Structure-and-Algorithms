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
    TreeNode* CREATE_ITERATIVE(){
        TreeNode* root=this;
        if(!root){
            cout<<"Enter data for root "<<endl;
            T rootNode;cin>>rootNode;
            root=new TreeNode(rootNode);
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int q_size=q.size();
            for(int i=0;i<q_size;i++){
                TreeNode* temp=q.front();q.pop();
                cout<<"Enter data for left & right node of the "<<temp->data<<endl;
                T leftNode,rightNode;
                cin>>leftNode>>rightNode;
                if(leftNode){
                    temp->left=new TreeNode(leftNode);
                    q.push(temp->left);
                }
                if(rightNode){
                    temp->right=new TreeNode(rightNode);
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
    TreeNode* CREATE_RECURSIVE(){
        function<TreeNode*(TreeNode*)>recursion=[&](TreeNode* root){
            if(!root){
                cout<<"Enter data for root "<<endl;    
                T rootNode;cin>>rootNode;
                if(!rootNode)
                    return root;
                root=new TreeNode(rootNode);
            }
            cout<<"Enter data for left node of the "<<root->data<<endl;
            root->left=recursion(root->left);
            cout<<"Enter data for right node of the "<<root->data<<endl;
            root->right=recursion(root->right);
            return root;
        };
        return recursion(this);
    }
};

void single_Traversal(TreeNode<int>* root){
    if(!root)return;
    stack<pair<TreeNode<int>*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    while(!st.empty() ){
        pair<TreeNode<int>*,int>temp=st.top();
        st.pop();
        if(temp.second==1){
            pre.push_back(temp.first->data);
            st.push({temp.first,temp.second+1});
            if(temp.first->left)
                st.push({temp.first->left,1});
        }

        if(temp.second==2){
            in.push_back(temp.first->data);
            st.push({temp.first,temp.second+1});
            if(temp.first->right)
                st.push({temp.first->right,1});
        }

        if(temp.second==3)
            post.push_back(temp.first->data);
        
    }
    for(auto &i:pre)
        cout<<i<<" ";
    cout<<endl;
    for(auto &i:in)
        cout<<i<<" ";
    cout<<endl;
    for(auto &i:post)
        cout<<i<<" ";
    cout<<endl;
    return ;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_ITERATIVE();
    single_Traversal(root);
    return 0;
}