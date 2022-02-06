/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 20:19                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 982 ms                                          memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/847/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int>v[200005];
int main()
{
    int n,i,j,f,x,high,low,mid,h,l;
    cin>>n;
    h=0;
    l=0;
    high=0;
    low=0;
    for(i=0; i<n; i++)
    {
        cin>>x;
        low=0;
        high=h;
        if(i==0)
        {
            v[low].push_back(x);
        }
        else
        {
            while(low<=high)
            {
                mid=(low+high)/2;
                 if(v[mid][v[mid].size()-1]==x)
                {
                    low=mid+1;
                }
                else if(v[mid][v[mid].size()-1]>x)
                {
                    low=mid+1;
                }
                else if(v[mid][v[mid].size()-1]<x)
                {
                    high=mid-1;
                }
            }
             v[low].push_back(x);
            h=max(h,low);
        }
    }
    for(i=0;v[i].size()!=0; i++)
    {
        for(j=0; j<v[i].size(); j++)
        {
            if(j!=0)cout<<" ";
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}