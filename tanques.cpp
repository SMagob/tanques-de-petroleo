#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;


class TanquePetroleo {
public:
	int id;  
	static int contadorId;  
    float nivelLiquido;
    float temperatura;
    float presion;
    float densidad;
    float nivelAgua;

    TanquePetroleo() : id(++contadorId) {
        srand(time(0)); // Inicializar la semilla para números aleatorios
    }

    void generarParametros() {
        nivelLiquido = rand() % 121; // Nivel de líquido entre 0 y 120
        temperatura = -40 + rand() % 160;   // Temperatura entre -40 y 120
        presion = 1 + rand() % 10;        // Presión entre 1 y 10
        densidad = 0.83 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.4)); // Densidad entre 0.83 y 1.23
        nivelAgua = (( rand() % 8) / 2);          // Nivel de agua entre 0 y 4
    }
};

int TanquePetroleo::contadorId = -1;

class Alarma : virtual public TanquePetroleo {
public:
    void activaralarmal() {
        cout << " Liquido fuera del intervalo!" << endl;
    }

    void activaralarmall() {
        cout << " Temperatura fuera del intervalo!" << endl;
    }

    void activaralarmalll() {
        cout << " Presion fuera del intervalo!" << endl;
    }

    void activaralarmalv() {
        cout << " Agua fuera del intervalo!" << endl;
    }
};

class Supervisor {
public:
    string nombre;
    int dia, mes, ano;
	vector<int> tanquesAsignados;
};

class Sensor : public Alarma {
public:
    bool leerNivelLiquido(const TanquePetroleo& tanque) {
        cout << "Nivel de Liquido: " << tanque.nivelLiquido;
        if (tanque.nivelLiquido >= 0 && tanque.nivelLiquido <= 90) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
            this->activaralarmal();
            return false;
        }
    }

    bool leerTemperatura(const TanquePetroleo& tanque) {
        cout << "Temperatura: " << tanque.temperatura;
        if (tanque.temperatura >= -20 && tanque.temperatura <= 100) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
            this->activaralarmall();
            return false;
        }
    }

    bool leerPresion(const TanquePetroleo& tanque) {
        cout << "Presion: " << tanque.presion;
        if (tanque.presion >= 2 && tanque.presion <= 8) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
            this->activaralarmalll();
            return false;
        }
    }

    string leerDensidad(const TanquePetroleo& tanque) {
        if (tanque.densidad >= 0.83 && tanque.densidad < 0.87) {
            return "Ligero";
        } else if (tanque.densidad >= 0.87 && tanque.densidad < 0.92) {
            return "Mediano";
        } else if (tanque.densidad >= 0.92 && tanque.densidad < 1.00) {
            return "Pesado";
        } else if (tanque.densidad >= 1.00) {
            return "Extrapesado";
        } else {
            return "Desconocido";
        }
    }

    bool leerNivelAgua(const TanquePetroleo& tanque) {
        cout << "Nivel de agua: " << tanque.nivelAgua;
        if (tanque.nivelAgua >= 0.5 && tanque.nivelAgua <= 2) {
            cout << " Dentro del intervalo." << endl;
            return true;
        } else {
            this->activaralarmalv();
            return false;
        }
    }
};

class sistemasupervisorio : virtual public TanquePetroleo, virtual public Sensor, virtual public Supervisor {
public:

