// Hello World program 
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()


#ifdef _WIN32
    //#include <windows.h>//solo para windows aunque lo comente o borre igual va funcionar
    #define CLEAR_COMMAND "cls"//comando para limpiar pantlla
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>//ayuda en el desenpeño de la pantalla 
    #include <termios.h>
    #define CLEAR_COMMAND "clear"//comando para limpiar pantalla
#endif











//char celda1{'1'},celda2{'2'},celda3{'3'},celda4{'4'},celda5{'5'},celda6{'6'},celda7{'7'},celda8{'8'},celda9{'9'};
//char celda1{' '},celda2{' '},celda3{' '},celda4{' '},celda5{' '},celda6{' '},celda7{' '},celda8{' '},celda9{' '};

void mostrar_caratula(){
	 std::system(CLEAR_COMMAND);            // Borrar todo el contenido de la pantalla
    std::cout << "\x1B[H";          // Mover el cursor a la esquina superior izquierda

    std::cout << "\x1B[200;90;106m";         // Aplicar color y estilo
    std::cout << "/***************************************************************************************/" << std::endl; 
    std::cout << "\x1B[m";             // Restablecer color a valor por defecto
    std::cout << "\x1B[31;1m                         Universidad Catolica San Pablo \x1B[m" << std::endl; 
    std::cout << "\x1B[33;1m              Escuela Profesional de Ciencia de la Computacion \x1B[m" << std::endl; 
    std::cout << "\x1B[22;1m                     Curso de Ciencia de la Computacion I \x1B[m" << std::endl; 
    std::cout << "\x1B[38;5;63m                 Estudiante - Jhon Alexander Flores Condori  \x1B[m" << std::endl; 
    std::cout << "\x1B[3;38;5;160m                          Arequipa 2024 - Semestre II \x1B[m" << std::endl; 
    std::cout << "\x1B[200;90;106m";         // Aplicar color y estilo de nuevo
    std::cout << "/***************************************************************************************/" << std::endl;
    std::cout << "\x1B[m";             // Restablecer color a valor por defecto 
    std::cout << "\n !! juego 3 en raya !! \n\n"; // Mostrar título del proyecto
}



// Declaración de funciones
void imprimir_tablero(char celda1, char celda2, char celda3,
                      char celda4, char celda5, char celda6,
                      char celda7, char celda8, char celda9);

bool tablero_lleno(char celda1, char celda2, char celda3,
                   char celda4, char celda5, char celda6,
                   char celda7, char celda8, char celda9);

bool juego_ganado(const char celda1, const char celda2, const char celda3,
                  const char celda4, const char celda5, const char celda6,
                  const char celda7, const char celda8, const char celda9);

void movimiento_jugador(char &celda1, char &celda2, char &celda3,
                        char &celda4, char &celda5, char &celda6,
                        char &celda7, char &celda8, char &celda9, char jugador);

void movimiento_computadora(char &celda1, char &celda2, char &celda3,
                             char &celda4, char &celda5, char &celda6,
                             char &celda7, char &celda8, char &celda9);

