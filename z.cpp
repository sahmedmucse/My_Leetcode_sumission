#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout << "NO"<<endl;
#define testcase int t; cin>>t; while(t--)


int main()
{
   string s,p;

   cin>>s>>p;

   map<char,int>st;

   for(auto &u:p)
   {
     st[u]++;
   }

   vector<int>ans;

   map<char,int>cr;

   int l=0,r=0;

   while(r<s.size())
   {
     cr[s[r]]++;

     while(cr[s[r]] > st[s[r]])
     {
       cr[s[l]]--;
       l++;
     }

     bool kom = false;

     for(char c='a'; c<='z'; c++)
     {
       if(cr[c] < st[c])
       {
         kom = true;
       }
     }

     if(kom == false )
     {
       ans.push_back(l);
     }
     r++;


   }

    for(auto u:ans) cout << u <<" ";
   cout << endl;


}

// leetcode
// 438. Find All Anagrams in a String
