/*#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int TwoArraysMedian(vector<int> &a, vector<int> &b, int n)
{
    int res = 0;
    int split_1 = n / 2, split_2;
    int left = 0, right = n;
    while (true)
    {
        split_1 = (left + right) / 2;
        split_2 = n - split_1;
        if (split_1 == 0 || split_2 == n)
        {
            res = b[n];
            break;
        }
        if (split_2 == 0 || split_1 == n)
        {
            res = a[n];
            break;
        }
        if (b[split_2] > a[split_1 + 1])
        {
            left = split_1 + 1;
            continue;
        }
        else if (a[split_1] > b[split_2 + 1])
        {
            right = split_1 - 1;
            continue;
        }
        if (split_1 + split_2 == n)
        {
            res = max(a[split_1], b[split_2]);
            break;
        }
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    //for (int i = 1; i <= n; i++)printf("%d ", a[i]);
    //for (int i = 1; i <= n; i++)printf("%d ", b[i]);
    printf("%d", TwoArraysMedian(a, b, n));
    return 0;
}*/
/*
#include<iostream>
#include<queue>
#include<stdio.h>
#include<memory.h>
using namespace std;
const int maxn = 100010;
struct edge
{
    int next, to, w;
}ex[maxn];
int cnt;
int n;
int pointcount[maxn];
int outpoint[maxn];
int topo[maxn];
int dis[maxn];
int head[maxn];
void init()
{
    cnt = 0;
    memset(dis, 0, sizeof(dis));
    memset(outpoint, 0, sizeof(outpoint) + 1);
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w = 0)
{
    outpoint[v]++;
    ex[cnt].to = v;
    ex[cnt].next = head[u];
    ex[cnt].w = w;
    head[u] = cnt++;
}
bool topological()
{
    queue<int> q;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!outpoint[i])
        {
            q.push(i);
        }
    }
    int u, v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        topo[count++] = u;
        for (int p = head[u]; ~p; p = ex[p].next)
        {
            v = ex[p].to;
            --outpoint[v];
            if (!outpoint[v])
            {
                q.push(v);
            }
        }
    }
    return true;
}
int longestpath()
{
    int max_res = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        int u = topo[i];
        for (int j = head[u]; ~j; j = ex[j].next)
        {
            int v = ex[j].to;
            dis[v] = (dis[v] > dis[u] + pointcount[u]) ? dis[v] : dis[u] + pointcount[u];
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        //printf("%d ",dis[i]);
        max_res = (max_res > dis[i]) ? max_res : dis[i];
    }
    return max_res;
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    cin >> n;
    init();
    int index = 0;
    for (int i = 1; i <= n; i++) {
        cin >> index;
        cin >> pointcount[index];
    }
    int u, v;
    while (cin >> u >> v)
        add(v, u, pointcount[v]);
    for (int i = 1; i <= n; i++)
        add(i, n + 1, pointcount[i]);
    topological();
    printf("%d", longestpath());
    return 0;
}*/
#include <iostream>
#include <vector>
#include <stdio.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;
struct node
{
    int state;
    int cost;
    int begin_time;
    int end_time;
    node(int co = 0) : state(WHITE), cost(co), begin_time(0), end_time(0) {}
};

void DFS(int point, vector<node> &nodes, vector<int> *edge)
{
    nodes[point].state = GREY;
    nodes[point].begin_time = 0;
    vector<int>::iterator i;
    for (i = edge[point].begin(); i != edge[point].end(); i++)
    {
        if (nodes[*i].state == WHITE)
        {
            DFS(*i, nodes, edge);
            if (nodes[*i].end_time >= nodes[point].begin_time)
                nodes[point].begin_time = nodes[*i].end_time;
        }
        else if (nodes[*i].end_time >= nodes[point].begin_time)
            nodes[point].begin_time = nodes[*i].end_time;
    }
    nodes[point].state = BLACK;
    nodes[point].end_time = nodes[point].cost + nodes[point].begin_time;
}

int main()
{
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    vector<int> *edge = new vector<int>[n + 1];
    int index, cost;
    for (int i = 1; i <= n; i++)
    {
        cin >> index >> cost;
        nodes[index] = node(cost);
    }
    int u, v;
    while (cin >> u >> v)
        edge[u].push_back(v);
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        DFS(i, nodes, edge);
        if (nodes[i].end_time > res)
            res = nodes[i].end_time;
    }
    cout << res << endl;
    return 0;
}