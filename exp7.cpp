#include <iostream>
using namespace std;

long repeatedString(string s, long n) {
    long count_a = 0;
    
    
    for (char ch : s) {
        if (ch == 'a')
            count_a++;
    }
    
   
    long repeat_count = n / s.size();
    long remaining_chars = n % s.size();
    
    count_a *= repeat_count;
    
    for (int i = 0; i < remaining_chars; i++) {
        if (s[i] == 'a')
            count_a++;
    }
    
    return count_a;
}

int main() {
    string s;
    long n;
    cout << "Enter the string to repeat: ";
    cin >> s;
    cout << "Enter the number of characters to consider: ";
    cin >> n;

    long result = repeatedString(s, n);
    cout << "Frequency of 'a' in the substring: " << result << endl;

    return 0;
}