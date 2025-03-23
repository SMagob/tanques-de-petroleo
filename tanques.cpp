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
        nivelLiquido = 50 + rand() % 100; // Nivel de líquido entre 50 y 150
        temperatura = 20 + rand() % 60;   // Temperatura entre 20 y 80
        presion = 1 + rand() % 10;        // Presión entre 1 y 10
        densidad = 0.83 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.4)); // Densidad entre 0.8 y 1.2
        nivelAgua = rand() % 2;          // Nivel de agua entre 0 y 2
    }
};

class Sensor {
public:
	
	
    bool  leerNivelLiquido(const TanquePetroleo& tanque) {
            cout << "Nivel de Liquido: " << tanque.nivelLiquido << " - ";	
        if (tanque.nivelLiquido >= 50 && tanque.nivelLiquido <= 100) {
            cout << "Dentro del intervalo." << endl;
            return true;
        } else {
            cout << "Fuera del intervalo!" << endl;
            return false;
        }
    }

    bool leerTemperatura(const TanquePetroleo& tanque) {
        cout << "Temperatura: " << tanque.temperatura << " - ";
        if (tanque.temperatura >= -30 && tanque.temperatura <= 100) {
            cout << "Dentro del intervalo." << endl;
            return true;
        } else {
            cout << "Fuera del intervalo!" << endl;
            return false;
		}
    }

    bool leerPresion(const TanquePetroleo& tanque) {
        cout << "Presion: " << tanque.presion << " - ";
        if (tanque.presion >= 2 && tanque.presion <= 8) {
            cout << "Dentro del intervalo." << endl;
            return true;
        } else {
            cout << "Fuera del intervalo!" << endl;
            return false;
        }
    }

    void leerDensidad(const TanquePetroleo& tanque) {
        cout << "Densidad: " << tanque.densidad << " - ";
        if (tanque.densidad >= 0.83 && tanque.densidad < 0.87) {
            cout << "Tipo de crudo: Ligero" << endl;
        } 	
        if (tanque.densidad >= 0.87 && tanque.densidad < 0.92) {
            cout << "Tipo de crudo: Mediano" << endl;
        } 	
        if (tanque.densidad >= 0.92 && tanque.densidad < 1.00) {
            cout << "Tipo de crudo: Pesado" << endl;
        } 	
		if (tanque.densidad >= 1) {
            cout << "Tipo de crudo: Extrapesado" << endl;
        } 	        
    }

    bool leerNivelAgua(const TanquePetroleo& tanque) {
        cout << "Nivel de agua: " << tanque.nivelAgua << " - ";
        if (tanque.nivelAgua <= 10) {
            cout << "Dentro del intervalo." << endl;
            return true;
        } else {
            cout << "Fuera del intervalo!" << endl;
            return false;
        }
    }
};

class alarma{
	public:

};

int main(){
	
	TanquePetroleo tanque;
    Sensor sensor;
	
	cout << "Universidad Nacional Experimental Politecnica de Venezuela \n"<< endl;
    cout << "PROGRAMA DE SUPERVISION Y CONTROL DE LOS PARAMETROS \nOPERATIVOS DE UN TANQUE DE ALMACENAMIENTO DE PETROLEO \n"<<endl;
	cout << "Codigo desarrollado por \n Daniel Moran	 CI:30454164	Exp:20211-0069 \n Jesus Morales	 CI:28585772	Exp:20211-0336 \n Ronald Gordillo CI:30196995 	Exp:20221-0075 \n Hector Duran 	 CI:30146076 	Exp:20211-0291 \n"<<endl;
	tanque.generarParametros();

    sensor.leerNivelLiquido(tanque);
    sensor.leerTemperatura(tanque);
    sensor.leerPresion(tanque);
    sensor.leerDensidad(tanque);
    sensor.leerNivelAgua(tanque);

    return 0;
}
