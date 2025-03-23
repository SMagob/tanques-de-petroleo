#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class TanquePetroleo {
public:
    float nivelLiquido;
    float temperatura;
    float presion;
    float densidad;
    float nivelAgua;	
    
    TanquePetroleo() {
        srand(time(0)); // Inicializar la semilla para números aleatorios
    }

    void generarParametros() {
        nivelLiquido = rand() % 121; // Nivel de líquido entre 0 y 120
        temperatura = -40 + rand() % 160;   // Temperatura entre -40 y 120
        presion = 1 + rand() % 10;        // Presión entre 1 y 10
        densidad = 0.83 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.4)); // Densidad entre 0.83 y 1.23
        nivelAgua = ((1 + rand() % 8)/ 2);          // Nivel de agua entre 0 y 4
    }
};

class Alarma : virtual public TanquePetroleo{
	public:

	void activaralarmal(){
		cout << " Liquido fuera del intervalo!" << endl;
	}

	void activaralarmall(){
		cout << " Temperatura fuera del intervalo!" << endl;
	}

	void activaralarmalll(){
		cout << " Presion fuera del intervalo!" << endl;
	}

	void activaralarmalv(){
		cout << " Agua fuera del intervalo!" << endl;
	}
	
};

class Supervisor{
	public:
	string nombre;
	struct fecha{
		int dia, mes, ano;
	};
};

class Sensor : public Alarma {
public:
	
	
    bool  leerNivelLiquido(const TanquePetroleo& tanque) {
            cout << "Nivel de Liquido: " << tanque.nivelLiquido ;	
        if (tanque.nivelLiquido >= 0 && tanque.nivelLiquido <= 90) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
			this-> activaralarmal();
            return false;
        }
    }

    bool leerTemperatura(const TanquePetroleo& tanque) {
        cout << "Temperatura: " << tanque.temperatura ;
        if (tanque.temperatura >= -20 && tanque.temperatura <= 100) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
			this-> activaralarmall();
            return false;
		}
    }

    bool leerPresion(const TanquePetroleo& tanque) {
        cout << "Presion: " << tanque.presion ;
        if (tanque.presion >= 2 && tanque.presion <= 8) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
			this-> activaralarmalll();
            return false;
        }
    }

    void leerDensidad(const TanquePetroleo& tanque) {
        cout << "Densidad: " << tanque.densidad ;
        if (tanque.densidad >= 0.83 && tanque.densidad < 0.87) {
            cout << " Tipo de crudo: Ligero" << endl;
        } 	
        if (tanque.densidad >= 0.87 && tanque.densidad < 0.92) {
            cout << " Tipo de crudo: Mediano" << endl;
        } 	
        if (tanque.densidad >= 0.92 && tanque.densidad < 1.00) {
            cout << " Tipo de crudo: Pesado" << endl;
        } 	
		if (tanque.densidad >= 1) {
            cout << " Tipo de crudo: Extrapesado" << endl;
        } 	        
    }

    bool leerNivelAgua(const TanquePetroleo& tanque) {
        cout << "Nivel de agua: " << tanque.nivelAgua ;
        if (tanque.nivelAgua >= 0.5 && tanque.nivelAgua <= 2) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
		this-> activaralarmalv();
        return false;
        }
    }
};



class sistemasupervisorio : virtual public TanquePetroleo, virtual public Sensor, public Supervisor{
	public:

	void iniciarsistema(){
	TanquePetroleo tanque;
    Sensor sensor;
	Alarma alarma;
	Supervisor supervisor;	
	int opcion;
	
	cout <<  "             Sistema iniciado correctamente\n\n";
	tanque.generarParametros();
	sensor.leerNivelLiquido(tanque);
    sensor.leerTemperatura(tanque);
    sensor.leerPresion(tanque);
    sensor.leerDensidad(tanque);
    sensor.leerNivelAgua(tanque);
	cin >> opcion;
	switch (opcion){
		case 0:

		break;
		case 1:

		break;
		case 2:

		break;
		case 3:

		break;
		case 4:

		break;
		default:
		cout <<"No escogio ninguna de las opciones, vuelva a ingresar la opcion correspondiente.";
		break;
	};
	}

};

int main(){
	sistemasupervisorio sistema;

	cout << "Universidad Nacional Experimental Politecnica de Venezuela \n"<< endl;
    cout << "PROGRAMA DE SUPERVISION Y CONTROL DE LOS PARAMETROS \nOPERATIVOS DE UN TANQUE DE ALMACENAMIENTO DE PETROLEO \n"<<endl;
	cout << "Codigo desarrollado por: \n ~ Daniel Moran	 CI:30454164	Exp:20211-0069 \n ~ Jesus Morales	 CI:28585772	Exp:20211-0336 \n ~ Ronald Gordillo CI:30196995 	Exp:20221-0075 \n ~ Hector Duran 	 CI:30146076 	Exp:20211-0291";
	cout << "\nSe iniciara el sistema de supervision de tanques:\n\n";
	sistema.iniciarsistema();
    return 0;
}
