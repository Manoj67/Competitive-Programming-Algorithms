#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, e;
bool vis[1234];
vector<int> adj[1234];
int color[1234];

bool dfs(int v){
    for(int i = 0; i < adj[v].size(); ++i){
        int u = adj[v][i];
        if(!vis[u]){
            vis[u] = true; // mark current node as visited
            color[u] = !color[v]; // set color as opposite of parent node
            if(!dfs(u))
                return false;
        }
        else if(color[v] == color[u]) // if same color
            return false; // Not Bipartite
    }
    return true; // else Bipartite
}

int main() {

    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis[0] = true, color[0] = 0; // mark source vertex as visited and set its color to 0
    if(dfs(1))
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
}

/* Input:
    1 2
    2 3
    2 8
    3 4
    4 6
    5 7
    5 9
    8 9
        // if we add "2->4" the graph will be Non-Bipartite
   Output:
    Bipartite
*/
