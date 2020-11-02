// 709. To Lower Case

class Solution {
public:
    string toLowerCase(string str) {

        for(int i = 0; i<str.size(); i++){

            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }

        return str;
    }
};
