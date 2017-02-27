#include <bits/stdc++.h>
using namespace std;


#define mst(x,a) memset(x,a,sizeof(x))


inline int  b_search(int DP[], int l,int r,int key)
{
    while(r>l+1)
    {
        int g=l+(r-l)/2;
        if(DP[g]>=key){
        	r=g;
		}
        else{
        	l=g;
		}
    }
    return r;
}

int solve(int a[], int  l)
{
    int length=1;
    int dp[10001];
    mst(dp,0);
    dp[0]=a[0];
    for(int i=1;i<l;i++)
    {
        if(a[i]<dp[0])
        	dp[0]=a[i];

        else if(a[i]>dp[length-1])
        	dp[length++]=a[i];
        else
        	dp[b_search(dp,-1,length-1,a[i])]=a[i];
    }
    return length;
}

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
    	cin>>n;
    	int a[2*n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	a[i+n]=a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
        	ans=max(ans,solve(a+i,n));
        }
        cout<<ans<<endl;
    }
    return 0;
}
