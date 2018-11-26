#include<iostream>

using namespace std;

int main() {

	int n;

	cout << "Enter n: ";
	cin >> n;

	int a = 1;
	int c = 1;
	int b = n;
	int d = n - 1;
	int k;
	
	
	if (n > 2) {

		cout << 1 << "/" << n << "   " << 1 << "/" << (n - 1) << "   ";

		while (n) {

			k = int((n + b) / d);
			int p = k * c - a;
			int q = k * d - b;

			cout << p << "/" << q << "    ";


			a = c;
			b = d;
			c = p;
			d = q;

			if (p == (n - 1)) {
				break;
			}

		}
	}
	else if (n == 2) {
		cout << 1 << "/" << 2<<"\n";
	}
	else {
		cout << "Invalid data\n";
	}

	system("pause");
	return 0;

}