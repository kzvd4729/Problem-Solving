/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-24 14:46:29                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 33                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-6134
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        int cnt=0;
        for(int i=n;i<=m;i++)
        {
            int a[15]={0},k=i;
            bool flg=true;
            while(k>0)
            {
                a[k%10]++;
                if(a[k%10]>1){
                    flg=false;
                    break;
                }
                k/=10;
            }
            if(flg)cnt++;
        }
        cout<<cnt<<endl;
    }


    return 0;
}