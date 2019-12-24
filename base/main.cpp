#include <iostream>
#include"textClass.h"
#include"textExtendClass.h" 
#include"struct.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Dog dog1;
	
	cout<<dog1.getI()<<dog1.getII()<<endl;
	
	Dog dog2(3,4);
	
	cout<<dog2.getI()<<dog2.getII()<<endl;
	
	BigDog digDog(5,6);
	
	cout<<digDog.getI()<<digDog.getII()<<endl;
	
	sDome s1;
	s1.a = 1;
	
	structDome s2;
	s2.a = 3;
	
	int sum = s1.add(1,4);
	
	cout<<s1.a<<s2.a<<sum<<endl; 
	
	return 0;
}
