#include <iostream>

using namespace std;
int fact(int);
bool EsVocal(char caracter);
void calcular(int cantdinero, int &b1000, int &b2000, int &b5000, int &b10000,int &b20000, int &b50000, int &m50, int &m100, int &m200, int &m500, int &faltante);

int main()
{

    int opcion=1;
    cout<<"Bienvenido a la practica 1"<<endl;

    while(opcion!=0)
    {
        cout<< "seleccione una opcion" <<endl;
        cout<< "1.Problema 1"<<endl;
        cout<<"2.Problema 2"<<endl;
        cout<<"3.Problema 3"<<endl;
        cout<<"5.Problema 5"<<endl;
        cout<<"6.Problema 6"<<endl;
        cout<< "0. Salir"<<endl;
        cin>>opcion;

        switch (opcion) {
        case 1:
        {
            //problema realizado por la profesora
            char caracter;
            cout<<"Ejecutando el problema 1 ..."<<endl;
            cout<<"Ingrese un caracter"<<endl;
            cin>>caracter;
            if((caracter>=65 && caracter<=90) ||(caracter>=97 && caracter<=122))
            {
                if(EsVocal(caracter))
                    cout<<caracter<<" es una vocal"<<endl;
                else
                    cout<<caracter<<" es una consonante"<<endl;

            }else
                cout<<caracter <<" No es una letra"<<endl;
            break;
        }
        case 2:
        {
            int b1000 = 0, b2000 = 0, b5000 = 0, b10000 = 0;
            int b20000 = 0, b50000 = 0, m50 = 0, m100 = 0;
            int m200 = 0, m500 = 0, faltante = 0;
            int cantdinero;

            cout << "Ingresa el valor de cantidad de dinero: ";
            cin >> cantdinero;

            // Llamada a la función para calcular billetes y monedas
            calcular(cantdinero, b1000, b2000, b5000, b10000, b20000, b50000, m50, m100, m200, m500, faltante);

            // Mostrar el resultado
            cout << "50000 : " << b50000 << endl;
            cout << "20000 : " << b20000 << endl;
            cout << "10000 : " << b10000 << endl;
            cout << "5000  : " << b5000 << endl;
            cout << "2000  : " << b2000 << endl;
            cout << "1000  : " << b1000 << endl;
            cout << "500   : " << m500 << endl;
            cout << "200   : " << m200 << endl;
            cout << "100   : " << m100 << endl;
            cout << "50    : " << m50 << endl;
            cout << "Faltante: " << faltante << endl;
            break;
        }
        case 3:
        {
            int dia,mes;

            cout << "Ingrese dia:" << endl;
            cin>>dia;
            cout << "ingrese mes:" << endl;
            cin>>mes;

            if (mes < 1 || mes >12){
                cout << "El mes" << mes << " Es invalido"<< endl;
            }
            else{
                int dias[]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                if (dia < 1||dias[mes-1]){
                    if (mes ==2 && dia==29){
                        cout << dia << "/" << mes<< "posible bisiesto" << endl;
                    }else{

                        cout << dia << "/" << mes << " es una fecha valida." <<endl;

                    }
                } else {
                    cout << dia << "/" << mes << " es una fecha invalida." << endl;

                }

            }

            break;
        }
        case 5:{
            int n;

            cout << "Ingrese un numero impar: ";
            cin >> n;

            // Imprimir el patrón ascendente con espacio a la izquierda
            for (int i = 1; i <= n; i += 2) {
                for (int j = 1; j <= (n - i) / 2; j++) {
                    cout << " "; // Espacios a la izquierda
                }
                for (int j = 1; j <= i; j++) {
                    cout << "*";
                }
                cout << endl;


            }

            // Imprimir el patrón descendente con espacio a la izquierda
            for (int i = n - 2; i >= 1; i -= 2) {
                for (int j = 1; j <= (n - i) / 2; j++) {
                    cout << " "; // Espacios a la izquierda
                }
                for (int j = 1; j <= i; j++) {
                    cout << "*";
                }

                cout << endl;

        }
        break;

        case 6:{
            int s;

            cout<<" Escriba un numero:" <<endl;
            cin >>s;
            double e=0;
            for ( int i=0;i<s;i++){
                double u=fact(i);
                e+=1/u;

            }

            cout <<" El valor aproximado de en en base a su numero"<<s<<"es"<<e<<endl;
        }
        break;
        default:
            if(opcion!=0)
                cout<<"opcion no valida"<<endl;
            break;
        }
    }
}
}

    //funciones
    bool EsVocal(char caracter)
    {
        if(caracter>=97)
            caracter-=32;

        if(caracter=='A'|| caracter=='E'|| caracter=='I'
            || caracter=='O'||caracter=='U')
            return true;
        else
            return false;
    }
    void calcular(int cantdinero, int &b1000, int &b2000, int &b5000, int &b10000,
                  int &b20000, int &b50000, int &m50, int &m100, int &m200, int &m500, int &faltante) {
        b50000 = cantdinero / 50000;
        cantdinero %= 50000;

        b20000 = cantdinero / 20000;
        cantdinero %= 20000;

        b10000 = cantdinero / 10000;
        cantdinero %= 10000;

        b5000 = cantdinero / 5000;
        cantdinero %= 5000;

        b2000 = cantdinero / 2000;
        cantdinero %= 2000;

        b1000 = cantdinero / 1000;
        cantdinero %= 1000;

        m500 = cantdinero / 500;
        cantdinero %= 500;

        m200 = cantdinero / 200;
        cantdinero %= 200;

        m100 = cantdinero / 100;
        cantdinero %= 100;

        m50 = cantdinero / 50;
        cantdinero %= 50;

        faltante = cantdinero; // Lo que queda es el faltante
    }

    int fact (int f){
        int factorial = f;
        if (factorial >1){
            factorial=f*fact(f-1);
            return factorial;
        }
        else {
            return 1;
        }
    }
