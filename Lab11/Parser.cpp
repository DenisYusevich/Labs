#include<iostream>
#include"Parser.h"
#include"exñeption.h"
#include"Valid.h"

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


Expression Parser::createExp() {

	Expression exp;



	for (int i = 0; i <= str.size(); ++i) {

		if (isdigit(str[i]) && !isdigit(str[i + 1])) {
			op.push_back(convert(str[i]));
			
		}
		if (isdigit(str[i]) && isdigit(str[i + 1])) {
			op.push_back(10 * convert(str[i]) + convert(str[i + 1]));//TODO for all nums
			i++;
		}
		

		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {

			func.push_back(str[i]);

		}

		if (op.vec_size() == 2) {
			if (func.pop_back() == '/') {
					int a, b;
					b = op.pop_back();
					a = op.pop_back();
					if (!func.isEmpty()) {
						
						if (func.print_back() == '-') {
							a = a * (-1);
							func.pop_back();
						}
					}
				
				
				Rational r(a, b);
				fraction.push_back(r);
			}	
		}	

		if (i == (str.size() - 1)) {
			

			if (op.vec_size() == 1) {

				op.push_back(1);
				int a, b;
				b = op.pop_back();
				a = op.pop_back();
				if (!func.isEmpty()) {

					if (func.print_back() == '-') {
						a = a * (-1);
						func.pop_back();
					}
				}


				Rational r(a, b);
				fraction.push_back(r);
			}

			Expression exTemp(fraction, func);
			
			exp = exTemp;
			for (int i = 0; i < fraction.vec_size(); ++i) {
				fraction.pop_back();
			}
			for (int i = 0; i < op.vec_size(); ++i) {
				op.pop_back();
			}
			for (int i = 0; i < func.vec_size(); ++i) {
				func.pop_back();
			}

			
		}
	}
	
	
	return exp;

}