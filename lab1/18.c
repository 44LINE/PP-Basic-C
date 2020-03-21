#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

/*
    author - Nowak Kamil
    Zadanie 18
*/

typedef struct number {
    int value;
    int position;
}number;

number* setValue(number* num) {
    int intInput = 0;

    printf("Wprowadz liczbe calkowita: ");

        if (scanf("%d", &intInput) == 1)
            num->value = (int)intInput;

        return num;
}

void main() {
    number* a = (number*)malloc(sizeof(number));
    number* b = (number*)malloc(sizeof(number));
    number* c = (number*)malloc(sizeof(number));
    number* d = (number*)malloc(sizeof(number));
    number* MAX = (number*)malloc(sizeof(number));

    a->position = (int)1;
    b->position = (int)2;
    c->position = (int)3;
    d->position = (int)4;

    setValue(a);
    setValue(b);
    setValue(c);
    setValue(d);
    
    MAX->value = a->value;
    MAX->position = a->position;

    if (MAX->value < b->value) {
        MAX->position = b->position;
        MAX->value = b->value;
    }
    if (MAX->value < c->value) {
        MAX->position = c->position;
        MAX->value = c->value;
    }
    if(MAX->value < d->value) {
        MAX->position = d->position;
    }

    printf("Najwieksza liczba to pozycja %d", MAX->position);
}
