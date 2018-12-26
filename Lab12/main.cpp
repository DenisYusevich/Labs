#include<iostream>
#include<string>
#include<fstream>
#include"Dictionary.h"

using namespace std;



int convert(char x) {

	int int_x;

	char c_arr[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int i_arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 10; ++i) {
		if (x == c_arr[i]) {
			int_x = i_arr[i];
		}
	}
	return int_x;


}


int main() {

	Dictionary<int, int> dict;
	ifstream input("input.txt");

	string str;
	int counter1 = 0;
	while (getline(input, str)) {
		
		counter1++;

		for (int i = 0; i <= str.size(); ++i) {

			if (isdigit(str[i])) {

				int j = i;
				int a;
				a = convert(str[i]);
				bool flag = false;
				while (flag == false) {

					if (!isdigit(str[j + 1])) {
						dict.add(counter1,a);
						flag = true;
					}
					else {

						a *= 10;
						a += convert(str[j + 1]);
						++j;
					}

				}i = j;

			}
		}
	}
	dict.search(3)->showData();
	dict.del();
	

	Dictionary<int,string> dict_str;
	ifstream input_string("input_str.txt");
	string str1;
	int counter2 = 0;
	while (getline(input_string, str1)) {
		counter2++;

		dict_str.add(counter2, str1);


	}
	dict_str.search(3)->showData();
	dict_str.del();
	/*Dictionary<int, char>dict_ch;
	ifstream input_char("input_ch");
	char ch;
	int counter3 = 0;
	while (!input_char.eof()) {
		input_char >> ch;
		counter3++;
		dict_ch.add(counter3, ch);

	}
	dict_ch.search(1)->showData();*/


	system("pause");
	return 0;

}