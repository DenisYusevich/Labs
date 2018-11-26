#include<iostream>;

using namespace std;



bool nod(int ch,int z) {

	for (int i = 2; i <= ch; i++) {
		if (ch % i == 0 && z % i == 0) {
			return true;
		}

	}

}

int main() {


	int num;
	int z;
	int ch;
	int counter = 0;
	int max;
	int sum = 0;

	int chis[100];
	int znam[100];
	double division[100];

	cout << "Enter num: ";
	cin >> num;



	z = num;
	ch = 1;
	
	while (ch < num-1) {

		counter++;
		z--;
		if (z == ch ) {
			z = num - 1;
			ch++;
		}

		if (nod(ch, z) == true) {
			chis[counter] = 0;
			znam[counter] = 0;
			division[counter] = 0;
			continue;

		}
		double ch1 = ch;
		double z1 = z;

		chis[counter] = ch;
		znam[counter] = z;

		division[counter] = ch1 / z1;


		
		
		//cout << ch << "/" << z << endl;
	}
	max = 0;

	for (int i = 1; i < counter; i++) {

		if (chis[i] == 0 && znam[i] == 0) {
			continue;
		}
		else {
			
			if (division[i] > max) {
				cout << division[i]<<endl;
				max = division[i];
				cout << chis[i] << "/" << znam[i] << endl;
				division[i] = 0;
				sum += division[i];
			}
			else {
				continue;
			}
			

		}

	}


	system("pause");
	return 0;
	

}