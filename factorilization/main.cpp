#include <bits/stdc++.h>

#define range 2001

using namespace std;

int primes[range], currPrime = 0 ,mark[range];

void sieve(){
	int limit=sqrt(range+1);
	for(int i=0;i<range;i++) mark[i] = 1;
	mark[0] = 0;
	mark[1]= 0; mark[2] = 1;
	primes[currPrime++] = 2; 
	for(int i=4;i<=range;i+=2) mark[i] = 0;
	for(int i=3;i<range;i+=2){
		if(mark[i]){
			primes[currPrime++] = i;
			if(i<=limit){
				for(int j=i*i;j<=range;j+=i*2){
					mark[j] = 0;
				}
			}
		}
	}
}

typedef struct Factorial{
	int num;
	int power;
	Factorial(int a,int b): num(a), power(b){}
} fact;

int main(){
	sieve();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << n << " = ";
		int p = 0, power = 0;
		vector<fact> facts;
		while(n>1){
			power = 0;
			while(n%primes[p] == 0){
				power++;
				n/=primes[p];
			}
			if(power > 0){
				fact f(primes[p],power);
				facts.push_back(f);
			}
			p++;
		}
		for(int i=0;i<facts.size();i++){
			cout << facts[i].num << '^' << facts[i].power << ' ';
		}
		cout << endl;
	}
	return 0;
}

