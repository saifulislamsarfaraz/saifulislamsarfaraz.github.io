class Graph{
    constructor(){
        this.adjecancyList = {}
    }

    addVertex(vertex){
        if(!this.adjecancyList[vertex]){
            this.adjecancyList[vertex] = [];
        }
    }

    addEdges(v1,v2){
        this.adjecancyList[v1].push(v2);
        this.adjecancyList[v2].push(v1);
    }

    removeEdge(v1,v2){
        this.adjecancyList[v1] = this.adjecancyList[v1].filter(v => v !== v2);
        this.adjecancyList[v2] = this.adjecancyList[v2].filter(v => v !== v1);
    }

    removeVertex(vertex){
        while(this.adjecancyList[vertex].length){
            const adjacencyVertex = this.adjecancyList[vertex].pop();
            this.removeEdge(vertex,adjacencyVertex);
        }
        delete this.adjecancyList[vertex];
    }

    depthFirstSearch(start){
    const result = [];
    const visited = {};
        (function dfs(vertex){
            if(!vertex) return null;
            visited[vertex] = true;
            result.push(vertex);
            adjecancyList[vertex].forEach(neighbor => {
                if(!visited[neighbor])
                dfs(neighbor);
            });
        })(start);

        return result; 
    }
}

let g = new Graph();

g.addVertex("A");
g.addVertex("B");
g.addVertex("C");
g.addVertex("D");
g.addVertex("E");
g.addVertex("F");

g.addEdges("A","B");
g.addEdges("A","C");
g.addEdges("B","D");
g.addEdges("C","E");
g.addEdges("D","E");
g.addEdges("D","F");
g.addEdges("E","F");














