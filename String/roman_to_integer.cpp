// 13. Roman to Integer

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> Roman =
                                {  { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

        int integer = Roman[s.back()];
        for(int i = s.size() - 2; i>=0; i--){

            // for cases like IV or XL
            if(Roman[s[i]] < Roman[s[i+1]])
                integer -= Roman[s[i]];

            else
                integer += Roman[s[i]];
        }

        return integer;
    }
};
