#include <bits/stdc++.h>
using namespace std;
 
int m[100100], l[100100];
 
int main(){
	
	int n, ans = 100100;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) scanf(" %d", &l[i]);
	
	for(int i = 0; i < n / 2; i++) {
		if(l[i] - i > 0) m[l[i] - i]++;
		if(l[n - i - 1] - i > 0) m[l[n - i - 1] - i]++;
	}
	
	if(n % 2) {int i = n / 2; if(l[i] - i > 0) m[l[i] - i]++;}
	
	for(int i = 1; i <= 100000; i++) ans = min(ans, n - m[i]);
	
	printf("%d\n", ans);
}
