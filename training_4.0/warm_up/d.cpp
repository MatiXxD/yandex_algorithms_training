#include <iostream>
#include <string>
#include <map>

int main(){
    
    std::string str1, str2;
    std::cin >> str1 >> str2;

    std::map<char, int> m1, m2;
    for(char c: str1){ 
        if(!m1.count(c)) m1[c] = 0;
        m1[c] += 1;
    }
    for(char c: str2){ 
        if(!m2.count(c)) m2[c] = 0;
        m2[c] += 1; 
    }

    if(m1 == m2) std::cout << "YES";
    else std::cout << "NO";

}