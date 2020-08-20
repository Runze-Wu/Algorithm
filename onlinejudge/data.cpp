#include <iostream> //输入输出
#include <ctime>    //time()
using namespace std;
int main()
{
    srand(time(NULL));
    int c=(rand()<<6|rand())%10+1;
    // int c=2;
    int n = (rand() << 15 | rand()) % 1000 + 1; //这样造出的rand数更随机
    // int n=6;
    cout <<c<<" "<< n << endl;
    while (n--)
    {
        // cout << (rand() << 15 | rand()) % 10000 << ' ';
        cout<<(rand()<<15|rand())%10000+1<<' ';
        //保证数据在[0,9999]。如果要[1,10000]，就用第二行的
    }
    return 0;
}