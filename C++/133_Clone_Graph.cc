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
        if(node == NULL) return NULL;
        
        if (visit.find(node->label) != visit.end()) {
            return visit[node->label];
        }
        
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        visit.insert({node->label,root});
        
        for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();it != node->neighbors.end(); it++)
        {
            root->neighbors.push_back(cloneGraph(*it));
        }
        
        return root;
    }
    
private:
    unordered_map<int,UndirectedGraphNode*> visit;
};
