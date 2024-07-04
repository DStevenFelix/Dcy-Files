#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000;
int dp[MAXN][MAXN];
string a, b;

void printSteps(int i, int j) {
    if (i == 0 && j == 0) return;
    if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
        printSteps(i - 1, j);
        cout << "Delete " << a[i - 1] << " from A" << endl;
    }
    else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
        printSteps(i, j - 1);
        cout << "Insert " << b[j - 1] << " into A" << endl;
    }
    else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])) {
        printSteps(i - 1, j - 1);
        if (a[i - 1] != b[j - 1]) {
            cout << "Replace " << a[i - 1] << " with " << b[j - 1] << endl;
        }
    }
}

int main()
{
    cin >> a >> b;
    int len1 = a.length(), len2 = b.length();
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    cout << "The minimum edit distance is " << dp[len1][len2] << endl;
    cout << "The steps are:" << endl;
    printSteps(len1, len2);
    return 0;
}

/*首先，输入两个字符串a和b，分别存储在变量a和b中，然后获取它们的长度len1和len2。
然后，创建一个二维数组dp，用来记录字符串a的前i个字符变换为字符串b的前j个字符所需的最少操作次数。
初始化dp的第一行和第一列为i和j，表示将空字符串变换为另一个字符串或者将一个字符串变换为空字符串所需的操作次数。
接着，用一个双重循环，从第二行第二列开始，遍历dp数组的每个元素。
对于每个元素dp[i][j]，根据字符串a和b的第i - 1个和第j - 1个字符是否相等，分别计算出三种可能的操作次数：删除a[i - 1]、插入b[j - 1]或者替换a[i - 1]为b[j - 1]。然后取这三种操作次数中的最小值作为dp[i][j]的值。
最后，输出dp数组右下角的元素，即为字符串a变换为字符串b所需的最少操作次数。
然后调用一个递归函数printSteps，从右下角开始，根据dp数组中相邻元素的值的关系，回溯出每一步的具体操作，并输出到屏幕上。
*/