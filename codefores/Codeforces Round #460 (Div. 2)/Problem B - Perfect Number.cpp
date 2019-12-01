#include <bits/stdc++.h>

using namespace std;

const int N = 3e7;

int cnt[N];

int main(){
	
	int x;
	cin >> x;

	int r = 0;

	for(int i = 1; i < N; ++i){
		cnt[i] = cnt[i / 10] + i % 10;
		if(cnt[i] != 10) continue;
		if(++r == x) {
			cout << i;
			break;
		}
	}

	return 0;
}
