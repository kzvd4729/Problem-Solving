/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2017 21:29                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/825/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
char ans[99999];
long long int n,i,cnt,id,zero;
int main()
{
    cin>>n;
    cin>>s;
    id=-1;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            cnt++;
            zero=0;
        }
        else
        {
            zero++;
            if(cnt)ans[++id]=(char)cnt+'0';
            if(zero==2)
            {
                zero=0;
                ans[++id]='0';
            }
            cnt=0;
        }
    }
    if(cnt)ans[++id]=(char)cnt+'0';
    ans[++id]='\0';
    cout<<ans<<endl;
     return 0;
}