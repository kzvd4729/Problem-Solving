/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/12/2017 21:54                        
*  solution_verdict: Wrong answer on test 34                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/839/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,k,arr[103],i,x,y;
int main()
{
    cin>>n>>k;
    for(i=1; i<=k; i++)
    {
        cin>>arr[i];
    }
    int tw=n*2;
    int fo=n;
    int exo=0;
    int ext=0;
    int f=0;
    for(i=1; i<=k; i++)
    {
        x=arr[i];
        y=x/4;
        if(y>0)
        {
            if(fo>0)
            {
                if(fo-y>=0)
                {
                    fo=fo-y;
                    y=0;
                }
                else
                {
                    y=y-fo;
                    fo=0;
                }
            }
            if(y>0)
            {
                y=y*2;
                if(ext>0)
                {
                    if(ext-y>=0)
                    {
                        ext=ext-y;
                        y=0;
                    }
                    else
                    {
                        y=y-ext;
                        ext=0;
                    }
                }
                if(y>0)
                {
                    if(tw>0)
                    {
                        if(tw-y>=0)
                        {
                            tw=tw-y;
                            y=0;
                        }
                        else
                        {
                            y=y-tw;
                            tw=0;
                        }
                    }
                 }
                if(y>0)
                {
                    y=y*2;
                    if(exo-y<0)f=1;
                    else exo-=y;
                }
            }
        }
        x=x%4;
        if(x==3)
        {
            if(fo>0)fo--;
            else
            {
                if(ext>0)
                {
                    ext--;
                    if(exo>0)exo--;
                    else
                    {
                        if(ext>0)ext--;
                        else if(tw>0)tw--;
                        else
                        {
                            if(fo>0)
                            {
                                fo--;
                                ext++;
                            }
                            else f=1;
                        }
                    }
                }
                else if(tw>0)
                {
                    tw--;
                    if(exo>0)exo--;
                    else
                    {
                        if(ext>0)ext--;
                        else if(tw>0)tw--;
                        else
                        {
                            if(fo>0)
                            {
                                fo--;
                                ext++;
                            }
                            else f=1;
                        }
                    }
                 }
            }
        }
        if(x==2)
        {
            if(ext>0)ext--;
            else if(tw>0)tw--;
            else if(exo>1)exo-=2;
            else
            {
                if(fo>0)
                {
                    fo--;
                    exo++;
                }
                else f=1;
            }
         }
        if(x==1)
        {
            if(exo>0)exo--;
            else
            {
                if(ext>0)ext--;
                else if(tw>0)tw--;
                else
                {
                    if(fo>0)
                    {
                        fo--;
                        ext++;
                    }
                    else f=1;
                }
            }
         }
     }
      if(f==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}