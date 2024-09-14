#include<bits/stdc++.h>
using namespace std;

int phi(int n){
	int ret = n;
	int root = sqrt(n+1);
	for(int i=2;i<=root;i++){
		if(n%i == 0){
			while(n%i==0) n/=i;
			ret -= ret / i;
		}
	}
	if(n>1){
		ret -= ret/n;
	}
	return ret;
}

int main(){
	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		cout << phi(n) << endl;
	}
	return 0;
}
