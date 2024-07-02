// USER: "Ab.Mahin"
// Problem: Beautiful Blocks Again
// Contest: LightOJ
// URL: https://lightoj.com/problem/beautiful-blocks-again
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
const ll N = 2e5 + 5;


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
	
    while(t--){
        ll n, m;
        cin >> n >> m;
        
        ll ans[n][m + 1]{0}, a[n * m];
        memset(ans, 0, sizeof ans);
        
        vector<pair<ll, ll>> v;
        
        for(ll i = 0; i < (n * m); i++){
        	cin >> a[i];
        	v.push_back({a[i], i});
        }
        
        for(ll i = 0; i < n; i++) ans[i][0] = 1;
        sort(v.begin(), v.end(), greater<pair<ll, ll>>());
        
        vector<ll> vec;
        ll sum = 0;
        for(ll i = 0; i < (n + m) - 1; i++){
        	vec.push_back(v[i].second);
        	sum += v[i].first;
        }     
        
        sort(vec.begin(), vec.end());
        cout << sum << '\n';
        ll x = n - 1, y = m;
        vector<pair<ll, ll>> p;
        p.push_back({n - 1, 1});
        
        
        ll res[n * m]{0};
        for(ll i = 0, j = 0; i < (n * m); i++){
        	if(i == vec[j]){
        		if(j < vec.size()) j++;
        		if(!ans[x][y]){
        			ans[x][y] = y;
        			res[i] = ans[x][y];
        			if(y -1 >= 0 && !ans[x][y - 1]){
        				if(x - 1 >= 0) p.push_back({x - 1, y});
        				y = y - 1;
        			}
        			else if(x - 1 >= 0) x = x - 1;
        		}
        		else{
        			if(x - 1 < 0) continue;
        			ans[x - 1][y] = y + 1;
        			res[i] = ans[x - 1][y];
        			x = x - 1;
        		}
        	}
        	else{
        		ll id = p.size() - 1;
        		ll l = p[id].first;
        		ll r = p[id].second;
        		p.pop_back();
        		
        		ans[l][r] = r;   
        		res[i] = ans[l][r];    		
        		l--;
        		if(r < y){
        			if(l == 0) l = n - 1, r++;
        		}
        		
        		if(l != - 1) p.push_back({l, r});
        	}
        }
        
        for(ll i = 0; i < (n * m); i++) cout << res[i] << ' ';
        cout << '\n';
        
    }
    
    
    
    return 0;
}