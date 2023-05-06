#include <iostream>
#include <fstream>
#include <string>



void crearArchivos(int cantidadArchivos) {
    std::string rutaDirectorio;
    if (cantidadArchivos % 2 == 0) {
        rutaDirectorio = "C:\\Users\\LATITUDE\\Documents\\par\\";
    } else {
        rutaDirectorio = "C:\\Users\\LATITUDE\\Desktop\\IMPAR\\";
    }

    for (int i = 1; i <= cantidadArchivos; i++) {
        std::string nombreArchivo = "file" + std::to_string(i) + ".txt";
        std::string rutaArchivo = rutaDirectorio + nombreArchivo;

        std::ofstream archivo(rutaArchivo);
        if (archivo.is_open()) {
            archivo << "Contenido del archivo " << nombreArchivo << std::endl;
            archivo.close();
        } else {
            std::cout << "No se pudo crear el archivo " << nombreArchivo << std::endl;
        }
    }
}

int main() {
    int cantidadArchivos;
    std::cout << "¿Cuantos archivos desea crear? ";
    std::cin >> cantidadArchivos;

    crearArchivos(cantidadArchivos);

    return 0;
}



#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool agregarTexto(int numArchivo, string texto) {

    string nombreArchivo = "file" + to_string(numArchivo) + ".txt";


    ofstream archivo(nombreArchivo, ios::app);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }


    archivo << texto << endl;


    int numLineas = 0;
    string linea;
    ifstream archivoLectura(nombreArchivo);
    while (getline(archivoLectura, linea)) {
        numLineas++;
    }
    archivoLectura.close();


    int lineasFaltantes = numArchivo - numLineas;
    while (lineasFaltantes > 0) {
        archivo << "Linea vacia" << endl;
        lineasFaltantes--;
    }


    archivo.close();
    return true;
}

int main() {

    if (agregarTexto(2, "Texto agregado al archivo 2")) {
        cout << "Texto agregado exitosamente" << endl;
    }

    return 0;
}

#include <fstream>
#include <string>

void agregarTextoArchivos(int numArchivos, std::string textoAgregar) {
    for (int i = 1; i <= numArchivos; i++) {
        std::string nombreArchivo = "file" + std::to_string(i) + ".txt";
        std::ofstream archivo(nombreArchivo, std::ios_base::app);
        for (int j = 0; j < i; j++) {
            archivo << textoAgregar << "\n";
        }
        archivo.close();
    }
}
