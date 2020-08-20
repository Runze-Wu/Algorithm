/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100010
char T[MAXN];

int PalindSeq(int count)
{
    if(count<=1)return count;
    int n = count;
    vector<short>tem(n,0);
    vector<vector<short>> dp(n,tem);
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (T[i + j] == T[j])
                dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
            else
                dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
        }
    }
    return dp[0][n - 1];
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    int index=0;
    char a;
    while (scanf("%c", &a) != EOF){
        if(a==' ')continue;
        T[index++]=a;
    }
    printf("%d", PalindSeq(index));
    return 0;
}*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
vector<vector<int>> edges;
string oneline;
stringstream in;
void MiniVertexCover(int u, int* dp1,int*dp2)
{
    dp1[u]=1;
    dp2[u]=0;
    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        MiniVertexCover(v, dp1,dp2);
        dp1[u] += min(dp1[v], dp2[v]);
        dp2[u] += dp1[v];
    }
}
int MiniVertexCoverWrapper(int num)
{
    int *dp1 = new int[num];
    int *dp2 = new int[num];
    MiniVertexCover(0, dp1,dp2);
    return min(dp1[0], dp2[0]);
}
int main()
{
    printf("I have read the rules about plagiarism punishment\n");
    
    int num = 0;
    while (getline(cin, oneline))
    {
        vector<int> edge;
        in << oneline;
        int temp;
        num++;
        int cur;
        in >> cur;
        while (in >> temp)
            edge.push_back(temp);
        in.clear();
        edges.push_back(edge);
    }

    printf("%d", MiniVertexCoverWrapper(num));
    return 0;
}