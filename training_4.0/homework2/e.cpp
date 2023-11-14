#include <iostream>
#include <string>
#include <vector>


void modifyString(std::string& str){

    std::vector<char> temp;
    temp.push_back('$');
    for(char ch : str){
        temp.push_back(ch);
        temp.push_back('$');
    }

    str = std::string(temp.begin(), temp.end());

}

int main(){

    std::string str; std::cin >> str;
    modifyString(str);

    int n = str.size();
    int l = 0, r = 0;
    std::vector<int> pr(n, 1);
    for(int i = 1 ; i < n ; i++){
        if(i < r) pr[i] = std::min(r - i + 1, pr[l + r - i]);
        while(i-pr[i] >= 0 && i+pr[i] < n && str[i-pr[i]] == str[i+pr[i]]) 
            pr[i]++;

        if(i + pr[i] - 1> r){
            l = i - pr[i] + 1;
            r = i + pr[i] - 1;
        }

    }

    long long answer = 0;
    for(int val : pr) answer += val / 2;
    std::cout << answer << std::endl;

    return 0;

}