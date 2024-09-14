#include <bits/stdc++.h>
using namespace std;

#define range 100002

vector<int> divisors[range];
int sum[range], numbers[range];

void sieve(){
	for(int i=0;i<range;i++){
		sum[i] = 0;
		numbers[i] = 0;
	}
	for(int i=1;i<range;i++){
		for(int j=i;j<range;j+=i){
			divisors[j].push_back(i);
			numbers[j]++;
			sum[j] = sum[j] + i;
		}
	}
}

int main(int argc, char const *argv[])
{
	sieve();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << "Factorials of " << n << " : \n";
		for(int i:divisors[n]){
			cout << i << " ";
		}
		cout << endl;
		cout << "Numbers: " << numbers[n] << endl;
		cout << "Sum: " << sum[n] << endl;
	}
	return 0;
}
