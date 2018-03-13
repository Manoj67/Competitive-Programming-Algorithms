#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <int> adj[10];   //Vector for maintaining adjacency list explained above
int level[10]; //To determine the level of each node
bool vis[10];

void dfs(int s) {
	vis[s] = 1;
	cout << s << " ";
	for(int i = 0; i < adj[s].size(); ++i){
		if(!vis[adj[s][i]])
			dfs(adj[s][i]);
	}
}

int main(){
	int n, e; // nodes and edges
	cin >> n >> e;
	for(int i = 0; i < e; ++i){
		int u, w;
		cin >> u >> w;
		adj[u].push_back(w);
		adj[w].push_back(u);
	}
	dfs(3);
}
