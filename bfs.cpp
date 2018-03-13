#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> adj[10] ;   //Vector for maintaining adjacency list explained above
int level[10]; //To determine the level of each node
bool vis[10]; //Mark the node if visited


void bfs(int s){
	queue <int> q;
	q.push(s);
	level[s] = 0 ;  //Setting the level of the source node as 0
	vis[s] = true;
	while(!q.empty()){
		int p = q.front();
		cout << p << " ";
		q.pop();
		for(int i = 0; i < adj[p].size(); i++){
			if(vis[adj[p][i]] == false){
            //Setting the level of each node with an increment in the level of parent node
				level[adj[p][i]] = level[p]+1;
				vis[adj[p][i]] = true;
				q.push(adj[p][i]);
			}
		}
	}
}

int main(){
	int n,e;
	cin >> n >> e;

	for(int i = 0; i < e; ++i){
		int u, w;
		cin >> u >> w;
		adj[u].push_back(w);
		adj[w].push_back(u);

	}

	bfs(1);
}
