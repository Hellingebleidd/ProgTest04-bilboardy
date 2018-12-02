#include <stdio.h>

#define NESPRAVNY_VSTUP -1

int len;
int pos[1000001];


int nacitajHodnoty() {
    int tmp, pocet = 0;
    char oddelovac;

    printf("Mozna umisteni:\n");
    tmp = scanf("%d : %c", &len, &oddelovac);
    if (tmp != 2 || oddelovac != '{' || len <= 0)
        return NESPRAVNY_VSTUP;

    do {
        tmp = scanf("%d %c", &(pos[pocet]), &oddelovac);
        if (tmp != 2 || (oddelovac != ',' && oddelovac != '}') || pocet >= (1000000 - 1) || pos[pocet]<1 || pos[pocet]>=len)
            return NESPRAVNY_VSTUP;
        pocet++;
    } while (oddelovac != '}');

    pos[pocet++] = len;
    printf("Vzdalenosti:\n");

    return pocet;

}


int main(void) {
    int pocet, tmp, koniec, dist, tmpDist;
    int i, min = 0, tmpI = 0;

    pocet = nacitajHodnoty();
    if (pocet != NESPRAVNY_VSTUP) {

        do {
            min = 0;
            tmpI = 0;
            tmp = scanf("%d", &dist);
            koniec = getchar();
            if (tmp <= 0 && koniec == EOF)
                return 0;
            if (tmp != 1 || dist <= 0 || (koniec != EOF && koniec != '\n' && koniec != ' ')) {
                printf("Nespravny vstup.\n");
                return NESPRAVNY_VSTUP;
            }
            tmpDist = dist;
            if(dist==len)
                break;
            for (i = 0; i < pocet; i++) {
                if (pos[i] > tmpDist) {
                    if (tmpI == i) {  //uz tuto poziciu raz riesil
                        printf("N/A\n");
                        break;
                    }
                    tmpDist = dist + pos[i - 1];
                    min++;
                    tmpI = i;
                }
            }
            if (min > 0)
                printf("Billboardu: %d\n", min);

        } while (koniec != EOF);

    } else {
        printf("Nespravny vstup.\n");
    }


    return 0;
}