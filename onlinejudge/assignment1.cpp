/*#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        cout<<a+b<<endl;
    }
    
    return 0;
}*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
inline void my_swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int findk_pos(int *array, int k_pos, int begin, int end)
{
    int split = begin;
    int key = array[begin];
    for (int i = begin + 1; i <= end; i++)
        if (array[i] <= key)
            my_swap(array[++split], array[i]);
    my_swap(array[split], array[begin]);
    if (split == k_pos)
        return split;
    else if (split < k_pos)
        return findk_pos(array, k_pos, split + 1, end);
    else
        return findk_pos(array, k_pos, begin, split - 1);
}
priority_queue<int, vector<int>> myq1;               //大根堆
priority_queue<int, vector<int>, greater<int>> myq2; //小根堆
int main()
{
    int k, n;
    cin >> k >> n;
    int *array = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> array[i];
    int mid = findk_pos(array, (n + 1) / 2, 1, n);
    for (int i = 1; i < mid; i++)
        myq1.push(array[i]);
    for (int i = mid + 1; i <= n; i++)
        myq2.push(array[i]);
    stack<int> mystack;
    for (int i = 0; i < k && !myq1.empty(); i++)
    {
        mystack.push(myq1.top());
        myq1.pop();
    }
    while (!mystack.empty())
    {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << array[mid] << " ";
    for (int i = 0; i < k && !myq2.empty(); i++)
    {
        cout << (myq2.top());
        if (i != k - 1)
            cout << " ";
        myq2.pop();
    }
    return 0;
}
/*
#include <iostream>
#include<time.h>
#include<vector>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int bianary_find(int *array,int target,int begin,int end)
{
    while (begin<end)
    {
        int mid=(end-begin)/2+begin;
        if(array[mid]==target)return mid;
        else if(array[mid]>target)end=mid-1;
        else begin=mid+1;
    }
    return array[begin]==target?begin:-1;
}
int main()
{
    int n;
    // cin >> n;
    srand(time(NULL));
    n=rand()%30000;
    vector<int> mydata;
    set<int> myset;
    int *array = new int[n + 1];
    bool *flag = new bool[n + 1];
    for (int i = 1; i <=n; i++)
    {
        myset.insert((rand()%30000));
        flag[i] = false;
    }
    set<int>::iterator iter;
    int begin=1;
    for (iter = myset.begin(); iter != myset.end(); ++iter)
    {
        array[begin++]=*iter;
    }
    sort(array, array + n);
    cout << endl;
    ofstream out1;
    out1.open("1.ans");
    int target;
    target=array[1]+array[10];
    cout<<target<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            // cout<<array[i]<<" ";
            if(array[i]+array[j]==target)
                out1<<array[i]<<" "<<array[j]<<endl; 
        }
    }
    out1.close();
    out1.open("1.out");
    for (int i = 1; i <=n; i++)
    {
        if(flag[i])continue;
        int key=array[i];
        int pos=bianary_find(array,target-key,1,n);
        if(pos!=-1)
        {   
            if(array[pos]>key)
                out1<<key<<" "<<array[pos]<<endl;
            flag[pos]=true;
        }
    }
    out1.close();
    if(system("fc 1.ans 1.out"))
        cout<<"WA"<<endl;
    return 0;
}*/
/*
#include <iostream>
using namespace std;
int bianary_find(int *array, int target, int begin, int end)
{
    while (begin < end)
    {
        int mid = (end - begin) / 2 + begin;
        if (array[mid] == target)
            return mid;
        else if (array[mid] > target)
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return array[begin] == target ? begin : -1;
}
int main()
{
    int n;
    cin >> n;
    int *array = new int[n + 1];
    bool *flag = new bool[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> array[i];
        flag[i] = false;
    }
    int target;
    cin >> target;
    for (int i = 1; i <=n; i++)
    {
        if (flag[i])
            continue;
        int key = array[i];
        int pos = bianary_find(array, target - key, 1, n);
        if (pos != -1)
        {
            if (array[pos] > key)
                cout << key << " " << array[pos] << endl;
            flag[pos] = true;
        }
    }
    return 0;
}*/