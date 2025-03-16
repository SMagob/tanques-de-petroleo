#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class tanquepetroleo {
	private:
	int codigo;
	float nivelliquido, temperatura, presion, densidad, nivelagua;
};

class sensor: public tanquepetroleo{
	public:
	float medirnivelliquido(){

	}
	float medirtemperatura(){

	}
	float medirpresion(){

	}
	float medirdensidad(){

	}
	float medirnivelagua(){
		
	}
};

class alarma{
	public:
	bool sonar(){

	}
};

int main(){
	cout << "Codigo desarrollado por Daniel Moran, Jesus Morales en la Universidad Nacional Experimental Politecnica de Venezuela \n"<< endl;
	return 0;
}