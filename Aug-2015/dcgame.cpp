

//https://www.codechef.com/AUG15/problems/DCGAME

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>
#include <stack>

struct info
{
	long long value;
	long long less;
	long long equal;
	long long greater;
};



std::vector<info> nodes;

std::vector<long long> ints;

std::vector<std::pair<long long,long long> > fs;

std::vector<std::pair<long long,long long> > freqs;

std::map<long long,long long> f;


std::pair<long long,long long> binary_search(long long const & value)
{
	long long start=0;
	long long end= nodes.size()-1;

	while(start < end)
	{
		long long mid=start+((end-start)>>1);
		long long data = nodes[mid].value;
		if( nodes[start].value == value)
			return std::make_pair(start,start);
		else if ( data == value)
			return std::make_pair(mid,mid);
		else if ( nodes[end].value == value )
			return std::make_pair(end,end);
		else if( data > value)
		{
			if( end == mid)
				return std::make_pair(end,start);
			end=mid;
		}
		else {
			if( start == mid)
				return std::make_pair(end,start);
			start=mid;
		}
	}
	return std::make_pair(end,start);
}


struct node
{
	long long key;
	long long value;
};

std:: vector<node> v_k;
std:: vector<long long> r;
std:: vector<long long> l;
std:: vector< std::pair<long long,long long> > uf;


std:: vector<long long> leftsum;
std:: vector<long long> rightsum;

void rightsolve()
{
	r.resize(uf.size());
	
	std::stack<node> S;
	S.push(v_k[0]);

	for(long long i=1 ; i<v_k.size() ; ++i)
	{
		auto  next=v_k[i];

		if( !S.empty() )
		{
			auto element=S.top();
			S.pop();
			
			while(element.value <= next.value)
			{
				r[element.key]=(next.key-element.key-1);
				if( S.empty() )
					break;
				element=S.top();
				S.pop();
			}

			if( element.value > next.value)
				S.push(element);
		}
		S.push(next);
	}

	while( ! S.empty() )
	{
		auto element=S.top();
		S.pop();
		r[element.key]=(v_k.size()-element.key-1);
	}

}

void leftsolve()
{
	l.resize(uf.size());
	
	std::stack<node> S;
	S.push(v_k[v_k.size()-1]);

	for(long long i=v_k.size()-2 ; i>=0 ; --i)
	{
		auto  next=v_k[i];

		if( !S.empty() )
		{
			auto element=S.top();
			S.pop();
			
			while(element.value < next.value)
			{
				l[element.key]=(element.key-next.key-1);
				if( S.empty() )
					break;
				element=S.top();
				S.pop();
			}

			if( element.value >= next.value)
				S.push(element);
		}
		S.push(next);
	}

	while( ! S.empty() )
	{
		auto element=S.top();
		S.pop();
		l[element.key]=element.key;
	}

}


void uniqueFreq()
{
	long long cnt=1;
	for(long long i=1 ; i<ints.size() ; ++i)
	{
		if( ints[i-1] == ints[i] ){
			cnt++;
			continue;
		}
		uf.push_back( std::make_pair(ints[i-1],cnt));
		cnt=1;
	}
	uf.push_back( std::make_pair(ints[ints.size()-1],cnt));
}


std::vector< std::pair<long long, long long> > result;

void solution()
{
	for(long long i=0 ; i<uf.size() ; ++i)
	{
		long long N= i-1;
		long long M= N-l[i];
		long long LM= M<0 ? 0 : leftsum[M];
		long long LN= N<0 ? 0 : leftsum[N];

		long long O= i+1;
		long long P= O+r[i];
		long long RO= O>(uf.size()-1) ? 0 : rightsum[O];
		long long RP= P>(uf.size()-1) ? 0 : rightsum[P];


		long long left=LN-LM;
		long long right=RO-RP;
		long long ans= (uf[i].second*(left+right)) + (left*right) + ( uf[i].second*(uf[i].second+1)/2);
		result.push_back(std::make_pair(uf[i].first,ans));
	}

	std::sort(result.begin(),result.end());

	long long cnt=0;

	for(long long i=1 ; i<result.size() ; ++i)
	{
		if(result[i].first != result[i-1].first)
		{
			freqs.push_back(std::make_pair(result[i-1].first,result[i-1].second+cnt));
			cnt=0;
			continue;
		}
		cnt+=result[i-1].second;
	}
	freqs.push_back(std::make_pair(result[result.size()-1].first,result[result.size()-1].second+cnt));
}


void nlogn()
{
	uniqueFreq();
	for(long long i=0 ; i<uf.size() ; ++i)
		v_k.push_back({i,uf[i].first});

	leftsum.resize(uf.size());
	leftsum[0]=uf[0].second;
	for(long long i=1 ; i<uf.size() ; ++i)
		leftsum[i]=leftsum[i-1]+uf[i].second;

	rightsum.resize(uf.size());
	rightsum[0]=leftsum[leftsum.size()-1];
	for(long long i=1 ; i<uf.size() ; ++i)
		rightsum[i]=leftsum[leftsum.size()-1]-leftsum[i-1];
	
	rightsolve();
	leftsolve();

	solution();
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	long long n,q;
	std::cin>>n>>q;
	
	for(long long i=0 ; i<n ; ++i)
	{
		long long v;
		std::cin>>v;
		ints.push_back(v);
	}

	nlogn();
	long long total= (n*(n+1))/2;
	
	long long sum=0; // value - less - equal - greater 
	for(long long i=0 ; i<freqs.size() ; ++i)
	{
		nodes.push_back( { (freqs[i].first) ,sum, freqs[i].second,total-sum-(freqs[i].second)} );
		sum+=freqs[i].second;
	}

	std::string ans="";
	while(q--)
	{
		char ch; long long v;char who;
		std::cin>>ch>>v>>who;

		char decide;
		if( who == 'C' ) decide='D'; else decide='C';

		if( v > freqs[freqs.size()-1].first ){
			if( ch == '<' )
				ans+= ( total&1 ) ?	 who : decide;
			else
				ans+=decide;
		}

		else if( v < freqs[0].first )
		{
			if( ch == '>')
				ans+=( total&1)? who : decide;
			else
				ans+=decide;
		}
		else
		{
			std::pair<long long,long long> idx=binary_search(v);
			if( (idx.first) == (idx.second) )
			{
				if( ch == '<' )
					ans+= ((nodes[idx.first].less)&1) ? who : decide;
				else if( ch == '=' )
					ans+= ( (nodes[idx.first].equal)&1) ? who : decide;
				else
					ans+=( (nodes[idx.first].greater)&1)? who : decide;
			}
			else
			{
				if(ch == '=')
					ans+=decide;
				else if( ch == '<' )
					ans+=( (nodes[idx.first].less)&1) ? who : decide;
				else
					ans+=( (nodes[idx.second].greater)&1) ? who : decide;
			}
		}
	}
	std::cout<<ans;
}