int main() {
    // Inicializar el tablero
    char celda1 = '1', celda2 = '2', celda3 = '3';
    char celda4 = '4', celda5 = '5', celda6 = '6';
    char celda7 = '7', celda8 = '8', celda9 = '9';

    char jugador = 'X';
    char computadora = 'O';

    char nombre_jugador[50];
    std::cout << "Jugador, ingrese su nombre: ";
    std::cin >> nombre_jugador;

    bool juego_ganado_flag = false;
    bool tablero_lleno_flag = false;
    int turno = 0;

    // Inicializar la semilla para números aleatorios
    std::srand(std::time(nullptr));

    while (!juego_ganado_flag && !tablero_lleno_flag) {
        imprimir_tablero(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

        if (turno % 2 == 0) {
            std::cout << nombre_jugador << ", es tu turno (X)." << std::endl;
            movimiento_jugador(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9, jugador);
        } else {
            std::cout << "Es el turno de la computadora (O)." << std::endl;
            movimiento_computadora(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);
        }

        juego_ganado_flag = juego_ganado(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);
        tablero_lleno_flag = tablero_lleno(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

        turno++;
    }

    imprimir_tablero(celda1, celda2, celda3, celda4, celda5, celda6, celda7, celda8, celda9);

    if (juego_ganado_flag) 
	{
        if (turno % 2 == 0)
		{
			std::cout << "La computadora ha ganado Mejor suerte la proxima vez." << std::endl;
        } else 
		{
            std::cout << "Felicidades " << nombre_jugador << " has ganado" << std::endl;
        }
    } else if (tablero_lleno_flag) 
		{
        std::cout << "El juego ha terminado en empate." << std::endl;
		}

    return 0;
}

void imprimir_tablero(char celda1, char celda2, char celda3,
                      char celda4, char celda5, char celda6,
                      char celda7, char celda8, char celda9) {
    std::cout << "    A  | B  | C  " << std::endl;
    std::cout << " 1  " << celda1 << "  | " << celda2 << "  | " << celda3 << std::endl;
    std::cout << "   ____|____|____" << std::endl;
    std::cout << " 2  " << celda4 << "  | " << celda5 << "  | " << celda6 << std::endl;
    std::cout << "   ____|____|____" << std::endl;
    std::cout << " 3  " << celda7 << "  | " << celda8 << "  | " << celda9 << std::endl;
    std::cout << "       |    |    " << std::endl;
}

bool tablero_lleno(char celda1, char celda2, char celda3,
                   char celda4, char celda5, char celda6,
                   char celda7, char celda8, char celda9) {
    return celda1 != '1' && celda2 != '2' && celda3 != '3' &&
           celda4 != '4' && celda5 != '5' && celda6 != '6' &&
           celda7 != '7' && celda8 != '8' && celda9 != '9';
}

bool juego_ganado(const char celda1, const char celda2, const char celda3,
                  const char celda4, const char celda5, const char celda6,
                  const char celda7, const char celda8, const char celda9) {
    // Validación horizontal
    if (celda1 == celda2 && celda2 == celda3) return true;
    if (celda4 == celda5 && celda5 == celda6) return true;
    if (celda7 == celda8 && celda8 == celda9) return true;

    // Validación vertical
    if (celda1 == celda4 && celda4 == celda7) return true;
    if (celda2 == celda5 && celda5 == celda8) return true;
    if (celda3 == celda6 && celda6 == celda9) return true;

    // Validación diagonal
    if (celda1 == celda5 && celda5 == celda9) return true;
    if (celda3 == celda5 && celda5 == celda7) return true;

    return false;
}

void movimiento_jugador(char &celda1, char &celda2, char &celda3,
                        char &celda4, char &celda5, char &celda6,
                        char &celda7, char &celda8, char &celda9, char jugador) {
    char fila;
    char columna;

    while (true) {
        std::cout << "Ingrese la fila (1, 2, 3): ";
        std::cin >> fila;
        std::cout << "Ingrese la columna (A, B, C): ";
        std::cin >> columna;

        if (fila < '1' || fila > '3' || (columna != 'A' && columna != 'B' && columna != 'C')) {
            std::cout << "Entrada no valida Intentelo de nuevo." << std::endl;
            continue;
        }

        // Asignar el valor al tablero según la fila y columna
        if (fila == '1') {
            if (columna == 'A' && celda1 == '1') { celda1 = jugador; return; }
            if (columna == 'B' && celda2 == '2') { celda2 = jugador; return; }
            if (columna == 'C' && celda3 == '3') { celda3 = jugador; return; }
        } else if (fila == '2') {
            if (columna == 'A' && celda4 == '4') { celda4 = jugador; return; }
            if (columna == 'B' && celda5 == '5') { celda5 = jugador; return; }
            if (columna == 'C' && celda6 == '6') { celda6 = jugador; return; }
        } else if (fila == '3') {
            if (columna == 'A' && celda7 == '7') { celda7 = jugador; return; }
            if (columna == 'B' && celda8 == '8') { celda8 = jugador; return; }
            if (columna == 'C' && celda9 == '9') { celda9 = jugador; return; }
        }

        std::cout << "La celda ya esta ocupada Intentelo de nuevo." << std::endl;
    }
}

void movimiento_computadora(char &celda1, char &celda2, char &celda3,
                             char &celda4, char &celda5, char &celda6,
                             char &celda7, char &celda8, char &celda9) {
    
int movimiento;//PARA QUE LA COMPUTADORA NO PIERDA SU TURNO AL LANZAR UN NUMERO ALEATORIO 
    bool movimiento_valido = false;

    while (!movimiento_valido) {
        movimiento = std::rand() % 9; // Número aleatorio entre 0 y 8

        // Convertir el número aleatorio a las posiciones del tablero
        switch (movimiento) {
            case 0: if (celda1 == '1') { celda1 = 'O'; movimiento_valido = true; } break;
            case 1: if (celda2 == '2') { celda2 = 'O'; movimiento_valido = true; } break;
            case 2: if (celda3 == '3') { celda3 = 'O'; movimiento_valido = true; } break;
            case 3: if (celda4 == '4') { celda4 = 'O'; movimiento_valido = true; } break;
            case 4: if (celda5 == '5') { celda5 = 'O'; movimiento_valido = true; } break;
            case 5: if (celda6 == '6') { celda6 = 'O'; movimiento_valido = true; } break;
            case 6: if (celda7 == '7') { celda7 = 'O'; movimiento_valido = true; } break;
            case 7: if (celda8 == '8') { celda8 = 'O'; movimiento_valido = true; } break;
            case 8: if (celda9 == '9') { celda9 = 'O'; movimiento_valido = true; } break;
        }
    }
}