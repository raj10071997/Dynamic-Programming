#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cout<<"enter the no. of elements"<<endl;
	cin>>n;
	
	int a[n];
	cout<<"enter the elements"<<endl;
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int DP[n][2];
	//DP[i][0] contains the answer including the ith element and taking it greater than the previous number
	//DP[i][1] if it takes the ith element smaller than the preivous number.
	
	DP[0][0]=1;
	DP[0][1]=1;
	
	for(int i=0;i<n;i++)
    {
        DP[i][0]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
                DP[i][0]=max(DP[i][0],DP[j][1]+1);
        }
        DP[i][1]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
                DP[i][1]=max(DP[i][1],DP[j][0]+1);
        }
    }
    int maximum=1;
    cout<<"the maximum subsequence is ";
    for(int i=0;i<n;i++)
        maximum=max(maximum,max(DP[i][0],DP[i][1]));
    cout<<maximum<<endl;
    return 0;
}
