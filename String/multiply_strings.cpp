// 43. Multiply Strings

// doesn't work for negative inputs
class Solution {
public:
    string multiply(string num1, string num2) {

        // this will have our ans
        string product(num1.size() + num2.size(), '0');

        for(int i = num1.size() - 1; i>=0; i--){

            for(int j = num2.size() - 1; j>=0; j--){

                // i+j+1 to combat to the some elements that we skip as the j increases
                // and represent them with X

                // we already might be having some value, just adding on it, like we
                // do in the last step of calcuting product
                int sum = (product[i+j+1] - '0') + (num1[i] - '0')*(num2[j] - '0');
                product[i+j+1] = sum%10 + '0';
                product[i+j] += sum/10 ;  // carry
            }

        }

        // deleting leading zeros
        for(int i = 0; i<num1.size() + num2.size(); i++){

            if(product[i]!= '0')
                return product.substr(i);
        }

        return "0";
    }
};
