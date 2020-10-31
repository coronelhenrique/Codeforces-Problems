#include <bits/stdc++.h>
using namespace std;
 
int main(){
	
	int t;
	scanf("%d", &t);
	
	for(; t > 0; t--){
		int n, ans = 0, l[110];
		scanf(" %d", &n);
		
		for(int i = 0; i < n; i++) scanf(" %d", &l[i]);
		
		sort(l, l + n);
		
		for(int i = 1; i < n; i++) ans = ans || l[i] == l[i - 1] + 1;
		
		printf("%d\n", 1 + ans);
	}
		
	return 0;
}
