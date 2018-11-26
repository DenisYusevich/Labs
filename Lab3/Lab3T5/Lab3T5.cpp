#include<iostream>

using namespace std;

int digitCount(int n) {
	int result = 1;
	while (n /= 10) {
		result++; 
	}
		return result;
}

int main() {

	int k;

	cout << "Enter k\n";
	cin >> k;
		

	int i = 1;
	while (digitCount(i) < k) {
		k -= digitCount(i);
		++i;
	}

	k = digitCount(i) - k;
	while (k) {
		i /= 10;
		--k;
	}
	cout << i % 10 << "\n";


 system("pause");
 return 0;
}
