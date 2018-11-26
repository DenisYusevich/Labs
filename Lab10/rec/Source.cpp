#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isSymmetri(string s, int i, int j) {
	if (i > j) {
		return true;
	}
	if (i == j) {
		return true;
	}

	if (s[i] == s[j] && isSymmetri(s, i + 1, j - 1)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 1; ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			cout << (isSymmetri(s, i, j) ? "Yes" : "No") << ", start: " << i << " end: " << j << "\n";
		}
	}
	system("pause");
	return 0;
}
