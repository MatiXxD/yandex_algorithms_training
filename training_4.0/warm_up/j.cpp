#include <iostream>

int main(){

    long count; std::cin >> count;

    long a, b, n;
    long groups, extra, delta;
    for(long i = 0 ; i < count ; i++){
        std::cin >> n >> a >> b;
        groups = n / a;
        extra = n % a;
        delta = b - a; 

        if(delta*groups >= extra) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;

    }

    return 0;

}