import java.io.*;
import java.util.*;

public class Java{

	static class TreeNode<T>{
		T data;
		TreeNode left,right;

		TreeNode(T data){
			this.data=data;
			this.left=null;
			this.right=null;
		}

		TreeNode(T data,TreeNode left,TreeNode right){
			this.data=data;
			this.left=left;
			this.right=right;
		}

		void LEVEL_ORDER(PrintWriter out){
			out.println("Level-Order Traversal : ");
			
			TreeNode root=this;
			Queue<TreeNode>q=new LinkedList<>();
			q.add(this);
	        while(!q.isEmpty()){
	            int qsize=q.size();
	            for(int i=0;i<qsize;i++){
	                TreeNode temp=q.poll();
	                out.print(temp.data+" ");
	                if(temp.left!=null)
	                    q.add(temp.left);
	                if(temp.right!=null)
	                    q.add(temp.right);
	            }out.println();
	        }
	        return ;
		}

		static<T> TreeNode CREATE_ITERATIVE(Scanner in,PrintWriter out,java.util.function.Function<String,T> parser){
			TreeNode root=null;
			T rootdata;
			out.println("Enter data for the root : ");
			rootdata=parser.apply(in.next());
        	root=new TreeNode(rootdata);

        	Queue<TreeNode>q=new LinkedList<>();
        	q.add(root);
        	while(!q.isEmpty()){
        		int qsize=q.size();
        		for(int i=0;i<qsize;i++){
        			TreeNode temp=q.poll();
        			T leftrootdata,rightrootdata;
        			out.print("Enter left and right data for the "+temp.data+" : \n");
        			leftrootdata=parser.apply(in.next());
        			rightrootdata=parser.apply(in.next());

        			if(!leftrootdata.equals(0)){
	                    temp.left=new TreeNode(leftrootdata);
	                    q.add(temp.left);
	                }
	                if(!rightrootdata.equals(0)){
	                    temp.right=new TreeNode(rightrootdata);
	                    q.add(temp.right);
	                }
        		}
        	}
        	return root;
		}

		static<T> TreeNode recursion(TreeNode root,Scanner in,PrintWriter out,java.util.function.Function<String,T> parser){	
			if(root==null){
                out.print("Enter data for root : \n");
                T rootdata=parser.apply(in.next());
                if(rootdata.equals(0)){
                    return root;
                }
                root=new TreeNode(rootdata);
            }
            out.print("Enter data for the left of the "+root.data+" : \n");
            root.left=recursion(root.left,in,out,parser);
            out.print("Enter data for the right of the "+root.data+" : \n");
            root.right=recursion(root.right,in,out,parser);
            return root;
		}

		static<T> TreeNode CREATE_RECURSION(Scanner in,PrintWriter out,java.util.function.Function<String,T> parser){
			TreeNode root=null;
			return TreeNode.recursion(root,in,out,parser);	
		}
	}

	static void preorder(TreeNode root,PrintWriter out){
		if(root==null)
			return;
		out.print(root.data+" ");
		preorder(root.left,out);
		preorder(root.right,out);
	}

	public static void main(String args[]) throws FileNotFoundException{
		try(
			Scanner in = new Scanner(new File("input.txt"));
			PrintWriter out = new PrintWriter("output.txt")
		){
			TreeNode<Integer>root=TreeNode.CREATE_ITERATIVE(in,out,Integer::parseInt);
			// TreeNode<Integer>root=TreeNode.CREATE_RECURSION(in,out,Integer::parseInt);
			root.LEVEL_ORDER(out);
			out.print("Preorder Traversal is : ");
			preorder(root,out);
		}
	}
} 
// Input for iterative creation 1 2 3 4 5 6 7 0 0 0 0 0 0 0 0 
// Input for recursive creation 1 2 4 0 0 5 0 0 3 6 0 0 7 0 0