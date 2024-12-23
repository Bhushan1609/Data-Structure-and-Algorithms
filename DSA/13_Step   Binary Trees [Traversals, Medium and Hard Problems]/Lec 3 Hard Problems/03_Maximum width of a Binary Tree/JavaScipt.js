const cin=require("prompt-sync")();
class Node{
    constructor(data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}
class Pair {
    constructor(first, second) {
        this.first = first;
        this.second = second;
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
function widthOfBinaryTree(root){
    if (root === null) return ;
    let q = [];
    q.push(new Pair(root, 0));
    let ans = 0;
    while (q.length > 0) {
        let n = q.length;
        let mini = q[0].second;
        let first = 0, last = 0;
        for (let i = 0; i < n; i++) {
            let temp = q.shift();
            let currentNumber = temp.second;
            if (i === 0) first = currentNumber;
            if (i === (n - 1)) last = currentNumber;
            if (temp.first.left !== null) q.push(new Pair(temp.first.left, (currentNumber << 1) + 1));
            if (temp.first.right !== null) q.push(new Pair(temp.first.right, (currentNumber << 1) + 2));
        }

        ans = Math.max(ans, last - first + 1);
    }
    console.log(ans);
    return ;
}
// let root=nonRecursiveTreeCreation();
// levelOrder(root);

console.log("Enter Data for the Root : ");
let root=null;
root=RecursiveTreeCreation(root);
// levelOrder(root);
widthOfBinaryTree(root);
