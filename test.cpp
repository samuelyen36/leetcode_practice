#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
void permutation(std::vector <int> &vec, int start, int end){
    if(start == end){
        //std::cout<<"print out: "<<std::endl;
        for(auto i = vec.begin(); i!=vec.end(); i++){
            std::cout<<(*i)<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    else{
        for(int i = start; i<=end; i++){
            printf("swap %d and %d\n",i ,start);
            std::swap(vec[i],vec[start]);
            permutation(vec, start+1, end);
            std::swap(vec[i],vec[start]);
        }
    }
}

void permute(std::vector<int> a, int l, int r){
    if (l == r){
        for(auto i=a.begin(); i!=a.end();i++){
            std::cout<<*i<<" ";
        }
        std::cout<<std::endl;
    }
    else{
        // Permutations made
        for (int i = l; i <= r; i++){
            std::swap(a[l], a[i]);
            permute(a, l+1, r);
            std::swap(a[l], a[i]);
        }
    }
}

int main(){
    std::vector <int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    auto it = vec.end();
    it--;
    std::cout<< *it <<std::endl;
    return 0;
}