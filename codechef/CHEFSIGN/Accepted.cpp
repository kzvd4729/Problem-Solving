/****************************************************************************************
*  @author: kzvd4729                                         created: 08-07-2017 09:13:35                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.17 sec                                        memory_used: 3.2M                                 
*  problem: https://www.codechef.com/JULY17/problems/CHEFSIGN
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,i,ans,cnt1,cnt2;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        cnt1=0;
        cnt2=0;
        ans=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='<')
            {
                cnt1++;
                cnt2=0;
            }
            if(s[i]=='>')
            {
                cnt2++;
                cnt1=0;
            }
            ans=max(max(ans,cnt1),cnt2);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}