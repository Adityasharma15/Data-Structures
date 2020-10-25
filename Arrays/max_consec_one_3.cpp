// 1004. Max Consecutive Ones III

class Solution {

// using sliding window protocol

// we will always have a window of atmost k zeroes
// contained in left & right pointers, we will keep
// updating our maximum length found so far and then
// return this value in the end.

public:
    int longestOnes(vector<int>& A, int K) {

        int n = A.size(), left = 0, max_len = 0;
        for(int right = 0; right<n; right++){

            // if zero occurs, we will decrease K.
            if(!A[right]) K--;

            // in order to keep atmost K zeros in our window
            // whenever we run out of Ks, we will increase one
            // by dropping one zero from behind
            while(K<0){

            // keep decreasing the window size from behind
            // untill we find a zero and our window has
            // atmost K zeros again
            if(!A[left++]) K++;
            }

            max_len = max(max_len, (right-left)+1);
        }

        return max_len;
    }
};
