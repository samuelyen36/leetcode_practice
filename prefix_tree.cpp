#include <vector>
#include <string>
using namespace std;
/*
https://leetcode.com/problems/implement-trie-prefix-tree/
208. Implement Trie (Prefix Tree)
*/
class Trie {
public:
    vector<string> dictionary;
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        this->dictionary.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        for(string str: this->dictionary){
            if(word == str){
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        for(string str: this->dictionary){
            string substr = str.substr(0,len);
            if(substr == prefix){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */