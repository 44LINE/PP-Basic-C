
/*
@author Kamil Nowak
@subject Zadanie 17 - laboratorium 1
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>

static bool doesExist();

int main(int argc, _TCHAR* argv[])
{
    system("cls");

    double a = 0.0, b = 0.0, c = 0.0;
    int ret = -1;
    //input data
    printf("Zadanie z trojkatem\n");
    printf("Podaj a,b,c\n");
    ret = scanf("%le%le%le", &a, &b, &c);
    if (ret != 3)
    {
        printf("Blad przy wczytaniu\n");
        printf("Wczytane: a = %e b = %e c = %e\n", a, b, c);
        //To jest blad oprogramowania
        main();
    }
    //Sprawdzanie bokow
    if (a <= 0.0 || b <= 0.0 || c <= 0.0 || !doesExist(a, b, c)) {
        printf("Z tych bokow nie zbudujesz trojkata.\n");
        main()
    }

    //Obliczenia    
    double p = (a + b + c) / 2;
    double S = sqrt(p(p - a) * (p - b) * (p - c));
    double R = S / p;

    printf("Pole = %0.5f\nPromien kola wpisanego w trojkat = %0.5f\n", S, R);
    printf("---------------------------------------------------------");
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



