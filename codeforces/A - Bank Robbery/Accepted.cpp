/****************************************************************************************
*  @author: kzvd4729                                         created: May/13/2017 15:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/794/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,n,x,cnt,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    cin>>n;
    cnt=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x>b&&x<c)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}