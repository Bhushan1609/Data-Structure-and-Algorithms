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
    static void preorder(Node root,Vector<Integer>v){
        if(root==null)return;
        v.add(root.data);
        preorder(root.left,v);
        preorder(root.right,v);
    }
    static void inorder(Node root,Vector<Integer>v){
        if(root==null)return;
        inorder(root.left,v);
        v.add(root.data);
        inorder(root.right,v);
    }
    static void postorder(Node root,Vector<Integer>v){
        if(root==null)return;
        postorder(root.left,v);
        postorder(root.right,v);
        v.add(root.data);
    }
    static void iterativePreorder(Node root) {
        if (root == null) return;

        Stack<Node> s = new Stack<>();
        s.push(root);

        while (!s.isEmpty()) {
            Node temp = s.pop();
            System.out.print(temp.data + " ");

            if (temp.right != null) s.push(temp.right);
            if (temp.left != null) s.push(temp.left);
        }
        System.out.println();
    }
    static void iterativeInorder(Node root) {
        Stack<Node> s = new Stack<>();
        Node curr = root;
        while (!s.isEmpty() || curr != null) {
            if (curr != null) {
                s.push(curr);
                curr = curr.left;
            } else {
                curr = s.pop();
                System.out.print(curr.data + " ");
                curr = curr.right;
            }
        }
        System.out.println();
    }
    static void iterativePostorder(Node root) {
        Stack<Node> s = new Stack<>();
        Stack<Integer> out = new Stack<>();
        s.push(root);
        while (!s.isEmpty()) {
            Node temp = s.pop();
            out.push(temp.data);

            if (temp.left != null) s.push(temp.left);
            if (temp.right != null) s.push(temp.right);
        }
        while (!out.isEmpty()) {
            System.out.print(out.pop() + " ");
        }
        System.out.println();
    }
    void iterativePostorderUsingOneStack(Node root) {
        Stack<Node> stack = new Stack<>();
        Node curr = root;

        while (curr != null || !stack.isEmpty()) {
            if (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            else {
                Node temp = stack.peek().right;
                if (temp == null) {
                    temp = stack.pop();
                    System.out.print(temp.data + " ");
                    while (!stack.isEmpty() && temp == stack.peek().right) {
                        temp = stack.pop();
                        System.out.print(temp.data + " ");
                    }
                } 
                else {
                    curr = temp;
                }
            }
        }
    }
    public static void main(String args[]){
        // Node root=nonRecursiveTreeCreation();
        // levelOrder(root);

        System.out.println("Enter Data for the Root : ");

        Node root=null;
        root=RecursiveTreeCreation(root);
        levelOrder(root);

        Vector<Integer>v1=new Vector<>();
        Vector<Integer>v2=new Vector<>();
        Vector<Integer>v3=new Vector<>();

        preorder(root,v1);
        System.out.println(v1);
        inorder(root,v2);
        System.out.println(v2);
        postorder(root,v3);
        System.out.println(v3);

        iterativePreorder(root);
        iterativeInorder(root);
        iterativePostorder(root);
    }
}