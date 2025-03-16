#include<iostream>
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

int main(){
	cout << "Codigo desarrollado por Daniel Moran en la Universidad Nacional Experimental Politecnica de Venezuela \n"<< endl;
	return 0;
}