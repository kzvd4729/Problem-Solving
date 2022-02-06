/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 14:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/690/problem/D1
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
string s[N+2];
int main()
{
    int r,c;cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        cin>>s[i];
    }
    int f=0,cnt=0;
    for(int i=0;i<c;i++)
    {
        if(s[r-1][i]=='B')
        {
            if(!f)cnt++;
            f=1;
        }
        else f=0;
    }
    cout<<cnt<<endl;
    return 0;
}