import java.util.*;
public class J{
    static void createGraphUsingMatrix(Scanner sc){
        System.out.print("Enter Number of Nodes and Edges Respectively : ");
        int nodes=sc.nextInt();
        int edges=sc.nextInt();
        int[][] graphMatrix = new int[nodes+1][nodes+1];
        for(int i = 0; i < edges; i++) {
            System.out.print("Enter the Nodes that have an Edge in Between : ");
            int a = sc.nextInt();
            int b = sc.nextInt();
            graphMatrix[a][b]=graphMatrix[b][a]=1;
        }
        for(int i = 0; i <= nodes; i++){
            for (int j = 0; j <= nodes; j++) System.out.print(graphMatrix[i][j]+" ");
            System.out.println();
        }
    }
    static void printGraph(ArrayList<ArrayList<Integer>> graph,int nodes){
        for (int i=0;i<=nodes;i++) {
            System.out.print("{" + i + "} : {");
            for (int j=0;j<graph.get(i).size();j++) {
                System.out.print("[" + graph.get(i).get(j) + "], ");
            }
            System.out.println("}");
        }
    }
    static void createGraph(Scanner sc){
        System.out.print("Enter Number of Nodes and Edges Respectively : ");
        int nodes=sc.nextInt();
        int edges=sc.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>(nodes);
        for (int i=0;i<=nodes;i++)graph.add(new ArrayList<>());
        for (int i=0;i<edges;i++) {
            System.out.print("Enter the Nodes that have an Edge in Between : ");
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        printGraph(graph,nodes);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        createGraph(sc);
    }
}