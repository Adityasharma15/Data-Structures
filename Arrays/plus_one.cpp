// 66. Plus One

class Solution {

// Solving this as plus one for Linked List(Locked problem)

// There are few conditions, if the last element is not 9
// simply increment is, otherwise find the last non 9 element
// and increment it and turn everything in front of it as 0
// append one more 0 at end, if not able to find any non
// 9, append 1 in front and change everything to 0.

public:
    vector<int> plusOne(vector<int>& digits) {

        int last_non9 = -1;
        int n = digits.size();

        for(int i = 0; i<n; i++){

            if(digits[i]!=9)
                last_non9 = i;
        }

        int last_digit = digits[n-1];

        // if last digit is not 9, just increment it
        if(last_digit !=9){
            digits[n-1]++;
            return digits;
        }

        // if there is some digit which is not 9
        if(last_non9 != -1){
            digits[last_non9]++;

            for(int i = last_non9+1; i<n; i++)
                digits[i] = 0;

            return digits;
        }

        // now if there is no non 9 number

        digits[0] = 1;

        for(int i = 1; i<n; i++)
            digits[i] = 0;

        digits.push_back(0);
        return digits;
    }
};
