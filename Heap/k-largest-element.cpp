// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mapp;

        for(auto i: nums)
            mapp[i]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;

        for(auto i: mapp)
        {
            min_heap.push({i.second,i.first});

            if(min_heap.size() >k)
                min_heap.pop();
        }

        vector<int> k_most_freq;

        while(!min_heap.empty())
        {
            pair<int,int> p;
            p = min_heap.top();
            k_most_freq.push_back(p.second);
            min_heap.pop();
        }

        return k_most_freq;
    }
};
