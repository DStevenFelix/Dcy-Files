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

/*���ȣ����������ַ���a��b���ֱ�洢�ڱ���a��b�У�Ȼ���ȡ���ǵĳ���len1��len2��
Ȼ�󣬴���һ����ά����dp��������¼�ַ���a��ǰi���ַ��任Ϊ�ַ���b��ǰj���ַ���������ٲ���������
��ʼ��dp�ĵ�һ�к͵�һ��Ϊi��j����ʾ�����ַ����任Ϊ��һ���ַ������߽�һ���ַ����任Ϊ���ַ�������Ĳ���������
���ţ���һ��˫��ѭ�����ӵڶ��еڶ��п�ʼ������dp�����ÿ��Ԫ�ء�
����ÿ��Ԫ��dp[i][j]�������ַ���a��b�ĵ�i - 1���͵�j - 1���ַ��Ƿ���ȣ��ֱ��������ֿ��ܵĲ���������ɾ��a[i - 1]������b[j - 1]�����滻a[i - 1]Ϊb[j - 1]��Ȼ��ȡ�����ֲ��������е���Сֵ��Ϊdp[i][j]��ֵ��
������dp�������½ǵ�Ԫ�أ���Ϊ�ַ���a�任Ϊ�ַ���b��������ٲ���������
Ȼ�����һ���ݹ麯��printSteps�������½ǿ�ʼ������dp����������Ԫ�ص�ֵ�Ĺ�ϵ�����ݳ�ÿһ���ľ�����������������Ļ�ϡ�
*/