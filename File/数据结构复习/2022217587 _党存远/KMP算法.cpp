// C++ 代码实现 KMP 算法进行字符串匹配
#include <iostream> // 引入输入输出库
#include <string> // 引入字符串库
#include <vector> // 引入向量库
using namespace std; // 使用标准命名空间

// 一个函数用来计算模式串的前缀函数
vector<int> computePrefix(string pattern) {
    // 初始化一个空的向量来存储前缀值
    vector<int> prefix(pattern.size());

    // 设置第一个值为零
    prefix[0] = 0;

    // 从模式串的第二个字符开始循环
    int j = 0; // 最长的既是前缀又是后缀的索引
    for (int i = 1; i < pattern.size(); i++) {
        // 如果当前字符和前缀的下一个字符匹配，延长前缀
        if (pattern[i] == pattern[j]) {
            j++;
            prefix[i] = j;
        }
        // 否则，尝试找到一个更短的前缀来匹配
        else {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = prefix[j - 1]; // 回退到前一个前缀值
            }
            // 如果当前字符和前缀的下一个字符匹配，延长前缀
            if (pattern[i] == pattern[j]) {
                j++;
            }
            // 否则，没有前缀可以匹配
            prefix[i] = j;
        }
    }

    // 返回前缀向量
    return prefix;
}

// 一个函数用来在文本中找到所有模式串的出现位置，使用 KMP 算法
vector<int> kmpSearch(string text, string pattern) {
    // 初始化一个空的向量来存储匹配的起始索引
    vector<int> matches;

    // 计算模式串的前缀函数
    vector<int> prefix = computePrefix(pattern);

    // 遍历文本
    int j = 0; // 模式串中当前字符的索引
    for (int i = 0; i < text.size(); i++) {
        // 如果当前字符和模式串的下一个字符匹配，同时移动两个指针
        if (text[i] == pattern[j]) {
            j++;
            // 如果我们到达了模式串的末尾，我们找到了一个匹配
            if (j == pattern.size()) {
                matches.push_back(i - j + 1); // 把匹配的起始索引加入到向量中
                j = prefix[j - 1]; // 回退到前一个前缀值
            }
        }
        // 否则，尝试找到一个更短的前缀来匹配
        else {
            while (j > 0 && text[i] != pattern[j]) {
                j = prefix[j - 1]; // 回退到前一个前缀值
            }
            // 如果当前字符和模式串的下一个字符匹配，同时移动两个指针
            if (text[i] == pattern[j]) {
                j++;
            }
            // 否则，没有前缀可以匹配
        }
    }

    // 返回匹配向量
    return matches;
}

// 一个函数用来打印一个整数向量
void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// 一个主函数用来测试算法
int main() {
    // 创建一个文本和一个模式串
    string text = "ABABDABACDABABCABAB";
    
    string pattern = "ABABCABAB";
    

    // 打印文本和模式串
    cout << "text = " << text << endl;
    cout << "pattern = " << pattern << endl;

    // 使用 KMP 算法在文本中找到并打印所有模式串的出现位置
    vector<int> matches = kmpSearch(text, pattern);
    cout << "matches = ";
    printVector(matches);//matches是子串在text串中的定位问题

    return 0;
}
