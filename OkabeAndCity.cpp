#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;
#define ll long long
#define N 100005
#define MAX INT_MAX

ll d[N];
int visited[N];
int a[N], b[N];

void solve(int n, int m, int k){
    queue<int>q;

    for (int i = 1; i <= k; i++) {
        visited[i] = 0;
        d[i] = MAX;
    }
    visited[1] = 1;
    q.push(1);
    d[1] = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        visited[u] = 0;
        for (int i = 1; i <= k; i++){
            ll val = MAX;
            if (i == u) {
                continue;
            }
            int dx = abs(a[i] - a[u]);
            int dy = abs(b[i] - b[u]);

            if (dx + dy == 1) {
                val = 0;
            }
            else if (dx <= 2 || dy <= 2) {
                val = 1;
            }
            if (d[i] > d[u] + val) {
                d[i] = d[u] + val;
                if (!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    if (d[k] == MAX) {//No es posible
        cout << "-1" << endl;
    }
    else {
        cout << d[k] << endl;
    }
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    int light = 0;
    for (int i = 1; i <= k; i++){
        cin >> a[i] >> b[i];
        if (a[i] == n && b[i] == m) {
            light = 1;
        }
    }

    if (light == 0) {
        a[++k] = n + 1;
        b[k] = m + 1;
    }

    solve(n, m, k);
}