#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	scanf("%d\n", &t);
	
	for(; t > 0; t--){
	
		char ans[9][9];
		for(int i = 0; i < 9; i++) {for(int j = 0; j < 9; j++) {scanf("%c", &ans[i][j]); if(ans[i][j] == '1') ans[i][j] = '2';} scanf("\n");}
		
		for(int i = 0; i < 9; i++) {for(int j = 0; j < 9; j++) printf("%c", ans[i][j]); printf("\n");}
	}
	
	return 0;
}
