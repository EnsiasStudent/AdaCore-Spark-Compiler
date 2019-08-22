// here you need to write the code of the syntaxic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include "analyseur_syntaxique.c"

int main(){
    int i;
    stream = fopen("C://Users//Adnane//ClionProjects//Compila//expression.txt","r");
    if(stream == NULL) Erreur(ERR_FICH_VID);
    current = fgetc(stream);
    next_Sym();
    PROGRAMME();
    if(Sym_Cour.token == EOF_TOKEN){
        // printf("\n\nBRAVO: le programme est correcte !!!\n");
        fclose(stream);
        stream = fopen("C://Users//Adnane//ClionProjects//Compila//Pcode","w");
        for(i=0; i<PC; i++){
            switch(PCODE[i].SUITE.type){
                case BOOLEAN : fprintf(stream, "(%d) %s\t%d\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.b); break;
                case INTEGER : fprintf(stream, "(%d) %s\t%d\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.i); break;
                case FLOAT : fprintf(stream, "(%d) %s\t%f\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.f); break;
                case NATURAL : fprintf(stream, "(%d) %s\t%d\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.i); break;
                case POSITIVE : fprintf(stream, "(%d) %s\t%d\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.i); break;
                case CHARACTER : fprintf(stream, "(%d) %s\t%c\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.c); break;
                case STRING : fprintf(stream, "(%d) %s\t%s\n", i, tab_p_code[PCODE[i].MNE].name, PCODE[i].SUITE.data.s); break;
            }
        }
    }
    else{
        printf("\n\nPAS BRAVO: fin de programme erronée !!!!\n");
    }
    printf("\nOutput : \n");
    INTER_PCODE();
    return 0;
}
