/****************************************************************************************
*  @author: kzvd4729                                         created: 20-02-2018 20:36:25                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.29 sec                                        memory_used: 45.5M                                
*  problem: https://www.codechef.com/problems/TRICHEF
****************************************************************************************/
#include<bits/stdc++.h>
#define ll int
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define pi 2*acos(0.0)
#define eps .1e7
using namespace std;
vector<ll>v[5];
inline double area(double x,double y){return 0.5*x*y;}
//vector<double>vmid;
ll ara[2000006],ara2[2000006],a[2000006],b[2000006];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,t,test=1,q,n;
    ll x,x2,x3,p;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        x=x2=x3=0;
        for(i=0;i<=3;i++)v[i].clear();
        for(i=0;i<=2000000;i++)ara[i]=ara2[i]=a[i]=b[i]=0;
        //vmid.clear();
        //cin>>n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            //cin>>p>>q;
            scanf("%d%d",&p,&q);
            v[p].pb(q);
            if(p==1)x++;
            if(p==2)x2++;
            if(p==3)x3++;
            if(p==2)
            {
                ara[2*q]=1;
                ara2[2*q]=1;
            }
            if(p==1)
            {
                a[2*q]=1;
            }
            if(p==3)
            {
                b[2*q]=1;
            }
        }
//        for(i=1;i<=3;i++)
//        {
//            for(j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
//            cout<<endl;
//        }
//        cout<<x<<" "<<x2<<" "<<x3<<endl;
        double rslt=0;
        ll temp=0,k=0;
        for(i=0;i<=2000000;i++)
        {
            if(ara[i]==1&&k==0)
            {
                temp=i;
                k++;
                ara[i]=0;
            }
            else
            {
                if(ara[i]==1)
                {
                    ara[i]=(i-temp)*k;
                    double ex=.5*ara[i]*(x+x3)/2;
                    rslt+=ex;
                    k++;
                }
                else
                {
                    ara[i]=(i-temp)*k;
                }
            }
        }
        temp=0;
        k=0;
        for(i=2000000;i>=0;i--)
        {
            if(ara[i]==1&&k==0)
            {
                temp=i;
                k++;
                ara2[i]=0;
            }
            else
            {
                if(ara[i]==1)
                {
                    ara2[i]=(temp-i)*k;
                    k++;
                }
                else
                {
                    ara2[i]=(temp-i)*k;
                }
            }
        }
//        for(i=1;i<=6;i++)cout<<ara[i]<<" ";
//        cout<<endl;
//        for(i=1;i<=6;i++)cout<<ara2[i]<<" ";
//        cout<<endl;
        temp=0,k=0;
        for(i=0;i<=2000000;i++)
        {
            if(a[i]==1&&k==0)
            {
                temp=i;
                k++;
                a[i]=0;
            }
            else
            {
                if(a[i]==1)
                {
                    a[i]=(i-temp)*k;
                    double ex=.5*a[i]*(x2+2*x3)/2;
                    rslt+=ex;
                    k++;
                }
                else
                {
                    a[i]=(i-temp)*k;
                }
            }
        }
        temp=0,k=0;
        for(i=0;i<=2000000;i++)
        {
            if(b[i]==1&&k==0)
            {
                temp=i;
                k++;
                b[i]=0;
            }
            else
            {
                if(b[i]==1)
                {
                    b[i]=(i-temp)*k;
                    double ex=.5*b[i]*(x*2+x2)/2;
                    rslt+=ex;
                    k++;
                }
                else
                {
                    b[i]=(i-temp)*k;
                }
            }
        }
        for(i=0;i<v[1].size();i++)
        {
            for(j=0;j<v[3].size();j++)
            {
                ll mid=(v[1][i]+v[3][j]);
                double ex=ara[mid]*1.00/2;
                rslt+=ex;
                ex=ara2[mid]*1.00/2;
                rslt+=ex;
            }
        }
//        for(i=0;i<vmid.size();i++)
//        {
//            cout<<vmid[i]<<" ";
//        }
//        cout<<endl;
//        cout<<rslt<<endl;
        //cout<<setprecision(6)<<fixed<<rslt<<endl;
        printf("%.2lf\n",rslt);
    }
    return 0;
}