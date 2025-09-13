#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define yes cout << "YES"<<endl;
#define no cout << "NO"<<endl;
#define testcases int t; cin>>t; while(t--)

bool isOn(int x, int i)
{
    if(x&(1<<i))
    {
        return true;
    }
    else
    {
        return false ;
    }
}


int main()
{
    optimize() ;

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
       cin >> v[i];
    }

    int l=0,r=0;
    int ans = 1;

    vector<int>currerntBitcount(31);

    while(r<n)
    {
        bool invalid =false;
        for(int i=0; i<31; i++)
        {
            if(isOn(v[r],i))
            {
                currerntBitcount[i]++;
                if(currerntBitcount[i] > 1)
                {
                    invalid =true ;
                }
            }
        }

        if( invalid == false)
        {
            ans=max(ans,r-l+1);
            r++;
        }
        else
        {
            while(1)
            {
                invalid =false ;
                for(int i=0; i<31; i++)
                {
                    if(isOn(v[l],i))
                    {
                        currerntBitcount[i]--;
                        if(currerntBitcount[i] > 1)
                        {
                            invalid =true;
                        }
                    }
                }
                l++;
                if(invalid)
                {
                    continue;
                }
                else
                {
                    ans = max(ans,r-l+1);
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

