#include <iostream>
#include <vector>
#include <map>
#include <climits>

typedef std::pair<long long, long long> myPair;


void fillList(std::vector<std::vector<myPair>>& lst, const int k){

    int a, b, l;
    for(int i = 0 ; i < k ; i++){
        std::cin >> a >> b >> l;
        lst[a].push_back(myPair(b, l));
        lst[b].push_back(myPair(a, l));
    }

}


int main(){
    
    int n, k, a, b;
    std::cin >> n >> k;

    std::vector<std::vector<myPair>> lst(n+1);
    fillList(lst, k);
    std::cin >> a >> b;

    std::vector<bool> visited(n+1, false);
    std::vector<long long> dist(n+1, LONG_LONG_MAX); dist[a] = 0; 
    std::multimap<long long, long long> distMap; distMap.insert({0, a});

    while(!visited[b] && !distMap.empty()){
        auto curIter = distMap.begin();
        int cur = (*curIter).second;
        for(int i = 0 ; i < lst[cur].size() ; i++){
            int neighbor = lst[cur][i].first;
            int weight = lst[cur][i].second;
            if(dist[cur] + weight < dist[neighbor]){
                long long temp = dist[neighbor];
                dist[neighbor] = dist[cur] + weight;
                for (auto[itr, rangeEnd] = distMap.equal_range(temp); itr != rangeEnd; itr++) {
                    if((*itr).second == neighbor) {
                        distMap.erase(itr);
                        break;
                    }
                }
                distMap.insert({dist[neighbor], neighbor});
            }
        }
        visited[cur] = true; 
        distMap.erase(curIter);
    }

    if(dist[b] == LONG_LONG_MAX) dist[b] = -1; 
    std::cout << dist[b] << std::endl;

    return 0;

}
