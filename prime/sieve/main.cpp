#include<bits/stdc++.h>

using namespace std;

int Prime[1000], nPrime = 0, range = 1000;
int mark[1001];

// 1 is prime, 0 not prime

void sieve(){
	for(int i=3;i<=range;i++) mark[i] = 1;
	mark[1] = 0;
	mark[2] = 1;
	Prime[nPrime++] = 2;
	int limit = sqrt(range+1);
	for(int i=4;i<=range;i+=2) mark[i] = 0;
	for(int i=3;i<=range;i+=2){
		if(mark[i]){
			Prime[nPrime++] = i;
			if(i<=limit){
				for(int j=i*i;j<=range;j+=2*i){
					mark[j] = 0;
				}
			}
		}
	}
	cout << "Total primes: " << nPrime << endl;
}

int main(){
	sieve();
	int t; cin >> t;
	while(t--){
		int a,b; cin >> a >> b;
		cout <<  a << "th prime is " << Prime[a-1] << endl;
		if(mark[b]) cout << b << " is a prime";
		else cout << b << " is not a prime";
		cout << endl;
	}
	return 0;
}
