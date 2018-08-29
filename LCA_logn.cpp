#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 2e5;
const int LG = 17;
int par[MAXN][LG];
int depth[MAXN];
vector<int> tree[MAXN];

dfs(int cur, int prev){
	depth[cur] = depth[prev] + 1;
	par[cur][0] = prev;

	for(int i = 0; i < tree[cur].size(); ++i){
		if(tree[cur][i] != prev){
			dfs(tree[cur][i], cur);
		}
	}
}

int LCA(int u, int v){
	int lg;
	if(depth[u] < depth[v]) // u must be deeper than v
		swap(u, v);

	for(lg = 0; (1<<lg) <= depth[u]; lg++);
	lg--;

	for(int i=lg; i>=0; i--){
	        if (depth[u] - (1<<i) >= depth[v])
	            u = par[u][i]; // maintaining same level
	}

	if(u==v)
		return u;

	for(int i = lg; i >= 0; --i){
		if(par[u][i] != -1 and par[u][i] != par[v][i]){
			u = par[u][i]; // binary lifting
			v = par[v][i];
		}
	}
	return par[u][0]; // if parent of u and v are same, return one of parent
}

/* get ancestor of node which is 'dis' distance above
int getancestor(int u, int dis){
	dis = depth[u]-dis;

	int lg;
	for(lg = 0; (1<<lg)<=depth[u]; lg++);
	lg--;

	for(int i = lg; i >= 0; --i){
		if(depth[u]-(1<<lg) >= dis)
			u = par[u][i];
	}
	return u;
}
*/

int main(){
	int n;
	cin >> n;

	int e = n-1;
	cout << "enter edges" << endl;
	while(e--){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	memset(par, -1, sizeof(par));

	depth[0] = -1;
	dfs(1, 0);

	// storing parent of nodes
	for(int node = 1; node <= LG; ++node){
		for(int i = 1; i <= n; ++i){
			if(par[node][i-1] != -1){
				par[node][i] = par[par[node][i-1]][i-1];
			}
		}
	}

	int u, v;
	cout << "enter values to find the ancestor of " << endl;
	cin >> u >> v;
	cout <<"ancestor is "<< LCA(u, v) << endl;

	int p, q;
	cout << "enter the values to find distance between them" << endl;
	cin >> p >> q;
	int dis = depth[p]+depth[q]-2*depth[LCA(p, q)];
	cout << "distance is " << dis << endl;

}
