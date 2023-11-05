#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<int> nums(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> nums[i];
    
    std::vector<int> sums(nums.begin(), nums.end());
    for(int i = 1 ; i < n ; i++)
        sums[i] += sums[i-1];

    for(int i = 0 ; i < n ; i++){
        if(i == 0) 
            std::cout << sums[n-1] - n*nums[i] << ' '; 
        else 
            std::cout << (i+1)*nums[i] - sums[i] - (n - i - 1) * nums[i] + (sums[n-1] - sums[i]) << ' ';
    }
    std::cout << std::endl;

    return 0;

}