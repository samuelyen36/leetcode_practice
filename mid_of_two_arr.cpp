#include <iostream>
#include <vector>

class Solution {
public:
    std::vector <int> merge_to_len_n(std::vector <int> &nums1, std::vector <int> &nums2, int len){
        std::vector <int> tmp;
        auto it_1 = nums1.begin();
        auto it_2 = nums2.begin();
        for(int i=0; i<len; i++){
            if(it_1 == nums1.end() && it_2 != nums2.end()){        //vector1 has been finished
                tmp.push_back((*it_2));
                it_2++;
                continue;
            }

            if(it_2 == nums2.end() && it_1 != nums1.end()){
                tmp.push_back((*it_1));
                it_1++;
                continue;
            }

            if((*it_1) < (*it_2)){
                tmp.push_back((*it_1));
                it_1++;
            }
            else{
                tmp.push_back((*it_2));
                it_2++;
            }
        }

        return tmp;
    }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        int total_length = len_1 + len_2;
        std::cout<<"length is: "<<total_length<<std::endl;
        std::vector <int> sorted = merge_to_len_n(nums1, nums2, (total_length/2)+1);

        if(total_length % 2 ==0){       //length is even, do the average
            std::cout<<"divide two number\n";
            int mid = total_length/2;
            return (double(sorted[mid] + sorted[mid-1])/2);
        }
        else{       //length is odd
            std::cout<<"return single number\n";
            return double(sorted[(total_length-1)/2]);
        }
    }
};

int main(){
    Solution sol;
    std::vector <int> vec1;
    std::vector <int> vec2;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(7);
    vec1.push_back(10);
    vec2.push_back(1);
    sol.findMedianSortedArrays(vec1,vec2);
}