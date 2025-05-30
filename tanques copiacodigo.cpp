#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
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
        nivelAgua = (( rand() % 8) / 2);          // Nivel de agua entre 0 y 4
    }
};

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

class sistemasupervisorio : virtual public TanquePetroleo, virtual public Sensor, public Supervisor {
public:
    vector<TanquePetroleo*> tanques;
    vector<Sensor*> sensores;
    vector<Supervisor*> supervisor;
    void iniciarsistema() {
        int opcion;
        do {
            cout << "\n Menu:\n";
            cout << "1. Agregar tanques\n";
            cout << "2. Eliminar tanques\n";
            cout << "3. Agregar supervisores\n";
            cout << "4. Generar reporte de tanques\n";
            cout << "5. Mostrar parametros de un tanque\n";
            cout << "6. Generar reporte de supervisores\n";
            cout << "7. Salir\n";
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            while (cin.fail()) { // Validacion de entrada para evitar caracteres no numericos
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida, por favor introduzca un valor entre 1 y 7" << endl;
                cout << "\n Menu:\n";
                cout << "1. Agregar tanques\n";
                cout << "2. Eliminar tanques\n";
                cout << "3. Agregar supervisores\n";
                cout << "4. Generar reporte de tanques\n";
                cout << "5. Mostrar parametros de un tanque\n";
                cout << "6. Generar reporte de supervisores\n";
                cout << "7. Salir\n";
                cout << "Ingrese una opcion: ";
                cin >> opcion;
            }

            switch (opcion) {
                case 1:
                    agregarTanque();
                    break;
                case 2:
                    eliminarTanque();
                    break;
                case 3:
                    agregarSupervisor();
                    break;
                case 4:
                    generarReporteTanques();
                    break;
                case 5:
                    mostrarParametrosTanque();
                    break;
                case 6:
                    generarReporteSupervisores();
                    break;
                case 7:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "No escogio ninguna de las opciones, vuelva a ingresar la opcion correspondiente." << endl;
                    break;
            }
        } while (opcion != 7);
    }

    void agregarTanque() {
        TanquePetroleo* nuevoTanque = new TanquePetroleo();
        nuevoTanque->generarParametros();
        tanques.push_back(nuevoTanque);
        cout << "\nTanque agregado correctamente." << endl;
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
    
        // Ingreso del nombre del supervisor
        cout << "Ingrese el nombre del supervisor: ";
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
            cout << "Error al abrir el archivo para guardar el supervisor." << endl;
        }
    
        delete nuevoSupervisor; // Liberar la memoria asignada
    }
    
    void generarReporteTanques() {
        ofstream archivo("reporte_tanque.txt", ios::out);

        if (archivo.fail()) {
            cerr << "Error al abrir el archivo para el reporte." << endl;
            exit(1);
        }

        archivo << "Reporte de Parámetros del Tanque" << endl;
        archivo << "--------------------------------" << endl;

        for (const auto& tanque : tanques) {
            string tipoCrudo = leerDensidad(*tanque);

            archivo << "Nivel de Líquido: " << tanque->nivelLiquido << endl;
            archivo << "Temperatura: " << tanque->temperatura << endl;
            archivo << "Presión: " << tanque->presion << endl;
            archivo << "Densidad: " << tanque->densidad << " - Tipo de crudo: " << tipoCrudo << endl;
            archivo << "Nivel de Agua: " << tanque->nivelAgua << endl;
            archivo << "--------------------------------" << endl;
        }

        archivo.close();
        cout << "Reporte generado correctamente en 'reporte_tanque.txt'." << endl;
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
        cout << "\nFuncionalidad no implementada aun." << endl;
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