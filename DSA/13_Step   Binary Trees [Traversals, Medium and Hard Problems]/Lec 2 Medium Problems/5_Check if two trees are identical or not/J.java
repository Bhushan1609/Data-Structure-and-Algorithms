import java.util.*;
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
    static boolean isSameTree(Node root1, Node root2) {
        if( (root1==null && root2!=null) || (root1!=null && root2==null))return false;
        if(root1==null && root2==null)return true;
        if(root1.data != root2.data)return false;
        return isSameTree(root1.left,root2.left) && isSameTree(root1.right,root2.right);
    }
    public static void main(String args[]){
        Node root=nonRecursiveTreeCreation();
        levelOrder(root);

        // System.out.println("Enter Data for the Root : ");

        // root=null;
        // root=RecursiveTreeCreation(root);
        // levelOrder(root);
        System.out.println();
        System.out.println(isSameTree(root,root));
    }
}