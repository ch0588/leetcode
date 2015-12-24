class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>res;
        if(n==0) return res;
        int d[n]={0},depth[n]={0};
        vector<int>adj[n];
        for(auto e:edges){
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
            d[ e.first ]++;
            d[ e.second ]++;
        }
        queue< pair<int,int> >Q; //node, depth
        int max_depth = 0;
        for(int i=0; i<n; ++i) 
            if(d[i]==1){
                Q.push( make_pair(i,0) );
                depth[i] = 0;
            }
        while(!Q.empty()){
            int u = Q.front().first;
            int ud = Q.front().second;
            max_depth = max(max_depth,ud);
            Q.pop();
            for(int v:adj[u]){
                d[v]--;
                if(d[v]==1) {
                    Q.push( make_pair(v,ud+1) );
                    depth[v] = ud+1;
                }
            }
        }
        for(int i=0; i<n; ++i)
            if(depth[i]==max_depth) res.push_back(i);
        return res;
    }
};


class Solution {
public: 
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto e: edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        vector<int> degree(n, 0);  //degree
        for(int i=0; i<n; i++) degree[i]=graph[i].size();
        for(int remain=n, j; remain>2;){
            vector<int> del; // nodes to delete
            for(j=0; j<n; j++){
                if(degree[j]==1) { //find leaves
                    remain--;
                    del.push_back(j);
                    degree[j]=-1;
                }
            }
            for(auto k: del){ //delete this node and its edges 
                for(auto neigh: graph[k]) degree[neigh]--;
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++) if(degree[i]>=0) res.push_back(i);
        return res;
    }
};