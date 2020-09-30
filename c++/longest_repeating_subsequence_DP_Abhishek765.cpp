#include <bits/stdc++.h>
using namespace std;

#define IOS	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
//for debugging
#define deb(x) cout << #x << " " << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define pqb priority_queue<int>					  /* Max heap*/
#define pqs priority_queue<int, vi, greater<int>> /* Min heap*/
#define setbits(x) _builtin_popcountll(x)		  //finding the no. of set bits
#define zrobits(x) _builtin_ctzll(x)			  //finding the no. of zeroes after the last one
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mka(arr, n, type) type *arr = new type[n];

#define f(i, n) for (int i = 0; i < n;i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define cd(x, y) int x, y; cin >> x >> y;
#define w(x)  int x;cin >> x;while(x--)
#define ws(x) int x;scanf("%d", &x);while(x--)

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int MAX = 26;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //for shuffling of array
void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
  ll gcd(ll a, ll b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}
ll LCM(ll a, ll b){
	ll lcm = (a*b) / gcd(a,b);

	return lcm;
}
string LRS(string s1){
	int n = s1.length();
    int look[n + 1][n + 1];
    int i, j;
	string ans;
    for( i = 0; i <=n; i++){
        for ( j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0){
                look[i][j] = 0;
            }

            else if(s1[i - 1] == s1[j - 1] && i != j){
                look[i][j] = 1 + look[i - 1][j - 1] ;
				ans.pb(s1[i - 1]);
				i++;
            }
            else{
                look[i][j] = max(look[i - 1][j], look[i][j-1]);
                }
            }  
        }
	

     return ans;  
}
int main()
{   
	IOS;
	av();
	w(t){
			int len;
			cin>>len;
			string s;
			cin>>s;
			// string ans = LRS(s);
			// ans.erase(prev(ans.end()));
			// string newans;
			// for(int i = 0; i < ans.length() - 1; i++){
			// 	newans.pb(ans[i]);
			// }
			cout<<LRS(s)<<endl;

			
		}
	
	return 0;
}