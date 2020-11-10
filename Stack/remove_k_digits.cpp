// 402. Remove K Digits

class Solution {

  // Solution using stack
  // we will iterate string from start
  // push into stack if stack is empty or current
  // element is greater than top.

public:
    string removeKdigits(string num, int k) {

        int n = num.size();
        stack<int> digits;
        for(int i = 0; i<n; i++){

            int curr_digit = num[i] - '0';
            // while top is greater than current, remove it
            while(!digits.empty() && digits.top()>curr_digit && k){
                digits.pop();
                k--;
            }
            digits.push(curr_digit);
        }

        while(!digits.empty() && k){
            digits.pop();
            k--;
        }

        stack<int> reverse_digits;
        while(!digits.empty()){
            reverse_digits.push(digits.top());
            digits.pop();
        }

        // removie leading zeros
        while(!reverse_digits.empty() && reverse_digits.top()==0){
            reverse_digits.pop();
        }

        string smallest = "";
        while(!digits.empty()){
            reverse_digits.push(digits.top());
            digits.pop();
        }

        while(!reverse_digits.empty()){
            char curr_digit = reverse_digits.top() + '0';
            smallest += curr_digit;
            reverse_digits.pop();
        }

        if(smallest.size() == 0)
            return "0";

        return smallest;
    }
};
