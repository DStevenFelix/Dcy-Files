// C++ ����ʵ�� KMP �㷨�����ַ���ƥ��
#include <iostream> // �������������
#include <string> // �����ַ�����
#include <vector> // ����������
using namespace std; // ʹ�ñ�׼�����ռ�

// һ��������������ģʽ����ǰ׺����
vector<int> computePrefix(string pattern) {
    // ��ʼ��һ���յ��������洢ǰ׺ֵ
    vector<int> prefix(pattern.size());

    // ���õ�һ��ֵΪ��
    prefix[0] = 0;

    // ��ģʽ���ĵڶ����ַ���ʼѭ��
    int j = 0; // ��ļ���ǰ׺���Ǻ�׺������
    for (int i = 1; i < pattern.size(); i++) {
        // �����ǰ�ַ���ǰ׺����һ���ַ�ƥ�䣬�ӳ�ǰ׺
        if (pattern[i] == pattern[j]) {
            j++;
            prefix[i] = j;
        }
        // ���򣬳����ҵ�һ�����̵�ǰ׺��ƥ��
        else {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = prefix[j - 1]; // ���˵�ǰһ��ǰ׺ֵ
            }
            // �����ǰ�ַ���ǰ׺����һ���ַ�ƥ�䣬�ӳ�ǰ׺
            if (pattern[i] == pattern[j]) {
                j++;
            }
            // ����û��ǰ׺����ƥ��
            prefix[i] = j;
        }
    }

    // ����ǰ׺����
    return prefix;
}

// һ�������������ı����ҵ�����ģʽ���ĳ���λ�ã�ʹ�� KMP �㷨
vector<int> kmpSearch(string text, string pattern) {
    // ��ʼ��һ���յ��������洢ƥ�����ʼ����
    vector<int> matches;

    // ����ģʽ����ǰ׺����
    vector<int> prefix = computePrefix(pattern);

    // �����ı�
    int j = 0; // ģʽ���е�ǰ�ַ�������
    for (int i = 0; i < text.size(); i++) {
        // �����ǰ�ַ���ģʽ������һ���ַ�ƥ�䣬ͬʱ�ƶ�����ָ��
        if (text[i] == pattern[j]) {
            j++;
            // ������ǵ�����ģʽ����ĩβ�������ҵ���һ��ƥ��
            if (j == pattern.size()) {
                matches.push_back(i - j + 1); // ��ƥ�����ʼ�������뵽������
                j = prefix[j - 1]; // ���˵�ǰһ��ǰ׺ֵ
            }
        }
        // ���򣬳����ҵ�һ�����̵�ǰ׺��ƥ��
        else {
            while (j > 0 && text[i] != pattern[j]) {
                j = prefix[j - 1]; // ���˵�ǰһ��ǰ׺ֵ
            }
            // �����ǰ�ַ���ģʽ������һ���ַ�ƥ�䣬ͬʱ�ƶ�����ָ��
            if (text[i] == pattern[j]) {
                j++;
            }
            // ����û��ǰ׺����ƥ��
        }
    }

    // ����ƥ������
    return matches;
}

// һ������������ӡһ����������
void printVector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// һ�����������������㷨
int main() {
    // ����һ���ı���һ��ģʽ��
    string text = "ABABDABACDABABCABAB";
    
    string pattern = "ABABCABAB";
    

    // ��ӡ�ı���ģʽ��
    cout << "text = " << text << endl;
    cout << "pattern = " << pattern << endl;

    // ʹ�� KMP �㷨���ı����ҵ�����ӡ����ģʽ���ĳ���λ��
    vector<int> matches = kmpSearch(text, pattern);
    cout << "matches = ";
    printVector(matches);//matches���Ӵ���text���еĶ�λ����

    return 0;
}
