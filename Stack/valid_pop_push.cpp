// 946. Validate Stack Sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // consider pushed as a stack in order to save O(n) space , and we will
        // do operations on it and find if popped sequence can be generated

        // stack_ptr points to stack top in the array pushed
        // output_ptr points to sequence of output we are lookin currently
        int stack_ptr = 0, output_ptr = 0;

        // this loop will run for all the inputs, from pushed vector
        for(auto input : pushed){

            // subsequently we will turn the earlier part of vector to stack,
            pushed[stack_ptr++] = input ;

            // while top of stack is equal to output, keep popping
            while(stack_ptr>0 && pushed[stack_ptr-1] == popped[output_ptr]){
                stack_ptr--;
                output_ptr++;
            }
        }

        // if the stack is empty, return true;
        return stack_ptr==0;
    }
};
