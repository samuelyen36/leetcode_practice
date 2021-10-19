/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#include <iostream>
using namespace std;


class Solution {
int lower_bound, upper_bound;
public:
    int guessNumber(int n) {
        lower_bound = 1, upper_bound = n;
        while(lower_bound != upper_bound){
            cout<<lower_bound<<"\t"<<upper_bound<<"\n";
            int mean = (upper_bound-lower_bound)/2 + lower_bound;
            int res = guess(mean);
            if(res == 0){
                return mean;
            }
            else if(res == 1){
                lower_bound = (mean+1);
                continue;
            }
            else{       //res == -1, increase the lower bound
                upper_bound = (mean-1);
                continue;
            }
        }
        return lower_bound;
    }
};