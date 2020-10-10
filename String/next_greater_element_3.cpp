// 556. Next Greater Element III

class Solution {
public:
    int nextGreaterElement(int n) {

        // convert to string to
        string num = to_string(n);
        int i = num.size() - 2;

        // can't find next greater for single digit
        if(num.size()==1)
            return -1;

        // from the right, find first element that is smaller
        // than some element from its right
        for(; i>=0; i--)
        {
            if(num[i] < num[i+1])
                break;
        }

        // if the number is in non increasing order, return -1
        if(i == -1)
            return -1;

        // sort the rest num in non decreasing to turn it into
        // the smallest next number
        sort(num.begin() + i + 1, num.end());

        // swap with the next smallest greater number for our i
        for(int j = i+1; j<num.size(); j++)
        {
            if(num[i] < num[j]){
                swap(num[i], num[j]);
                break;
            }
        }

        // convert back to number
        long final_num = stol(num);

        // according to the question
        return final_num > INT_MAX ? -1 : final_num ;
    }
};
