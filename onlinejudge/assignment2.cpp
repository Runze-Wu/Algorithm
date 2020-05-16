/*#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long sum = 0;
void merge(vector<string> &a, int l, int mid, int r)
{
    vector<string> temp(r - l + 1);
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
            sum += mid - i + 1;
            j++;
        }
        else
        {
            a[k] = temp[i - l];
            i++;
        }
    }
}
void merge_sort(vector<string> &a, int l, int r)
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
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    int n;
    cin >> n;
    vector<string> ori(n);
    for (int i = 0; i < n; i++)
        cin >> ori[i];
    merge_sort(ori, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout<<ori[i]<<endl;
    cout << sum << endl;
    return 0;
}*/
#include<iostream>
#include<string>
#include<set>
using namespace std;
void merge(string&a, int l, int mid, int r)
{
    string temp(r - l + 1,'\n');
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
void merge_sort(string &a, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}
struct mydata
{
    string key;
    string ori;
    int count;
    mydata(string a,int num=0):key(a),ori(a),count(num){
        merge_sort(key,0,key.length()-1);
    }
    mydata(string k,string o,int num):key(k),ori(o),count(num){}
    bool operator<(const mydata &tar)const{
        return key<tar.key;
    }

};

int main()
{
    cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
    int n;
    cin>>n;
    set<mydata> ori;
    for(int i=0;i<n;i++)
    {
        string key;
        cin>>key;
        mydata data(key);
        set<mydata>::iterator pos=ori.find(data);
        if(pos!=ori.end()){
            string min_ori=key;
            string keys = (*pos).key;
            if ((*pos).ori < key)
                min_ori = (*pos).ori;
            int count = (*pos).count+1;
            ori.erase(*pos);
            ori.insert(mydata(keys,min_ori,count));
        }
        else ori.insert(data);
    }
    set<string> res;
    set<mydata>::iterator j;
    for(j=ori.begin();j!=ori.end();j++)
        if((*j).count)res.insert((*j).ori);
    cout<<res.size()<<endl;
    set<string>::iterator i;
    for(i=res.begin();i!=res.end();i++)
    {
        cout<<*i<<endl;
    }
    return 0;
}