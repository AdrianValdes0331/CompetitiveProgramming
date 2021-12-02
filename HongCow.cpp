#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#define MAX 100005
#define LL long long

int c[MAX];
int v1[MAX], v2[MAX], v3[MAX], v4[MAX];
LL v5[MAX];

vector<int>vec[MAX];
map<int, int>myMap;

LL max2 = 0;
LL cont = 0;
LL cm = 0;
LL b;

int check(int u)
{
    int i;
    for (i = u; i != v1[i];) {
        i = v1[i];
    }
    return i;
}

int main()
{
    int n, m, k;
    int i, j;
    cin >> n >> m >> k;

    for (i = 0; i < MAX; i++) {
        vec[i].clear();
        v1[i] = i;
        v2[i] = 1;
    }

    for (i = 1; i <= k; i++) {
        cin >> c[i];
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        vec[u].push_back(v);
        vec[v].push_back(u);

        int uu = check(u);
        int vv = check(v);

        if (uu != vv){
            if (v2[uu] > v2[vv]){
                v2[uu] += v2[vv];
                v1[vv] = uu;
                v5[uu] += v5[vv];
                v5[uu]++;
            }
            else{
                v2[vv] += v2[uu];
                v1[uu] = vv;
                v5[vv] += v5[uu];
                v5[vv]++;
            }
        }
        else {
            v5[uu]++;
        }
    }

    for (i = 1; i <= n; i++){
        v3[i] = check(i);
    }

    for (i = 1; i <= k; i++){
        myMap[v3[c[i]]] = 1;
        if (v2[v3[c[i]]] > max2){
            max2 = max((LL)v2[v3[c[i]]], max2);
            b = v5[v3[c[i]]];
        }
    }

    for (i = 1; i <= n; i++){
        if (!myMap.count(v3[i])){
            cont += v2[v3[i]];
            myMap[v3[i]] = 1;
            cm += v5[v3[i]];
        }
    }

    LL maxStable = cont * (cont - 1) / (LL)2;
    maxStable += max2 * cont;
    maxStable -= cm;
    
    for (i = 1; i <= k; i++){
        maxStable += (LL)v2[v3[c[i]]] * (LL)(v2[v3[c[i]]] - 1) / (LL)2;
        maxStable -= v5[v3[c[i]]];
    }

    cout << maxStable << endl;
    return 0;
}

// LL akk = maxStable;
// int check(int u);