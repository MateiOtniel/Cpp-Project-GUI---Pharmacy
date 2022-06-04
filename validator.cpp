#include "validator.h"

void Validator::validateMedicineWithId(const string id, const string denumire, const string pret, const string producator, const string substanta) const{
	string err = "";
	string err1 = "";
	try{
		validateId(id);
	}
	catch (string err1){
		err += err1;
	}
	try{
		validateMedicine(denumire, pret, producator, substanta);
	}
	catch (string err1){
		err += err1;
	}
	if(err != "")
		throw err;
}

void Validator::validateMedicine(const string& denumire, const string& pret, const string& producator, const string& substanta) const{
	string err = "";
	if(denumire == "" or denumire.size() > 50)
		err += "Denumire invalida!\n";
	for(int i = 0; i < denumire.size(); i++)
		if((denumire[i] < 'a' || denumire[i] > 'z') && (denumire[i] < 'A' || denumire[i] > 'Z')){
			err += "Denumire invalida!\n";
			break;
		}
	if(pret == "" or pret.size() > 6)
		err += "Pret invalid!\n";
	for(int i = 0; i < pret.size(); i++)
		if(pret[i] < '0' || pret[i] > '9'){
			err += "Pret invalid!\n";
			break;
		}
	if(producator == "" or producator.size() >15)
		err += "Producator invalid!\n";
	for(int i = 0; i < producator.size(); i++)
		if((producator[i] < 'a' || producator[i] > 'z') && (producator[i] < 'A' || producator[i] > 'Z')){
			err += "Producator invalid!\n";
			break;
		}
	if(substanta == "" or substanta.size() > 25)
		err += "Substanta invalida!\n";
	for(int i = 0; i < substanta.size(); i++)
		if((substanta[i] < 'a' || substanta[i] > 'z') && (substanta[i] < 'A' || substanta[i] > 'Z')){
			err += "Substanta invalida!\n";
			break;
		}
	if(err != "")
		throw err;
}

void Validator::validateId(const string id) const{
	string err = "";
	if(id == "" or id.size() > 6)
		err += "Id invalid!\n";
	for(int i = 0; i < id.size(); i++)
		if(id[i] < '0' || id[i] > '9'){
			err += "Id invalid!\n";
			break;
		}
	if(err != "")
		throw err;
}