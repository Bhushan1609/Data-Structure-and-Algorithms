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
    static class Pair<U, V> {
        public final U first;
        public final V second;
        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }

        public U getKey() {
            return first;
        }

        public V getValue() {
            return second;
        }
    }
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
    static void reverse(int low,int high,List<Integer>v){
        while(low<=high){
            int temp=v.get(low);
            v.set(low,v.get(high));
            v.set(high,temp);  
            low++;
            high--;      
        }
    }
    static void verticalOrder(Node root) {
        Map<Integer, Map<Integer, TreeSet<Integer>>> mapp = new TreeMap<>();
        Queue<Pair<Node, Pair<Integer, Integer>>> q = new LinkedList<>();
        q.add(new Pair<>(root, new Pair<>(0, 0)));
        while (!q.isEmpty()) {
            Pair<Node, Pair<Integer, Integer>> p = q.poll();
            Node temp = p.getKey();
            int x = p.getValue().getKey();
            int y = p.getValue().getValue();
            mapp.computeIfAbsent(x, k -> new TreeMap<>()).computeIfAbsent(y, k -> new TreeSet<>()).add(temp.data);
            if (temp.left != null) q.add(new Pair<>(temp.left, new Pair<>(x - 1, y + 1)));
            if (temp.right != null) q.add(new Pair<>(temp.right, new Pair<>(x + 1, y + 1)));
        }

        List<List<Integer>> ans = new ArrayList<>();
        for (Map.Entry<Integer, Map<Integer, TreeSet<Integer>>> entry : mapp.entrySet()) {
            List<Integer> col = new ArrayList<>();
            for (TreeSet<Integer> set : entry.getValue().values()) {
                col.addAll(set);
            }
            ans.add(col);
        }
        System.out.println(ans);
        return ;
    }
    public static void main(String args[]){
        
        Node root=nonRecursiveTreeCreation();
        levelOrder(root);

        // System.out.println("Enter Data for the Root : ");

        // root=null;
        // root=RecursiveTreeCreation(root);
        // levelOrder(root);
        System.out.println();
        verticalOrder(root);
    }
}