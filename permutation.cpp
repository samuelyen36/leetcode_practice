#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        permutation(nums, 0, nums.size()-1, res);
        return res;
    }

    void permutation(std::vector <int> &vec, int start, int end, std::vector <std::vector<int>> &res){
        if(start == end){
            for(auto i = vec.begin(); i!=vec.end(); i++){
                std::cout<<*i<<" ";
            }
            std::cout<<std::endl;
            std::vector <int> tmp;
            tmp.assign(vec.begin(),vec.end());
            res.push_back(tmp);
            return;
        }
        else{
            for(int i = start; i<=end; i++){
                std::swap(vec[i],vec[start]);
                permutation(vec, start+1, end, res);
                std::swap(vec[i],vec[start]);
            }
        }
        return;
    }
};

int main(){
    std::vector <int> vec;
    std::vector<std::vector<int>> res;
    Solution tmp;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    tmp.permutation(vec, 0, vec.size()-1, res);
    //permutation(vec, 0, vec.size()-1, res);
    //std::string tmp = "abc";
    //permute("abc", 0, tmp.size()-1);
    return 0;
}