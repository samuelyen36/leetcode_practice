#include <vector>
#include <string>
using namespace std;


class Solution {
private:
    bool search(int x, int y, int pos_of_string, vector<vector<char>>& board, string& word);
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()){
            return true;
        }
        if(board.size()==0 && board[0].size() == 0){
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(search(i, j, 0, board, word) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

bool Solution::search(int x, int y, int pos_of_string, vector<vector<char>>& board, string& word){
    if(x < 0 || y < 0 || x > board.size()-1 || y > board[0].size()-1){
        return false;
    }
    if(board[x][y] != word[pos_of_string]){     //this step doesn't meet the requirement
        return false;
    }

    char c = word[pos_of_string];
    board[x][y] = '\0';
    bool res;
    if( (pos_of_string == word.size()-1) ){
        return true;
    }
    else{
        res = search(x+1, y, pos_of_string+1, board, word) || search(x, y+1, pos_of_string+1, board, word) || search(x, y-1, pos_of_string+1, board, word) || search(x-1, y, pos_of_string+1, board, word);
    }
        
    board[x][y] = c;
    

    return res;
}
