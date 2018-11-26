#include<iostream>

using namespace std;

bool  exitt = false;


bool isSimple(int n) {

	bool isSimple = true;

	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			isSimple = false;
			return false;
		}
	}
	if (isSimple == true) {
		return true;
	}
}



int* simpleSort(int *arr,int n) {

	int s = -1;

	for (int i = 0; i < n; ++i) {

		if (isSimple(arr[i]) == true) {
			s++;
		}
	}

	int *simpleArr = new int[s+1];
	int k = 0;
	for (int i = 0; i < n; ++i) {

		if (isSimple(arr[i]) == true) {
			simpleArr[k] = arr[i];
			k++;
		}
	}
		 
	return simpleArr;
	
}

int* div3Sort(int* arr, int n) {


	int s = -1;

	for (int i = 0; i < n; ++i) {

		if (arr[i] % 3 == 0) {
			s++;
		}
	}

	int *div3Arr = new int[s + 1];
	int k = 0;
	for (int i = 0; i < n; ++i) {

		if (arr[i] % 3 == 0) {
			div3Arr[k] = arr[i];
			k++;
		}
	}
	return div3Arr;
}


int* oddSort(int* arr,int n) {

	int s = -1;

	for (int i = 0; i < n; ++i) {

		if (arr[i] % 2 == 0) {
			s++;
		}
	}

	int *oddArr = new int[s + 1];
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] % 2 == 0) {

			oddArr[k] = arr[i];
			k++;
		}
	}
	return oddArr;


}


int output(int*(*f)(int*, int), int* arr, int n) {
	for (int i = 0; i < n && *(f(arr, n) + i) > 0; ++i) {
		cout << *(f(arr, n) + i) << " ";
	}
	cout<<endl;
	return 0;
}




int menu() {

	int n;
	int*(*pSimpleSort)(int*, int);
	pSimpleSort = simpleSort;
	int*(*pDiv3Sort)(int*, int);
	pDiv3Sort = div3Sort;
	int*(*pOddSort)(int*, int);
	pOddSort = oddSort;

	cout << "Hi \n";
	cout << "Enter the size of array: ";
	cin >> n;

	int *arr = new int[n];
	cout << "Enter elements of array: ";
	for (int i = 0; i < n; ++i) {

		cin >> arr[i];

	}

	int choice;
	cout << "Choose one of these options: " << endl << "1)Simple numbers" << endl << "2)Div3 numbers" << endl << "3)Odd numbers" << endl << "0)Exit" << endl;
	cin >> choice;

	switch (choice) {
	case 1:output(*pSimpleSort, arr, n);
		break;
	
	case 2:output(*pDiv3Sort, arr, n);
		break;

	case 3:output(*pOddSort, arr, n);
		break;

	case 0:exitt = true;
		return 0;
		break;
	}


	return 0;
	

}


int main() {

	while (exitt == false) {
		menu();
	}

	system("pause");
	return 0;

}
