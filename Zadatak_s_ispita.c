#include <stdio.h>
#include <stdlib.h>

int * neka_funkcija(char niz[100]){
    int i;
    int niz2[100];
    for(i=0; i<100; i++){
        niz2[i]=0;
    }
    for(i=0; i<100; i++){
        niz2[niz[i]-65]++;
    }

    return niz2;
    //return 0;
}

int main()
{
    FILE* ulazna_datoteka, *izlazna_datoteka;
    ulazna_datoteka=fopen("ulaz.txt", "r");
    izlazna_datoteka = fopen("izlaz.txt", "w");
    if(ulazna_datoteka==NULL){
        printf("greska1");
        exit(1);
    }else if (izlazna_datoteka==NULL){
    printf("greska2");
    close(ulazna_datoteka);
    exit(2);
    }else{
    printf("obe otvoreno uspjesno...\n");
    char niz[1000];
    int i;
    for(i=0; i<1000; i++)
        niz[i]=0;
    char c;
    i=0;
    while((c = getc(ulazna_datoteka))!=EOF){
        niz[i++]=c;
    }

    int* pok;
    pok=neka_funkcija(niz);


    for(i=0; i<26; i++){
        printf("%c ima ukupno %d elemenata\n", i+65, *pok++);
    }
    pok=neka_funkcija(niz);
    for(i=0; i<26; i++)
    {
        fprintf(izlazna_datoteka,"%c%d ", i+65, *pok++);
    }
    }

    printf("\n%c", (int)('a'-'A')+2);
    close(ulazna_datoteka);
    close(izlazna_datoteka);

    char recenica[10];
    scanf("%s", &recenica);
    char c=getchar();
    if(c!='X')
        printf("%c %s nije do kraja", c, recenica);
    else
        printf("na kraju smo");
    return 0;
}
