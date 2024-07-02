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
function preorder(root,v){
    if(root==null)return;
    v.push(root.data);
    preorder(root.left,v);
    preorder(root.right,v);
}
function inorder(root,v){
    if(root==null)return;
    inorder(root.left,v);
    v.push(root.data);
    inorder(root.right,v);
}
function postorder(root,v){
    if(root==null)return;
    postorder(root.left,v);
    postorder(root.right,v);
    v.push(root.data);
}
function iterativePreorder(root) {
    if (!root) return;

    const stack = [];
    stack.push(root);

    while (stack.length > 0) {
        const node = stack.pop();
        process.stdout.write(node.data + " ");

        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
    }
    console.log();
}
function iterativeInorder(root) {
    const stack = [];
    let curr = root;
    while (stack.length > 0 || curr) {
        if (curr) {
            stack.push(curr);
            curr = curr.left;
        } else {
            curr = stack.pop();
            process.stdout.write(curr.data + " ");
            curr = curr.right;
        }
    }
    console.log();
}

function iterativePostorder(root) {
    if (!root) return;
    const stack1 = [];
    const stack2 = [];
    stack1.push(root);

    while (stack1.length > 0) {
        const node = stack1.pop();
        stack2.push(node.data);

        if (node.left) stack1.push(node.left);
        if (node.right) stack1.push(node.right);
    }

    while (stack2.length > 0) {
        process.stdout.write(stack2.pop() + " ");
    }
    console.log();
}
function iterativePostorderUsingOneStack(root) {
    const stack = [];
    let curr = root;

    while (curr !== null || stack.length > 0) {
        if (curr !== null) {
            stack.push(curr);
            curr = curr.left;
        } 
        else {
            let temp = stack[stack.length - 1].right;
            if (temp === null) {
                temp = stack.pop();
                console.log(temp.data);
                while (stack.length > 0 && temp === stack[stack.length - 1].right) {
                    temp = stack.pop();
                    console.log(temp.data);
                }
            } 
            else {
                curr = temp;
            }
        }
    }
}
let root=nonRecursiveTreeCreation();
levelOrder(root);

// console.log("Enter Data for the Root : ");
// let root=null;
// root=RecursiveTreeCreation(root);
// levelOrder(root);

let v1=[];
let v2=[];
let v3=[];
preorder(root,v1);
console.log(v1);
inorder(root,v2);
console.log(v2);
postorder(root,v3);
console.log(v3);
iterativePreorder(root);
iterativeInorder(root);
iterativePostorder(root);