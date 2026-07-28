#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 10;
 
void llenarDatos(string nombres[], float notas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEstudiante #" << i + 1 << endl;

        cout << "Nombre: ";
        getline(cin, nombres[i]);

        do
        {
            cout << "Calificacion (0-100): ";
            cin >> notas[i];

            if (notas[i] < 0 || notas[i] > 100)
            {
                cout << "Error, La calificacion debe estar entre 0 y 100.\n";
            }

        } while (notas[i] < 0 || notas[i] > 100);

        cin.ignore();
    }
}

void mostrarDatos(string nombres[], float notas[], int n)
{
    cout << "LISTA DE ESTUDIANTES\n";
    cout << left << setw(25) << "Nombre" << "Calificación" << endl;
   

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(25) << nombres[i]
            << fixed << setprecision(2)
            << notas[i] << endl;
    }
}

float calcularPromedio(float notas[], int n)
{
    float suma = 0;

    for (int i = 0; i < n; i++)
    {
        suma += notas[i];
    }

    return suma / n;
}

void buscarMaximo(string nombres[], float notas[], int n)
{
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (notas[i] > notas[pos])
            pos = i;
    }

    cout << "\nNota mas alta\n";
    cout << "Nombre: " << nombres[pos] << endl;
    cout << "Calificacion: " << notas[pos] << endl;
}

void buscarMinimo(string nombres[], float notas[], int n)
{
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (notas[i] < notas[pos])
            pos = i;
    }
    cout << "\Nota mas baja\n";
    cout << "Nombre: " << nombres[pos] << endl;
    cout << "Calificacion: " << notas[pos] << endl;
}

void contarAprobados(float notas[], int n)
{
    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < n; i++)
    {
        if (notas[i] >= 70)
            aprobados++;
        else
            reprobados++;
    }

    cout << "\nAprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}

int main()
{
    int n = MAX;

    cout << " REGISTRO DE CALIFICACIONES \n";
    cout << "Se registraran " << n << " estudiantes.\n\n";

    string nombres[MAX];
    float notas[MAX];

    llenarDatos(nombres, notas, n);
    mostrarDatos(nombres, notas, n);
    buscarMaximo(nombres, notas, n);
    buscarMinimo(nombres, notas, n);

    cout << "\nPromedio general: "
        << fixed << setprecision(2)
        << calcularPromedio(notas, n) << endl;

    contarAprobados(notas, n);

    return 0;
}

