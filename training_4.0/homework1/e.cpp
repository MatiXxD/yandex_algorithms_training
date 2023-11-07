#include <iostream>
#include <string>
#include <vector>


void bitSort(std::vector<std::string>& nums){

    int numSize = nums[0].length();
    std::vector<std::vector<std::string>> buckets(10);

    for(int i = 0 ; i < numSize ; i++){
        
        std::cout << "**********\nPhase " << i+1 << std::endl;

        for(int j = 0 ; j < nums.size() ; j++){
            int ind = nums[j][numSize-1-i] - '0';
            buckets[ind].push_back(nums[j]);
        }

        auto iter = nums.begin();
        for(int j = 0 ; j < 10 ; j++){

            std::cout << "Bucket " << j << ':' << ' ';
            if(!buckets[j].size()) std::cout << "empty";
            for(int k = 0 ; k < buckets[j].size() ; k++) {
                std::cout << buckets[j][k];
                if(k != buckets[j].size()-1) std::cout << ", ";
                *iter++ = buckets[j][k];
            }
            std::cout << std::endl;

            buckets[j].clear();

        }

    }

    std::cout << "**********" << std::endl;

}

void print(const std::vector<std::string>& nums){
    for(int i = 0 ; i < nums.size() ; i++){
        std::cout << nums[i];
        if(i != nums.size()-1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(){

    int n; std::cin >> n;
    std::vector<std::string> nums(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> nums[i];

    std::cout << "Initial array:\n"; print(nums);
    bitSort(nums);
    std::cout << "Sorted array:\n"; print(nums);

    return 0;

}