#include <iostream>
#include <map>

using mp = std::map<int, int>;

void findCount(int& count, int n, int col, int row, int rowsMask, std::pair<mp, mp>& diag){

    if(diag.first[row + col] > 1 || diag.second[row - col] > 1){
        return;
    }
    if(col == n){
        count++;
        return;
    }

    for(int i = 1 ; i <= n ; i++){
        if(!(rowsMask & (1 << i))){
            rowsMask |= (1 << i);
            diag.first[i + col + 1] += 1;
            diag.second[i - col - 1] += 1;
            findCount(count, n, col+1, i, rowsMask, diag);
            rowsMask &= ~(1 << i);
            diag.first[i + col + 1] -= 1;
            diag.second[i - col - 1] -= 1;
        }
    }

}

int main(){

    int n; std::cin >> n;
    
    int count = 0;
    std::pair<mp, mp> diag;
    findCount(count, n, 0, 0, 0, diag);
    std::cout << count << std::endl;

    return 0;

}