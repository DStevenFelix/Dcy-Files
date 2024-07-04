#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    double x = (a * (b * b + 1)) / (a + b * b + 1);
    double ans = sqrt(x * x + a) + sqrt((b - x) * (b - x) + 1);
    printf("%.6lf\n", ans);
    return 0;
}
