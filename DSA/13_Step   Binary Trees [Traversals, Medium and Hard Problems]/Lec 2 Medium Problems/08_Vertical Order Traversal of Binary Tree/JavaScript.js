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
function reverse( low, high,v){
    while(low<=high){
        let temp=v[low];
        v[low]=v[high];
        v[high]=temp;
        low++;
        high--;      
    }
}
function verticalOrder(root) {
    if (!root) return [];

    const mapp = new Map();
    const q = [];
    q.push(new Pair(root, new Pair(0, 0)));

    while (q.length > 0) {
        const p = q.shift();
        const temp = p.first;
        const x = p.second.first;
        const y = p.second.second;

        if (!mapp.has(x)) mapp.set(x, new Map());
        if (!mapp.get(x).has(y)) mapp.get(x).set(y, new Set());

        mapp.get(x).get(y).add(temp.data);

        if (temp.left) q.push(new Pair(temp.left, new Pair(x - 1, y + 1)));
        if (temp.right) q.push(new Pair(temp.right, new Pair(x + 1, y + 1)));
    }

    const ans = [];
    const sortedX = Array.from(mapp.keys()).sort((a, b) => a - b);

    for (const x of sortedX) {
        const column = [];
        const sortedY = Array.from(mapp.get(x).keys()).sort((a, b) => a - b);

        for (const y of sortedY) {
            column.push(...Array.from(mapp.get(x).get(y)));
        }
        ans.push(column);
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
verticalOrder(root);
