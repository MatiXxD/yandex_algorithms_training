#include <iostream>
#include <vector>

void partition(std::vector<long>& nums, int x){

    auto equal = nums.begin();
    auto greater = nums.begin();

    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] > x) continue;
        else if(nums[i] == x){
            long temp = nums[i];
            nums[i] = *greater;
            *greater = temp;
            greater++;
        }
        else{
            long temp = nums[i];
            nums[i] = *greater;
            *greater = *equal;
            *equal = temp;
            greater++; equal++;
        }
    }

    std::cout << equal - nums.begin() << std::endl << nums.end() - equal << std::endl;

}


int main(){

    int n; std::cin >> n;
    
    std::vector<long> nums(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> nums[i];

    int x; std::cin >> x;
    partition(nums, x);

    return 0;

}