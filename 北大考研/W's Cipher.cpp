#include <iostream>
#include<string>

using namespace std;


void change(string &K, int k) {
	int len = K.size();
	string temp = K + K;
	K = temp.substr(len - (k%len), len);
}
int main() {
	int k1, k2, k3;
	while (cin >> k1 >> k2 >> k3 && !(k1 == 0 && k2 == 0 && k3 == 0)) {
		string str;
		string K1 = "", K2 = "", K3 = "";
		string p = "";
		cin >> str;
		for (auto i : str) {
			if ('a' <= i && i <= 'i') { K1 += i; p += '1'; }
			else if ('j' <= i && i <= 'r') { K2 += i; p += '2'; }
			else { K3 += i; p += '3'; }
		}

		change(K1, k1); change(K2, k2); change(K3, k3);
		int c1 = 0, c2 = 0, c3 = 0;
		for (auto i : p) {
			if (i == '1') cout << K1[c1++];
			else if (i == '2') cout << K2[c2++];
			else cout << K3[c3++];
		}
		cout << endl;
	}
}