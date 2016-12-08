#include<iostream>
//#include <ctime>
#include <cstdlib>
using namespace std;
int const S = 100;//times

long long mod_mul(long long a, long long b, long long n) {
	long long res = 0;
	while (b) {
		if (b & 1)
			res = (res + a) % n;
		a = (a + a) % n;
		b >>= 1;
	}
	return res;
}

long long mod_exp(long long a, long long b, long long n) {
	long long res = 1;
	while (b) {
		if (b & 1)
			res = mod_mul(res, a, n);
		a = mod_mul(a, a, n);
		b >>= 1;
	}
	return res;
}
long long  pow(long long  num, long long  exp, long long  mod) {
		//如果num是个longlong 那么会出问题
	if (num == 0) return 0;
	long  long ans = 1;
	long  long base = num%mod;
	while (exp != 0) {
		if(exp%2==1)
		ans *= base;
		ans %= mod;
		exp /= 2;
		base = (base*base) % mod;
	}
	return ans;
}
//prime return true 
bool millerRabin(long long  n) {
	if (n == 2) return true;
	if (n < 2) return false;
	if (n % 2 == 0) return false;
	//剩下都是大于2 的奇数
	int ary[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
};

	for (int i = 0; i < 70; i++) {
		//2-n-1 
		long long  a = (rand() % (n-2 ))+2;
	//	cout << a << endl;
		long long   u = n - 1;
		while (u % 2 == 0) u /= 2;
		long long  x = mod_exp(a, u, n);
		//cout << x <<" /"<<a<< endl;

		while (u < n) {
			long long  y = mod_mul(x, x, n);
			if (y == 1 && x != 1 && x != n - 1) return false;
			x = y;
			u = u+u;
		}
		if (x != 1) return false;
	}
	return true;
}
int main() {
	long long n;
	int t;
	cin >> t;
	while (t--) 
	{
		cin >> n;
		if (millerRabin(n))  
		{
			cout << "Yes\n";
		}
		else 
		{
			cout << "No\n";
		
		}
	}
	char c;
	cin >> c;
	return 0;
}