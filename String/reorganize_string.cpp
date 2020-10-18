// 767. Reorganize String

class Solution {
// using max heap

public:
    string reorganizeString(string S) {

        if(!S.size())
            return "";

        // this will have our solution
        string reorganized = "";

        // hash will contain frequency of each char
        unordered_map<char, int> char_freq;

        // max heap, having frequency and that char
        priority_queue< pair<int, char>> pq;

        // storing frequencies
        for(auto ch: S)
            char_freq[ch]++;

        // pushing into heap
        for(auto i: char_freq){
            if(i.second)
              pq.push({i.second, i.first});
         }

        while(pq.size() > 1){

            // pop 2 most frequent characters and push them
            // in the string adjacently
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();

            reorganized += first.second;
            reorganized += second.second;

            if(--first.first) pq.push({first.first, first.second});
            if(--second.first) pq.push({second.first, second.second});
        }

        // if a single character is left with more than 1 freq
        // then we would need to add it subsequently as no other
        // charac is left, so return empty string;
        if(pq.top().first > 1)
            return "";

        // if the string is of odd lenght, one char will
        // be left when taking in pairs
        if(!pq.empty())
            reorganized += pq.top().second;

        return reorganized;
    }
};
