#include <iostream>
#include <cmath>

int main(){

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int m = a*d + b*c;
    int n = b*d;

    int nod = 1;
    for(int i = std::min(m, n) ; i > 0 ; i--)
        if(!(m % i) && !(n % i)){
            nod = i; break;
        }
    m /= nod; n /= nod;
    std::cout << m << ' ' << n;

    return 0;

}