#define nl "\n"
#define all(x) (x).begin(), (x).end()
int dp[1001][1001];
void printLCS(string s, string t, int n, int m){
	for(int i=0; i<=m; i++)
		dp[0][i]=0;
	for(int i=0; i<=n; i++)
		dp[i][0]==0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i-1]==t[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j ]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int res=dp[n][m];
	string str="";
	int i=n; int j=m;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			str.pb(s[i-1]);
			i--; j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else
			j--;
	}
	reverse(all(str));
	cout<<res<<nl;
	cout<<str<<nl;
}
