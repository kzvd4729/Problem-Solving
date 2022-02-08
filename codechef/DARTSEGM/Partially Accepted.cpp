/****************************************************************************************
*  @author: kzvd4729                                         created: 28-04-2018 20:57:57                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.24 sec                                        memory_used: 16.5M                                
*  problem: https://www.codechef.com/LTIME59A/problems/DARTSEGM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,l,r,q;
struct data
{
  long x,y;
}arr[50050];
long cross(pair<long,long>P,pair<long,long>Q,pair<long,long> R)//if return >0 
    then point R is upper of lineseg PQ else down
{
    return  (Q.first-P.first)*(R.second-P.second)-(R.first-P.first)*(Q.second-P
        .second);
}
void hull(vector<pair<long,long> > &P,vector<pair<long,long> > &L,vector<pair
    <long,long> > &U)
{
    int j=0,k=0,n=P.size();
    sort(P.begin(),P.end());
    U.resize(2*n);
    L.resize(2*n);
    for(int i=0; i<n; i++)
    {
        while(j>=2 && cross(L[j-2],L[j-1],P[i])<=0)
            j--;
        while(k>=2 && cross(U[k-2],U[k-1],P[i])>=0)
            k--;
        L[j++]=P[i];
        U[k++]=P[i];
    }
    U.resize(k);
    L.resize(j);
}
long fun(pair<long,long> P ,pair<long,long> Q)
{
    return (P.first-Q.first)*(P.first-Q.first)+(P.second-Q.second)*(P.second-Q
        .second);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        cin>>n;
    for(int i=1;i<=n;i++)
      cin>>arr[i].x>>arr[i].y;
    long t,n,k1,k2;
    vector<pair<long,long> >v,U,L;
    cin>>q;
    while(q--)
    {
        v.clear();
        U.clear();
        L.clear();
        cin>>l>>r;
        for(int i=l; i<=r; i++)
            v.push_back(make_pair(arr[i].x,arr[i].y));
        if(v.size()==1)
        {
            cout<<"0\n";
            continue;
        }
        hull(v,L,U);
        int i=0,j,m;
        j=L.size()-1;
        m=U.size()-1;
        long dist=-1;
        while(i<m || j>0)
        {
            dist=max(dist,fun(U[i],L[j]));
            if(i==m)
                j--;
            else if(j==0)
                i++;
            else
            {
                if ( (U[i+1].second-U[i].second) * (L[j].first-L[j-1].first) > 
                    (L[j].second-L[j-1].second) * (U[i+1].first-U[i].first) )
                    i++;
                else
                    j--;
            }
        }
        cout<<dist<<endl;
    }
}