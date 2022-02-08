/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-20 19:19:03                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/arc081/tasks/arc081_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define N 100005
using namespace std;
long n,un,ans;
string s1,s2;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
      cin>>n;
    cin>>s1>>s2;
    ans=1;
    for(long i=0; i<n; i++)
    {
        if(i==0)
        {
            if(s1[i]==s2[i])
            {
                ans=(ans*3)%1000000007;
            }
            else
            {
                ans=(ans*6)%1000000007;
                i++;
            }
        }
        else
        {
            if(s1[i]==s2[i])
            {
                if(s1[i-1]==s2[i-1])
                {
                    ans=(ans*2)%1000000007;
                }
            }
            else
            {
                if(s1[i-1]==s2[i-1])
                {
                    ans=(ans*2)%1000000007;
                    i++;
                }
                else
                {
                    ans=(ans*3)%1000000007;
                    i++;
                }
            }
        }
        ///cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}