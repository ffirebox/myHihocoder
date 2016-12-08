#include<iostream>

using namespace std;
int const S = 100;//times

int josephus(int n, int k) {
	//0-n-1   n numbers 
	if (n == 1) return 0;
	if (n < k) {
		int ret = 0;
		for (int i = 2; i <= n; i++) {
			ret = (ret + k) % i;
		}
		return ret;
	
	}
	int ret = josephus(n - n / k, k);
	if (ret < n%k)
		ret = ret - n%k + n;
	else
		ret = ret - n%k + (ret - n%k) / (k - 1);
	return ret;

}
int main() {
	int n,k;
	int t;
	cin >> t;
	while (t--) 
	{
		cin >> n>>k;
		cout << josephus(n, k) << endl;
	}
	char c;
	cin >> c;
	return 0;
}