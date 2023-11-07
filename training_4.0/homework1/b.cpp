#include <iostream>
#include <vector>
#include <cstdlib>

typedef std::vector<long>::iterator long_iter;

std::pair<long_iter, long_iter> partition(long_iter l, long_iter r, int x){

    auto equal = l;
    auto greater = l;

    for(auto iter = l ; iter < r ; iter++){
        if(*iter > x) continue;
        else if(*iter == x){
            long temp = *iter;
            *iter = *greater;
            *greater = temp;
            greater++;
        }
        else{
            long temp = *iter;
            *iter = *greater;
            *greater = *equal;
            *equal = temp;
            greater++; equal++;
        }
    }

    return std::pair(equal, greater);

}

void quickSort(long_iter l, long_iter r){

    if(r - l <= 0) return;

    int x = rand() % (r - l);
    auto p = partition(l, r, *(l+x));

    quickSort(l, p.first);
    quickSort(p.second, r);

}

void print(const std::vector<long>& nums){
    for(long num : nums)
        std::cout << num << ' ';
    std::cout << std::endl;
}


int main(){

    int n; std::cin >> n;
    
    std::vector<long> nums(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> nums[i];

    quickSort(nums.begin(), nums.end()); 
    print(nums);

    return 0;

}