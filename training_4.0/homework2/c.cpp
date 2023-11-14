#include <iostream>
#include <vector>
#include <string>

std::vector<int> getFunc(const std::string& str){

    int n = str.size();
    if(!n) return std::vector<int>();

    int l = 0, r = 0;
    std::vector<int> z(n, 0);
    for(int i = 1 ; i < n ; i++){

        if(i < r) z[i] = std::min(r-i, z[i - l]);
        while(i + z[i] < n && str[i+z[i]] == str[z[i]]) z[i]++;
        
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
        
    }

    return std::move(z);

}


int main(){

    std::string str; std::cin >> str;
    std::vector<int> zFunc = getFunc(str);

    for(int val : zFunc)
        std::cout << val << ' ';
    std::cout << std::endl;

    return 0;

}