#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#pragma warning (disable: 4996) 
#define PATH "plik.txt"

FILE* plik;
int series(double x, double delta, int n);
void verifyInput(double a, double b, double delta);
void writeOutToFile(double x, double sum, int n);


void main()
{
    system("cls");

    //INPUT

    //przedzial [a,b]
    double a, b,
    //skok 
    double dx, 
    //dokladnosc
    double delta;
    printf("--------------------------------------------------------\n");
    printf("Podaj przedzial [a,b], krok dx oraz dokladnosc: ");
    printf("--------------------------------------------------------\n");
    
    //Sprawdzenie poprawnosci wczytania danych
    if (scanf("%lf %lf %lf %lf", &a, &b, &dx, &delta) != 4 ) { 
        printf("Blad danych\n");
        system("pause");
        main();
    }
    else 
        verifyInput(a, b, delta);

    plik = fopen(PATH, "w");

    fprintf(plik, "x | f_szereg(x) | f_ścisłe(x) | liczba wyrazów szeregu");
    fprintf(stdout, "x | f_szereg(x) | f_ścisłe(x) | liczba wyrazów szeregu");

    //Obliczenia
    for (double x = a; x <= b; x = x + dx) {
        //Funkcja series zwraca liczbe wyrazow potrzebnych do osiagniecia dokladnosci. 
        //Obecnie nie zapamietuje zwracanej wartosci lecz mozna to zmienic w kazdej chwili.
        series(x, delta, 1);
    }

    fclose(plik);
    
    system("pause");
    main();
}

int series(double x, double delta, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum = sum + pow(x, 1 + 2 * i) / (1 + 2 * i) * pow(-1, i);
    }

    //Czy zostala osiagnieta dokladnosc
    if (fabs(sum / atan(x) - 1) > delta)
        //Jesli nie, to dzieki rekurencji osiagniemy docelowa dokladnosc.
        series(x, delta, n + 1);

    //Zapis do pliku
    writeOutToFile(x, sum, n);
    //Zwraca liczbe wyrazow
    return n;
}

void writeOutToFile(double x, double sum, int n) {
    fprintf(plik, "%0.5f | %0.5f | %0.5f | %d", x, sum, atan(x), n);
    fprintf(stdout, "%0.5f | %0.5f | %0.5f | %d", x, sum, atan(x), n);
}


void verifyInput(double a, double b, double delta) {
    //Sprawdzenie czy zawiera sie w przedziale |x| < 1
    if (delta <= 0.0 && delta >= 1) {
        printf("Niepoprawna dokladnosc\n");
        system("pause");
        main();
    }

    if (a >= 1.0 || a <= -1.0) {
        printf("Niepoprawny poczatek przedzialu\n");
        system("pause");
        main();
    }

    if (b >= 1.0 || b <= -1.0 || b < a) {
        printf("Niepoprawny koniec przedzialu\n");
        system("pause");
        main();
    }
}

