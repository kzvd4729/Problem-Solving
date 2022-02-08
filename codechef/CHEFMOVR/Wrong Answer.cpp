/****************************************************************************************
*  @author: kzvd4729                                         created: 07-08-2017 11:43:44                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.27 sec                                        memory_used: 16.3M                                
*  problem: https://www.codechef.com/AUG17/problems/CHEFMOVR
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n, d;
        cin >>n >> d;
        ll arr[n + 1];
        ll s = 0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            s += arr[i];
        }
        ll avg = s / n;
        if(s % n)
        {
            cout << "-1" << endl;
            continue;
        }
        ll moves = 0, f = 0;
        for(int i=n; i >n-d; i--)
        {
            ll s = 0,c = 0;
            for(int j = i; j >=1;j-=d)
            {
                ///s+=arr[j];
                if(arr[j] < avg) {
                    moves += avg - arr[j];
                    arr[j - d] -= (avg - arr[j]);
                    arr[j] = avg;
                }
                else if(arr[j] > avg)
                {
                    moves += arr[j] - avg;
                    arr[j - d] += arr[j] - avg;
                    arr[j] = avg;
                }
                ///c++;
            }
            /*for(int j = i; j <= n; j += d)
            {
                if(avg != arr[j])
                {
                    cout << "-1" << endl;
                    f = 1;
                    break;
                }
            }
            if(f==1) break;
            if(s / c != avg)
            {
                cout << "-1" << endl;
                    f = 1;
                    break;
            }*/
        }
        for(int i=1;i<=n;i++)
        {
            if(arr[i]!=avg)f=1;
        }
        if(f == 0)
        {
            cout << moves <<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}