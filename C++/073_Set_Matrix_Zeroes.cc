class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<std::pair<int,int>> pairs;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0){
                    pairs.push_back({i,j});
                }
            }
        }
        
        for(int i=0;i<pairs.size();i++)
            setZero(matrix,pairs[i].first,pairs[i].second);
    }
    
    void setZero(vector<vector<int>>& matrix,int x,int y){
        for(int i=0;i<matrix.size();i++)
            matrix[i][y] = 0;
        for(int j=0;j<matrix[0].size();j++)
            matrix[x][j] = 0;
    }
    
};
