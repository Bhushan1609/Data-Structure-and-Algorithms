const fs = require("fs");

let rawInput = "";
const useFileIO = fs.existsSync("input.txt");

if (useFileIO)
	rawInput = fs.readFileSync("input.txt", "utf8");
else
    rawInput = fs.readFileSync(0, "utf8"); // stdin

const input = rawInput.trim().split(/\s+/).map(Number);
let idx = 0;

class TreeNode{
	data;
	left;
	right;

    constructor(data,left=null,right=null){
        this.data=data;
        this.left=left;
        this.right=right;
    } 

    LEVEL_ORDER(out){
        out.push("Level-Order Traversal :\n");

        let root=this;
        let q=[];
        q.push(root);
        while(q.length>0){
            let qsize=q.length;
            for(let i=0;i<qsize;i++){
            	let temp=q.shift();
            	out.push(temp.data+" ");
            	if(temp.left)
            		q.push(temp.left);
            	if(temp.right)
            		q.push(temp.right);
            }out.push("\n");
        }
        return ;
    }

    static CREATE_ITERATIVE(out){
    	let root=null;
        let rootdata=input[idx++];
        out.push("Enter data for the root : \n");
        root=new TreeNode(rootdata);

        let q=[];
        q.push(root);
        while(q.length>0){
        	let qsize=q.length;
        	for(let i=0;i<qsize;i++){
        		let temp=q.shift();
        		let leftrootdata,rightrootdata;
        		out.push("Enter left and right data for the "+temp.data+" : \n");
        		leftrootdata=input[idx++];
        		rightrootdata=input[idx++];
        		if(leftrootdata!==0){
        			temp.left=new TreeNode(leftrootdata);
        			q.push(temp.left);
        		}
        		if(rightrootdata!==0){
        			temp.right=new TreeNode(rightrootdata);
        			q.push(temp.right);
        		}
        	}
        }
        return root;
    }

    static CREATE_RECURSION(out){
        const recursion=(root)=>{
        	if(!root){
            	out.push("Enter data for root : \n");
            	let rootdata;rootdata=input[idx++];
                	if(rootdata===0)
                    	return root;
                root=new TreeNode(rootdata);
        	}
            out.push("Enter data for the left of the "+root.data+" : \n");
            root.left=recursion(root.left);
            out.push("Enter data for the right of the "+root.data+" : \n");
            root.right=recursion(root.right);
            return root;
        };
        let root=null;
        return recursion(root);
    }
}

let output=[];

// let root=TreeNode.CREATE_RECURSION(output);
let root=TreeNode.CREATE_ITERATIVE(output);
root.LEVEL_ORDER(output);

if(useFileIO)
    fs.writeFileSync("output.txt", output.join(""));
else
    console.log(output.join("\n"));

// Input for iterative creation 1 2 3 4 5 6 7 0 0 0 0 0 0 0 0 
// Input for recursive creation 1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
