/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/14/2018 10:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/915/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long fre[30],ar[30],l1,l2;
string a,b,tmp,x,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    l1=a.size();
    l2=b.size();
    if(l2>l1)
    {
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<a<<endl;
        return 0;
    }
    for(long i=1;i<=l1;i++)fre[a[i-1]-'0']++;
    for(long i=0;i<l1;i++)
    {
        for(long j=9;j>=0;j--)
        {
            if(fre[j]&&j<(b[i]-'0'))
            {
                for(long k=0;k<=9;k++)ar[k]=fre[k];
                tmp=x;
                tmp.push_back(j+'0');
                ar[j]--;
                for(long k=9;k>=0;k--)
                {
                    while(ar[k]--)
                    {
                        tmp.push_back(k+'0');
                    }
                }
                if(tmp.size()==l1)ans=max(ans,tmp);
                break;
            }
        }
        if(fre[b[i]-'0'])
        {
            x.push_back(b[i]);
            fre[b[i]-'0']--;
        }
        else break;
    }
    ///ans.push_back('\0');
    if(x.size()==l1)ans=max(ans,x);
    cout<<ans<<endl;
    return 0;
}