#include<bits/stdc++.h>
using namespace std;

// Recursive AO* Function
int AOStar(string node,
           map<string, vector<vector<pair<string,int>>>> &graph,
           map<string,int> &heuristic){

    // If node is not present in graph,
    // it is a goal node
    if(graph.find(node) == graph.end()){

        return heuristic[node];
    }

    int minimumCost = INT_MAX;

    // Explore all AND/OR paths
    for(auto path : graph[node]){

        int currentCost = 0;

        cout << "\nChecking Path: ";

        // Calculate total cost of current path
        for(auto child : path){

            cout << node << " -> "
                 << child.first << " ";

            currentCost +=
                child.second +
                AOStar(child.first,
                       graph,
                       heuristic);
        }

        cout << "\nCost = "
             << currentCost
             << endl;

        // Select minimum cost path
        minimumCost =
            min(minimumCost, currentCost);
    }

    // Update heuristic value
    heuristic[node] = minimumCost;

    return minimumCost;
}

int main(){

    // Graph representation
    // Node -> possible paths
    map<string,
        vector<vector<pair<string,int>>>> graph;

    // Heuristic values
    map<string,int> heuristic;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "\nEnter node names and heuristic values:\n";

    for(int i = 0; i < n; i++){

        string node;

        int h;

        cin >> node >> h;

        heuristic[node] = h;
    }

    int edges;

    cout << "\nEnter number of parent nodes: ";
    cin >> edges;

    for(int i = 0; i < edges; i++){

        string parent;

        int choices;

        cout << "\nEnter parent node: ";
        cin >> parent;

        cout << "Enter number of paths from "
             << parent << ": ";

        cin >> choices;

        vector<vector<pair<string,int>>> allPaths;

        // Multiple OR paths
        for(int j = 0; j < choices; j++){

            int children;

            cout << "\nEnter number of children in path "
                 << j+1 << ": ";

            cin >> children;

            vector<pair<string,int>> path;

            // AND nodes in same path
            for(int k = 0; k < children; k++){

                string child;

                int cost;

                cout << "Enter child and edge cost: ";

                cin >> child >> cost;

                path.push_back({child,cost});
            }

            allPaths.push_back(path);
        }

        graph[parent] = allPaths;
    }

    string start;

    cout << "\nEnter start node: ";
    cin >> start;

    cout << "\nAO* Traversal:\n";

    int answer =
        AOStar(start, graph, heuristic);

    cout << "\nMinimum Cost = "
         << answer << endl;

    return 0;
}


/*
Enter number of nodes: 5

Enter node names and heuristic values:
A 10
B 4
C 6
D 0
E 0

Enter number of parent nodes: 2

Enter parent node: A
Enter number of paths from A: 2

Enter number of children in path 1: 1
Enter child and edge cost: B 1

Enter number of children in path 2: 2
Enter child and edge cost: C 1
Enter child and edge cost: D 1

Enter parent node: C
Enter number of paths from C: 1

Enter number of children in path 1: 1
Enter child and edge cost: E 1

Enter start node: A
*/