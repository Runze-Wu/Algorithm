#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
inline void my_swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}
int findk_pos(vector<string> &array, int k_pos, int begin, int end)
{
    if (begin > end)
        return -1;
    int split = begin;
    string key = array[begin];
    for (int i = begin + 1; i <= end; i++)
        if (array[i] < key)
            my_swap(array[++split], array[i]);
    if (array[split] != array[begin])
        my_swap(array[split], array[begin]);
    if (split == k_pos)
        return split;
    else if (split < k_pos)
        return findk_pos(array, k_pos, split + 1, end);
    else
        return findk_pos(array, k_pos, begin, split - 1);
}
priority_queue<string, vector<string>> myq1;
priority_queue<string, vector<string>, greater<string>> myq2;
int main()
{
    int k, n;
    cin >> n >> k;
    vector<string> array(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> array[i];
    int mid = findk_pos(array, (n + 1) / 2, 1, n);
    int left_pos = findk_pos(array, mid - k, 1, mid - 1);
    int right_pos = findk_pos(array, k + mid, mid + 1, n);
    for (int i = left_pos; i <= mid - 1; i++)
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
}
/*
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
}*/
/*
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int value;
    Node *Left;
    Node *Right;
    Node() : value(0), Left(NULL), Right(NULL) {}
    Node(int val) : value(val), Left(NULL), Right(NULL) {}
};
void LastOrderTree(Node *root)
{
    if (root)
    {
        LastOrderTree(root->Left);
        LastOrderTree(root->Right);
        cout << root->value << " ";
    }
}
int LevelOrderTree(Node *root)
{
    if (root == NULL)
        return 0;
    int max_width = 0;
    queue<Node *> myqueue;
    myqueue.push(root);
    while (!myqueue.empty())
    {
        int cur_width = myqueue.size();
        max_width = max_width > cur_width ? max_width : cur_width;
        for (int i = 0; i < cur_width; i++)
        {
            Node *temp = myqueue.front();
            myqueue.pop();
            if (temp->Left)
                myqueue.push(temp->Left);
            if (temp->Right)
                myqueue.push(temp->Right);
        }
    }
    return max_width;
}
int search_node(int num, const int *array, int len)
{
    for (int i = 0; i < len; i++)
        if (num == array[i])
            return i;
    return -1;
}
Node *BuiltTree(int len, const int *pre_oder, const int *in_order)
{
    if (len == 0)
        return NULL;
    Node *root = new Node(*pre_oder);
    int split = search_node(*pre_oder, in_order, len);
    root->Left = BuiltTree(split, pre_oder + 1, in_order);
    root->Right = BuiltTree(len - split - 1, pre_oder + split + 1, in_order + split + 1);
    return root;
}

int MaxLen(Node *root)
{
    if (root == NULL)
        return 0;
    int left = MaxLen(root->Left);
    int right = MaxLen(root->Right);
    return left > right ? left + 1 : right + 1;
}
int MaxWidth(Node *root)
{
    static int max_width = 0;
    if (root == NULL)
        return 0;
    int left_depth = MaxLen(root->Left);
    int right_depth =MaxLen(root->Right);
    max_width = (max_width > (left_depth + right_depth)) ? max_width : (left_depth + right_depth);
    return max_width;
}
int main()
{
    int n;
    cin >> n;
    int *pre_order = new int[n + 1];
    int *in_order = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> pre_order[i];
    for (int i = 0; i < n; i++)
        cin >> in_order[i];
    Node *root = BuiltTree(n, pre_order, in_order);
    // LastOrderTree(root);
    int maxlen = MaxLen(root);
    cout << maxlen - 1 << endl;
    int maxwidth=MaxWidth(root);
    cout<<maxwidth<<endl;

    delete[] pre_order;
    delete[] in_order;
    return 0;
}*/