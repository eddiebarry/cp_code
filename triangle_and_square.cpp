#include<bits/stdc++.h>
using namespace std;
long long si(){
	long long x;
	cin>>x;
	return x;
}

pair<double, double>intersection(pair<int,int> a, pair<int,int> b, pair<int,int> c, pair<int,int> d){
	//c2 - c1 / m1 - m2
	double x = 
}

bool chk(pair<double, double> ans, int a, int b, int x, int y){

}

int main(){
	long long t = si();
	while(t--){
		long long a = si(), b = si(), x = si(), y = si();

		pair<double, double> bottom = intersection(make_pair(a,y), make_pair(x+b,y+b), make_pair(0,y), make_pair(x,y+b));
		pair<double, double> right  = intersection(make_pair(x+b,0), make_pair(x,y), make_pair(x+b,a), make_pair(x,y+b));
		pair<double, double> up     = intersection(make_pair(a,y+b), make_pair(x+b,y), make_pair(0,y+b), make_pair(x,y));
		pair<double, double> left   = intersection(make_pair(x,a), make_pair(x+b,y+b), make_pair(x,0), make_pair(x+b,y));

		if()
	}
}