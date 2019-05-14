#include<bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > mat;

int ans = 100000;
vector< vector<int> > matAns;
bool irrat = false;

int countBlanks( int i, int j )
{
	int cnt = 0;
	if( i>1 && !mat[i-1][j] )
		cnt++;
	if( i<n && !mat[i+1][j] )
		cnt++;
	if( j>1 && !mat[i][j-1] )
		cnt++;
	if( j<n && !mat[i][j+1] )
		cnt++;
	return cnt;
}

void testMat()
{
	int cnt = 0;
	for( int i=1;i<=n;i++ )
		for( int j=1;j<=n;j++ )
		{
			if( mat[i][j] )
			{
				cnt++;
				continue;
			}
			
			bool sat = false;
			
			if( i>1 && mat[i-1][j] && countBlanks(i-1, j)==1 )
				sat = true;
			if( i<n && mat[i+1][j] && countBlanks(i+1, j)==1 )
				sat = true;
			if( j>1 && mat[i][j-1] && countBlanks(i, j-1)==1 )
				sat = true;
			if( j<n && mat[i][j+1] && countBlanks(i, j+1)==1 )
				sat = true;
			
			if( !sat )
				return;
		}
	
	if( cnt < ans )
	{
		ans = cnt;
		matAns = mat;
	}
}

void find( int i, int j )
{
    if( i>n || j>n )
    {
        irrat = true;
        return;
    }
    
	if( i==n && j==n )
	{
		mat[i][j] = 1;
		testMat();
		mat[i][j] = 0;
		testMat();
		return;
	}
	
	int ni, nj;
	if( j==n )
	{
		ni = i+1;
		nj = 1;
	}
	else
	{
		ni = i;
		nj = j+1;
	}
	
	mat[i][j] = 1;
	find(ni, nj);
	mat[i][j] = 0;
	find(ni, nj);
}

int main() {
	
	cout<<"Matrix initialization started\n";
	n = 5;
	mat.resize(n+5);
	for( int i=1;i<=n;i++ )
	{
		mat[i].resize(n+5);
		for( int j=1;j<=n;j++ )
			mat[i][j] = 0;
	}
	cout<<"Matrix initialization finished\n";
	
	ans = 100000;
	
	find( 1, 1 );
	
	if( irrat )
	    cout<<"\nIrrational behaviour\n";
	else
	    cout<<ans<<endl;
	
	for( int i=1;i<=n;i++ )
	{
	    for( int j=1;j<=n;j++ )
	        cout<<matAns[i][j]<<" ";
	    cout<<endl;
	}
	
	return 0;
}