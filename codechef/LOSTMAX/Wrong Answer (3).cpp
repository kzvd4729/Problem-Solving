/****************************************************************************************
*  @author: kzvd4729                                         created: 29-07-2017 19:54:40                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME50/problems/LOSTMAX
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int t,i,l,id,ls,x,arr[400000],k,ans;
string s;
void con(long long int lo,long long int hi)
{
    x=0;
    for(k=lo;k<=hi;k++)
    {
        x=x*10+(long long int)(s[k]-'0');
    }
    arr[++id]=x;
}
int main()
{
    cin>>t;
    while(t--)
    {
        s.clear();
        id=-1;
        ans=0;
        ///getchar();
        fflush(stdin);
        getline(cin,s);
        l=s.size();
        ls=0;
        for(i=0;i<l;i++)
        {
            if(s[i]==' ')
            {
                con(ls,i-1);
                ls=i+1;
            }
        }
        con(ls,l-1);
        for(i=0;i<=id;i++)
        {
            if(arr[i]!=id)
            {
                ans=max(ans,arr[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}