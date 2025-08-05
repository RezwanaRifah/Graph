#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , m; cin >> n >> m;
	vector<int> adj[n+1];
	
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " "; // Print all adjacent vertices
        }
        cout << endl;
    }
    
    cout << endl;
	
	int src = 1;
	int visited[n+1] = {0};
	int level[n+1];
	queue<int> q;
	
	q.push(src);
	visited[src]= 1;
	level[src] = 0;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(auto v:adj[u]){
			if(visited[v]) continue;
			
			visited[v] = 1;
			level[v] = level[u] + 1;
			q.push(v);
		}
	}
	
	cout << endl;
	
	for(int i = 1; i <= n; i ++){
		cout << i << "-->" << level[i] << endl;
	}
	
	cout << endl;
	
	for(int i = 1; i <= n; i ++){
		cout << i << "-->" << visited[i] << endl;
	}
	
	cout << endl;
	
	int flag = 0;
	for(int i = 1; i <= n; i++){
		
		cout << i << " " << visited[i] << endl;
		if(visited[i] == 0){
			flag++;
			break;
		}
	}
	
	if(n == m+ 1 && flag == 0) cout << "Tree" << endl;
	else cout << "Not Tree" << endl;
	
	return 0;
	
}