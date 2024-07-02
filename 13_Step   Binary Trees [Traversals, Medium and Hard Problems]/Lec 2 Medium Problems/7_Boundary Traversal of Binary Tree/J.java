import java.util.*;

import javax.swing.tree.TreeNode;
class Node{
    public
    int data;
    Node left;
    Node right;
    Node(int d){
        this.data=d;
        this.left=null;
        this.right=null;
    }
};

public class J{
    static void levelOrder(Node root){
        Queue<Node>q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node temp=q.poll();
                System.out.print(temp.data+" ");
                if(temp.left != null)q.add(temp.left);
                if(temp.right != null)q.add(temp.right);
            }
            System.out.println();
        }
    }
    static Node nonRecursiveTreeCreation(){
        Node root=null;
        Scanner sc=new Scanner(System.in);
        Queue<Node>q=new LinkedList<>();
        System.out.print("Enter Data for Root : ");
        int data=sc.nextInt();
        root = new Node(data);
        q.add(root);
        while(!q.isEmpty()){
            Node temp=q.poll();
            System.out.print("Enter the data for the left children of "+temp.data+" : ");
            data=sc.nextInt();
            if(data != 0){
                temp.left=new Node(data);
                q.add(temp.left);
            }
            System.out.print("Enter the data for the right children of "+temp.data+" : ");
            data=sc.nextInt();
            if(data != 0){
                temp.right=new Node(data);
                q.add(temp.right);
            }
        }
        return root;
    }
    static Node RecursiveTreeCreation(Node root){
        if(root==null){
            Scanner sc=new Scanner(System.in);
            int data=sc.nextInt();
            if(data==0)return null;
            root=new Node(data);
        }
        System.out.print("Enter the data for the left children of "+root.data+" ");
        root.left=RecursiveTreeCreation(root.left);
        System.out.print("Enter the data for the right children of "+root.data+" ");
        root.right=RecursiveTreeCreation(root.right);
        return root;
    }
    static boolean isLeaf(Node root){
        return ( (root.left==null) && (root.right==null) );
    }
    static void addLeft(Node root,ArrayList <Integer>ans){
        if(root==null)return;
        while(root!=null){
            if(isLeaf(root)==false)ans.add(root.data);
            if(root.left!=null)root=root.left;
            else root=root.right;
        }
    }
    static void addLeaf(Node root,ArrayList <Integer>ans){
        if(root==null)return;
        if(isLeaf(root)==true)ans.add(root.data);
        addLeaf(root.left,ans);
        addLeaf(root.right,ans);
    }
    static void addRight(Node root,ArrayList <Integer>ans){
        if(root==null)return;
        ArrayList <Integer>ans2=new ArrayList<>();
        while(root!=null){
            if(isLeaf(root)==false)ans2.add(root.data);
            if(root.right!=null)root=root.right;
            else root=root.left;
        }
        for(int i=ans2.size()-1;i>=0;i--)ans.add(ans2.get(i));
        return ;
    }
    static void boundarytraversal(Node root)
	{
	    ArrayList <Integer>ans=new ArrayList<>();
	    if(!isLeaf(root))ans.add(root.data);
	    Node curr1,curr2,curr3;
	    curr1=curr2=curr3=root;
	    addLeft(curr2.left,ans);
	    addLeaf(root,ans);
	    addRight(curr3.right,ans);
	   System.out.println(ans);
	}
    public static void main(String args[]){
        Node root=nonRecursiveTreeCreation();
        levelOrder(root);

        // System.out.println("Enter Data for the Root : ");

        // root=null;
        // root=RecursiveTreeCreation(root);
        // levelOrder(root);
        System.out.println();
        boundarytraversal(root);
    }
}