#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<stack> // 使用C++自带的STL栈
using namespace std;

#define OK 0
#define ERROR -1
#define OVERFLOW -1
#define OPSETSIZE 7 // 运算符号集合长度，目前只有7个符号
typedef int Status;
char Prior[7][7] = {
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '<', '<', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '>', '>', '>', '>', '<', '>', '>',
    '<', '<', '<', '<', '<', '=', ' ',
    '>', '>', '>', '>', ' ', '>', '>',
    '<', '<', '<', '<', '<', ' ', '='
};
float Operate(float a, unsigned char theta, float b)
{
    float ans = 0;
    switch (theta)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    default:
        break;
    }
    return ans;
}
char OPSET[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#'}; // 运算符集合
Status In(char Test, char* TestOp)
{
    int len = strlen(TestOp);
    for(int i = 0; i < len; ++i)
    {
        if(Test == TestOp[i])
            return 1;
    }
    return 0;
}
char precede(char Aop, char Bop)
{
    int a, b;
    for(int i = 0; i < 7; ++i)
    {
        if(Aop == OPSET[i])
            a = i;
        if(Bop == OPSET[i])
            b = i;
    }
    return Prior[a][b];
}
float EvaluateExpression(string MyExp)
{
    // 算术表达式求值的算符优先算法。
    // 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合。
    stack<char> OPTR;   // 运算符栈，字符元素
    stack<double> OPND; // 运算数栈，实数元素
    char TempData[20];
    double Data, a, b, r;
    char theta, Dr[2];
    char c;
    int i = 0; // 用于控制字符串的位置移动
    // InitStack(OPTR); InitStack(OPND); 两行代码无用去掉
    // Push(OPTR, '#'); c = MyExpression; 原有的两行代码改造为下面两句
    OPTR.push('#');
    c = MyExp[0];
    
    strcpy(TempData, "\0");
    while(c != '#' || OPTR.top() != '#')
    {
        if(!In(c, OPSET))
        {
            // 读入的字符不是运算符，是 1 个数字
            Dr[0] = c;
            Dr[1] = '\0';
            strcat(TempData, Dr);
            c = MyExp[++ i]; // 读下一个字符
            if(In(c, OPSET))
            {
                Data = (float)atof(TempData);
                // Push(OPND, Data);
                //.......改造上一句代码为一句c++代码
                OPND.push(Data);
                strcpy(TempData, "\0");
            }
        }
        else
        {
            // 是运算符，开始进行计算
            switch(precede(OPTR.top(), c))
            {
                case '<':   // 栈顶元素优先权低
                    // Push(OPTR, *c);
                    OPTR.push(c);
                    // ........改造上一句代码为一句c++代码
                    // ........读下一个字符
                    c = MyExp[++ i];
                    break;
                case '=':   // 脱括号并接收下一字符
                    // Pop(OPTR, x);
                    OPTR.pop();
                    // ........改造上一句代码为1-2句c++代码
                    // ........读下一个字符
                    c = MyExp[++ i];
                    break;
                case '>':   // 退栈并将运算结果入栈
                    // Pop(OPTR, theta);
                    theta = OPTR.top();
                    OPTR.pop();
                    // Pop(OPND, b);
                    b = OPND.top();
                    OPND.pop();
                    // Pop(OPND, a);
                    a = OPND.top();
                    OPND.pop();
                    // Push(OPND, Operate(a, theta, b));
                    OPND.push(Operate(a,theta,b));
                    // ........把上面四句代码改造成7-8句c++代码
                    break;
            } // end switch
        }   // end else
    }   // end while
    // return GetTop(OPND);
    return OPND.top();
    // ........改造上一句代码为一句c++代码
}   // end function
int main()
{
    string Exp;
    int t;
    double result;
    cin >> t;
    while(t --)
    {
        cin >> Exp;
        result = EvaluateExpression(Exp);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}