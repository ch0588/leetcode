// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // initialize marks
        map<int, UndirectedGraphNode *> marks;
        if (node)
            return dfs(node, marks);
        else
            return NULL;
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &marks) {
        // create new node and search its all neighbors
        UndirectedGraphNode *p;
        p = new UndirectedGraphNode(node->label);
        marks[p->label] = p;
        
        // loop all neighbors
        for (UndirectedGraphNode *n : node->neighbors) {
            // hook already created and searched node
            if (marks.count(n->label) > 0)
                (p->neighbors).push_back(marks[n->label]);
            else
                (p->neighbors).push_back(dfs(n, marks));
        }
        return p;
    }
};