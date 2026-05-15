#include<bits/stdc++.h>
using namespace std;

void printPath(int vertex, vector<int> &parent){
    if(vertex == -1) return;

    printPath(parent[vertex], parent);

    cout<<vertex<<" ";
}

void dijkstra(int V, vector<pair<int,int>> adj[], int source){
    vector<int> distance(V, INT_MAX);

    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[source] = 0;

    pq.push({0,source});

    while(!pq.empty()){
        int dist = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        for(auto neighbor : adj[u]){
            int v = neighbor.first;
            int weight = neighbor.second;

            if(distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
                parent[v] = u;

                pq.push({distance[v], v});
            }
        }
    }

    cout<<"\nShortest path from: "<<source<<":\n";

    for(int i = 0; i<V; i++){
        cout<<"\nVertex: " << i <<endl;

        cout<<"Cost: "<<distance[i]<<endl;

        cout<<"Path: ";

        printPath(i, parent);


        cout<<endl;
    }

}


int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int,int>> adj[V];

    cout << "\nEnter edges (source destination weight):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        // Undirected Graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;

    cout << "\nEnter source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);

    return 0;
}

/*
Enter number of vertices: 5
Enter number of edges: 6

Enter edges (source destination weight):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1

Enter source vertex: 0
*/