/*#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 10;
int n,m;
struct edge
{
    int u, v, w;
    bool operator<(const edge &edges) const
    {
        return w < edges.w;
    }
};
edge edges[maxn];
int a[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

int find(int x)
{
    if (a[x] == x)
        return x;
    else
        return a[x] = find(a[x]);
}
bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (x < y)
            a[y] = x;
        else
            a[x] = y;
        return 1;
    }
    else
        return 0;
}

void kruskal(int n, int m)
{
    int sum_mst = 0;
    int num = 0;
    sort(edges, edges + m);
    init(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) 
        {
            sum_mst += edges[i].w;
            num++;
            unite(u, v);
        }
        if (num >= n - 1)
            break;
    }
    printf("%d\n", sum_mst);
}
int main()
{
    cin >> n;
    int u,v,w;
    int i=0;
    while (cin >> edges[i].u >> edges[i].v >> edges[i].w)i++;
    m=i;
    kruskal(n, m);
    return 0;
}*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
    string oneline;
    stringstream in;
    int n=0;
    while (getline(cin,oneline))
    {
        if(oneline.length()==0)continue;
        n++;
        in<<oneline;
        int temp;
        while(in>>temp)
        {
            cout<<temp<<" ";
        }
        in.clear();
    }
    cout<<n;
    
    return 0;
}