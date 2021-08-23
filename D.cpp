#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front
#define mt make_tuple
#define eb emplace_back

typedef int64_t ll;
#define int int64_t
#define LB(x,v) (ll)(lower_bound(x.begin(),x.end(),v)-x.begin())
#define UB(x,v) (ll)(upper_bound(x.begin(),x.end(),v)-x.begin())
#define len(x) (ll)x.length()
#define sz(x) (ll)x.size()
typedef pair<ll,ll> ii;
typedef long double ld; 
typedef vector<int> vi;
typedef vector<set<ll>> vset;

typedef vector<ll> vl;
typedef vector<ld> vd;
typedef unsigned long long ull;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while(token = strtok(NULL,", ")) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef LOCAL
#define dbg(...) { debugg(tokenizer(harg(__VA_ARGS__, \b\t-->Line)), __VA_ARGS__, __LINE__); cerr << endl;}
#else
#define dbg(...) { }
#endif

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define Rep(i, n) for (ll i = 1; i <= (n); i++)
#define repr(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r) - 1; i >= (l); i--)
#define all(a) a.begin(), a.end()
#define cinai(a, n) vi a(n); rep(fukre, n) { cin>>a[fukre]; }
#define cinal(a, n) vl a(n); rep(fukre, n) { cin>>a[fukre]; }
#define coutai(a, n) rep(fukre, n) { cout<<a[fukre]<<" "; } ent;
#define coutal(a, n) rep(fukre, n) { cout<<a[fukre]<<" "; } ent;
#define resize_vec(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define ms(dp, x) memset(dp, x, sizeof(dp))
#define endl '\n'
#define ent cout<<endl;

ll powm(ll a, ll b, ll mod) {
	ll res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
const ld pi = 3.14159265358979323846;
const ll mod = 1e9 + 7;
const ll N = 1000005;
const ll inf = 1e9;
const ll INF = 1e18;


void solve()
{
	int n, m;
	cin>>n>>m;
	int a11 = 0, a12 = 0, a21 = 0, a22 = 0;
	rep(i, n){
		string s;
		cin>>s;
		rep(j, m){
			if(s[j] == '.'){
				if((i + j) % 2 == 0)
					a11++;
				else
					a12++;
			}
			else{
				if((i + j) % 2 == 0)
					a21++;
				else
					a22++;
			}
		}
	}
	if(m * n % 2)
		cout<<a11 + a22<<endl;
	else
		cout<<n * m - max(a11 + a22, a21 + a12)<<endl;
}

#define testCases
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int tc = 1;
#ifdef testCases
	cin>>tc;
#endif
	for(int t = 1; t <= tc; t++)
	{
#ifdef LOCAL
	int tt = clock();
#endif
		// cout<<"Case #"<<t<<": ";
		solve();
		
#ifdef LOCAL
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}


// watch 