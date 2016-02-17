/*
 一层一层剥开，从外向里最深处
 */
// Time Complexity: O(m)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n == 0) return res;
        int d[n] = {0}, depth[n] = {0};
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
            d[e.first]++;
            d[e.second]++;
        }
        queue<pair<int, int>> Q;  // node, depth
        int max_depth = 0;
        for (int i = 0; i < n; ++i)
            if (d[i] == 1) {
                Q.push(make_pair(i, 0));
                depth[i] = 0;
            }
        while (!Q.empty()) {
            int u = Q.front().first;
            int ud = Q.front().second;
            max_depth = max(max_depth, ud);
            Q.pop();
            for (int v : adj[u]) {
                d[v]--;
                if (d[v] == 1) {
                    Q.push(make_pair(v, ud + 1));
                    depth[v] = ud + 1;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            if (depth[i] == max_depth) res.push_back(i);
        return res;
    }
};