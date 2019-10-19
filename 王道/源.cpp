#define _CRT_SECURE_NO_WARNINGS
 
//输入两个长度不超过200的正整数A,B，求A和B的乘积。保证输入的正整数不会以0开头，要求输出的正整数也不能以0开头
 
#include <cstdio>
#include <cstring>
 
using namespace std;
 
 
class BigInteger {
public:
    static const int maxn = 1010;
 
    BigInteger &operator=(const BigInteger &rhs) {
        n = rhs.n;
        for (int i = 0; i < n; i++) {
            digit[i] = rhs.digit[i];
        }
        return *this;
    }
 
    int digit[maxn], n;
 
    void readInput() {
        static char buffer[maxn];
        scanf("%s", buffer);
		int len = strlen(buffer);
		n = 0;
        for (int i = len - 1; i >= 0; i--) {
            digit[n++] = buffer[i] - '0';
        }
    }
 
    void normalize(int i) {
        n = i;
        while (n > 1 && digit[n - 1] == 0) {
            n--;
        }
    }
 
    void clear0() {
        n = 1;
        memset(digit, 0, sizeof(digit));
    }
 

 
    void mul(const BigInteger &rhs, BigInteger &result) const {
        for (int i = 0; i < n + rhs.n; i++) {
            result.digit[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rhs.n; j++) {
                result.digit[i + j] += digit[i] * rhs.digit[j];
                if (result.digit[i + j] >= 10) {
                    result.digit[i + j + 1] += result.digit[i + j] / 10;
                    result.digit[i + j] %= 10;
                }
            }
        }
        result.normalize(n + rhs.n);
    }
 

 
    int compare(const BigInteger &rhs) const {
        if (n != rhs.n) {
            return n - rhs.n;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (digit[i] != rhs.digit[i]) {
                return digit[i] - rhs.digit[i];
            }
        }
        return 0;
    }
 
    void output() const {
        bool started = false;
        for (int i = n - 1; i >= 0; i--) {
                putchar('0' + digit[i]);
            }
	}
 
};
 
int main() {
	BigInteger a, b, c;
    a.readInput();
    b.readInput();
    a.mul(b, c);
    c.output();
    return 0;
}
