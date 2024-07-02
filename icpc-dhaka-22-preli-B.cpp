// USER: "Ab.Mahin"
// Problem: B. Transform the Array
// Contest: CodeMarshal - 2022 ICPC Asia Dhaka Regional Online Preliminary Contest Hosted by Green University of Bangladesh
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-22-preli/problems/B
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e7 + 5;
ll spf[N];

void siv(){
	for(ll i =  1; i < N; i++) spf[i] = i;
	for(ll i = 2; i < N; i++){
		for(ll j = i; j < N; j += i){
			spf[j] = min(spf[j], i);
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	siv();
    while(t--){
        ll n;
        cin >> n;
        ll a[n], b[n], Aok = 1, Bok = 1;
        map<ll, ll> mp;
        
        ll g = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	g = __gcd(a[i], g);
        	ll x =  a[i];
        	while(x != 1){
        		mp[x] = 1;
        		x /= spf[x];
        	}
        }
        
        
        g = 0;
        for(ll i = 0; i < n; i++){
        	cin >> b[i];
        	g = __gcd(b[i], g);
        	ll x =  b[i];
        	while(x != 1){
        		if(!mp[x]) Aok = 0;
        		x /= spf[x];
        	}
        }
        
       
        
        for(ll i = 0; i < n; i++){
        	Bok &= (a[i] == b[i]);
        }
        
        
                
        cout << "Case " << tt++ << ": " << (Aok ? "Yes" : "No") << ' ' << (Bok ? "Yes" : "No") << '\n';
    }
    
    
    return 0;
}