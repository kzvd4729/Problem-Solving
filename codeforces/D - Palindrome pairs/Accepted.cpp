/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/18/2018 17:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 33300 KB                             
*  problem: https://codeforces.com/contest/159/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,lt,rt,pal[2002][2002],st[2002],ed[2002];
string s;
void palindrome(void)
{
    for(long i=0;i<n;i++)
    {
        for(long j=0;j<n;j++)
        {
            lt=j;
            rt=j+i;
            if(rt>=n)break;
            if(lt==rt)pal[lt][rt]=1;
            else if(lt+1==rt&&s[lt]==s[rt])pal[lt][rt]=1;
            else if(s[lt]==s[rt]&&pal[lt+1][rt-1])pal[lt][rt]=1;
        }
    }
    for(long i=0;i<n;i++)
    {
        for(long j=0;j<n;j++)
        {
            st[i]+=pal[i][j];
            ed[j]+=pal[i][j];
        }
    }
    for(long i=n-2;i>=0;i--)st[i]+=st[i+1];
//    for(long i=0;i<n;i++)cout<<st[i];
//    cout<<endl;
//    for(long i=0;i<n;i++)cout<<ed[i];
//    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
     n=s.size();
     palindrome();
     long ans=0;
    for(long i=0;i<n-1;i++)ans+=ed[i]*st[i+1];
    cout<<ans<<endl;
 //    for(long i=0;i<n;i++)
//    {
//        for(long j=0;j<n;j++)
//        {
//            cout<<i<<" "<<j<<" "<<pal[i][j]<<endl;
//        }
//    }
     return 0;
}