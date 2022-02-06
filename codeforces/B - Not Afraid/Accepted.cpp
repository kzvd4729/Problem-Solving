/****************************************************************************************
*  @author: kzvd4729#                                        created: Mar/24/2017 17:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/787/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int visp[100005];
int visn[100005];
int main()
{
    int n,m,i,j,x,z,f,ff,q;
    while(cin>>n>>m)
    {
        ff=0;
        for(i=0;i<m;i++)
        {
            cin>>x;
            memset(visp,0,sizeof(visp));
            memset(visn,0,sizeof(visn));
            f=0;
            for(j=0;j<x;j++)
            {
                cin>>z;
                if(z<0)
                {
                    q=z*-1;
                    visn[q]=1;
                    if(visp[q]==1)f=1;
                }
                else
                {
                    visp[z]=1;
                    if(visn[z]==1)f=1;
                }
             }
            if(f==0)ff=1;
         }
        if(ff==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      }
      return 0;
}