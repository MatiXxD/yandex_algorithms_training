#include <iostream>
#include <stack>
#include <map>

int main(){

    std::string s;
    std::cin >> s;

    std::map<char, char> mp;
    mp = {{'(', ')'},
          {'[', ']'},
          {'{', '}'}};
    
    std::stack<char> buff;
    for(char ch : s){
        if(ch == '(' || ch == '[' || ch == '{')
            buff.push(ch);
        else{
            if(buff.size() == 0){
                buff.push(ch); break;
            }
            else if(mp[buff.top()] == ch)
                buff.pop();
            else
                buff.push(ch);
        }
    }

    if(buff.size() == 0) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;

    return 0;

}