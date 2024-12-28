#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path in binary matrix
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] || grid[n - 1][n - 1]) return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;

    vector<int> dirs = {-1, -1, -1, 0, 1, 1, 1, 0, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1 && y == n - 1) return grid[x][y];
        for (int d = 0; d < 8; ++d) {
            int nx = x + dirs[d], ny = y + dirs[d + 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << "Shortest Path: " << shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
