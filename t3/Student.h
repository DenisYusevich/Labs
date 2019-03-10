#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


struct Raiting {

	Raiting() {};

	int GA_R;
	int CALC_R;
	int PROGRAMMING_R;
	int HISTORY;

	Raiting(int GA_R, int CALC_R, int PROGRAMMING_R, int HISTORY) :GA_R(GA_R), CALC_R(CALC_R), PROGRAMMING_R(PROGRAMMING_R), HISTORY(HISTORY) {};
};
class Student {

public:
	Student() {};
	Student(int ga, int calc, int his, int progr, string name, int group) :raiting(ga, calc, progr, his), name(name), groupNumber(group) {};

	string getName() {
		return name;
	}
	int getGroup() {
		return groupNumber;
	}

	int getAverage() {
		return (raiting.CALC_R + raiting.GA_R + raiting.HISTORY + raiting.PROGRAMMING_R) / 4;
	}

	bool operator >(Student& rhs) {
		return this->getAverage() > rhs.getAverage();
	}
	bool operator <(Student& rhs) {
		return this->name < rhs.name;
	}
	bool operator()() {
		if (raiting.CALC_R < 4 || raiting.GA_R < 4 || raiting.HISTORY < 4 || raiting.PROGRAMMING_R < 4) {
			return true;
		}
		else {
			return false;
		}
	}

	friend istream& operator>>(istream& in, Student& s) {
		in >> s.name;
		in >> s.groupNumber;
		in >> s.raiting.GA_R;
		in >> s.raiting.CALC_R;
		in >> s.raiting.PROGRAMMING_R;
		in >> s.raiting.HISTORY;
		return in;
	}

	friend ostream& operator<<(ostream& os, Student& s) {
		os << s.name << " ";
		os << "Group:" << s.groupNumber << " ";
		os << "Rates: ";
		os << s.raiting.GA_R << " ";
		os << s.raiting.CALC_R << " ";;
		os << s.raiting.PROGRAMMING_R << " ";;
		os << s.raiting.HISTORY;
		return os;
	}

private:


	string name;
	int groupNumber;
	Raiting raiting;

};


