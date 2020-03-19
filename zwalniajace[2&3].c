#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

void lastMarksOccurrance();
void countAverage();

void main() {
	system("cls");

	printf("--------------------------------------------------------\n");
	printf("----------------PROJEKTY-ZWALNIAJACE-(2 & 3)------------\n");
    printf("--------------------------------------------------------\n");
    printf("-------------------------------------author-Nowak-Kamil-\n");
	printf("--------------------------------------------------------\n");
	printf("Nacisnij aby wybrac\n");
	printf("[1].Ostatnie wystapienie dowolnego znaku tekstu drugiego w tekscie pierwszym\n");
	printf("[2].Policz srednia arytmetyczna elementow dodatnich tablicy\n");
    printf("[0].Exit\n");
	printf("--------------------------------------------------------\n");

    char ch = getchar();
    system("cls");

    switch (ch)
        {
        case '1': {
            lastMarksOccurrance();
            system("PAUSE");
            break;
        }
        case '2': {
            countAverage();
            system("PAUSE");
            break;
        }
        case '3': {
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
   
}

void lastMarksOccurrance() {
    int i, sizeOfCharOccurrences, j, flag, lastIndex;
    char str1[32];
    char str2[32];

    printf("Wprowadz string 1: ");
    scanf("%s", str1);
    printf("\n--------------------------------------------------------\n");

    printf("Wprowadz string 2: ");
    scanf("%s", str2);
    printf("\n--------------------------------------------------------\n");

    system("cls");
    printf("Pierwszy string: %s", str1);
    printf("\n--------------------------------------------------------\n");
    printf("Drugi string: %s", str2);
    printf("\n--------------------------------------------------------\n");



    char charOccurrences[32];

    for (i = 0, sizeOfCharOccurrences = 0; i < 32; i++) {
        flag = -1;

        for (j = 0; j <= sizeOfCharOccurrences; j++) {
            if ((str2[i] == charOccurrences[j]) && (str2[i] != "") && (str2[i] != NULL) && (str2[i] != " "))
                flag = 1;
        }

        if (flag == -1) {
            charOccurrences[sizeOfCharOccurrences] = str2[i];
            sizeOfCharOccurrences++;
        }
    }

    int indexesOfOccurrences[32];

    for (i = 0; i < sizeOfCharOccurrences; i++) {
        for (j = 0, lastIndex = -1; j < 32; j++) {
            if ((str1[j] == charOccurrences[i]) && (str2[j] != "") && (str2[j] != NULL ) && (str2[i] != " "))
                lastIndex = j;
        }

        indexesOfOccurrences[i] = lastIndex;
    }

    for (i = 0; i < sizeOfCharOccurrences -1 ; i++) {
        printf("[%d] znak w string 2: %c [indeks ostatniego wystapienia w string 1: %d]\n", i, charOccurrences[i], indexesOfOccurrences[i] +1);
    }


    printf("\n--------------------------------------------------------\n");
    system("PAUSE");
    main();
}

void countAverage() {
    int n, m, i, j, tmp, sumOfPositives, numberOfPositives;


    printf("Srednia arytmetyczna elementow dodatnich z tablicy dwuwymiarowej");
    printf("\n--------------------------------------------------------\n");
    printf("Podaj n:");
    scanf("%d", &n);
    printf("\n--------------------------------------------------------\n");
    printf("Podaj m:");
    scanf("%d", &m);

    system("cls");

    int** tab = (int**) malloc(n* sizeof (int));

    for (i = 0; i < n; i++) {
        tab[i] = (int*) malloc(m* sizeof(int));
    }

    printf("--------------------------------------------------------\n");
    printf("Wprowadz liczby:");
    printf("\n--------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (scanf("%d", &tmp) == 1)
                tab[i][j] = tmp;
            else
                tab[i][j] = 0;
        }
    }

    for (i = 0, sumOfPositives = 0, numberOfPositives = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (tab[i][j] > 0) {
                sumOfPositives += tab[i][j];
                numberOfPositives++;
            }
        }
    }

    if (numberOfPositives != 0)
        printf("Srednia arytmetyczna liczba dodatnich: %0.5f\n", (float)sumOfPositives / numberOfPositives);
    printf("--------------------------------------------------------\n");
    system("PAUSE");
    main();
}
