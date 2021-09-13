#include <unordered_map>
#include <vector>
using namespace std;
/*
207. Course Schedule
https://leetcode.com/problems/course-schedule/
*/
class Solution {
private:
    vector<bool> visited;
    vector<bool> onPath;
    unordered_map<int, vector<int>> req;        //used for storing adj vector
    bool hascycle = false;

    void buildgraph(vector<vector<int>>& prerequisites);
    void dfs(int k);
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);      //initialize the vector
        onPath = vector<bool>(numCourses, false);
        buildgraph(prerequisites);
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        if(hascycle){
            return false;
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};




void Solution::buildgraph(vector<vector<int>>& prerequisites){
    int i=0;
    for(vector<int> tmp: prerequisites){
            int tk = tmp[0];
            int pre = tmp[1];
            if(req.count(tk) == 0){      //if it's never been access before
                req[tk] = vector<int>();
            }
            req[tk].push_back(pre);
    }
    return;
}

void Solution::dfs(int k){
    this->visited[k] = true;
    this->onPath[k] = true;
    vector<int> tmp = this->req[k];

    for(int w: tmp){
        if(this->hascycle){
            return;
        }
        else if(!this->visited[w]){
            dfs(w);
        }
        else if(this->onPath[w]){
            this->hascycle = true;
        }  
    }
    this->onPath[k] = false;
}