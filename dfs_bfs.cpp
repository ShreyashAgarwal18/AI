#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_recur_helper(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adj[vertex])
        {
            if (!visited[neighbor])
            {
                dfs_recur_helper(neighbor, visited);
            }
        }
    }

    void dfs_recur()
    {
        vector<bool> visited(vertices, false);
        cout << "\nRecursive Dfs Traversal: ";

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                dfs_recur_helper(i, visited);
            }
        }
        cout << endl;
    }

    void dfs_iter(int start)
    {
        vector<bool> visited(vertices, false);
        stack<int> st;

        st.push(start);

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            if (!visited[curr])
            {
                visited[curr] = true;
                cout << curr << " ";

                for (int i = adj[curr].size() - 1; i >= 0; i--)
                {
                    int neighbor = adj[curr][i];

                    if (!visited[neighbor])
                    {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }


    void bfs(){
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout<<"BFS: "<<endl;

        for(int i = 0; i<vertices; i++){

            if(!visited[i]){
                visited[i] = true;
                q.push(i);

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    cout<<curr<<" ";

                    for(int neighbor : adj[curr]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
};


int main(){

    int vertices;
    int edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < edges; i++) {

        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }


    int start;

    cout << "Enter starting vertex for Iterative DFS: ";
    cin >> start;

    // Function Calls
    g.dfs_recur();
    g.dfs_iter(start);
    g.bfs();

}



/*Sample input
5
4
0 1
0 2
1 3
2 4
0

      0
     / \
    1   2
    |   |
    3   4
*/