/*
#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int l, int mid, int r)
{
    vector<int> temp(r - l + 1);
    for (int i = l; i <= r; i++)
        temp[i - l] = a[i];
    int i = l;
    int j = mid + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        {
            a[k] = temp[j - l];
            j++;
        }
        else if (j > r)
        {
            a[k] = temp[i - l];
            i++;
        }
        else if (temp[i - l] > temp[j - l])
        {
            a[k] = temp[j - l];
            j++;
        }
        else
        {
            a[k] = temp[i - l];
            i++;
        }
    }
}
void merge_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    int n, tar, count = 0;
    cin >> n >> tar;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    if (n >= 3)
    {
        merge_sort(array, 0, n - 1);
        // for (int i = 0; i < n; i++)cout<<array[i]<<" ";

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {

                if (array[i] + array[j] + array[k] < tar)
                    j++;
                else if (array[i] + array[j] + array[k] > tar)
                    k--;
                else{
                    // cout<<array[i]<<" "<<array[j]<<" "<<array[k]<<endl;
                    j++,k--;
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxn = 100010;
struct A
{
    int u, v;
    A(int temu,int temv):u(temu),v(temv){}
};
bool operator<(const A &a, const A &b)
{
    return a.u<b.u;
}
struct edge
{
    int next, to;
} ex[maxn];
int cnt;
int n;
int head[maxn];
int mytime = 0;
int back[maxn];
int discoverTime[maxn];
set<int> cutPoint;
set<A>cutEdge;
void init()
{
    cnt = 0;
    memset(back, 0, sizeof(back));
    memset(discoverTime, 0, sizeof(discoverTime));
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w = 0)
{
    ex[cnt].to = v;
    ex[cnt].next = head[u];
    head[u] = cnt++;
}
void FindCutPoint(int root, int v, int parent)
{
    mytime++;
    discoverTime[v] = back[v] = mytime;
    int tree = 0;
    for (int i = head[v]; ~i; i = ex[i].next)
    {
        tree++;
        int u = ex[i].to;
        if (!discoverTime[u])
        {
            FindCutPoint(root, u, v);
            if (tree > 1 && v == root)
                cutPoint.insert(v);
            if (v != root && back[u] >= discoverTime[v])
                cutPoint.insert(v);
            if(back[u]>discoverTime[v])
                cutEdge.insert(A(min(u,v),max(u,v)));
            back[v] = min(back[u], back[v]);
        }
        else if (u != parent)
        {
            back[v] = min(back[v], discoverTime[u]);
        }
    }
}
void FindCutEdge(int root, int v, int parent)
{
}
int main()
{
    // cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    // cin >> n;
    // init();
    // int u, v;
    // while (cin >> u >> v)
    // {
    //     add(v, u);
    //     add(u, v);
    // }
    // FindCutPoint(0, 0, 0);
    // for (auto i = cutPoint.begin(); i != cutPoint.end(); i++)
    // {
    //     cout << *i << endl;
    // }
    // for(auto i=cutEdge.begin();i!=cutEdge.end();i++){
    //     cout<<(*i).u<<" "<<(*i).v<<endl;
    // }
    char temp[6];
    scanf("%6s",temp);
    printf("%s",temp);
    return 0;
}

/*
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
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
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
}*/