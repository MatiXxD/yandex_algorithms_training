#include <iostream>

int main(){

    int a, b, n;
    std::cin >> a >> b >> n; 

    if(a > b) std::cout << "Yes" << std::endl;
    else if(a == b){
        if (n == 1) std::cout << "No" << std::endl;
        else std::cout << "Yes" << std::endl;
    }
    else{
        int k = b / n;
        if(b % n) k += 1;
        if(a > k) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }

    return 0;

}