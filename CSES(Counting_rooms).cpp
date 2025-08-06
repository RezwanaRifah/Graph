// Time: 2025-08-07 00:12:06
// Problem: Counting Rooms
// URL: https://cses.fi/problemset/task/1192
// TL: 1000ms ML: 512MB


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	
	char grid[n][m];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	int visited[n][m];
	memset(visited, 0, sizeof visited);
	
	int count = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] || grid[i][j] == '#'){
				continue;
			}
			
			count ++;
			
			queue <pair<int, int>> q;
			q.push({i, j});
			visited[i][j] = 1;
			
			while(!q.empty()){
				pair<int, int> u ; 
				u = q.front();
				q.pop();
				
				int x = u.first;
				int y = u.second;
				
				if(x-1 >= 0){
					if(grid[x-1][y] == '.' && visited[x-1][y] == 0){
						q.push({x-1,y});
						visited[x-1][y]= 1;
					}
				}
				if(y+1 < m){
					if(grid[x][y + 1] == '.' && visited[x][y + 1] == 0){
						q.push({x,y + 1});
						visited[x][y + 1]= 1;
					}
				}
				
				if(x + 1 < n){
					if(grid[x + 1][y] == '.' && visited[x + 1][y] == 0){
						q.push({x + 1,y});
						visited[x + 1][y]= 1;
					}
				}
				
				if(y-1 >= 0){
					if(grid[x][y-1] == '.' && visited[x][y-1] == 0){
						q.push({x,y-1});
						visited[x][y-1]= 1;
					}
				}
				
				
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}