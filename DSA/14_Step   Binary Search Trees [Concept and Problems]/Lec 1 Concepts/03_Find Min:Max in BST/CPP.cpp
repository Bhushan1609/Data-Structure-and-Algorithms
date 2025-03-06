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

pair<int,int> min_max(TreeNode<int>* root){
    queue<TreeNode<int>*>q1,q2;
    q1.push(root);
    q2.push(root);
    int minEle=root->data,maxEle=root->data;
    while(!q1.empty()){
        TreeNode<int>* temp=q1.front();q1.pop();
        minEle=min(minEle,temp->data);
        if(temp->left)
            q1.push(temp->left);
    }
    while(!q2.empty()){
        TreeNode<int>* temp=q2.front();q2.pop();
        maxEle=max(maxEle,temp->data);
        if(temp->right)
            q2.push(temp->right);
    }
    return {minEle,maxEle};

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_BINARY_SEARCH_TREE();
    root->LEVEL_ORDER();
    pair<int,int>ans=min_max(root);
    cout<<"Minimum & Maximum in BST are : "<<ans.first<<" "<<ans.second<<endl;
    return 0;
}