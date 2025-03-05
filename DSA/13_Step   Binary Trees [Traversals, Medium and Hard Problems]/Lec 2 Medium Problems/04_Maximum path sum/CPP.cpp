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

int heightSum(TreeNode<int>* root,int &sum){
    if(!root) return 0;
    int leftSum=max(0,heightSum(root->left,sum));
    int rightSum=max(0,heightSum(root->right,sum));
    sum=max(sum,leftSum+rightSum+root->data);
    return max(leftSum,rightSum)+root->data;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_ITERATIVE();
    int sum=-1609;
    heightSum(root,sum);
    cout<<"Maximum PathSum of the tree is : "<<sum<<endl;
    return 0;
}