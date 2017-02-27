#include <bits/stdc++.h>
using namespace std;

map<pair< pair<long long int,long long int>, pair<long long int,long long int> >,bool> m;

int main()
{
	cout<<"enter the height and width"<<endl;
	
	 long long int x,y;
	 cin>>x>>y;
	 
	 cout<<"enter the number of poor node"<<endl;
	 long long int n;
	 cin>>n;
	 
	 cout<<"enter the bad paths in a group of four"<<endl;
	 long long int a,b,c,d;
	 
	 for(long long int i=0;i<n;i++)
	 {
	 	cin>>a>>b>>c>>d;
	 	if(a+b==c+d+1)
	 		m[make_pair(make_pair(a,b),make_pair(c,d))]=1;
	 	else
	 		m[make_pair(make_pair(c,d),make_pair(a,b))]=1;
	 		
	 }
	 
	 long long int dp[x+1][y+1];
	 for(long long int i=0;i<=x;i++)
	 {
	 	for(long long int j=0;j<=y;j++)
	 	dp[i][j]=0;
	 }
	 
	 dp[0][0]=1;
	 
	 for(long long int i=0;i<=x;i++)
	 {
	 	for(long long int j=0;j<=y;j++)
	 	{
	 		pair< pair<long long int,long long int>, pair<long long int,long long int> >  v = make_pair(make_pair(i,j),make_pair(i,j-1));
	 		
	 		if(j>=1&& !m[v] )
	 				dp[i][j]+=dp[i][j-1];
	 				
	 		pair< pair<long long int,long long int>, pair<long long int,long long int> > hot = make_pair(make_pair(i,j),make_pair(i-1,j));
	 		if(i>=1&&!m[hot])
	 			dp[i][j]+=dp[i-1][j];
		 }
	 }
	 cout<<"Ans : ";
	 cout<<dp[x][y]<<endl;
	 
	 return 0;
}
