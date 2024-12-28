#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int countPossibleRoots(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    int n = edges.size() + 1;
    unordered_map<int, unordered_set<int>> tree;
    unordered_map<int, unordered_set<int>> guessSet;

    for (auto& edge : edges) {
        tree[edge[0]].insert(edge[1]);
        tree[edge[1]].insert(edge[0]);
    }
    for (auto& guess : guesses) {
        guessSet[guess[0]].insert(guess[1]);
    }

    int count = 0;
    function<int(int, int)> dfs = [&](int node, int parent) {
        int correctGuesses = 0;
        for (int child : tree[node]) {
            if (child == parent) continue;
            correctGuesses += dfs(child, node);
        }
        if (guessSet[parent].count(node)) correctGuesses++;
        if (correctGuesses >= k) count++;
        return correctGuesses;
    };

    dfs(0, -1);
    return count;
}

// Example usage
int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {4, 2}};
    vector<vector<int>> guesses = {{1, 3}, {0, 1}, {1, 0}, {2, 4}};
    int k = 3;

    cout << "Possible Roots: " << countPossibleRoots(edges, guesses, k) << endl;

    return 0;
}
