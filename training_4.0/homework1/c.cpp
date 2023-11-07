#include <iostream>
#include <vector>

typedef std::vector<long>::iterator long_iter;

void merge(long_iter l1, long_iter r1, long_iter l2, long_iter r2, long_iter buff){

    while(l1 != r1 && l2 != r2){
        if(*l1 <= *l2) 
            *buff++ = *l1++;
        else
            *buff++ = *l2++;
    }

    while(l1 != r1) *buff++ = *l1++;
    while(l2 != r2) *buff++ = *l2++;

}


int main(){

    int n; std::cin >> n; 
    std::vector<long> v1(n);
    for(int i = 0 ; i < n ; i++)
        std::cin >> v1[i];    

    int m; std::cin >> m; 
    std::vector<long> v2(m);
    for(int i = 0 ; i < m ; i++)
        std::cin >> v2[i];

    std::vector<long> merged(n+m);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin());

    for(long num : merged)
        std::cout << num << ' ';
    std::cout << std::endl;

    return 0;

}