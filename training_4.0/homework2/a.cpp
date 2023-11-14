#include <iostream>
#include <string>
#include <vector>


void getHashs(const std::string& str, std::vector<long>& hash, std::vector<long>& hashX){

    const long x = 257;
    const long p = 1e9 + 7;

    hash[0] = 0; hashX[0] = 1;
    for(int i = 1 ; i < hash.size() ; i++){
        hash[i] = (hash[i-1]*x + str[i]) % p;
        hashX[i] = (hashX[i-1]*x) % p;
    }

}

int main(){

    std::string str; std::cin >> str;
    str = "0" + str;

    std::vector<long> hash(str.size());
    std::vector<long> hashX(str.size());
    getHashs(str, hash, hashX);

    int q; std::cin >> q;
    for(int i = 0 ; i < q ; i++){

        long a, b, l;
        std::cin >> l >> a >> b;
        a += 1; b += 1;

        if(a + l-1 > str.size()-1 || b + l-1 > str.size()-1) 
            std::cout << "no" << std::endl;
        else{
            long hash1 = (hash[a+l-1] + hash[b-1]*hashX[l]) % int(1e9 + 7);
            long hash2 = (hash[b+l-1] + hash[a-1]*hashX[l]) % int(1e9 + 7);
            if(hash1 == hash2) std::cout << "yes" << std::endl;
            else std::cout << "no" << std::endl;
        }

    }

    return 0;

}