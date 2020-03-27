/*#include <iostream>
#include <queue>
#include <stack>
#include<string>
#include<vector>
using namespace std;
inline void my_swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
int findk_pos(vector<string>&array, int k_pos, int begin, int end)
{
    int split = begin;
    string key = array[begin];
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
priority_queue<string, vector<string>> myq1;               //大根堆
priority_queue<string, vector<string>, greater<string>> myq2; //小根堆
int main()
{
    int k, n;
    cin >> k >> n;
    vector<string>array(n+1);
    for (int i = 1; i <= n; i++)
        cin >> array[i];
    int mid = findk_pos(array, (n + 1) / 2, 1, n);
    int left_pos=findk_pos(array,mid-k-1,1,mid-1);
    int right_pos = findk_pos(array, k, mid+1, n);
    cout<<left_pos<<" "<<mid<<" "<<right_pos<<endl;
    for (int i = 1; i <=left_pos; i++)
        myq1.push(array[i]);
    for (int i = mid + 1; i <= right_pos; i++)
        myq2.push(array[i]);
    stack<string> mystack;
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
}*/
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

priority_queue<int, vector<int>> myq1;
priority_queue<int, vector<int>, greater<int>> myq2;
int main()
{
    int input;
    scanf("%d", &input);
    int i = 1;
    myq1.push(input);
    printf("%d ", myq1.top());
    while (scanf("%d", &input) == 1)
    {
        i++;
        if (input > myq1.top())
            myq2.push(input);
        else
            myq1.push(input);
        while ((int(myq1.size() - myq2.size()) > 1) || (int(myq2.size() - myq1.size()) > 1))
        {
            if (myq1.size() > myq2.size())
            {
                myq2.push(myq1.top());
                myq1.pop();
            }
            else
            {
                myq1.push(myq2.top());
                myq2.pop();
            }
        }
        if (i % 2)
            printf("%d ", (myq1.size() > myq2.size() ? myq1.top() : myq2.top()));
        else
            printf("%d ", myq1.top());
    }
    return 0;
}