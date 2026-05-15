#include <bits/stdc++.h>
using namespace std;

struct Cell
{

    int x, y;

    int g;

    int h;

    int f;
};

struct compare
{

    bool operator()(Cell a, Cell b)
    {
        return a.f > b.f;
    }
};

int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void aStar(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> goal)
{
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Cell, vector<Cell>, compare> pq;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    Cell startCell;

    startCell.x = start.first;
    startCell.y = start.second;

    startCell.g = 0;

    startCell.h = heuristic(
        start.first,
        start.second,

        goal.first,
        goal.second);

    startCell.f = startCell.g + startCell.h;

    pq.push(startCell);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    cout << "Visited path: \n";

    while (!pq.empty())
    {

        Cell current = pq.top();

        pq.pop();

        int x = current.x;
        int y = current.y;

        if (visited[x][y])
        {
            continue;
        }

        visited[x][y] = true;

        cout << "(" << x << "," << y << ")";

        if (x == goal.first && y == goal.second)
        {
            cout << "\nGoal Reached!\n";

            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                grid[nx][ny] == 0 && !visited[nx][ny])
            {

                Cell neighbor;

                neighbor.x = nx;
                neighbor.y = ny;

                neighbor.g = current.g + 1;

                neighbor.h = heuristic(
                    nx,
                    ny,
                    goal.first,
                    goal.second);

                neighbor.f = neighbor.g + neighbor.h;

                pq.push(neighbor);
            }
        }
    }

    cout << "\nNo Path Found!\n";
}


int main(){

    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,1,0,1},
        {0,0,0,0},
        {0,1,1,0}
    };

    pair<int,int> start = {0,0};

    pair<int,int> goal = {3,3};

    aStar(grid, start, goal);

    return 0;

}


/*
for user input

int main() {

    int rows, cols;

    // Input grid size
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Create grid
    vector<vector<int>> grid(rows, vector<int>(cols));

    // Input grid values
    cout << "\nEnter grid values:\n";
    cout << "0 = Free Cell\n";
    cout << "1 = Obstacle\n\n";

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            cin >> grid[i][j];
        }
    }

    // Input starting position
    int sx, sy;

    cout << "\nEnter starting position (x y): ";
    cin >> sx >> sy;

    // Input goal position
    int gx, gy;

    cout << "Enter goal position (x y): ";
    cin >> gx >> gy;

    // Store positions in pair
    pair<int,int> start = {sx, sy};

    pair<int,int> goal = {gx, gy};

    // Call A* Algorithm
    aStar(grid, start, goal);

    return 0;
}
*/

