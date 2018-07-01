class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        
        int in_degree[numCourses] = {0};
        int count = 0;
        int uniques = 0;
        bool visit[numCourses] = {0};
        
        vector<vector<int> > graph(numCourses);
        
        for(auto x : prerequisites) {
            if (!visit[x.second]) {
                visit[x.second] = 1;
                uniques++;
            }
            
            in_degree[x.first]++;
            graph[x.second].push_back(x.first);
        }
        
        while (1) {
            int i;
            for(i= 0;i < numCourses; i++) {
                if(in_degree[i] == 0) {
                    in_degree[i] = -1;
                    if (graph[i].size())
                        count++;
                    for(auto y : graph[i]) {
                        in_degree[y]--;
                    }
                    break;
                }
            }
            
            if (i == numCourses)
                break;
        }
        
        return count == uniques;
    }
};
