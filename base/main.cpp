#include <iostream>
#include"textClass.h"
#include"textExtendClass.h" 

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Dog dog1;
	
	cout<<dog1.getI()<<dog1.getII()<<endl;
	
	Dog dog2(3,4);
	
	cout<<dog2.getI()<<dog2.getII()<<endl;
	
	BigDog digDog(5,6);
	
	cout<<digDog.getI()<<digDog.getII()<<endl;
	
	return 0;
}
