// 459. Repeated Substring Pattern

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        // the idea is to find the occurence of some of
        // the substring within the string.

        // concatenate 2 strings together.
        string double_string = s+s;

        // remove the first element and also the last one
        double_string = double_string.substr(1);
        double_string.pop_back();

        // if still you find s in this string, then
        // there are more than 1 duplications, because
        // now it has been joined by another same string
        // but first and last elements are gone.
        return double_string.find(s) != -1;
    }
};
