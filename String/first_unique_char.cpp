// 387. First Unique Character in a String

class Solution {
// One pass solution, the idea is to use
// a hash to store frequence of characters
// a doubly linked list to store all the singly occured chars
// a hash to contain chars and a pointer to location in the list

public:
    int firstUniqChar(string s) {

        vector<int> char_freq(27, 0);
        list<int> unique_chars;
        unordered_map<char, list<int>::iterator> char_pos;

        for(int i = 0; i<s.length(); i++){

            char_freq[s[i]-'a']++;

            // if it is unique
            if(char_freq[s[i] - 'a'] == 1){
                unique_chars.push_back(i);

                // because .end() is stagnant and we won't remove
                // it so store a copy of that
                char_pos[s[i]] = prev(unique_chars.end());
            }

            // if it is still in the list
            if(char_freq[s[i] - 'a'] == 2){
                unique_chars.erase(char_pos[s[i]]);
                char_pos.erase(s[i]);
            }
        }

        return unique_chars.empty() ? -1 : unique_chars.front();
    }
};
