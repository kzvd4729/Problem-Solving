/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2017 17:56                        
*  solution_verdict: Time limit exceeded on pretest 1        language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 79800 KB                             
*  problem: https://codeforces.com/contest/876/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
vector<long>ans;
bool ok(long z)
{
    long zz=z;
    while(zz)
    {
        long r=(zz+10)%10;
        z+=r;
        zz/=10;
    }
    if(z==n)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long x=n;x>=max(n-100000,0LL);x--)
    {
        if(ok(x))ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(long i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        if(i==ans.size()-1)cout<<endl;
        else cout<<" ";
    }
    ans.clear();
    main();
     return 0;
}