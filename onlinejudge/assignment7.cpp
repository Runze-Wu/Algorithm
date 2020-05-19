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

#include <iostream>
#include <vector>
#include <queue>
#include<memory.h>
#include <assert.h>
using namespace std;
#define MIN -2147483648
#define MAX 2147483647
int mymax(int a, int b)
{
    return a > b ? a : b;
}
struct Node
{
    int v, w;
    Node(int _v, int _w) : v(_v), w(_w) {}
    bool operator<(const Node&a)const{
        return w<a.w;
    }
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
    void AddEdge(int u, int v, int w = 0)
    {
        Node temp(v, w);
        edges[u].push_back(temp);
        InDegree[v]++;
    }
    int dijkstra(int s,int t);
};
int Graph::dijkstra(int s,int t)
{
    bool *vis=new bool[num+1];
    int *dis=new int[num+1];
    memset(dis, false, sizeof(vis));
    memset(vis,false,sizeof(vis));
    priority_queue<Node>myque;
    myque.push(Node(s,0));
    dis[s]=0;
    int res=MAX;
    while (!myque.empty())
    {
        Node x=myque.top();
        myque.pop();
        int u=x.v,cost=x.w;
        if(u==t){
            res=res<cost?cost:res;
        }
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i].v,w=edges[u][i].w;
            int maxcost = cost>w?cost:w;
            if (maxcost>dis[v]){
                dis[v]=maxcost;
                myque.push(Node(v,maxcost));
            }
        }
    }
    return res;
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    int n,s,t,u,v,w;
    scanf("%d%d%d",&n,&s,&t);
    Graph mygraph(n);
    while (scanf("%d%d%d", &w,&u, &v) == 3){
        mygraph.AddEdge(u, v, w);
        mygraph.AddEdge(u, v, w);
    }
    assert(n);
    printf("%d",mygraph.dijkstra(s,t));
}