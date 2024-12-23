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
class Pair<U, V> {
    public final U first;
    public final V second;
    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
    public U fi() {
        return first;
    }
    public V se() {
        return second;
    }
};
public class Java{
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
    static void widthOfBinaryTree(Node root) {
        if(root==null)return ;
        Queue<Pair<Node,Integer>>q=new LinkedList<>();
        q.add(new Pair<Node,Integer>(root,0));
        int ans=0;
        while(!q.isEmpty()){
            int n=q.size();
            int mini=q.peek().se();
            int first=0,last=0;
            for(int i=0;i<n;i++){
                Pair<Node, Integer>temp=q.poll();
                int currentNumber=temp.se();
                if(i==0)first=currentNumber;
                if(i==(n-1))last=currentNumber;
                if(temp.fi().left != null)q.add(new Pair<Node,Integer>(temp.fi().left,(currentNumber << 1)+1));
                if(temp.fi().right != null)q.add(new Pair<Node,Integer>(temp.fi().right,(currentNumber << 1)+2));
            }
            ans=Math.max(ans,last-first+1);
        }
        System.out.println(ans);
        return ;
    }
    public static void main(String args[]){
        // Node root=nonRecursiveTreeCreation();
        // levelOrder(root);

        System.out.println("Enter Data for the Root : ");

        Node root=null;
        root=RecursiveTreeCreation(root);
        // levelOrder(root);
        widthOfBinaryTree(root);
    }
}