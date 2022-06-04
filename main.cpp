#include "ui.h"
#include "test.h"

int main(int argc, char* argv[]){
	QApplication a(argc, argv);
	test_all();
	FileRepoMedicamente repo{"all.txt"};
	Service srv{repo};
	Validator validator;
	Console c{srv, validator};
	c.connectButtons();
	return a.exec();
}