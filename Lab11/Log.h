#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include<Windows.h>

using namespace std;


class Log {

private:

	 ofstream log;
	 SYSTEMTIME st;
	

public:

	Log();
	void push(string str);
	void time();

};


