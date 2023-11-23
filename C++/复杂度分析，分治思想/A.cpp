#include <cstdio>
void hanoi(int n, char a, char c, char b){
    if(n == 1)
        printf("%d:%c->%c\n", 1, a, c);
    else{
        hanoi(n-1, a, b, c);
        printf("%d:%c->%c\n", n, a, c);
        hanoi(n-1, b, c, a);
    }
}
int main(){
    int n;
    char a, b, c;
    scanf("%d", &n);
    scanf(" %c %c %c", &a, &b, &c);
    hanoi(n, a, c, b);
    return 0;
}