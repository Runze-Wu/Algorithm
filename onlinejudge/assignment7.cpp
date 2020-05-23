/*#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;
#define MIN -2147483648
int mymax(int a, int b)
{
    return a > b ? a : b;
}
struct Node
{
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
};
class Graph
{
private:
    int num;
    vector<Node> *edges;
    vector<int> InDegree;

public:
    Graph(int _num) : num(_num)
    {
        edges = new vector<Node>[_num];
        InDegree = vector<int>(_num, 0);
    }
    //~Graph() { delete []edges; }
    void AddEdge(int u, int v, int w = 0)
    {
        Node temp(v, w);
        edges[u].push_back(temp);
        InDegree[v]++;
    }
    void TopoLogical(vector<int> &topo);
    void LongestPath(int s, vector<int> &res);
};
void Graph::TopoLogical(vector<int> &topo)
{
    queue<int> myque;
    for (int i = 0; i < num; i++)
    {
        if (InDegree[i] == 0)
            myque.push(i);
    }
    assert(myque.size() == 1);
    while (!myque.empty())
    {
        int u = myque.front();
        myque.pop();
        topo.push_back(u);
        for (int i = 0; i < edges[u].size(); i++)
        {
            int v = edges[u][i].v;
            InDegree[v]--;
            if (InDegree[v] == 0)
                myque.push(v);
        }
    }
}
void Graph::LongestPath(int s, vector<int> &res)
{
    vector<int> topo;
    TopoLogical(topo);
    assert(topo[0] == s && topo.size() == num);
    for (int i = 0; i < num; i++)
    {
        res.push_back(MIN);
    }
    res[s] = 0;
    for (int i = 0; i < topo.size(); i++)
    {
        int u = topo[i];
        if (res[u] != MIN)
        {
            for (int j = 0; j < edges[u].size(); j++)
            {
                int v = edges[u][j].v;
                int w = edges[u][j].w;
                res[v] = max(res[v], res[u] + w);
            }
        }
    }
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    int n, u, v, w;
    scanf("%d", &n);
    Graph mygraph(n);
    while (scanf("%d%d%d", &u, &v, &w) == 3)
        mygraph.AddEdge(u, v, w);
    assert(n);
    vector<int> res;
    mygraph.LongestPath(0, res);
    for (int i = 1; i < res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}*/
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;
#define maxn 500010
#define MAX 2147483647
struct edge
{
    int to, next, w;
} e[maxn];

int n, cnt, head[maxn];
int dis[maxn];
bool vis[maxn];
void spfa(int s)
{
	queue<int> myque;
	myque.push(s);
	vis[s] = true;
	dis[s] = 0;
	while (!myque.empty())
	{
		int u = myque.front();
		myque.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].next)
		{
			int v = e[i].to;
			int weight = e[i].w;
			if (dis[v] > max(dis[u], weight))
			{
				dis[v] = max(dis[u], weight);
				if (!vis[v]) {
					myque.push(v);
					vis[v] = true;
				}
			}
		}
	}
}
void init(int n)
{
    cnt=0;
    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
        dis[i] = MAX;
        head[i] = -1;
    }
}
void add(int u, int v, int w)
{
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myque;
void dijkstra(int s, int t)
{
    dis[s] = 0;
    myque.push(make_pair(0, s));
    while (!myque.empty())
    {
        int u = myque.top().second;
        myque.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            int weight = e[i].w;
            if (!vis[v]&&dis[v] > max(dis[u], weight))
            {
                dis[v] = max(dis[u], weight);
                myque.push(make_pair(dis[v], v));
            }
        }
    }
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    int n, s, t, u, v, w;
    scanf("%d%d%d", &n, &s, &t);
    init(n);
    while (scanf("%d%d%d", &w, &u, &v) != EOF)
    {
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra(s, t);
    printf("%d", dis[t]);
    return 0;
}*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define MAX 2147483647
struct edge
{
    int v;
    int w;
    edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, s, t, u, v, w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myque;
int dijkstra(int s, int t, vector<vector<edge>> &edges)
{
    vector<bool> vis(n, false);
    vector<int> dis(n, MAX);
    dis[s] = 0;
    myque.push(make_pair(0, s));
    while (!myque.empty())
    {
        int u = myque.top().second;
        myque.pop();
        //printf("%d\n", u);
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < edges[u].size(); i++)
        {
            int v = edges[u][i].v;
            int weight = edges[u][i].w;
            if (!vis[v] && dis[v] > max(dis[u], weight))
            {
                dis[v] = max(dis[u], weight);
                myque.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[t];
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");

    scanf("%d%d%d", &n, &s, &t);
    vector<vector<edge>> edges(n);
    while (scanf("%d%d%d", &w, &u, &v) != EOF)
    {
        edges[u].push_back(edge(v, w));
        edges[v].push_back(edge(u, w));
    }
    printf("%d", dijkstra(s, t, edges));
    return 0;
}