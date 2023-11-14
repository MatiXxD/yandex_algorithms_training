#include <iostream>
#include <string>
#include <vector>


void getHashs(const std::vector<long>& nums, std::vector<long>& hash, std::vector<long>& hashX, int m){

    const long p = 1e9 + 7;
    const long x = m + 1;

    int n = nums.size()+1;

    hash = std::vector<long>(n); hash[0] = 0;
    hashX = std::vector<long>(n); hashX[0] = 1;
    for(int i = 1 ; i < n ; i++){
        hash[i] = (hash[i-1] * x + nums[i-1]) % p;
        hashX[i] = (hashX[i-1] * x) % p;
    }

}


int main(){

    const long p = 1e9 + 7;
    int n, m; std::cin >> n >> m;
    
    std::vector<long> nums(n);    
    for(int i = 0 ; i < n ; i++) std::cin >> nums[i];
    std::vector<long> numsRev(nums.rbegin(), nums.rend());
    
    std::vector<long> hash, hashRev, hashX;
    getHashs(nums, hash, hashX, m);
    getHashs(numsRev, hashRev, hashX, m);

    int size = nums.size();
    std::vector<int> res;
    for(int i = 0 ; i <= size / 2; i++){

        int l = std::min(i, size-i);
        int a = i, b = size - i;

        long hash1 = (hash[a+l] + hashRev[b]*hashX[l]) % p;
        long hash2 = (hashRev[b+l] + hash[a]*hashX[l]) % p;

        if(hash1 == hash2) res.push_back(b);

    }

    for(auto i = res.rbegin() ; i < res.rend() ; i++)
        std::cout << *i << ' ';
    std::cout << std::endl;

    return 0;

}
