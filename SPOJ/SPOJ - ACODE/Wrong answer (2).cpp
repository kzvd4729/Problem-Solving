/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-08 16:39:15                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-ACODE
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int arr[5003],dp[5003],i,n,x;
void shift(void)
{
    for(i=1; i<=n; i++)
    {
        arr[i]=s[i-1]-'0';
    }
}
int main()
{
    while(cin>>s)
    {
        if(s=="0")break;
        n=s.size();
        shift();

        dp[0]=1;
        dp[1]=1;
        for(i=2; i<=n; i++)
        {
            x=(arr[i-1]*10)+arr[i];
            if(arr[i-1]==0||arr[i]==0)x=30;
            else if(x>=1&&x<=26)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1];
            }
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}