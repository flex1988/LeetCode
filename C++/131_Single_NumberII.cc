class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(vector<int>::iterator it = nums.begin();it != nums.end();it++){
            if(maps_.find(*it) != maps_.end())
            {
                maps_[*it]++;
            }else
            {
                maps_.insert({*it,1});
            }
        }
        
        for(auto iter=maps_.begin();iter != maps_.end();iter++)
        {
            if(iter->second == 1)
                return iter->first;
        }
        
        return 0;
    }
    
    unordered_map<int,int> maps_;
};
