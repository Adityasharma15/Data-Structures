// 3. Longest Substring Without Repeating Characters

class Solution {

// using sliding window protocol with storing last occurence of chars

public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> last_occurence;
        int left = -1, max_len = 0;

        for(int right = 0; right<s.length(); right++){

            // if it has occured within our window
            if(last_occurence.find(s[right])!= last_occurence.end()
               && last_occurence[s[right]] > left)
                left = last_occurence[s[right]];

            max_len = max((right - left),  max_len);
            last_occurence[s[right]] = right;
        }

        return max_len;
    }
};
