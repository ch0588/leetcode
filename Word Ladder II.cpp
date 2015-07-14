/*
首先bfs分层，然后类似求最短路上的点，dfs
*/
class Solution {
public:
struct NODE{
        string s;
        int t;
        NODE(){};
        NODE(string _s,int _t){
            s = _s;
            t = _t;
        }
    };
    map<string,int>H;
    vector< vector<string> >ret;
    vector<string>path;
    map< string,vector<string> >adj;
    void dfs(string s, int d, string end){
        if(d>H[end]) return;
        if(end==s)
            ret.push_back(path);

        if(adj.find(s)==adj.end()) return;
        vector<string>nexts = adj[s];
        for(int i=0; i<nexts.size(); ++i){
            string ns = nexts[i];
            if(H[ns]==d+1){
                path.push_back(ns);
                dfs(ns, d+1, end);
                path.pop_back();
            }
        }
    }
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict){
        H.clear();
        NODE now,next;
        queue<NODE>Q;

        now = NODE(start,1);
        Q.push(now);
        H[now.s] = now.t;
        adj.clear();

        while(!Q.empty()){
            now = Q.front();
            Q.pop();
            if(now.s==end){
                continue;
            }
            next.t = now.t+1;
            for(int i=0; i<now.s.size(); ++i)
                for(int j=0; j<26; ++j){
                    next.s = now.s;
                    next.s[i] = 'a'+j;
                    if(!dict.count(next.s)) continue;
                    adj[now.s].push_back(next.s);
                    if(H.find(next.s)!=H.end()) continue;
                    H[next.s] = next.t;
                    Q.push(next);
                }
        }
        ret.clear();
        path.clear();
        path.push_back(start);
        dfs(start, 1, end);
        return ret;
    }
};
