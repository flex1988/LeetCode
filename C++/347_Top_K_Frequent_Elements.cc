bool comp(const pair<int,int>& a,const pair<int,int>& b)
{
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                map[nums[i]]++;
            }
            else
            {
                map.insert({nums[i],1});
            }
        }
        
        priority_queue<pair<int, int> > queue;
        for(auto x: map)
        {
            queue.push({x.second,x.first});
        }
        
        vector<int> ret;
        for(int i = 0;i<k;i++){
            ret.push_back(queue.top().second);
            queue.pop();
        }
        
        return ret;
    }
};
