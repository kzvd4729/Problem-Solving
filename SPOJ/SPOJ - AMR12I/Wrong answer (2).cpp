/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-27 20:59:34                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-AMR12I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k,cnt,ans;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        s.push_back('!');
        ans=0;
        for(long i=1; i<s.size(); i++)
        {
            if(s[i]!=s[i-1])
            {
                ans++;
                cnt=1;
            }
            else
            {
                cnt++;
                if(cnt>k)ans++;
                cnt=1;
            }
        }
        cnt=1;
        for(long i=s.size()-3; i>=0; i--)
        {
            if(s[i]==s[i+1])cnt++;
            else break;
        }
        if(cnt>=k)cout<<ans<<endl;
        else cout<<-1<<endl;
        ///cout<<ans<<" "<<cnt<<endl;
    }
    return 0;
}