#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
/*
496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<unsigned int, unsigned int> u_map;    //val of nums2 and its corresponding greater element
        stack<unsigned int> st;      //keep track of next greater element by examing the top element of stack
        vector<int> res;

        for(int val: nums2){
            while(!st.empty() && st.top() < val){
                u_map[st.top()] = val;
                st.pop();
            }
            st.push(val);
        }

        for(int tmp: nums1){
            if(u_map.find(tmp) != u_map.end()){     //not empty
                res.push_back(u_map[tmp]);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};