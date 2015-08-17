

#include <iostream>
#include <string>
#include <vector>


std::vector<long long> fibonacci()
{
	std::vector<long long> fibs;
	fibs[0] = 0;
	fibs[1] = 1;
	fibs[2] = 2;
	for(int i=3; i<90; ++i)
		fibs[i] = fibs[i-1]+fibs[i-2];
	return fibs;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin>>t;
	std::vector<long long> fibs=fibonacci();
	while(t--)
	{
		long long n;
		std::cin>>n;	
		bool f=false;
		int i=1;
		for( ; i<fibs.size() ; ++i)
		{
			if( n == fibs[i]){
				std::cout<<i<<"\n";
				break;
			}
			if( fibs[i] > n){
				f=true;
				break;
			}
		}
		if(f)
			std::cout<<i-1<<"\n";
	}

}
