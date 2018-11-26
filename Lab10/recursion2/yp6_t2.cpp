/*
    Написать рекурсивную функцию, определяющую, является ли симметричной часть строки s,
    начиная с i-го элемента и кончая j-м.

    aaachdd
Simmetrical, start index: 0 end index: 1
Simmetrical, start index: 0 end index: 2
No, start index: 0 end index: 3
No, start index: 0 end index: 4
No, start index: 0 end index: 5
No, start index: 0 end index: 6
Simmetrical, start index: 1 end index: 2
No, start index: 1 end index: 3
No, start index: 1 end index: 4
No, start index: 1 end index: 5
No, start index: 1 end index: 6
No, start index: 2 end index: 3
No, start index: 2 end index: 4
No, start index: 2 end index: 5
No, start index: 2 end index: 6
No, start index: 3 end index: 4
No, start index: 3 end index: 5
No, start index: 3 end index: 6
No, start index: 4 end index: 5
No, start index: 4 end index: 6
Simmetrical, start index: 5 end index: 6
*/
#include <iostream>
#include <string>

using namespace std;

bool isSimmetrical(string str, int i, int j){
    if(i > j){
        return true;
    }
    if(i == j){
        return true;
    }

    if(str[i] == str[j] && isSimmetrical(str, i + 1, j - 1)){
        return true;
    }
	else{
        return false;
    }
}

int main(){
    string str;//из соображений удобства string
    cin >> str;
	
	
    for(int i=0;i<str.size()-1; ++i){

        for(int j=i+1; j<str.size(); ++j){

            cout << (isSimmetrical(str, i, j)?"Simmetrical":"No")<<", start index: " << i <<" end index: " << j <<"\n";
        }
    }
    system("pause");
    return 0;
}
