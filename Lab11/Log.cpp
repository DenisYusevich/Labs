#include"Log.h"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;



Log::Log() {

	log.open("log.txt",ofstream::app);

}

void Log::push(string str) {
	time();
	log << str;

}

void Log::time() {

	GetSystemTime(&st);
	log << to_string(st.wHour + 3) + "-"
		+ to_string(st.wMinute) + "." 
		+ to_string(st.wDay) + "."
		+ to_string(st.wMonth) + "."
		+ to_string(st.wYear)+":" << endl;


}