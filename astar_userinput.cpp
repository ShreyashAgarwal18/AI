#include<bits/stdc++.h>
using namespace std;

// Structure for each cell
struct Cell{
    int x, y;
    int g, h, f;
};

// Min Heap Comparator
struct compare{
    bool operator()(Cell a, Cell b){
        return a.f > b.f;
    }
};

// Manhattan Distance Heuristic
int heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStar(vector<vector<int>> &grid,
           pair<int,int> start,
           pair<int,int> goal){

    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Cell,
                   vector<Cell>,
                   compare> pq;

    vector<vector<bool>> visited(
        rows,
        vector<bool>(cols,false));

    // Parent array to print path
    vector<vector<pair<int,int>>> parent(
        rows,
        vector<pair<int,int>>(cols, {-1,-1}));

    // Start node
    Cell startCell;

    startCell.x = start.first;
    startCell.y = start.second;

    startCell.g = 0;

    startCell.h =
        heuristic(start.first,
                  start.second,
                  goal.first,
                  goal.second);

    startCell.f =
        startCell.g + startCell.h;

    pq.push(startCell);

    // Directions
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!pq.empty()){

        Cell current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        if(visited[x][y])
            continue;

        visited[x][y] = true;

        // Goal reached
        if(x == goal.first &&
           y == goal.second){

            cout << "\nGoal Reached!\n";

            // Print path
            vector<pair<int,int>> path;

            pair<int,int> temp = goal;

            while(temp.first != -1){

                path.push_back(temp);

                temp =
                    parent[temp.first][temp.second];
            }

            reverse(path.begin(), path.end());

            cout << "Path:\n";

            for(auto p : path){
                cout << "("
                     << p.first
                     << ","
                     << p.second
                     << ") ";
            }

            cout << "\nCost: "
                 << current.g
                 << endl;

            return;
        }

        // Explore neighbors
        for(int i = 0; i < 4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            // Valid cell and not obstacle
            if(nx >= 0 &&
               nx < rows &&
               ny >= 0 &&
               ny < cols &&
               grid[nx][ny] == 0 &&
               !visited[nx][ny]){

                Cell neighbor;

                neighbor.x = nx;
                neighbor.y = ny;

                // Actual cost
                neighbor.g = current.g + 1;

                // Heuristic cost
                neighbor.h =
                    heuristic(nx,
                              ny,
                              goal.first,
                              goal.second);

                // Total cost
                neighbor.f =
                    neighbor.g + neighbor.h;

                // Store parent
                parent[nx][ny] = {x,y};

                pq.push(neighbor);
            }
        }
    }

    cout << "\nNo Path Found!\n";
}

int main(){

    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(
        rows,
        vector<int>(cols));

    cout << "\nEnter grid:\n";
    cout << "0 = Free Path\n";
    cout << "1 = Obstacle\n\n";

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }

    int sx, sy, gx, gy;

    cout << "\nEnter start coordinates: ";
    cin >> sx >> sy;

    cout << "Enter goal coordinates: ";
    cin >> gx >> gy;

    aStar(grid,
          {sx, sy},
          {gx, gy});

    return 0;
}


/*
Enter rows and columns: 4 4

Enter grid:
0 = Free Path
1 = Obstacle

0 0 0 0
1 1 0 1
0 0 0 0
0 1 1 0

Enter start coordinates: 0 0
Enter goal coordinates: 3 3
*/