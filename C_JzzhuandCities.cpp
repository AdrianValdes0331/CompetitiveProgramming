//Adrian Valdes Zavala 
//A01720439
//C_JzzhuandCities

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 100002
#define INF INT_MAX
#define llp pair<long long, long long>
#define ll long long
using namespace std;

vector<llp> G[MAX];
vector<llp> vec;
ll d[MAX];
ll minCam[MAX];

void algDijstra(int s){
    priority_queue<llp, vector<llp>, greater<llp> > pq;
    fill(d, d + MAX, INF);
    d[s] = 0;
    pq.push(llp(0, s));
    while (!pq.empty()){
        llp p = pq.top();
        pq.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (int i = 0; i < G[v].size(); i++){
            llp edge = G[v][i];
            if (d[edge.first] == d[v] + edge.second){
                minCam[edge.first]++;
            }
            if (d[edge.first] > d[v] + edge.second){
                d[edge.first] = d[v] + edge.second;
                pq.push(llp(d[edge.first], edge.first));
                minCam[edge.first] = 1;
            }
        }
    }
}

int main() {
    int n, m, k;
    int cont = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u].push_back(llp(v, w));
        G[v].push_back(llp(u, w));
    }

    for (int i = 0; i < k;i++) {
        ll u1, v1;
        cin >> u1 >> v1;
        vec.push_back(llp(u1, v1));
        G[1].push_back(llp(u1, v1));
    }

    algDijstra(1);

    for (int i = 0; i < vec.size();i++) {
        ll v2 = vec[i].first;
        ll u2 = vec[i].second;
        if (d[v2]<u2) {
            cont++;
        }
        if (d[v2]==u2 && minCam[v2]>1) {
            cont++;
            minCam[v2]--;
        }
    }
    cout << cont << endl;
    return 0;
}