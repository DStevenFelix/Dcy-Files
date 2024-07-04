#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main() {
	string s1, s2;
	cout << "请输入两个字符串:" << endl;
	cin >> s1 >> s2;
	int _max = 0;
	int index;
	int m = s1.length(), n = s2.length();
	//dp矩阵
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 1; i <= m; i++) {
		char c1 = s1[i - 1];
		for (int j = 1; j <= n; j++) {
			char c2 = s2[j - 1];
			if (c1 == c2) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (_max < dp[i][j]) {
					_max = dp[i][j];
					index = i;
				}
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	string ans;
	for (int i = index - 1; _max > 0; i--, _max--) {
		ans += s1[i];

	}
	//倒序输出
	cout << "最长公共子序列为:" << endl;
	for (auto i = ans.rbegin(); i != ans.rend(); i++) {
		cout << *i;
	}
	return 0;
}



/*
* 这段代码定义了两个函数：LCSLength和PrintLCS。第一个函数接受两个字符串x和y，它们的长度m和n，以及两个二维数组
* 两个二维数组分别是c和b，它们用于存储LCS的长度和方向。c[i][j]表示字符串x[0..i-1]和y[0..j-1]的LCS的长度，b[i][j]表示LCS的方向，可以是0（左上方），1（上方）或-1（左方）。这两个数组的大小都是MAXLEN，这是一个预定义的常量，表示字符串的最大长度。

第一个函数首先将数组c的第一行和第一列都初始化为0，表示空字符串和任何字符串的LCS的长度都是0。
然后，它用一个双重循环遍历两个字符串的每个字符，比较它们是否相等。
如果相等，那么它们就是LCS的一部分，所以将数组c和b的对应位置更新为左上方的值加一和0。
如果不相等，那么它们就不是LCS的一部分，所以将数组c的对应位置更新为上方和左方中较大的值，将数组b的对应位置更新为上方或左方中较大值对应的方向。

第二个函数用于打印LCS。
它接受数组b，字符串x，以及两个字符串的长度。
它用一个递归算法从后往前遍历数组b，根据方向找到LCS的字符，并将它们打印出来。
如果遇到0，表示该位置是LCS的一部分，所以打印该位置对应的字符，并向左上方递归。
如果遇到1，表示该位置不是LCS的一部分，而是从上方继承了LCS的长度，所以向上方递归。
如果遇到-1，表示该位置不是LCS的一部分，而是从左方继承了LCS的长度，所以向左方递归。如果遇到边界，表示已经找到了LCS的起始位置，所以停止递归。
*/