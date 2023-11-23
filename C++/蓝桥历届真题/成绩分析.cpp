#include <cstdio>

int main(){
    int n,a;
    scanf("%d", &n);
    int Max = -1, Min = 105;
    double sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        sum += 1.0 * a;
        if(a < Min)
            Min = a;
        if(a > Max)
            Max = a;
    }
    double average = sum / n;
    printf("%d\n%d\n%.2f\n", Max, Min, average);
    return 0;
} 