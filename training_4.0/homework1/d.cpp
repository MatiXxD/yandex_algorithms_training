#include <iostream> 
#include <vector> 
 
typedef std::vector<long>::iterator long_iter; 
 
void merge(long_iter l1, long_iter r1, long_iter l2, long_iter r2, long_iter buff) { 
 
    while (l1 != r1 && l2 != r2) { 
        if (*l1 <= *l2) 
            *buff++ = *l1++; 
        else 
            *buff++ = *l2++; 
    } 
 
    while (l1 != r1) *buff++ = *l1++; 
    while (l2 != r2) *buff++ = *l2++; 
 
} 
 
std::vector<long> mergeSort(long_iter l, long_iter r) { 
 
    if (r - l == 1) return std::vector<long>{*l}; 
 
    int size = r - l; 
    auto larr = mergeSort(l, l + size / 2); 
    auto rarr = mergeSort(l + size / 2, r); 
 
    std::vector<long> merged(larr.size() + rarr.size()); 
    merge(larr.begin(), larr.end(), rarr.begin(), rarr.end(), merged.begin()); 
 
    return merged; 
 
} 
 
void print(const std::vector<long>& nums) { 
    for (long num : nums) 
        std::cout << num << ' '; 
    std::cout << std::endl; 
} 
 
 
int main() { 
 
    int n; std::cin >> n; 
 
    if (n != 0) { 
        std::vector<long> nums(n); 
        for (int i = 0; i < n; i++) 
            std::cin >> nums[i]; 
 
        auto sorted = mergeSort(nums.begin(), nums.end()); 
        print(sorted); 
    } 
 
    return 0; 
 
}
