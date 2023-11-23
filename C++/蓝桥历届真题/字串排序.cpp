#include <bits/stdc++.h>
using namespace std;

char s[10005];
char temp[10005];

int main(){
	scanf("%s", s);
	int cnt = 0;
	int num = strlen(s);
	for(int i = 0; i < num; i++){
		int x = 0;
		for(int j = i; j < num; j++){
			temp[x++] = s[j];
			set<char> st;
			int num_temp = strlen(temp);
			for(int k = 0; k < num_temp; k++)
				st.insert(temp[k]);
			cnt += st.size();
		}
	}
	printf("%d", cnt);
	return 0;
} 
