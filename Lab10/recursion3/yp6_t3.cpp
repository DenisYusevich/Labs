/*
Написать рекурсивную функцию нахождения
цифрового корня натурального числа.

    
        100
        ->100->1

   
        666
		->666->18->9

		14567
		->14567->23->5


*/
#include <iostream>


using namespace std;

int numRoot(int n){
    cout<<"->" <<n;
    if(n < 10){
        return 0;
    }
	
	else{
        int x= 0;
        while(n){
            x+=n%10;
            n/=10;
        }

        numRoot(x);
    }
}

int main(){
    int n;
    cin >> n;
    numRoot(n);


    system("pause");
    return 0;
}
