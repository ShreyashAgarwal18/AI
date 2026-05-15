#include<iostream>
using namespace std;

#define V 5

int findMinVertex(int key[], bool visited[]){
    int min = 9999;
    int minIndex;

    for(int i = 0; i<V; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prims(int graph[V][V]){
    int parent[V];

    int key[V];

    bool visited[V];

    int totalWeight = 0;

    for(int i = 0; i<V; i++){
        key[i] = 9999;
        visited[i] = false;
    }

    key[0] = 0;

    parent[0] = -1;

    for(int count = 0; count< V-1; count++){
        int u = findMinVertex(key,visited);
        visited[u] = true;

        for(int v = 0; v<V; v++){
            if(graph[u][v] != 0 && visited[v] == false && graph[u][v] < key[v]){
                parent[v] = u;

                key[v] = graph[u][v];
            }
        }
    }

    cout<<"\nEdge \tWeight\n";

    for(int i = 1; i<V; i++){
        cout<<parent[i]<< "-" << i <<"\t" << graph[i][parent[i]]<<endl;

        totalWeight+= graph[i][parent[i]];
    }

    cout<<"\nMinimum weight: "<<totalWeight<<endl;
}


int main(){
    // Adjacency Matrix representation of graph
    int graph[V][V] =
    {
        //0  1  2  3  4
        {0, 2, 0, 6, 0}, // Vertex 0
        {2, 0, 3, 8, 5}, // Vertex 1
        {0, 3, 0, 0, 7}, // Vertex 2
        {6, 8, 0, 0, 9}, // Vertex 3
        {0, 5, 7, 9, 0}  // Vertex 4
    };

    // Function call
    prims(graph);

    return 0;
}