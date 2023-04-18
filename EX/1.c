//請用 C 寫一個積分函數，然後呼叫它

#include <stdio.h>

double func(double x) {
    return x * x;
}

double integral(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; //計算每個梯形的高度
    double sum = 0.0;
    double x;

    sum += (f(a) + f(b)) / 2.0; //加上首尾兩個端點的值

    for (int i = 1; i < n; ++i) {
        x = a + i * h;
        sum += f(x);
    }
    sum *= h; //乘上每個梯形的底邊長度

    return sum;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 100;
    double result = integral(func, a, b, n);
    printf("The integral of x^2 from %lf to %lf is %lf\n", a, b, result);
    return 0;
}
