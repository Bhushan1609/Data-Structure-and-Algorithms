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
function reverse( low, high,v){
    while(low<=high){
        let temp=v[low];
        v[low]=v[high];
        v[high]=temp;
        low++;
        high--;      
    }
}
function mirror(root){
    if(root==null) return;
    let temp = root.left;
    root . left = root . right;
    root . right = temp;
    mirror(root . left);
    mirror(root . right);
}
function traverse(p , q, b){
    if(p == null || q == null){
        if(p != null && q == null) {
            b = false;
        }
        else if(p == null && q != null){
            b = false;
        }
        return;
    }
    let val1 = p . val , val2 = q . val;
    if(val1 !=  val2) b = false;
    traverse(p . left , q . left , b);
    traverse(p . right , q . right , b);
}
function isSymmetric( root) {
    let b = true;
    let p = root . left , *q = root . right;
    mirror(q);
    traverse(p ,q,b);
    System.out.println(b);
    System.out.println();
}
// let root=nonRecursiveTreeCreation();
// levelOrder(root);

console.log("Enter Data for the Root : ");
let root=null;
root=RecursiveTreeCreation(root);
// levelOrder(root);
isSymmetric(root);
