// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {

        // to store character and its frequency
        vector<int> char_freq(256,0);
        for(auto ch : s){
              char_freq[ch]++;
        }

        // to store frequency and all the corresponding
        // characters in non - increasing fashion of frequencies
        map<int, vector<char> , greater<int>> freq_chars;
        for(int i = 0; i<256; i++){

            // to push characters in the slot of their
            // frequency, if freq > 0
            if(char_freq[i]){
                freq_chars[char_freq[i]].push_back(i);
            }
        }

        string sorted = "";
        for(auto i : freq_chars){

            // store all chars of frequencies in order
            for(auto ch: i.second){
            int freq = i.first;
            while(freq--){sorted += ch;}
            }
        }

        return sorted;
    }
};
