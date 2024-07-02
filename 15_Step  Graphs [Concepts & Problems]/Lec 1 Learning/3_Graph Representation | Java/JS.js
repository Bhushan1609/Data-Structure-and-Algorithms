const cin=require("prompt-sync")();
function createGraphUsingMatrix(){
    console.log("Enter Number of Nodes and Edges Respectively : ");
    let nodes=parseInt(cin());
    let edges=parseInt(cin());
    let graphMatrix = Array.from({ length: nodes + 1 }, () => Array(nodes + 1).fill(0));
    for(let i = 0; i < edges; i++) {
        console.log("Enter the Nodes that have an Edge in Between : ");
        let a = parseInt(cin());
        let b = parseInt(cin());
        graphMatrix[a][b]=1;
        graphMatrix[b][a]=1;
    }
    for (let i = 0; i <= nodes; i++) {
        let row = "";
        for (let j = 0; j <= nodes; j++) row += graphMatrix[i][j] + " ";
        console.log(row);
    }
}
function createGraph() {
    console.log("Enter Number of Nodes and Edges Respectively : ");
    let nodes = parseInt(readline.question());
    let edges = parseInt(readline.question());
    let graph = new Array(nodes + 1).fill(0).map(() => []);
    for (let i = 0; i < edges; i++) {
        console.log("Enter the Nodes that have an Edge in Between : ");
        let a = parseInt(readline.question());
        let b = parseInt(readline.question());
        graph[a].push(b);
        graph[b].push(a); 
    }
    printGraph(graph, nodes);
}
function printGraph(graph, nodes) {
    for (let i = 1; i <= nodes; i++) {
        console.log("{" + i + "} : {");
        for (let j = 0; j < graph[i].length; j++) {
            console.log("[" + graph[i][j] + "], ");
        }
        console.log("}");
    }
}
createGraph();