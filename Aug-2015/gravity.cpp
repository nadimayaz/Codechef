

#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::ios_base::sync_with_stdio(false);

	int t;
	std::cin>>t;

	while(t--)
	{
		std::string a,b;
		std::cin>>a>>b;

		if( a.size() != b.size()){
			std::cout<<"No\n";
			continue;
		}
		


		if(a[0]=='.' and b[0]=='#'){
			int move=1;
			int cnt=0;
			bool ch=true;
			for(; move<a.size() ; ++move )
			{
				if( a[move]=='#' and b[move]=='#')
					break;
				if( a[move]=='.' and ch ){
					continue;
				}
				else if( a[move]=='#' and ch){
					ch=false;
					cnt++;
					continue;
				}
				else if( b[move]=='.' and !ch){
					continue;
				}
				else if(b[move]=='#' and !ch){
					cnt++;
					ch=true;
					continue;
				}
			}
			
			if( move == a.size() )
				std::cout<<"Yes\n"<<cnt<<"\n";
			else
				std::cout<<"No\n";
		}
		
		else if(a[0]=='#' and b[0]=='.'){
			int move=1;
			int cnt=0;
			bool ch=true;
			for(; move<a.size() ; ++move )
			{
				if( a[move]=='#' and b[move]=='#')
					break;
				if( b[move]=='.' and ch ){
					continue;
				}
				else if( b[move]=='#' and ch){
					ch=false;
					cnt++;
					continue;
				}
				else if( a[move]=='.' and !ch){
					continue;
				}
				else if(a[move]=='#' and !ch){
					cnt++;
					ch=true;
					continue;
				}
			}
			
			if( move == a.size() )
				std::cout<<"Yes\n"<<cnt<<"\n";
			else
				std::cout<<"No\n";
		}
		else if(a[0]=='.' and b[0]=='.'){
			int move=1;
			int cnt=0;
			bool ch=true;
			for(; move<a.size() ; ++move )
			{
				if( a[move]=='#' and b[move]=='#')
					break;
				if( a[move]=='.' and ch ){
					continue;
				}
				else if( a[move]=='#' and ch){
					ch=false;
					cnt++;
					continue;
				}
				else if( b[move]=='.' and !ch){
					continue;
				}
				else if(b[move]=='#' and !ch){
					cnt++;
					ch=true;
					continue;
				}
			}
		
			if( move != a.size()){
				std::cout<<"No\n";
				continue;
			}
			 move=1;
			int _cnt=0;
			ch=true;
			for(; move<a.size() ; ++move )
			{
				if( a[move]=='#' and b[move]=='#')
					break;
				if( b[move]=='.' and ch ){
					continue;
				}
				else if( b[move]=='#' and ch){
					ch=false;
					_cnt++;
					continue;
				}
				else if( a[move]=='.' and !ch){
					continue;
				}
				else if(a[move]=='#' and !ch){
					_cnt++;
					ch=true;
					continue;
				}
			}
			
			cnt < _cnt ? std::cout<<"Yes\n"<<cnt<<"\n" : std::cout<<"Yes\n"<<_cnt<<"\n";
		}

		else
			std::cout<<"No\n";
	}
}
