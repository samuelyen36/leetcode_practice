#include <vector>
using namespace std;

class Solution {
public:
    int recur_find(vector<int>&, int, int);
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        else if(nums.size()==2){
            if(nums[0] > nums[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return recur_find(nums, 0, nums.size()-1);
        }
    }
};

int Solution::recur_find(vector<int> &vec, int start, int end){     //return the index
    //cout<<start<<"\t"<<end;
    if(start ==end){        //terminate
        return start;
    }
    else {          //if(start < end)
        int mid = start + (end-start)/2;
        //cout<<"\tmid is: "<<mid<<endl;
        if(mid == 0 || mid == vec.size()-1){
            return mid;
        }
        else{
            if(vec[mid-1] < vec[mid] && vec[mid+1] < vec[mid]){     //peak
                return mid;
            }
            else if(vec[mid-1] > vec[mid] && vec[mid-1] > vec[mid+1]){
                return recur_find(vec, start, mid);
            }
            else {
                return recur_find(vec, mid+1, end);
            }
        }
    }
}

int main(){
    return 0;
}