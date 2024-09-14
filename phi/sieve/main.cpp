#include<bits/stdc++.h>
#define range 1000
using namespace std;

int phi[range+1], mark[range+1];

void sieve(){
	for(int i=0;i<=range;i++){
		phi[i] = i;
		mark[i] = 1;
	}
	for(int i=2;i<=range;i++){
		if(mark[i]){
			for(int j=i+i;j<=range;j+=i){
				phi[j] = phi[j] / i * (i-1);
				mark[j] = 0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	sieve();
	int t;cin>>t;
	for (int i = 0; i < t;i++)
	{
		int n; cin >> n;
		cout << phi[n] << endl;
	}
	return 0;
}
