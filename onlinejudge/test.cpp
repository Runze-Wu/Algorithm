#include <iostream>
#include <vector>
using namespace std;
    long long res=0;
int main()
{
    int c,n;
    cin>>c>> n;
    vector<int> ori(n);
    for (int i = 0; i < n; i++)
        cin >> ori[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(ori[i]>ori[j]*c){
                res++;
                // cout<<ori[i]<<" "<<ori[j]<<endl;
            }
    cout<<res<<endl;
    return 0;
}