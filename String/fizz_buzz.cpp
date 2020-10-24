// 412. Fizz Buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> output(n);

        for(int i = 0; i<n; i++){
            output[i] = to_string(i+1);
        }

        // taking care of indexing
        for(int i = 2; i<n; i+=3){
            output[i] = "Fizz";
        }

        for(int i = 4; i<n; i+=5){
            output[i] = "Buzz";
        }

        for(int i = 14; i<n; i+=15){
            output[i] = "FizzBuzz";
        }

        return output;
    }
};
