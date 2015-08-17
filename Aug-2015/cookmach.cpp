
//https://www.codechef.com/AUG15/problems/COOKMACH

#include <iostream>
#include <vector>


int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin>>t;

	while(t--)
	{

		int a,b;
		std::cin>>a>>b;


		int cnt=0;
		while(a&(a-1))
		{
			if(a&1)
				a=(a-1)>>1;
			else
				a=a>>1;
			cnt++;
		}

		int i;
		for(i=0 ; i<=32 ; ++i)
		{
			if(a&1)
				break;
			a=a>>1;
		}

		
		int j;
		for(j=0 ; j<=32 ; ++j)
		{
			if(b&1)
				break;
			b=b>>1;
		}

		std::cout<<(cnt+std::abs(i-j))<<"\n";

	}
}
