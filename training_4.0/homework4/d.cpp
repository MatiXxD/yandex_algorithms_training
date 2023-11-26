#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void findBest(int& best, int curPath, std::vector<int>& path, const std::vector<std::vector<int>>& mat){

	int cur = path[path.size() - 1];
	if(path.size() == mat.size()){
		if(mat[cur][0] && curPath + mat[cur][0] < best) 
			best = curPath + mat[cur][0];
		return;
	}

	if(curPath >= best){
		return;
	}

	for(int i = 0 ; i < mat[cur].size() ; i++){
		if(mat[cur][i] && std::find(path.begin(), path.end(), i) == path.end()){
			path.push_back(i);
			findBest(best, curPath+mat[cur][i], path, mat);
			path.pop_back();
		}
	}

}


int main(){

	int n; std::cin >> n;
	std::vector<std::vector<int>> mat(n, std::vector<int>(n));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				std::cin >> mat[i][j];
				
	if(n > 1){
		std::vector<int> path; path.push_back(0);
		int best = std::numeric_limits<int>::max(); findBest(best, 0, path, mat);
		if (best == std::numeric_limits<int>::max()) best = -1;
		std::cout << best << std::endl;
	}
	else{
		std::cout << 0 << std::endl;
	}

	return 0;

}