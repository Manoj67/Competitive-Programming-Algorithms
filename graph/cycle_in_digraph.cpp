#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[1234];
bool vis[1234];

bool dfs(int node, int parent){
    vis[node] = 1;
    for(int i = 0; i < adj[node].size(); ++i){
        int current = adj[node][i];
        if(!vis[current]){
            if(dfs(current, node)){
                return true;
            }
        }
        else if(current != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            if(dfs(i, -1))
                cout << "cyclic" << endl;
            else
                cout << "acyclic" << endl;
        }
    }
}
