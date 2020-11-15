// 1209. Remove All Adjacent Duplicates in String II

class Solution {
public:
    string removeDuplicates(string s, int k) {

        // char and no. of duplicates previously
        stack<pair<char, int>> stck;

        for(auto ch : s){

            // if prev is same, increase count of duplicates
            if(!stck.empty() && stck.top().first == ch){
                stck.push({ch, stck.top().second + 1});
            } else{
                stck.push({ch, 1});
            }

            if(!stck.empty() && stck.top().second >= k){
                int duplicates = k;
                while(!stck.empty() && duplicates--){
                    stck.pop();
                }
            }
        }

        string no_duplicate = "";
        while(!stck.empty()){
            no_duplicate += stck.top().first;
            stck.pop();
        }

        reverse(no_duplicate.begin(), no_duplicate.end());
        return no_duplicate;
    }
};
