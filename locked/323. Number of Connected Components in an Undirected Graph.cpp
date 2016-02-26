/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */


// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int>* adj;
    void dfs(int u, bool* vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs(v, vis);
        }
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        bool vis[n];
        memset(vis, false, sizeof(vis));
        adj = new vector<int>[n];
        for (auto it : edges) {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                res++;
                dfs(i, vis);
            }
        }
        return res;
    }
};