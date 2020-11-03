// 179. Largest Number

class Solution {

    static bool comp(string a, string b){
        return (a+b)>(b+a);
    }

public:
    string largestNumber(vector<int>& nums) {


        vector<string> number;
        for(auto i: nums){
            string s = to_string(i);
            number.push_back(s);
        }

        sort(number.begin(), number.end(), comp);
        string largest_num = "";
        for(auto s: number){
            largest_num += s;
        }


        // remove leading 0's
        while(largest_num[0]=='0' && largest_num.size()>1){
            largest_num = largest_num.substr(1);
        }

        return largest_num;
    }
};
