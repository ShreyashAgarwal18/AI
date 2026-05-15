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

    for(int i = 0; i<V; i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    int totalWeight = 0;

    cout<<"Edges:\n";

    while(count<V-1){
        Edge currentEdge = edges[i];

        int srcParent = findParent(parent, currentEdge.src);
        int destParent = findParent(parent, currentEdge.dest);
        

        if(srcParent != destParent){
            cout<<currentEdge.src << "-" << currentEdge.dest<< " Weight = " << currentEdge.weight<<endl;

            totalWeight+= currentEdge.weight;

            unionSet(parent, srcParent, destParent);

            count++;
        }
        i++;
    }

    cout<<"\nTotal Min Weight: "<<totalWeight<<endl;
}


int main(){
    int V = 4;
    int E = 5;

    Edge edges[E];

    edges[0] = {0, 1, 10};
    edges[1] = {0, 2, 6};
    edges[2] = {0, 3, 5};
    edges[3] = {1, 3, 15};
    edges[4] = {2, 3, 4};

     kruskals(edges, V, E);
     return 0;


}