#include <iostream>
#include <climits>
#include <vector>
#include <tuple>

using tpl = std::tuple<int, int, int>;

int minIndex(const std::vector<int>& time, const std::vector<bool>& visited){

    int index, size = time.size();
    for(int i = 1 ; i < size ; i++)
        if(!visited[i]) {
            index = i;
            break;
        }

    for(int i = index ; i < size ; i++)
        if(time[i] < time[index] && !visited[i]) index = i;

    return index;

}

void fillList(std::vector<std::vector<tpl>>& lst, const int r){

    int a, b, t1, t2;
    for(int i = 0 ; i < r ; i++){
        std::cin >> a >> t1 >> b >> t2;
        lst[a].push_back(tpl(b, t1, t2));
    }

}

int main(){

    int n, d, v, r;
    std::cin >> n >> d >> v >> r;

    std::vector<int> time(n+1, INT_MAX); time[d] = 0;
    std::vector<bool> visited(n+1, false);
    std::vector<std::vector<tpl>> lst(n+1);
    fillList(lst, r);

    while(!visited[v]){
        int cur = minIndex(time, visited);
        for(int i = 0 ; i < lst[cur].size() ; i++){
            int neighbor = std::get<0>(lst[cur][i]);
            int t1 = std::get<1>(lst[cur][i]);
            int t2 = std::get<2>(lst[cur][i]);
            if(time[cur] <= t1 && t2 < time[neighbor])
                time[neighbor] = t2;
        }
        visited[cur] = true;
    }

    if(time[v] == INT_MAX) time[v] = -1; 
    std::cout << time[v] << std::endl;

    return 0;

}