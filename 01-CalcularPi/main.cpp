#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calcularPi(double objetivo, int& iteraciones) { //iteraciones por referencia para asi poder ir sumandola al original cada vez que se realiza
    double pi = 0.0;
    int signo = 1; //la serie de Lebinz arranca en positivo
    double termino = 1.0; // la serie de lebinz arranca con 1
    int i = 0; 
    
    while (fabs(termino) >= objetivo) { 
        pi += termino; //para seguir las iteraciones con el resultado obtenido en la anterior
        signo *= -1; //porque se cambia el signo luego de cada iteracion
        i++; 
        termino = signo / (2.0 * i + 1.0);
        iteraciones++;
    }

    return 4 * pi; //porque la aproximacion a pi queda sobre 4, entonces para poder obtener el resultado pedido es necesario multiplicarlo
}

int main() {
double objetivo = 0.0000001; //diferencia para que el valor de pi de los pedido
double resultado = 0.0; 
int iteraciones; //calcular cuantas veces se realizo el while

resultado = calcularPi(objetivo, iteraciones); //realizar la funcion

cout << "El valor de Pi es: " << fixed << setprecision(6) << resultado << endl;
cout << "Se necesitaron: " << iteraciones << " iteraciones" << endl; 

return 0;
}