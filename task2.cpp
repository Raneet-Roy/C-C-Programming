#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge{
    int u, v, w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    vector<Edge> edges(m);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u-1, v-1, w};
        graph[u-1].push_back({v-1, w});
        graph[v-1].push_back({u-1, w});
    }

    // Dijkstra's Algorithm
    int source;
    cin >> source;
    source--;

    vector<int> dist(n, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto p: graph[u]){
            int v = p.first;
            int w = p.second;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");

    // Kruskal's Algorithm
    sort(edges.begin(), edges.end(), cmp);
    vector<Edge> mst;
    makeSet(n);

    for(auto e: edges){
        int u = e.u;
        int v = e.v;
        int w = e.w;

        int setU = findSet(u);
        int setV = findSet(v);

        if(setU != setV){
            mst.push_back({u, v, w});
            unionSet(setU, setV);
        }
    }

    for(auto e: mst){
        printf("(%d, %d) -> %d\n", e.u+1, e.v+1, e.w);
    }
    printf("\n");

    // Prim's Algorithm
    vector<bool> visited(n, false);
    vector<int> key(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.push({0, 0});
    key[0] = 0;

    while(!pq2.empty()){
        int u = pq2.top().second;
        pq2.pop();

        if(visited[u])
            continue;

        visited[u] = true;

        for(auto p: graph[u]){
            int v = p.first;
            int w = p.second;
            if(!visited[v] && key[v] > w){
                key[v] = w;
                pq2.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for(int i=1; i<n; i++){
        printf("(%d, %d) -> %d\n", parent[i]+1, i+1, key[i]);
    }

    return 0;
}
