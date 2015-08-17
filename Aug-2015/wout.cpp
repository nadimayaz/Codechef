

//https://www.codechef.com/AUG15/problems/WOUT

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	std::ios_base::sync_with_stdio(false);
	int  t;
	std::cin>>t;

	while(t--)
	{
		long long n,h;
		std::cin>>n>>h;
		std::vector< long long> fi(n+1,0);

		for( long long i=0 ; i< n ; ++i)
		{
			long long l,h;
			std::cin>>l>>h;
			l=read();
			h=read();
			fi[l]++;
			fi[h+1]--;
		}

		for( long long i=1 ; i<n ; ++i)
			fi[i]+=fi[i-1];


		std::vector< long long> comm(n,0);
		comm[0]=fi[n-1];
		for( long long i=1 ; i<n ; ++i)
			comm[i]=comm[i-1]+fi[n-i-1];
		
		 long long ans=(comm[h-1]);
		for( long long i=1 ; i<n-h+1 ; ++i)
		{
			 long long tmp=(comm[i+h-1]-comm[i-1]);
			if( ans < tmp)
				ans=tmp;
		}
		std::cout<<ans<<"\n";
	}
}
