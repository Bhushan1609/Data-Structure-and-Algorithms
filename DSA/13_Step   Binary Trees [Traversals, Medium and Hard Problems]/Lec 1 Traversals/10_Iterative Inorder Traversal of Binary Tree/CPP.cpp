#include<bits/stdc++.h>
using namespace std;

template<class T>
class TreeNode{
public:
    T data;
    TreeNode *left, *right;

    TreeNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    TreeNode(T data,TreeNode* left,TreeNode* right){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    void LEVEL_ORDER(){
        cout<<"Level-Order Traversal : "<<endl;

        TreeNode* root=this;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* temp=q.front();q.pop();
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }cout<<endl;
        }
        return ;
    }

    static TreeNode* CREATE_ITERATIVE(){
        TreeNode* root=NULL;
        T rootdata;
        cout<<"Enter data for the root : "<<endl;cin>>rootdata;
        root=new TreeNode(rootdata);
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* temp=q.front();q.pop();
                T leftrootdata,rightrootdata;
                cout<<"Enter left and right data for the "<<temp->data<<" : "<<endl;cin>>leftrootdata>>rightrootdata;
                if(leftrootdata!=0){
                    temp->left=new TreeNode(leftrootdata);
                    q.push(temp->left);
                }
                if(rightrootdata){
                    temp->right=new TreeNode(rightrootdata);
                    q.push(temp->right);
                }
            }
        }
        return root;
    }

    static TreeNode* CREATE_RECURSION(){
        function<TreeNode*(TreeNode*)>recursion=[&](TreeNode* root){
            if(!root){
                cout<<"Enter data for root : "<<endl;
                T rootdata;cin>>rootdata;
                if(rootdata==0)
                    return root;
                root=new TreeNode(rootdata);
            }
            cout<<"Enter data for the left of the "<<root->data<<" : "<<endl;
            root->left=recursion(root->left);
            cout<<"Enter data for the right of the "<<root->data<<" : "<<endl;
            root->right=recursion(root->right);
            return root;
        };
        TreeNode* root=NULL;
        return recursion(root);
    }
};

void iterative_inorder(TreeNode<int>*root){
    cout<<"Iterative Inorder Traversal : ";
    stack<TreeNode<int>*>st;
    TreeNode<int>*curr=root;
    while(!st.empty() or curr){
        if(curr){
            st.push(curr);
            curr=curr->left;
        }
        else{
            curr=st.top();st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=TreeNode<int>::CREATE_ITERATIVE();
    // TreeNode<int>*root=TreeNode<int>::CREATE_RECURSION();
    root->LEVEL_ORDER();
    iterative_inorder(root);
    return 0;
}
// Input for iterative creation 1 2 3 4 5 6 7 0 0 0 0 0 0 0 0 
// Input for recursive creation 1 2 4 0 0 5 0 0 3 6 0 0 7 0 0