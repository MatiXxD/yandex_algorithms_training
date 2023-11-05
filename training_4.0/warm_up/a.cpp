#include <iostream>
#include <vector>
#include <set>

int main(){

    int n, m;
    std::cin >> n >> m;

    std::vector<int> nums(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> nums[i]; 
    }

    for(int i = 0 ; i < m ; i++){
        
        int a, b; std::cin >> a >> b;
        if(b <= a) {
            std::cout << "NOT FOUND\n";
            continue;
        }

        std::set<int, std::greater<int>> temp(nums.begin() + a, nums.begin() + b+1);
        if(temp.size() <= 1) std::cout << "NOT FOUND\n";
        else std::cout << *temp.begin() << std::endl;        

    }

    return 0;

}