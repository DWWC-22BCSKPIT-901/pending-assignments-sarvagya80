#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to calculate the distance of the nearest 0 for each cell
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                result[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dirs[d], ny = y + dirs[d + 1];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && result[nx][ny] > result[x][y] + 1) {
                result[nx][ny] = result[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> mat1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> result1 = updateMatrix(mat1);

    cout << "Updated Matrix: " << endl;
    for (auto& row : result1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
