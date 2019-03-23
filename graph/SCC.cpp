#include<iostream>
#include<vector>

using namespace std;

#define ll long long

const int MAX = 1e5+5;
const int mod = 1e9+7;

vector<int> g[MAX], gr[MAX];
bool vis[MAX];
vector<int> order, component;

void dfs1(int v){
    vis[v]= true;
    for(int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(!vis[to])
            dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v){
    vis[v] = true;
    component.push_back(v);
    for(int i = 0; i < gr[v].size(); ++i){
        int to = gr[v][i];
        if(!vis[to])
            dfs2(to);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u); 
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs1(i);
    }

    for(int i = 1; i <= n; ++i){
        vis[i] = 0;
    }
    int count = 0;
    for(int i = 1; i <= n; ++i){
        int v = order[n-i];
        if(!vis[v]){    
            dfs2(v);    
            count++;
            //component.clear();
        }
    }
    cout << count << endl;
}
