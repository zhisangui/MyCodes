#include <cstdio>
#include <stack>
int res[100];
using namespace std;
int main(){
    int n;
    int in[100];
    int out[100];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i ++){
            scanf("%1d", &in[i]);
        }
        for(int i = 0; i < n; i ++){
            scanf("%1d", &out[i]);
        }
        stack<int> st;
        int cntIN = 0, cntOUT = 0;
        int count = 0;
        for(int i = 0; i <= 3*n; i ++){
            if(st.empty() && cntIN < n){
                st.push(in[cntIN++]);
                res[count++] = 1;
            }
            if(!st.empty() && out[cntOUT] == st.top()){
                st.pop();
                cntOUT++;
                res[count++] = 0;
            }
            else if(cntIN != n){
                st.push(in[cntIN++]);
                res[count ++] = 1;
            }
            /*if(count == 2*n && st.empty())
                break;*/
        }
        if(count == 2*n){
            printf("Yes.\n");
            for(int i = 0; i < count; i ++){
                if(res[i] == 1)
                    printf("in\n");
                else
                    printf("out\n");
            }
        }
        else    
            printf("No.\n");
        printf("FINISH\n");
    }
    return 0;
}