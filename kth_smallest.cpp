#include <vector>
using namespace std;
/*
https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
668. Kth Smallest Number in Multiplication Table
*/
class Solution {
private:
    int count(int m, int n, int t);     //count the number that are smaller than t
public:
    int findKthNumber(int m, int n, int k) {        //m-> number of rows, n-> number of columns
        int lower = 1;
        int upper = m*n;

        while(lower <= upper){
            int mid = ((upper-lower)/2+lower);
            if(lower == upper){
                return lower;
            }
            

            if(count(lower, upper, mid) < k){
                lower = mid+1;
                continue;
            }
            else{
                upper = mid;
                continue;
            }
        }
        return lower;
    }
        /*int findKthNumber(int m, int n, int k) 
    {
        int l=1;    //The minimum number at Kth position could be 1
        int r=m*n;  //  And the maximum number at Kth positon could be m*n
        while(l<=r)
        {
            printf("%d %d \n",l, r);
            int mid=l+(r-l)/2;
            if(l==r)
            {
                return l;
            }
            if(count(m,n,mid)<k)       //if number of elements less than mid is lesser than k , then we should find the new value on the right of mid
            {
                l=mid+1;
            }
            else
            {
              r=mid;       //else we should find on the left of mid. 
            } 
        }
        return l;
    }*/
};


int Solution::count(int m, int n, int t){
    int res=0;
    for(int i=1; i<=m; i++){
        if(i*n < t){        //elements of this row is not larger that T
            res += n;
        }
        else{
            res += t/i;
        }
    }
    return res;
}