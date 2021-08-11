#include <iostream>
#include <vector>
#include <string>
/*22. Generate Parentheses   https://leetcode.com/problems/generate-parentheses/*/
class Solution {
public:
    void recursive_sol(std::vector<std::string> &res, std::string current_string, int n, int m);

    std::vector<std::string> generateParenthesis(int n) {
        std::vector <std::string> res;
        std::string str;

        recursive_sol(res, "", n, 0);

        return res;
    }

    
};

void Solution::recursive_sol(std::vector<std::string> &res, std::string current_string, int n, int m){       //n: ( that remains to be printed,     m: ) that have to be printed in order to match printed(
    if(n==0 && m==0){
        //std::cout<<"Going to push the following string back to vector: "<<current_string<<std::endl;
        res.push_back(current_string);
        return;
    }
    
    if(n>0){
        recursive_sol(res, current_string + '(', n-1, m+1);
    }
    if(m>0){
        recursive_sol(res, current_string + ')', n, m-1);
    }

    return;
}

int main(void){
    Solution sol;
    sol.generateParenthesis(3);

    return 0;
}