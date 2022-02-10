/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-27 17:14:29                      
*  solution_verdict: Compilation Error                       language: C                                       
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1074
****************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int f[15],g[15];

void foo(int n)
{
    while(n)
    {
        f[n%10]++;
        n/=10;
    }
}
void goo(int n)
{
    while(n)
    {
        g[n%10]++;
        n/=10;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        foo(i);
    }
    for(int i=1;i<=m;i++)
    {
        goo(i);
    }

    for(int i=0;i<10;i++) cout << g[i]-f[i] << endl;
    for(int i=0;i<10;i++) cout << f[i] << endl;
    return 0;
}