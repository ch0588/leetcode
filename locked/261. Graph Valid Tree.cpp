/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree? Show More Hint 
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 */
class Solution {
public:
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n==0) return true;
        
        vector<int>adj[n];
        int m = edges.size();
        
        if(m+1!=n) return false;
        
        for(auto e:edges){
            adj[e.first].emplace_back(e.second);
            adj[e.second].emplace_back(e.first);
        }
        
        queue<int>Q;
        int cnt = 0;
        bool vis[n] = {0};
        
        vis[0] = true;
        Q.push(0);
        while(!Q.empty()){
            int u = Q.front();
            //printf("u=%d\n",u);
            Q.pop();
            cnt++;
            for(int v:adj[u]){
                //printf("v=%d\n",v);
                if(vis[v]==false){
                    vis[v]=true;
                    Q.push(v);
                }
            }
        }
        return cnt==n;
    }
};


class Solution {
public:
    int *fa;
    int father(int x){
        if(x==fa[x]) return x;
        return fa[x] = father( fa[x] );
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n==0) return true;
        int m = edges.size();
        if(m+1!=n) return false;
        
        fa = new int[n];
        for(int i=0; i<n; ++i) fa[i] = i;
        
        for(auto e:edges){
            int u = e.first,v=e.second;
            int fu = father(u);
            int fv = father(v);
            if(fu==fv) return false;
            fa[fu] = fv;
        }
        return true;
    }
};