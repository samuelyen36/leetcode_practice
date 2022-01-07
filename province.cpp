#include <vector>
using namespace std;
class Solution {
private:
    int *disjoint_set;
    void _union(int , int);
    int find(int);
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int counter=0;
        disjoint_set = new int[isConnected[0].size()];
        for(int i=0; i<isConnected[0].size(); i++){
            disjoint_set[i] = i;        //initialize the disjoint set array
        }

        for(int i=0; i<isConnected[0].size(); i++){
            for(int j=i+1; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    _union(i ,j);
                }
            }
        }

        for(int i=0; i<isConnected[0].size(); i++){
            if(disjoint_set[i] == i){
                counter++;
            }
        }

        delete []disjoint_set;
        return counter;
    }
};

int Solution::find(int idx){
    if(this->disjoint_set[idx] == idx){
        return idx;
    }
    else{
        return find(this->disjoint_set[idx]);
    }
}

void Solution::_union(int x, int y){
    int rootx = this->find(x);
    int rooty = this->find(y);
    this->disjoint_set[rootx] = rooty;      
    return;
}