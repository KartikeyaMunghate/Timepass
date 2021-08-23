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
	int n = rand() % 500 + 1, m = rand() % 500 + 1;
// srand(time(0));
	cin>>n>>m;
	int fl = 0;
	if(n < m){
		fl = 1;
		swap(n, m);
	}
	vector<string> ans(n, string(m, ' '));
	int r = rand() % (n * m);
	int g = rand() % (n * m - r);
	int b = n * m - r - g;
	cin>>r>>g>>b;
	// dbg(n, m, r, g, b);
	int a11 = r, b11 = g, c11 = b;
	int ma = max({r, g, b});
	if(ma <= (m * n + 1) / 2){
		if(r == ma){
			rep(i, n){
				rep(j, m){
					if(r and (i+j)%2 == 0)
						r--, ans[i][j] = 'R';
					else if(g and (i+j) % 2 == 0)
						g--, ans[i][j] = 'G';
					else if(b and (i+j) % 2 == 0)
						b--, ans[i][j] = 'B';
				}
			}
			rep(i, n){
				rep(j, m){
					if(r and (i+j)%2 == 1)
						r--, ans[i][j] = 'R';
					else if(g and (i+j) % 2 == 1)
						g--, ans[i][j] = 'G';
					else if(b and (i+j) % 2 == 1)
						b--, ans[i][j] = 'B';
				}
			}
		}else if(g == ma){
			rep(i, n){
				rep(j, m){
					if(g and (i+j) % 2 == 0)
						g--, ans[i][j] = 'G';
					else if(r and (i+j)%2 == 0)
						r--, ans[i][j] = 'R';
					else if(b and (i+j) % 2 == 0)
						b--, ans[i][j] = 'B';
				}
			}
			rep(i, n){
				rep(j, m){
					if(g and (i+j) % 2 == 1)
						g--, ans[i][j] = 'G';
					else if(r and (i+j)%2 == 1)
						r--, ans[i][j] = 'R';
					else if(b and (i+j) % 2 == 1)
						b--, ans[i][j] = 'B';
				}
			}
		}else {
			rep(i, n){
				rep(j, m){
					if(b and (i+j) % 2 == 0)
						b--, ans[i][j] = 'B';
					else if(r and (i+j)%2 == 0)
						r--, ans[i][j] = 'R';
					else if(g and (i+j) % 2 == 0)
						g--, ans[i][j] = 'G';
				}
			}
			rep(i, n){
				rep(j, m){
					if(b and (i+j) % 2 == 1)
						b--, ans[i][j] = 'B';
					else if(r and (i+j)%2 == 1)
						r--, ans[i][j] = 'R';
					else if(g and (i+j) % 2 == 1)
						g--, ans[i][j] = 'G';
				}
			}
		}
	}else if(r == ma){
		rep(i, n){
			rep(j, m){
				if(g){
					ans[i][j] = 'G';
					g--;
				}else if(r){
					ans[i][j] = 'R';
					r--;
				}else{
					ans[i][j] = 'B';
					b--;
				}
			}
		}
	}else if(g == ma){
		rep(i, n){
			rep(j, m){
				if(r){
					ans[i][j] = 'R';
					r--;
				}else if(g){
					ans[i][j] = 'G';
					g--;
				}else{
					ans[i][j] = 'B';
					b--;
				}
			}
		}
	}else {
		rep(i, n){
			rep(j, m){
				if(r){
					ans[i][j] = 'R';
					r--;
				}else if(b){
					ans[i][j] = 'B';
					b--;
				}else if(g){
					ans[i][j] = 'G';
					g--;
				}
			}
		}
	}
	// dbg("hi");
	int r111 = 0, b111 = 0, g111 = 0;
	rep(i, n){
		rep(j, m){
			if(ans[i][j] == 'R')
				r111++;
			if(ans[i][j] == 'B')
				b111++;
			if(ans[i][j] == 'G')
				g111++;
			int r1 = 0, b1 = 0, g1 = 0;
			if(i){
				if(ans[i - 1][j] == 'R')
					r1 = 1;
				if(ans[i - 1][j] == 'G')
					g1 = 1;
				if(ans[i - 1][j] == 'B')
					b1 = 1;
			}
			if(j){
				if(ans[i][j - 1] == 'R')
					r1 = 1;
				if(ans[i][j - 1] == 'G')
					g1 = 1;
				if(ans[i][j - 1] == 'B')
					b1 = 1;
			}
			if(i + 1 < n){
				if(ans[i + 1][j] == 'R')
					r1 = 1;
				if(ans[i + 1][j] == 'G')
					g1 = 1;
				if(ans[i + 1][j] == 'B')
					b1 = 1;
			}
			if(j + 1 < m){
				if(ans[i][j + 1] == 'R')
					r1 = 1;
				if(ans[i][j + 1] == 'G')
					g1 = 1;
				if(ans[i][j + 1] == 'B')
					b1 = 1;
			}
			// cout<<a11<<" "<<b11<<" "<<c11<<endl;
			assert(r1 + b1 + g1 <= 2);
		}
	}
	assert(r111 == a11 and g111 == b11 and b111 == c11);
	if(fl){
		rep(i, m){
			rep(j, n){
				cout<<ans[j][i];
			}
			ent;
		}
		return;
	}
	rep(i, n){
		cout<<ans[i]<<endl;
	}
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