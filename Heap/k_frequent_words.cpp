// 692. Top K Frequent Words

class Solution {

    struct compare{
    bool operator()(pair<int, string> a, pair<int, string> b){

        if(a.first==b.first)
         return a.second < b.second;

        else
          return a.first > b.first;
        }
    };



public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mapp;

        for(auto i: words)
            mapp[i]++;

        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> min_heap;

        for(auto i: mapp)
        {
            min_heap.push({i.second,i.first});

            if(min_heap.size() >k)
                min_heap.pop();
        }

        vector<string> k_most_freq;

        while(!min_heap.empty())
        {
            pair<int,string> p;
            p = min_heap.top();
            k_most_freq.push_back(p.second);
            min_heap.pop();
        }

        reverse(k_most_freq.begin(), k_most_freq.end());

        return k_most_freq;
    }
};
