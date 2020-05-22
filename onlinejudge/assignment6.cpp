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
/*
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <assert.h>
using namespace std;
const int MAXN = 200010;
int my_min(int a, int b)
{
    return b < a ? b : a;
}

vector<vector<int>> edges;
int n = 0, cnt = 0, stack_top = -1;
bool vis[MAXN];
int low[MAXN], discover[MAXN], stack[MAXN], myscc[MAXN], scc_size[MAXN], in_degree[MAXN];
void tarjan(int x)
{
    low[x] = discover[x] = ++cnt;
    stack[++stack_top] = x;
    vis[x] = true;
    for (int i = 0; i < edges[x].size(); i++)
    {
        if (discover[edges[x][i]] == 0)
        {
            tarjan(edges[x][i]);
            low[x] = my_min(low[x], low[edges[x][i]]);
        }
        else if (vis[edges[x][i]])
        {
            low[x] = my_min(low[x], discover[edges[x][i]]);
        }
    }
    if (low[x] == discover[x])
    {
        while (true)
        {
            myscc[stack[stack_top]] = x;
            scc_size[x]++;
            vis[stack[stack_top]] = 0;
            stack_top--;
            if (x == stack[stack_top + 1])
                break;
        }
    }
}

void createDAG(vector<vector<int>> &sccDAG)
{
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            int x = myscc[i], y = myscc[edges[i][j]];
            if (x != y)
            {
                sccDAG[x].push_back(y);
                in_degree[y]++;
            }
        }
    }
}
void DFS(int x, vector<vector<int>> &sccDAG)
{
    vis[x] = true;
    for (int i = 0; i < sccDAG[x].size(); i++)
    {
        if (!vis[sccDAG[x][i]])
        {
            DFS(sccDAG[x][i], sccDAG);
        }
    }
}
int topo(vector<vector<int>> &sccDAG, vector<int> &result)
{
    int Max = -1;
    vector<int> orderq;
    for (int i = 0; i < sccDAG.size(); i++)
    {
        if (in_degree[i] == 0)
        {
            orderq.push_back(i);
        }
    }
    if (orderq.empty())
        return false;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < orderq.size(); i++)
    {
        int x = orderq[i];
        DFS(x, sccDAG);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == true)
            {
                res += scc_size[i];
                vis[i] = false;
            }
        }
        if (res > Max)
        {
            Max = res;
            result.clear();
            result.push_back(x);
        }
        else if (res == Max)
        {
            result.push_back(x);
        }
    }
    return Max;
}
int main()
{
    string oneline;
    stringstream in;
    while (getline(cin, oneline))
    {
        vector<int> edge;
        n++;
        in << oneline;
        int temp;
        while (in >> temp)
            edge.push_back(temp);
        in.clear();
        edges.push_back(edge);
    }
    //printf("I have read the rules about plagiarism punishment\n");
    vector<vector<int>> sccDAG(n);
    for (int i = 0; i < n; i++)
        if (discover[i] == 0)
            tarjan(i);
    createDAG(sccDAG);
    vector<int> result;
    set<int> finalres;
    int res = topo(sccDAG, result);
    if (res)
    {
        printf("%d\n", res - 1);
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (myscc[j] == result[i])
                    finalres.insert(j);
            }
        }
        for (auto i = finalres.begin(); i != finalres.end(); i++)
            printf("%d ", *i);
    }
    return 0;
}*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <sstream>
#include <memory.h>
#include <assert.h>
using namespace std;
int num = 0;
bool BFS(int v, vector<vector<int>> &edges, vector<int> &color)
{
    vector<bool> vis(num, 0);
    queue<int> myque;
    vis[v] = true;
    myque.push(v);
    while (!myque.empty())
    {
        int w = myque.front();
        myque.pop();
        for (int i = 0; i < edges[w].size(); i++)
        {
            int x = edges[w][i];
            if (vis[x])
            {
                if (color[x] == color[w])
                    return false;
            }
            else
            {
                color[x] = !color[w];
                vis[x] = true;
                myque.push(x);
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> tempedges;
    string oneline;
    stringstream in;
    num = 0;
    while (getline(cin, oneline))
    {
        vector<int> edge;
        in << oneline;
        int temp;
        num++;
        while (in >> temp)
            edge.push_back(temp);
        in.clear();
        tempedges.push_back(edge);
    }
    vector<vector<int>> edges(num);
    vector<int> color(num, -1);
    for (auto i = 0; i < num; i++)
    {
        int cur = tempedges[i][0];
        edges[cur].assign(tempedges[i].begin() + 1, tempedges[i].end());
    }
    color[0] = 1;
    assert(BFS(0, edges, color));
    for (int i = 0; i < num; i++)
    {
        if (color[i] == 1)
            cout << i << endl;
    }
    return 0;
}