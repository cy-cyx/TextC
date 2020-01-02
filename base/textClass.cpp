#include"textClass.h"

using namespace std;

Dog::Dog() {
	Dog::i = 1;
	Dog::ii = 2;
}

Dog::getI() {
	return Dog::i;
}

Dog::getII() {
	return Dog::ii;
}


Dog::Dog(int i,int ii) {
	Dog::i = i;
	Dog::ii = ii;
}

Dog::~Dog() {
	cout<<"xigou"<<endl;
}



