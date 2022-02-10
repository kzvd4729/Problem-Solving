/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-28 01:16:40                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1080
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,q,bit[100005],l,r,n,x1,x;
string s;
char c;
void upd(int id)
{
    for( ; id<=n;id+=id&-id)
    {
        bit[id]++;
    }
}
int get(int id)
{
    int sum=0;
    for( ; id>0;id-=id&-id)
    {
        sum+=bit[id];
    }
    return sum;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    tc=0;
    while(t--)
    {
        memset(bit,0,sizeof(bit));
        cin>>s;
        n=s.size();
        cout<<"Case "<<++tc<<":"<<endl;
        cin>>q;
        while(q--)
        {
            cin>>c;
            if(c=='I')
            {
                cin>>l>>r;
                upd(l);
                upd(r+1);
            }
            else
            {
                cin>>x1;
                x=get(x1);
                if(x%2==1)
                {
                    if(s[x1-1]=='0')cout<<'1'<<endl;
                    else cout<<'0'<<endl;
                }
                else cout<<s[x1-1]<<endl;
            }

        }

    }
    return 0;
}