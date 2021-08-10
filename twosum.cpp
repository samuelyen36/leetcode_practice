#include <cstdio>

#include <iostream>
#include <map>
#include <vector>
class Solution {
public:
    std::vector <int> twoSum(std::vector <int>& nums, int target) {
        std::vector <int> sol;
        std::map <int, int> hashmap;            //content, idx
        auto hashmap_it = hashmap.begin(); 
        std::cout<<"size of nums is: "<<nums.size()<<std::endl;
        for (auto _it = 0; _it < nums.size(); _it++){
            //hashmap.insert(std::pair(<int, char>((*it), 't')) );
            hashmap.insert(hashmap_it, std::pair <int, char>(nums[_it], _it));
        }

        for (auto i = 0; i < nums.size(); i++){
            auto residual = target - nums[i];
            auto ptr = hashmap.find(residual);
            if (ptr == hashmap.end()){
                //printf("not found\n");
            }
            else{
                if(ptr->second == i){     //to avoid matching itself twice
                    continue;
                }
                printf("find with %d and %d\n", nums[i], residual);
                for(auto k = 0; k < nums.size(); k++){
                    if(nums[k] == residual){
                        sol.push_back(k);
                        break;
                    }
                }
                sol.push_back(i);
                //sol.push_back(ptr->second);
                break;
            }
        }
        return sol;
    }
};


int main(void){
    Solution tmp;
    std::vector <int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(7);

    std::vector <int> res = tmp.twoSum(vec,8);
    printf("%d\t%d\n", res[0], res[1]);
    return 0;
}