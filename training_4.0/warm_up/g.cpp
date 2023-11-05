#include <iostream>
#include <vector>

void getSums(const std::vector<std::vector<int>>& field, std::vector<std::vector<int>>& sums){

    int n = field.size();
    int m = field[0].size();

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == 0 && j == 0) 
                sums[i+1][j+1] = field[i][j];
            else if(i == 0)
                sums[i+1][j+1] = sums[i+1][j] + field[i][j];
            else if(j == 0)
                sums[i+1][j+1] = sums[i][j+1] + field[i][j];
            else
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] + field[i][j] - sums[i][j];
        }
    }
   
}

int main(){

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> field(n, std::vector<int>(m));    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            std::cin >> field[i][j];

    std::vector<std::vector<int>> sums(n+1, std::vector<int>(m+1));
    getSums(field, sums);

    int max = 0; int mn = std::min(m, n); 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            for(int k = 1; k <= mn ; k++){
                if(i+k-1 > n || j+k-1 > m) break;

                int localSum = sums[i+k-1][j+k-1] + sums[i-1][j-1] - sums[i-1][j+k-1] - sums[i+k-1][j-1];
                if(k*k == localSum)
                    if (k > max) max = k;
                else if (k*k > localSum) break;
            }
        }
    }
    std::cout << max << std::endl;

    return 0;

}