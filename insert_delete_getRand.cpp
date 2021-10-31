#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    vector<int> vec;
    unordered_map<int, int> u_map;      //key, its idx in vec
public:
    RandomizedSet() {
        u_map.clear();
        vec.clear();
    }
    
    bool insert(int val) {
        if(u_map.find(val) != u_map.end()){     //already exist in the set
            return false;
        }
        else{
            int idx = vec.size();
            vec.push_back(val);
            u_map[val] = idx;
            return true;
        }
    }
    
    bool remove(int val) {
        if(u_map.find(val) == u_map.end()){    //searched item is not in the set
            return false;
        }
        else{
            int last = vec.back();
            u_map[last] = u_map[val];
            vec[u_map[val]] = last;
            vec.pop_back();
            u_map.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */