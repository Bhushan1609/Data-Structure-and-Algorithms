const cin=require("prompt-sync")();
class Node{
    constructor(data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}
function levelOrder(root){
    const q=[];
    q.push(root);
    while(q.length){
        let n=q.length;
        for(let i=0;i<n;i++){
            const temp=q.shift();
            process.stdout.write(temp.data+" ");
            if(temp.left)q.push(temp.left);
            if(temp.right)q.push(temp.right);
        }
        console.log();
    }
}
function nonRecursiveTreeCreation(){
    console.log("Enter Data for Root : ");
    let data=parseInt(cin());
    let root=new Node(data);
    const q = [];
    q.push(root);
    while (q.length) {
        const temp = q.shift();
        process.stdout.write(`Enter the data for the left child of ${temp.data}  `);
        data=parseInt(cin());
        if(data){
            temp.left=new Node(data);
            q.push(temp.left);
        }
        process.stdout.write(`Enter the data for the right child of ${temp.data}  `);
        data=parseInt(cin());
        if(data){
            temp.right=new Node(data);
            q.push(temp.right);
        }
    }
    return root;
}
function RecursiveTreeCreation(root){
    if(!root){
        let data=parseInt(cin());
        if(!data)return null;
        root=new Node(data);
    }
    process.stdout.write("Enter the data for the left children of "+root.data+" ");
    root.left=RecursiveTreeCreation(root.left);
    process.stdout.write("Enter the data for the right children of "+root.data+" ");
    root.right=RecursiveTreeCreation(root.right);
    return root;
}
function isLeaf(root) {
    return ( (root.left==null) && (root.right==null) );
}
function addLeft(root,ans){
    if(root==null)return;
    while(root!=null){
        if(isLeaf(root)==false)ans.push(root.data);
        if(root.left!=null)root=root.left;
        else root=root.right;
    }
}
function addLeaf(root,ans){
    if(root==null)return;
    if(isLeaf(root)==true)ans.push(root.data);
    addLeaf(root.left,ans);
    addLeaf(root.right,ans);
}
function addRight(root,ans){
    if(root==null)return;
    let ans2=[];
    while(root!=null){
        if(isLeaf(root)==false)ans2.push(root.data);
        if(root.right!=null)root=root.right;
        else root=root.left;
    }
    for(let i=ans2.length-1;i>=0;i--)ans.push(ans2[i]);
    return ;
}
function boundaryTraversal(root) {
    let ans=[];
    if(isLeaf(root)==false)ans.push(root.data);
    let curr1,curr2,curr3;
    curr1=curr2=curr3=root;
    addLeft(curr2.left,ans);
    addLeaf(root,ans);
    addRight(curr3.right,ans);
    console.log(ans);
  }
// let root=nonRecursiveTreeCreation();
// levelOrder(root);

console.log("Enter Data for the Root : ");
let root=null;
root=RecursiveTreeCreation(root);
// levelOrder(root);
boundaryTraversal(root);
