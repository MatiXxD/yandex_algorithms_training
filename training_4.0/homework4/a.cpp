#include <iostream>
#include <vector>
#include <algorithm>

void printVec(const std::vector<int>& vec){
    for(int x : vec) std::cout << x;
    std::cout << std::endl;
}

void printPermutations(int n, int m, std::vector<int>& prefix){

    if(m == 0) {
        printVec(prefix);
        return;
    }

    for(int num = 1 ; num <= n ; num++){
        if(std::find(prefix.begin(), prefix.end(), num) != prefix.end()) continue;
        prefix.push_back(num);
        printPermutations(n, m-1, prefix);
        prefix.pop_back();
    }

}

int main(){

    int n; std::cin >> n;
    std::vector<int> prefix;
    printPermutations(n, n, prefix);

    return 0;

}