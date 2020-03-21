#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

//rozne typy danych
typedef struct dataType {
    int d;
    char str[32];
    float f;
}dataType;

//pojedyczny element 
typedef struct element {
    dataType* data;
    struct element* next;
    struct element* prev;
} element;

//lista
typedef struct bidirectionalList {
    element* first;
    element* last;
    int size;
} bidirectionalList;


//zwraca liste
bidirectionalList* createNewList() {
    bidirectionalList* list = (bidirectionalList*)malloc(sizeof(bidirectionalList));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

//zwraca wyzerowane pola
dataType* newData() {
    int i; 

    dataType* data = malloc(sizeof(data));
    data->d = (int) 0;
    for (i = 0; i < 32; i++)
        data->str[i] = (char)' ';
    data->f = (float)0.0f;
    return data;
}

//zwraca element po id podanym przy printf'ie 
element* getElement(bidirectionalList* list, int indexOfElem) {
    element* elem = list->first;
    int index = 1;

    while (elem) {
        if (index == indexOfElem) break;
        elem = elem->next;
        index++;
    }

    return elem;
}

//zwraca poprzedni element (obsluga pushowania pomiedzy elementy)
element* getPrevElement(bidirectionalList* list, int indexOfElem) {
    return (element*)getElement(list, indexOfElem - 1);
}

//obsluguje input uzytkownika
dataType* getUserInput() {
    int type, intInput, i;
    char strInput[32];
    float floatInput;
    dataType* data = newData();

    printf("Wybierz rodzaj wprowadzanych danych\n");
    printf("[1].Liczba calkowita\n");
    printf("[2].Ciag znakow [max 32]\n");
    printf("[3].Liczba zmiennoprzecinkowa\n");

    if (scanf("%d", &type) == 1) {


        switch (type) 
        {
            case 1: {
                printf("Wprowadz wartosc [int]: ");
                if (scanf("%d", &intInput) == 1){
                    data->d = (int)intInput;
                }
                break;
            }
            case 2: {
                printf("Wprowadz wartosc [string]: ");
                if (scanf("%s", &strInput) == 1) {
                    for (i = 0; i < 32; i++) {
                        data->str[i] = (char)strInput[i];
                    }
                }
                break;
            }
            case 3: {
                printf("Wprowadz wartosc [float]: ");
                if (scanf("%f", &floatInput) == 1) {
                    data->f = (float)floatInput;
                }
                break;
            }

            default:
                break;
        }
    }
    return data;
}

//dodaje element do listy
void addElement(bidirectionalList* list, element* prev, dataType* providedData) {
    element* elem = (element*)malloc(sizeof(element));
    elem->data = providedData;
    elem->prev = prev;
    elem->next = (prev != NULL) ? prev->next : list->first;

    if (elem->prev != NULL) elem->prev->next = elem;
    else list->first = elem;

    if (elem->next != NULL) elem->next->prev = elem;
    else list->last = elem;
    
    list->size += 1;
}

//dodaje element jako pierwszy
void addAtBeg(bidirectionalList* list, dataType* data)
{
    addElement(list, NULL, data);
}

//dodaje element jako ostatni
void addAtEnd(bidirectionalList* list, dataType* data)
{
    addElement(list, list->last, data);
}

//usuwa element z listy
void removeElement(bidirectionalList* list, element* elem) {
    if (elem->prev) elem->prev->next = elem->next;
    else list->first = elem->next;
    if (elem->next) elem->next->prev = elem->prev;
    else list->last = elem->prev;

    list->size -= 1;
}

//usuwa pierwszy element z listy
void removeFirstElement(bidirectionalList* list) {
        removeElement(list, getElement(list, 1));
}

//usuwa ostatni element z listy
void removeLastElement(bidirectionalList* list) {
        removeElement(list, getElement(list, list->size));
}

//wypisuje liste na konsole
void printList(bidirectionalList* list) {
    if (!list->first) {
        printf("Lista jest pusta\n");
    }
    else {
        element* elem = list->first;
        int index = 1;

        while (elem) {
            printf("Wprowadzone dane % d:\n", index++);
            printf("   Liczba calkowita          : %d\n", (int)elem->data->d);
            printf("   Napis                     : %s\n", (char*)elem->data->str);
            printf("   Liczba zmiennoprzecinkowa : %f\n", (float)elem->data->f);    

            elem = elem->next;
        }
    }
}

//wypisuje liste od konca na konsole
void printListInversely(bidirectionalList* list) {
    if (!list->first) {
        printf("Lista jest pusta");
    }
    else {
        element* elem = list->last;
        int index = list->size;

        while (elem) {
            printf("Wprowadzone dane % d:\n", index--);
            printf("   Integer:%d\n", (int)elem->data->d);
            printf("   String:%s\n", (char*)elem->data->str);
            printf("   Float:%0f\n", (float)elem->data->f);

            elem = elem->prev;
        }
    }
}

//wypisuje menu na konsole
void menu() {
    system("cls");

    printf("--------------------------------------------------------\n");
    printf("----------------PROJEKTY-ZWALNIAJACE-( 4 )--------------\n");
    printf("--------------------------------------------------------\n");
    printf("-------------------------------------author-Nowak-Kamil-\n");
    printf("--------------------------------------------------------\n");
    printf("Obsluga struktur danych. Nacisnij aby wybrac\n");
    printf("[1].Dodaj element na poczatek listy\n");
    printf("[2].Dodaj element do listy\n");
    printf("[3].Dodaj element na koniec listy\n");
    printf("[4].Usun poczatkowy element\n");
    printf("[5].Usun element z listy\n");
    printf("[6].Usun ostatni element\n");
    printf("[7].Wyswietl liste na konsole\n");
    printf("[8].Wyswietl liste na konsole od konca\n");
    printf("[9].Restart\n");
    printf("[0].Exit\n");
    printf("--------------------------------------------------------\n");
}


//main
void main() {
    menu();
    bidirectionalList* list = createNewList();
    char ch;

    do {
        ch = getchar();
        int position;

        switch (ch)
        {
        case '1': {
            dataType* data = getUserInput();
            if (data) {
                addAtBeg(list, data);
                printf("Dodano\n");
            }
            break;
        }
        case '2': {
            dataType* data = getUserInput();
            if (data) {
                printf("Podaj pozycje: ");
                if (scanf("%d", &position) == 1) {
                    if (position > 0) {
                        addElement(list, getPrevElement(list, position), data);
                        printf("Dodano\n");
                    }
                }
            }
            break;
        }
        case '3': {
            dataType* data = getUserInput();
            if (data) {
                addAtEnd(list, data);
                printf("Dodano\n");
            }
            break;
        }
        case '4': {
            removeFirstElement(list);
            printf("Usunieto\n");
            break;
        }
        case '5': {
            printf("Podaj pozycje: ");
            if (scanf("%d", &position) == 1) {
                if (position > 0) {
                    removeElement(list, getElement(list, position));
                    printf("Usunieto\n");
                }
            }
            break;
        }
        case '6': {
            removeLastElement(list);
            printf("Usunieto\n");
            break;
        }
        case '7': {
            printList(list);
            break;
        }
        case '8': {
            printListInversely(list);
            break;
        }
        case '9': {
            //zwalnia pamiec
            free(list);
            main();
            break;
        }
        default:
            break;
        }
        system("pause");
        menu();

    } while (ch != '0');

}
