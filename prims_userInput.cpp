#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int spanningTree(int V, vector<vector<int>> adj[]){

        // {weight, {node, parent}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<int> vis(V,0);

        pq.push({0,{0,-1}});

        int sum = 0;

        cout << "\nEdges in MST:\n";

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            if(vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;

            // Skip first node
            if(parent != -1){
                cout << parent << " - " << node
                     << "  weight = " << wt << endl;
            }

            for(auto it : adj[node]){

                int adjNode = it[0];
                int edW = it[1];

                if(!vis[adjNode]){
                    pq.push({edW,{adjNode,node}});
                }
            }
        }

        return sum;
    }
};

int main(){

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];

    cout << "\nEnter edges in format:\n";
    cout << "source destination weight\n\n";

    for(int i = 0; i < E; i++){

        int u, v, w;
        cin >> u >> v >> w;

        vector<int> temp(2);

        // u -> v
        temp[0] = v;
        temp[1] = w;
        adj[u].push_back(temp);

        // v -> u
        temp[0] = u;
        temp[1] = w;
        adj[v].push_back(temp);
    }

    Solution obj;

    int sum = obj.spanningTree(V, adj);

    cout << "\nTotal weight of MST: " << sum << endl;

    return 0;
}


/*
Enter number of vertices: 5
Enter number of edges: 6

Enter edges in format:
source destination weight

0 1 2
0 2 1
1 2 1
2 3 2
3 4 1
4 2 2
*/