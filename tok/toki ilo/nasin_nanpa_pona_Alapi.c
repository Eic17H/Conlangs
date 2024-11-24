#include <stdio.h>
#include <stdlib.h>

#define UCSUR

int nnpA_li_kama_nanpa(char* nimi);
void nanpa_li_kama_nnpA_la_sitelen(int nanpa_open);
void nnpA_li_kama_nnp_la_sitelen(char* nimi_open);
char* nanpa_li_kama_nnpA_la_poki_nimi(int nanpa_open);

// FUINWEFUINEFW

/**
 * fweionwefin
 * @return
 */

int main(){
    for(int i=0; i<=100; i++)
        nanpa_li_kama_nnpA_la_sitelen(i);
    /*int nanpa_open = 1697;
    char* nimi_nnpA = nanpa_li_kama_nnpA_la_poki_nimi(nanpa_open);
    printf("%s\n", nimi_nnpA);
    int nanpa_kama = nnpA_li_kama_nanpa(nimi_nnpA);
    printf("%d\n", nanpa_kama);
    nnpA_li_kama_nnp_la_sitelen(nimi_nnpA);
    if(nanpa_open == nanpa_kama) printf("pona\n");
    free(nimi_nnpA);*/
    return 0;
}

// ilo ni li kute e nasin Alapi pona li pana e nanpa
int nnpA_li_kama_nanpa(char* nimi){
    int suli=0, ale=1, j=0, nanpa_pini=0;
    for(suli=0; nimi[suli] != '\0'; suli++);
    int nanpa_nasin[4] = {1, 2, 5, 20};
    for(int i = suli - 1; i >= 0; i--){
        while(nimi[i] == '\''){
            ale *= 100;
            j = 0;
            i--;
        }
        if(nimi[i] - '0' > j + 1) return -1;
        nanpa_pini += (nimi[i] - '0') * nanpa_nasin[j] * ale;
        if(j++>=4) return -1;
    }
    return nanpa_pini;
}

// ilo ni li kute e nanpa Alapi pona li sitelen e nanpa pona
void nnpA_li_kama_nnp_la_sitelen(char* nimi_open){
    int suli=0, ale=1, j=0, nanpa_pini=0;
    for(suli=0; nimi_open[suli] != '\0'; suli++);
    char sitelen[4] = {'M', 'L', 'T', 'W'};
    for(int i=0; i < suli; i++){
        if(nimi_open[i] == '\''){
            printf("A");
            j=-1;
        }
        else
            for(int k=0; k < nimi_open[i] - '0'; k++)
                printf("%c", sitelen[j]);
        j++;
    }
    printf("\n");
}

// ilo ni li kute e nanpa li sitelen e nanpa Alapi pona
void nanpa_li_kama_nnpA_la_sitelen(int nanpa_open){
    int ale;
    int nanpa_nasin[4] = {20, 5, 2, 1};
    for(ale=1; ale*100 <= nanpa_open; ale*=100);
    for(; ale>0; ale/=100){
        for(int k=0; k<4; k++){
            printf("%d", nanpa_open / ale / nanpa_nasin[k]);
            nanpa_open -= ((int) nanpa_open / ale / nanpa_nasin[k]) * ale * nanpa_nasin[k];
        }
        if(ale/100>0) printf("\'");
    }
    printf("\n");
}

// ilo ni li kute e nanpa li pana e nanpa Alapi pona
// sina pini kepeken nimi pana la o weka e ona tan awen sona ilo kepeken ilo "free()"
char* nanpa_li_kama_nnpA_la_poki_nimi(int nanpa_open){
    int suli=1, ale;
    char* nimi_pini = (char*) malloc(sizeof(char) * suli);
    nimi_pini[suli - 1] = '\0';
    int nanpa_nasin[4] = {20, 5, 2, 1};
    for(ale=1; ale*100 <= nanpa_open; ale*=100);
    for(; ale>0; ale/=100){
        suli += 4;
        realloc(nimi_pini, sizeof(char) * suli);
        nimi_pini[suli - 1] = '\0';
        for(int i=0; i<4; i++){
            nimi_pini[suli - 5 + i] = (char) ('0' + nanpa_open / ale / nanpa_nasin[i]);
            nanpa_open -= ((int) nanpa_open / ale / nanpa_nasin[i]) * ale * nanpa_nasin[i];
        }
        if(ale/100>0){
            suli += 1;
            realloc(nimi_pini, sizeof(char) * suli);
            nimi_pini[suli - 2] = '\'';
        }
    }
    return nimi_pini;
}