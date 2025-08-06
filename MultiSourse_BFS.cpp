#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >>m;
	vector<int> adj[n+1];
	
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int k; cin >> k;
	int fire[k];
	
	for(int i = 0; i <k; i++){
		cin >> fire[i];
	}
	
	vector<int> visited(n+1, 0);
	vector<int> dis(n+1, 0);
	queue<int> q;
	
	int ans = 0;
	
	for(int i = 0; i <k; i++){
		q.push(fire[i]);
		visited[fire[i]] = 1;
		dis[fire[i]] = 0;
	}
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(auto v: adj[u]){
			if(visited[v]) continue;
			
			visited[v] = 1;
			q.push(v);
			dis[v] = dis[u] + 1;
			
			ans = max(ans, dis[v]);
		}
	}
	
	cout << ans << endl;
	
	
	
}