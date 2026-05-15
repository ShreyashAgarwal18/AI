#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};

bool compare(Edge a, Edge b){
    return a.weight < b.weight;
}

int findParent(int parent[], int node){

    if(parent[node] == node){
        return node;
    }

    return findParent(parent, parent[node]);
}

void unionSet(int parent[], int u, int v){

    int uParent = findParent(parent, u);
    int vParent = findParent(parent, v);

    parent[uParent] = vParent;
}

void kruskals(Edge edges[], int V, int E){

    sort(edges, edges + E, compare);

    int parent[V];

    // Initially every node is parent of itself
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    int totalWeight = 0;

    cout << "\nEdges in MST:\n";

    while(count < V - 1){

        Edge currentEdge = edges[i];

        int srcParent = findParent(parent, currentEdge.src);
        int destParent = findParent(parent, currentEdge.dest);

        // If no cycle is formed
        if(srcParent != destParent){

            cout << currentEdge.src
                 << " - "
                 << currentEdge.dest
                 << "  Weight = "
                 << currentEdge.weight
                 << endl;

            totalWeight += currentEdge.weight;

            unionSet(parent, srcParent, destParent);

            count++;
        }

        i++;
    }

    cout << "\nTotal Minimum Weight: "
         << totalWeight << endl;
}

int main(){

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[E];

    cout << "\nEnter edges in format:\n";
    cout << "source destination weight\n\n";

    for(int i = 0; i < E; i++){

        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    kruskals(edges, V, E);

    return 0;
}

/*
Enter number of vertices: 4
Enter number of edges: 5

Enter edges in format:
source destination weight

0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/