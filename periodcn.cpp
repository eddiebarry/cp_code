#include<bits/stdc++.h>
using namespace std;
long long si(){
	long long x;
	cin>>x;
	return x;
}
int main(){
	int t = si();
	set<long long>s;
	for(int z = 32; z >= 1; z--){
		for(int i = 1; i * i  <= z; i++){		
		if(z%i==0){
			//i is  a factor
			long long basic = 1;
			for(int j = 1; j < i; j++){
				basic<<=1;
				basic|=1;
			}
			// std::cout<<std::bitset<32>(basic)<<std::endl;
			long long num = 0;
			for(int j = 0; j < z/i; j++){
				if(j%2==0){
					num<<=i;
					num+= basic;
				}
				else{
					num<<=i;
				}
			}
// std::cout<<std::bitset<32>(num)<<std::endl;
			s.insert(num);
			num = 0;
			for(int j = 0; j < z/i; j++){
				if(j%2==1){
					num<<=i;
					num+= basic;
				}
				else{
					num<<=i;
				}
			}
			s.insert(num);
			//32/i is a factor
			// std::cout<<std::bitset<32>(num)<<std::endl;

			basic = 1;
			for(int j = 1; j < z/i; j++){
				basic<<=1;
				basic|=1;
			}
			// std::cout<<std::bitset<32>(basic)<<std::endl;
			num = 0;
			for(int j = 0; j < i; j++){
				if(j%2==0){
					num<<=z/i;
					num+= basic;
				}
				else{
					num<<=z/i;
				}
			}
// std::cout<<std::bitset<32>(num)<<std::endl;
			s.insert(num);
			num = 0;
			for(int j = 0; j < i; j++){
				if(j%2==1){
					num<<=z/i;
					num+= basic;
				}
				else{
					num<<=z/i;
				}
			}
			s.insert(num);
// std::cout<<std::bitset<32>(num)<<std::endl;

		}
	}
	}
	
	std::vector<long long> v;
	for(auto x:s){
		v.push_back(x);
	}
	// for(auto x : v){
	// 	std::cout<<std::bitset<32>(x)<<" "<<x<<"\n";

	// }
	// cout<<v.size()<<"\n";
	// cout<<t<<"\n";
	while(t--){
		long long l = si(), r = si();
		long long ans = 0;
		for(auto x : v){
			if(x >= l && x <= r){
				ans++;
			}
			if(x >r){
				break;
			}
		}
		cout<<ans<<"\n";
	}

}