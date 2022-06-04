#pragma once
#include <string>
using namespace std;
class Validator{
public:
	void validateMedicineWithId(const string, const string, const string, const string, const string) const;
	void validateMedicine(const string&, const string&, const string&, const string&) const;
	void validateId(const string) const;
};
