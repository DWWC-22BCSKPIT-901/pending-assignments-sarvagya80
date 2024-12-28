#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if a path exists in a graph
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == destination) return true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Path exists: " << validPath(3, edges1, 0, 2) << endl;

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << "Path exists: " << validPath(6, edges2, 0, 5) << endl;

    return 0;
}
