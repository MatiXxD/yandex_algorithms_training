#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefFunc(std::string s) {

    int n = (int) s.size();
    std::vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {

        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];

        if (s[i] == s[cur])
            p[i] = cur + 1;

    }
    
    return p;

}

int main(){

    std::string str; std::cin >> str;
    std::vector prefArray = prefFunc(str);

    int res;
    if(str.size() == 0) res = 0;
    else if(str.size() == 1) res = 1;
    else res = prefArray[str.size()-1];
    
    std::cout << str.length() - res << std::endl;

    return 0;

}