class Solution {
public:
    int getSum(int a, int b) {
        if(b==0){
            return a;
        }
        int carry = ((a&b)*1u)<<1;
        int sum = a^b;
        do{
            int next_carry = carry & sum;
            sum = sum ^ carry;        //a xor b
            carry = ((next_carry)*1u)<<1;
        }while(carry!=0);

        return sum;
    }
};