    vector<TanquePetroleo*> tanques;
    vector<Sensor*> sensores;
    vector<Supervisor*> supervisores;
    void iniciarsistema() {
        int opcion;
        do {
            cout << "\n Menu:\n";
            cout << "1. Agregar tanques\n";
            cout << "2. Mostrar tanques\n";
            cout << "3. Eliminar tanques\n";
            cout << "4. Agregar supervisores\n";
            cout << "5. Generar reporte de tanques\n";
            cout << "6. Mostrar parametros de un tanque\n";
            cout << "7. Generar reporte de supervisores\n";
            cout << "8. Salir\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            while (cin.fail()) { // Validacion de entrada para evitar caracteres no numericos
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida, por favor introduzca un valor entre 1 y 7" << endl;
                cout << "\n Menu:\n";
                cout << "1. Agregar tanques\n";
                cout << "2. Mostrar tanques\n";
                cout << "3. Eliminar tanques\n";
                cout << "4. Agregar supervisores\n";
                cout << "5. Generar reporte de tanques\n";
                cout << "6. Mostrar parametros de un tanque\n";
                cout << "7. Generar reporte de supervisores\n";
                cout << "8. Salir\n";
                cout << "Ingrese una opcion: ";
                cin >> opcion;
            }

            switch (opcion) {
                case 1:
                    agregarTanque();
                    break;
                case 2:
                    mostrarTanquesDisponibles(tanques);
                    break;
                case 3:
                    eliminarTanque();
                    break;
                case 4:
                    agregarSupervisor();
                    break;
                case 5:
                    generarReporteTanques();
                    break;
                case 6:
                    mostrarParametrosTanque();
                    break;
                case 7:
                    generarReporteSupervisores();
                    break;
                case 8:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "No escogio ninguna de las opciones, vuelva a ingresar la opcion correspondiente." << endl;
                    break;
            }
        } while (opcion != 8);
    }

    void agregarTanque() {
        TanquePetroleo* nuevoTanque = new TanquePetroleo();
        nuevoTanque->generarParametros();
        tanques.push_back(nuevoTanque);
        cout << "\nTanque agregado correctamente." << endl;
    }

	void mostrarTanquesDisponibles(const vector<TanquePetroleo*>& tanques) {
		if (tanques.empty()) {
            cout << "\nNo hay tanques para mostrar." << endl;
        } else {
        cout << "\nTanques disponibles:\n";
		for (std::vector<TanquePetroleo*>::const_iterator it = tanques.begin(); it != tanques.end(); ++it) {
    const TanquePetroleo* tanque = *it;
    cout << "ID: " << tanque->id << " | Nivel: " << tanque->nivelLiquido
         << " | Temp: " << tanque->temperatura << endl;
}
		}
	}

    void eliminarTanque() {
        if (tanques.empty()) {
            cout << "\nNo hay tanques para eliminar." << endl;
        } else {
            delete tanques.back();
            tanques.pop_back();
            cout << "\nUltimo tanque eliminado correctamente." << endl;
        }
    }

    void agregarSupervisor() {
        Supervisor* nuevoSupervisor = new Supervisor();
    
		if (!tanques.empty()) {
			char asignarMas;
            // Ingreso del nombre del supervisor
        cout << "\nIngrese el nombre del supervisor: ";
        cin.ignore(); // Limpiar el buffer de entrada antes de getline()
        getline(cin, nuevoSupervisor->nombre);
    
        // Ingreso y validacion de la fecha de supervision
        bool fechaValida = false;
        do {
            cout << "Ingrese la fecha de supervision. Los dias deben estar entre 1-31, los meses entre 1-12 y los anos deben tener 4 digitos (dd mm aaaa): ";
            if (cin >> nuevoSupervisor->dia >> nuevoSupervisor->mes >> nuevoSupervisor->ano) {
                if (nuevoSupervisor->dia >= 1 && nuevoSupervisor->dia <= 31 &&
                    nuevoSupervisor->mes >= 1 && nuevoSupervisor->mes <= 12 &&
                    nuevoSupervisor->ano >= 0 && nuevoSupervisor->ano <= 9999) { 
                    fechaValida = true;
                } else {
                    cout << "Fecha invalida. Los dias deben estar entre 1-31, los meses entre 1-12 y los anos deben tener 4 digitos." << endl;
                }
            } else {
                cout << "Formato de fecha invalido. Intente nuevamente." << endl;
                cin.clear();
                cin.ignore(1000, '\n'); // Limpiar el buffer de entrada
            }
            cin.ignore(1000, '\n'); // Limpiar el buffer de entrada después de cada intento
        } while (!fechaValida);
    
        // Almacenar en archivo txt
        ofstream archivo("supervisores.txt", ios::app);
        if (archivo.is_open()) {
            archivo << nuevoSupervisor->nombre << "," << nuevoSupervisor->dia << "/" << nuevoSupervisor->mes << "/" << nuevoSupervisor->ano << endl;
            archivo.close();
            cout << "Supervisor agregado correctamente y almacenado en archivo." << endl;
        } else {
            cout << "\nError al abrir el archivo para guardar el supervisor." << endl;
        }

			do {
				mostrarTanquesDisponibles(tanques);
				cout << "Ingrese el ID del tanque a asignar: ";
				int idTanque;
				cin >> idTanque;

				bool existe = false;
				for (std::vector<TanquePetroleo*>::const_iterator it = tanques.begin(); it != tanques.end(); ++it) {
                    const TanquePetroleo* tanque = *it;
                    if (tanque->id == idTanque) {
                        nuevoSupervisor->tanquesAsignados.push_back(idTanque);
                        existe = true;
                        break;
                    }
                }
				
				if (!existe) {
					cout << "ID de tanque no válido.\n";
				} else {
					cout << "Tanque asignado correctamente.\n";
				}
				
				cout << "¿Desea asignar otro tanque? escriba:(s/S) para si, (n/N) para no: ";
				cin >> asignarMas;
			} while (asignarMas == 's' || asignarMas == 'S');
            supervisores.push_back(nuevoSupervisor);
		cout << " Supervisor agregado correctamente.\n";
		} else {
			cout << "\nNo hay tanques disponibles para asignarle un supervisor.\n";
		}

    }
    
    void generarReporteTanques() {
        ofstream archivo("reporte_tanque.txt", ios::out);
        if (tanques.empty()) {
            cout << "\nNo hay tanques para generar el reporte." << endl;
        } else {
        if (archivo.fail()) {
            cerr << "\nError al abrir el archivo para el reporte." << endl;
            exit(1);
        }

        for (std::vector<TanquePetroleo*>::const_iterator it = tanques.begin(); it != tanques.end(); ++it) {
        const TanquePetroleo* tanque = *it;
        std::string tipoCrudo = leerDensidad(*tanque);
        archivo << "Nivel de Líquido: " << tanque->nivelLiquido << std::endl;
        archivo << "Temperatura: " << tanque->temperatura << std::endl;
        archivo << "Presión: " << tanque->presion << std::endl;
        archivo << "Densidad: " << tanque->densidad << " - Tipo de crudo: " << tipoCrudo << std::endl;
        archivo << "Nivel de Agua: " << tanque->nivelAgua << std::endl;
        archivo << "--------------------------------" << std::endl;
        }
        archivo.close();
        cout << "\nReporte generado correctamente en 'reporte_tanque.txt'." << endl;
    }
    }

    void mostrarParametrosTanque() {
        if (tanques.empty()) {
            cout << "\nNo hay tanques registrados." << endl;
        } else {
            cout << "\nMostrando parametros del ultimo tanque agregado:" << endl;
            TanquePetroleo* ultimoTanque = tanques.back();
            Sensor sensor;
            sensor.leerNivelLiquido(*ultimoTanque);
            sensor.leerTemperatura(*ultimoTanque);
            sensor.leerPresion(*ultimoTanque);
            cout << "Densidad: " << ultimoTanque->densidad << " - Tipo de crudo: " << sensor.leerDensidad(*ultimoTanque) << endl;
            sensor.leerNivelAgua(*ultimoTanque);
        }
    }

	void generarReporteSupervisores() {
		ofstream archivo2("reporte_supervisor.txt");
		if (!archivo2) {
			cout << "Error al abrir reporte_supervisor.txt\n";
			exit(EXIT_FAILURE);
		}
		
		if (supervisores.empty()){
			cout << "\nAdvertencia!: no hay supervisores registrados.\n";
		}
        else{
            for (std::vector<Supervisor*>::const_iterator it = supervisores.begin(); it != supervisores.end(); ++it) {
                const Supervisor* supervisor = *it;
                archivo2 << "Reporte realizado por: " << supervisor->nombre << "\n";
                archivo2 << "Fecha de Reporte: Dia " << supervisor->dia
                         << " del Mes " << supervisor->mes
                         << " del año " << supervisor->ano << "\n\n";
                archivo2 << "Tanques asignados: ";
                if (supervisor->tanquesAsignados.empty()) {
                    archivo2 << "Ninguno";
                } else {
                    for (std::vector<int>::const_iterator idIt = supervisor->tanquesAsignados.begin(); idIt != supervisor->tanquesAsignados.end(); ++idIt) {
                        archivo2 << *idIt << " ";
                    }
                }
                archivo2 << "\n\n";
            }
            cout << "\nReporte generado correctamente en 'reporte_supervisor.txt'." << endl;
        }
		archivo2.close();  
	}
};

int main() {
    sistemasupervisorio sistema;

    cout << "Universidad Nacional Experimental Politecnica de Venezuela \n" << endl;
    cout << "PROGRAMA DE SUPERVISION Y CONTROL DE LOS PARAMETROS \nOPERATIVOS DE UN TANQUE DE ALMACENAMIENTO DE PETROLEO \n" << endl;
    cout << "Codigo desarrollado por: \n ~ Daniel Moran     CI:30454164    Exp:20211-0069 \n ~ Jesus Morales    CI:28585772    Exp:20211-0336 \n ~ Ronald Gordillo  CI:30196995    Exp:20221-0075 \n ~ Hector Duran     CI:30146076    Exp:20211-0291";
    cout << "\nSe iniciara el sistema de supervision de tanques:\n\n";
    sistema.iniciarsistema();

    return 0;
}
