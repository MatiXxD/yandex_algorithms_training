#include <iostream>
#include <iomanip>
#include <cmath>

long double abs(long double x){
    if(x < 0.0L) return -x;
    else return x;
}

int main(){

    constexpr long double PI = 3.14159265359L; 

    long int x_a, y_a, x_b, y_b;
    std::cin >> x_a >> y_a >> x_b >> y_b;

    long double r_a = sqrt(x_a*x_a + y_a*y_a), r_b = sqrt(x_b*x_b + y_b*y_b);
    long double theta_a = atan2(y_a, x_a), theta_b = atan2(y_b, x_b);

    long double theta = abs(theta_a - theta_b);
    if(theta > PI) theta = 2*PI - theta;

    long double r1 = abs(r_a - r_b);
    long double rMin = std::min(r_a, r_b);
    long double r2 = rMin * std::min(theta, 2.0L);

    std::cout << std::fixed;
    std::cout << std::setprecision(12) <<  r1+r2 <<  std::endl;

    return 0;

}