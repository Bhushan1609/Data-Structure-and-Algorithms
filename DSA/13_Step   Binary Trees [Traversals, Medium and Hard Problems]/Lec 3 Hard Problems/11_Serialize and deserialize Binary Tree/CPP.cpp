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

string serialize(TreeNode<int>* root) {
    if(!root) return "";
    string levelWise;
    queue<TreeNode<int>*>q;
    q.push(root);
    levelWise.append(to_string(root->data)+',');
    while(!q.empty()){
        int q_size=q.size();
        for(int i=0;i<q_size;i++){
            TreeNode<int>* temp=q.front();q.pop();
            if(temp->left){
                q.push(temp->left);
                levelWise.append(to_string(temp->left->data)+',');
            }else{
                levelWise.append("@,");
            }

            if(temp->right){
                q.push(temp->right);
                levelWise.append(to_string(temp->right->data)+',');
            }else{
                levelWise.append("@,");
            }
        }
    }
    return levelWise;
}

TreeNode<int>* deserialize(string data) {
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode<int>* root=new TreeNode(stoi(str));
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();q.pop();
        getline(s,str,',');
        if(str=="@")
            temp->left=NULL;
        else{
            temp->left=new TreeNode(stoi(str));
            q.push(temp->left);
        }
        getline(s,str,',');
        if(str=="@")
            temp->right=NULL;
        else{
            temp->right=new TreeNode(stoi(str));
            q.push(temp->right);
        }
    }
    return root;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    TreeNode<int>*root=NULL;
    root=root->CREATE_ITERATIVE();
    root->LEVEL_ORDER();
    cout<<endl;
    string data=serialize(root);
    TreeNode<int>*root1=deserialize(data);
    root1->LEVEL_ORDER();
    return 0;
}