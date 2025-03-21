#include <iostream>
#include <vector>
using namespace std;

// 문자열의 알파벳 개수를 세는 함수
vector<int> alpha_count(string s) {
    vector<int> freq(26, 0); // A~Z까지 26개의 알파벳 개수 저장
    for (char c : s) freq[c - 'A']++; 
    return freq;
}

// 두 단어가 비슷한 단어인지 확인하는 함수
bool is_similar(vector<int> &a, vector<int> &b) {
    int diff1 = 0, diff2 = 0;
    
    for (int i = 0; i < 26; i++) {
        if (a[i] > b[i]) diff1 += a[i] - b[i]; // 기준 단어에 있는 추가 문자 개수
        else diff2 += b[i] - a[i]; // 비교 단어에 있는 추가 문자 개수
    }
    
    // 차이가 1개 이하일 경우 비슷한 단어로 판별
    return (diff1 <= 1 && diff2 <= 1);
}

int main() {
    int N, result = 0;
    string base;
    cin >> N >> base;

    vector<int> base_freq = alpha_count(base); // 기준 단어의 알파벳 빈도 수 계산

    while (--N) {
        string word;
        cin >> word;
        vector<int> word_freq = alpha_count(word); // 비교 단어의 빈도 수 계산
        if (is_similar(base_freq, word_freq)) result++; // 비슷한 단어 개수 증가
    }

    cout << result << '\n';
    return 0;
}
