/*
@author Kamil Nowak
@subject Projekt 29 - laboratorium 1

Prawdopobnie przeoczyłem informacje co należy zrobić z podanymi wyrażeniami na kartce.
Jeśli to rozwiązanie jest niepoprawne, proszę o wiadomość email.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

static int setAmount();
static void series();
static void interval();
static void arctg();


int main()
{

    system("cls");

    printf("--------------------------------------------------------\n");
    printf("Wybierz opcje\n");
    printf("--------------------------------------------------------\n");
    printf("[1] arc tg(x)\n");
    printf("[2] |x| < 1\n");
    printf("[3] Suma szeregu n-elementowego\n");
    printf("[0] Zakoncz\n");
    printf("--------------------------------------------------------\n");

    char ch = getchar();
  
    switch (ch)
    {
    case '1': {
        arctg();
        system("PAUSE");
        break;
    }
    case '2': {
        interval();
        system("PAUSE");
        break;
    }
    case '3': {
        series();
        system("PAUSE");
        break;
    }
    case '0': {
        exit(0);
        break;
    }
    default:
        main();
        break;
    }

    main();
    return 0;
}

void arctg() {
    double x = 0.0;

    printf("--------------------------------------------------------\n");
    printf("Podaj X: ");
    scanf("%le", &x);
    printf("-------------------------------------------------------\n");

    printf("Arcus tangens z %0.5f jest rowny %0.5f\n", x, atan(x));
}

void interval() {
    double x = 0.0;

    printf("--------------------------------------------------------\n");
    printf("Podaj X: ");
    scanf("%le", &x);
    printf("-------------------------------------------------------\n");

    if (x < 1 && x > -1)
        printf("Liczba %0.5f spelnia nierownosc\n", x);
    else 
        printf("Liczba %0.5f nie spelnia nierownosci\n", x);
}

void series() {
    int n = 0;
    double x = 0.0;

    printf("--------------------------------------------------------\n");
    printf("Podaj pierwszy element szeregu: ");
    scanf("%le", &x);
    n = setAmount();
    printf("\n--------------------------------------------------------\n");

    double sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + pow(x, 1 + 2 * i) / (1 + 2 * i) * pow(-1, i);
    }
    printf("--------------------------------------------------------\n");
    printf("Suma szeregu %i-elementowego z pierwszym elementem %0.5f jest rowna: %0.5f", n, x, sum);
    printf("--------------------------------------------------------\n");
}

int setAmount()
{
    int n = 0;
    printf("\nWPROWADZ N:");
    scanf("%i", &n);

    if (n <= 0) {
        printf("Cos poszlo nie tak!\n");
        system("PAUSE");
        main();
    }
    
    return n;
}


