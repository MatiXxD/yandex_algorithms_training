#include <iostream>
#include <vector>
#include <iomanip>

int main(){

    int n;
    long k;
    std::cin >> k >> n;

    std::vector<long> nums(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> nums[i];

    long double resTime = 0; int top = n - 1;
    while(top >= 0){
        
        if(nums[top] > k){
            resTime += 2 * (nums[top] / k) * (top+1);
            nums[top] = nums[top] % k;
        }
        while(nums[top] == 0) top--;
        resTime += 2 * (top+1);

        long temp = 0;
        while(temp != k){
            if(top == -1) break;

            if(nums[top] <= k - temp){
                temp += nums[top];
                nums[top--] = 0;
            }
            else{
                nums[top] -= k - temp;
                temp = k;
            }
        }
        
    }
    std::cout << std::fixed << std::setprecision(0) << resTime << std::endl;

    return 0;

}