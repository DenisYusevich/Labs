#include<iostream>
#include<fstream>

using namespace std;

int main() {

	ifstream input("input.txt");

	char ch;
	int counter = 0;
	while (input.get(ch))
	{

		counter++;
	}
	char* arr = new char[counter];

	
	input.close();

	input.open("input.txt");

	for (int i = 0; i < counter; ++i) {
		input.get(ch);
		arr[i] = ch;
	}

	for (int i = 0; i < counter; ++i) {
		cout << arr[i];
	}

	cout << endl;
	
	
	int st = 0, en = 0;
	while (arr[st] != '\0') {
		if (arr[st] != ' ' && arr[st]!='\0') {
			en = st + 1;
			while (arr[en] != ' ' && arr[en] != '\0') en++;
			for (int i = 0; i < (en - st) / 2; i++)
				swap(arr[st + i], arr[en - i - 1]);
			st = en;
		}
		else {
			st++;
		}
	}
	
	cout << arr;
	
	system("pause");
	
	return 0;


}


//hello darkness my old friend
//olleh ssenkrad ym dlo ╢sS / < ¤¤¤¤dneirf