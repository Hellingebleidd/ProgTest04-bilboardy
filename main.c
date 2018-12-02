#include <stdio.h>
#define NESPRAVNY_VSTUP -1

int len;
int pos[50];
int dist;


int nacitajHodnoty(){
    int tmp, pocet =0, koniec;
    char oddelovac;
    printf("Mozna umisteni\n");
    tmp=scanf("%d : %c", &len,&oddelovac);
    if(tmp!=2 || oddelovac!='{')
        return NESPRAVNY_VSTUP;

    do{
        tmp=scanf("%d %c", &(pos[pocet++]), &oddelovac);
        if(tmp!=2 || (oddelovac!=',' && oddelovac!='}'))
            return NESPRAVNY_VSTUP;
    }while(oddelovac!='}');

    printf("Vzdalenosti:\n");

}


int main(void) {
   int pocet;
   int i, min=0, tmpMin=0;

   do{
       tmp=scanf("%d", &dist);
       koniec=getchar();
       if(tmp!=1 || dist<0 || (koniec!=EOF && koniec!='\n' && koniec!=' '))
           return NESPRAVNY_VSTUP;
       return pocet;
   }(while EOF);

   pocet=nacitajHodnoty();
   if(pocet!=NESPRAVNY_VSTUP){

   }
   else {
       printf("Nespravny vstup\n");
   }

   for(i=0; i<pocet; i++){
     if(pos[i]<=dist)
         i++;
     else{
        dist=dist + pos[i-1];
        min++;
     }
   }

    printf("Billboardu: %d\n", min);
    return 0;
}