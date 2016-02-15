// Time Complexity: O(m)
// Space Complexity: O(m)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> adj[numCourses], res;
        int indegree[numCourses] = {0};
        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        queue<int> Q;
        bool used[numCourses] = {0};
        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0) {
                Q.push(i);
                used[i] = true;
            }
        res.clear();
        while (!Q.empty()) {
            int now = Q.front();
            res.push_back(now);
            Q.pop();
            for (int i = 0; i < adj[now].size(); ++i) {
                int next = adj[now][i];
                indegree[next]--;
                if (indegree[next] == 0 && used[next] == false) {
                    used[next] = true;
                    Q.push(next);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i)
            if (used[i] == false) res.clear();
        return res;
    }
};