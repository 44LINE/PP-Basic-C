
/*
@author Kamil Nowak
@subject Zadanie 19 - laboratorium 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

static bool doesExist();
static void square();
static void rectangle();
static void triangle();
static void circle();
static double getUserInput();

int main()
{

    system("cls");

    printf("--------------------------------------------------------\n");
    printf("Wybierz opcje\n");
    printf("--------------------------------------------------------\n");
    printf("[1] Trojkat\n");
    printf("[2] Kwadrat\n");
    printf("[3] Prostokat\n");
    printf("[4] Kolo\n");
    printf("[0] Zakoncz\n");
    printf("--------------------------------------------------------\n");

    char ch = getchar();

    switch (ch)
    {
    case '1': {
        triangle();
        system("PAUSE");
        break;
    }
    case '2': {
        square();
        system("PAUSE");
        break;
    }
    case '3': {
        rectangle();
        system("PAUSE");
        break;
    }
    case '4': {
        circle();
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

static bool doesExist(double a, double b, double c)
/*==============================================================================
Warunek istnienia trojkata
===============================================================================*/
{
    if ((a + b) > c && (b + c) > a && (a + c) > b)
        return true;
    else
        return false;
}

static void square() {
    double x = 0.0;

    printf("--------------------------------------------------------\n");
    x = getUserInput();
    printf("Pole = %0.5f\n Obwod = %0.5f\n", x * x, 4 * x);
    printf("-------------------------------------------------------\n");
}

static void rectangle() {
    double x = 0.0;
    double y = 0.0;

    printf("--------------------------------------------------------\n");
    x = getUserInput();
    y = getUserInput();
    printf("Pole = %0.5f\n Obwod = %0.5f\n", x * y, 2 * x + 2 * y);
    printf("-------------------------------------------------------\n");
}

static void triangle() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    a = getUserInput();
    b = getUserInput();
    c = getUserInput();

    if (!doesExist(a, b, c)) {
        printf("Z tych bokow nie zbudujesz trojkata.\n");
        main()
    }

    double p = (a + b + c) / 2;
    double S = sqrt(p(p - a) * (p - b) * (p - c));

    printf("--------------------------------------------------------\n");
    printf("Pole = %0.5f\n Obwod = %0.5f\n", S, a + b + c);
    printf("\n--------------------------------------------------------\n");
}

static void circle() {
    double x = 0.0;

    printf("--------------------------------------------------------\n");
    x = getUserInput();
    printf("Pole = %0.5f\n Obwod = %0.5f\n", 3.14 * pow(x, 2), 2 * 3.14 * x);
    printf("-------------------------------------------------------\n");
}

static double getUserInput() {
    double n = 0.;
    printf("\nWprowadz zmienna:");
    scanf("%i", &n);

    if (n <= 0.0) {
        printf("Cos poszlo nie tak!\n");
        system("PAUSE");
        main();
    }

    return n;
}



