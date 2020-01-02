#include <iostream>
#include <stdio.h>
#include"textClass.h"
#include"textExtendClass.h" 
#include"struct.h"
#include"indefiniteParameter.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	// 测试类 
	
	Dog dog1;
	
	cout<<dog1.getI()<<dog1.getII()<<endl;
	
	Dog dog2(3,4);
	
	cout<<dog2.getI()<<dog2.getII()<<endl;
	
	BigDog digDog(5,6);
	
	cout<<digDog.getI()<<digDog.getII()<<endl;
	
	// 测试结构体 
	
	sDome s1;
	s1.a = 1;
	
	structDome s2;
	s2.a = 3;
	
	int sum = s1.add(1,4);
	
	cout<<s1.a<<s2.a<<sum<<endl; 
	
	// 测试 new delete 
	
	structDome *s3 = new structDome();
	
	s3 -> a = 4;
	
	cout << s3->a<<endl;
	
	delete s3;
	
	cout <<s3->a<<endl; 
	
	// 测试不定参数 
	
	int s = indefiniteParamFun(4,1,1,1,1);
	
	cout << s << endl;
	
	return 0;
}
