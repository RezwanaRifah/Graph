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
	
	int src, dist; cin >> src >> dist;
	
	vector<int> visited(n+1, 0);
	vector<int> dis(n+1, 0);
	vector<int> prev(n+1, 0);
	
	queue<int> q;
	q.push(src);
	visited[src] = 1;
	dis[src] = 0;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(auto v: adj[u]){
			if(visited[v]) continue;
			
			q.push(v);
			visited[v] = 1;
			dis[v] = dis[u] + 1;
			
			prev[v] = u;
		}	
	}
	
	int x = dist;
	vector<int> path;
	
	while(1){
		path.push_back(x);
		
		if(x == src) break;
		
		x = prev[x];
		
	}
	
	reverse(path.begin(),path.end());
	
	for(auto v: path){
		cout << v << " ";
	}
	
	cout << endl;
	
	
	return 0;
	
}