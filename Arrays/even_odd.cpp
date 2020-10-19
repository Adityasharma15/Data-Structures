// 922. Sort Array By Parity II

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        int n = A.size();
        // one pointers looks out for eve positions and check if
        // some odd is there and similarly a pointer odd
        for(int eve = 0, odd = 1; eve<n && odd<n ; eve+=2 , odd+=2)         {
           // when we find some odd at eve position
           // eve will point to this
            while(eve<n && A[eve]%2 == 0)
                eve+=2;

            while(odd<n && A[odd]%2 == 1)
                odd+=2;

            // correct if there was some incorrect positions
            if(eve < n && odd < n) swap(A[eve], A[odd]);
        }

        return A;
    }
};
