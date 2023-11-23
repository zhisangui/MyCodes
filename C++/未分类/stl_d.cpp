#include <cstdio>
#include <stack>
char s[1005];
using namespace std;
int main(){
    while(scanf("%s", s) != EOF){
        stack<char> st;
        for(int i = 0; s[i] != '\0'; i ++){
            if(s[i] == '(')
                st.push(s[i]);
            if(s[i] == 'B')
                break;
            if(s[i] == ')')
                st.pop();
        }
        printf("%d\n", st.size());
    }
    return 0;
}