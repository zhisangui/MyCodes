#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    int n;
    int m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ){
        map< string, map<string,int> > ma;
        scanf("%d", &m);
        while(m --){
            string sa, sb;
            int x;
            cin >> sa >> sb >> x;
            ma[sb][sa] += x;
        }
        for(auto it = ma.begin(); it != ma.end(); it ++){
            cout << it->first << endl;
            for(auto ii = it->second.begin(); ii != it->second.end(); ii ++){
                cout << "   |----" << ii->first << '(' << ii->second << ')' << endl;
            }
        }
        if(i != n)
            cout << endl;
    }
    return 0;
}