#include <iostream>
#include <vector>
#include <climits>

int minIndex(const std::vector<int>& dist, const std::vector<bool>& visited){

    int index, size = dist.size();
    for(int i = 1 ; i < size ; i++)
        if(!visited[i]) {
            index = i;
            break;
        }

    for(int i = index ; i < size ; i++)
        if(dist[i] < dist[index] && !visited[i]) index = i;

    return index;

}

int main(){

    int n, s, f;
    std::cin >> n >> s >> f;

    std::vector<std::vector<int>> mat(n+1, std::vector<int>(n+1, -1));
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            std::cin >> mat[i][j];

    std::vector<bool> visited(n+1, false);
    std::vector<int> dist(n+1, INT_MAX); dist[s] = 0; 
    std::vector<int> path(n+1, 0); path[s] = -1;
    
    int pathIndex = 1; 
    while(!visited[f]){
        int cur = minIndex(dist, visited);
        for(int i = 1 ; i < dist.size() ; i++)
            if(mat[cur][i] + dist[cur] < dist[i] && mat[cur][i] != -1){
                dist[i] = mat[cur][i] + dist[cur];
                path[i] = cur;
            }
        visited[cur] = true;
    }
    
    if(dist[f] == INT_MAX) std::cout << -1 << std::endl;
    else{
        std::vector<int> temp;
        int i = f;
        while(i != -1){
            temp.push_back(i);
            i = path[i];
        }
        for(auto iter = temp.rbegin() ; iter < temp.rend() ; iter++)
            std::cout << *iter << ' ';
        std::cout << std::endl;
    }
    

    return 0;

}