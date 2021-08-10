#include <vector>
#include <iostream>
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int len = height.size()-1;      //total length of array height
        int start=0, end=len;
        int _max = std::min(height[0],height[end]) * len;
        while(start != end){
            int new_volume = (end-start)*std::min(height[start],height[end]);
            std::cout<<_max<<" "<<new_volume<<std::endl;
            _max = std::max( _max, new_volume);
            if(height[start] >= height[end]){
                end--;
            }
            else{
                start++;
            }
        }
        return _max;
    }
};

int main(){
    Solution sol;
    std::vector <int> vec = {1,2,3,4,5,6};
    sol.maxArea(vec);
    return 0;
}