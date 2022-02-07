/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-04 15:38:37                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 770                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-13131
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[500005];
vector<int>d[500005];
void dv(void)
{
    int i,j;
    for(i=1;i<=500000;i++)
    {
        for(j=i;j<=500000;j=j+i)
        {
            d[j].push_back(i);
        }
    }
}
int main()
{
    dv();
    int t,sum,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        for(i=0;i<d[n].size();i++)
        {
            if(d[n][i]%k!=0)sum=sum+d[n][i];
        }
        cout<<sum<<endl;
    }
    return 0;
}