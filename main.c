#include <stdio.h>

int main(void) {
    int len, dist, pozicia, i, vstup; //pozicia by asi malo byt pole
    char koniec;

    printf("napis\n");


    printf("Mozna umisteni\n");
    scanf("%d: {", &len);
    if (len <= 0) {
        printf("Nespravny vstup");
        return 0;
    }

    for (i = 1; i <= 5; i++) {          //potom pre i<=100000
        scanf("%d, ", &pozicia);
        //printf("pozicia: %d\n", pozicia);
        if (pozicia < 1 || pozicia > (len - 1)) {
            printf("Nespravny vstup");
            return 0;
        }
    }
    scanf("%c",&koniec);
    if (koniec != '}'){
        printf("Nespravny vstup");
        return 0;
    }


    printf("Vzdialenosti:\n");
    scanf("%d", &dist);
    if (dist <= 0) {
        printf("Neplatny vstup");
        return 0;
    }

    //printf("vzdialenost: %d\n", dist);

    //TU MA TERAZ IST TEN VYPOCET

    return 0;
}