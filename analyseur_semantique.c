//
// Created by Adnane on 03/02/2019.
//

//declaration semantique
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include "analyseur_lexical.c"

int OFFSET = 0;

typedef enum {BOOLEAN, INTEGER, NATURAL, POSITIVE, FLOAT, CHARACTER, STRING, DURATION, NEWTYPE, ARAYTYPE, COMPOSITETYPE, ENUMERATIONTYPE} TSYM;
typedef enum {TO_BOOLEAN, TO_INTEGER, TO_NATURAL, TO_POSITIVE, TO_FLOAT, TO_CHARACTER, TO_STRING, TO_TYPE_INTEGER_TOKEN, TO_TYPE_FLOAT_TOKEN, TO_TYPE_CHARACTER_TOKEN, TO_TYPE_STRING_TOKEN}TYPE_OPERS;

typedef struct {
    TSYM target;
    TYPE_OPERS OPERS_POSSIBLE[20];
    int CPT_OPERS;
    enum AdaTokens OPERAS_POSSIBLE[20];
    int CPT_OPERAS;
}TYPING_CORRESPONDENCE;

TYPING_CORRESPONDENCE TAB_TYPING_CORRESPONDENCE[10] = {
        {BOOLEAN, {TO_BOOLEAN}, 1, {AND_TOKEN, OR_TOKEN, XOR_TOKEN}, 3},
        {INTEGER, {TO_INTEGER, TO_NATURAL, TO_POSITIVE, TO_TYPE_INTEGER_TOKEN, TO_TYPE_CHARACTER_TOKEN, TO_CHARACTER, TO_FLOAT, TO_TYPE_FLOAT_TOKEN}, 8, {PLUS_TOKEN, HYPHEN_TOKEN, STAR_TOKEN, DOUBLE_STAR_TOKEN, SLASH_TOKEN, MOD_TOKEN}, 6},
        {NATURAL, {TO_INTEGER, TO_NATURAL, TO_POSITIVE, TO_TYPE_INTEGER_TOKEN, TO_TYPE_CHARACTER_TOKEN, TO_CHARACTER, TO_FLOAT, TO_TYPE_FLOAT_TOKEN}, 8, {PLUS_TOKEN, HYPHEN_TOKEN, STAR_TOKEN, DOUBLE_STAR_TOKEN, SLASH_TOKEN, MOD_TOKEN}, 6},
        {POSITIVE, {TO_INTEGER, TO_NATURAL, TO_POSITIVE, TO_TYPE_INTEGER_TOKEN, TO_TYPE_CHARACTER_TOKEN, TO_CHARACTER, TO_FLOAT, TO_TYPE_FLOAT_TOKEN}, 8, {PLUS_TOKEN, HYPHEN_TOKEN, STAR_TOKEN, DOUBLE_STAR_TOKEN, SLASH_TOKEN, MOD_TOKEN}, 6},
        {FLOAT, {TO_INTEGER, TO_NATURAL, TO_POSITIVE, TO_FLOAT, TO_TYPE_INTEGER_TOKEN, TO_TYPE_FLOAT_TOKEN, TO_TYPE_CHARACTER_TOKEN, TO_CHARACTER}, 8, {PLUS_TOKEN, HYPHEN_TOKEN, STAR_TOKEN, DOUBLE_STAR_TOKEN, SLASH_TOKEN}, 5},
        {CHARACTER, {TO_TYPE_CHARACTER_TOKEN}, 1, {}, 0},
        {STRING, {TO_STRING, TO_TYPE_STRING_TOKEN}, 2, {}, 0}
};

//typedef enum {TCONST, TVAR, TNEWT, TARRAYT, TCOMPT, TENUMT} CSYM;
enum Erreurs_Semantique {DDEC, INDEC, CCVNA, TND, NCT, VNS, CNE} ;
//DDEC <=> Double Declaration
//INDEC <=> Identifiant Non Declaré
//CCVNA <=> Constante Change Valeur Non Autorisé
struct Messages_Erreurs_Semantique { enum Erreurs_Semantique CODE_ERR; char mes[100]; };
struct Messages_Erreurs_Semantique mess_err_sem[] = {   {DDEC, "double déclaration"},
                                                        {INDEC, "identificateur non déclaré"},
                                                        {CCVNA, "constante ne peut changer de valeur"},
                                                        {TND, "type non declarer"},
                                                        {NCT , "nom cohérent type"},
                                                        {VNS, "ce variable est n'est pas de type structure"},
                                                        {CNE , "champs non exite dans cette structure"}
};
typedef struct {
    char NOM[20];
    int id_parent;
    int id;
}STR_TAB_SYM_IDF_FUNC;

typedef struct {
    char NOM[20];
    int id_parent;
    int id;
}STR_TAB_SYM_IDF_PROC;

typedef struct {
    char NOM[20];
    TSYM TIDF;
    int ADRESSE;
    int id;
} STR_TAB_SYM_CONST;

typedef struct {
    char NOM[20];
    TSYM TIDF;
    int ADRESSE;
    int id;
    char nomType[30];
} STR_TAB_SYM_VAR;

typedef struct {
    char NOM[20];
    TSYM TIDF;
    int id;
} STR_TAB_SYM_NEW_TYPE;

typedef struct {
    char NOM[20];
    TSYM TIDF;
    int id;
} STR_TAB_SYM_MOD_TYPE;

typedef struct {
    char NOM[20];
    TSYM TIDF;
    int start;
    int end;
    char interval[30];
    int id;
} STR_TAB_SYM_ARRAY_TYPE;

typedef struct {
    char NOMS[30][30];
    int size;
    TSYM TIDF;
}PARAMETER;

typedef struct {
    char NOM[20];
    PARAMETER PARAM[30];
    int CPT;
    int id;
} STR_TAB_SYM_COMPOSITE_TYPE;

typedef struct {
    char NOM[20];
    char PARAM[30][30];
    int CPT;
    int id;
} STR_TAB_SYM_ENUMERATION_TYPE;

#define NIDFS 100
STR_TAB_SYM_IDF_FUNC TAB_SYM_FUNC[NIDFS]; int CMP_TABSYM_FUNC = 0;
STR_TAB_SYM_IDF_PROC TAB_SYM_PROC[NIDFS]; int CMP_TABSYM_PROC = 0;
STR_TAB_SYM_CONST TABSYM_CONST[NIDFS];  int CMP_TABSYM_CONST = 0;
STR_TAB_SYM_VAR TABSYM_VAR[NIDFS];  int CMP_TABSYM_VAR = 0;
STR_TAB_SYM_NEW_TYPE TABSYM_NEW_TYPE[NIDFS];    int CMP_TABSYM_NEW_TYPE = 0;
STR_TAB_SYM_ARRAY_TYPE TABSYM_ARRAY_TYPE[NIDFS];    int CMP_TABSYM_ARRAY_TYPE = 0;
STR_TAB_SYM_COMPOSITE_TYPE TABSYM_COMPOSITE_TYPE[NIDFS];    int CMP_TABSYM_COMPOSITE_TYPE = 0;
STR_TAB_SYM_ENUMERATION_TYPE TABSYM_ENUMERATION_TYPE[NIDFS];    int CMP_TABSYM_ENUMERATION_TYPE = 0;

char nom_create_type[30];
char scSem[50];
int idParent=-1, idCourant=-1;
typedef struct {
    TSYM target;
    TYPE_OPERS OPER_COURANT;
    enum AdaTokens OPERA_COURANT;
    bool boolean;
}TYPING_CORR_COURANT;
TYPING_CORR_COURANT AffCourante;
//fin declaration semantique

//proto-types semantique
void TEST_ALREADY_DEC(char *dec);
TSYM CHECK_TYPE_EXIST(char *dec);
TYPE_OPERS CHECK_IDF_USE(char *nom);
TYPE_OPERS CHECK_IDF_UPDATE(char *nom);
void ADD_DEC_FUNC(char *nom);
void ADD_DEC_PROC(char *nom);
void ADD_DEC_CONST(char decls[30][30], int size, TSYM type);
void ADD_DEC_VARS(char decls[30][30], int size, TSYM type, char *nomType);
void ADD_DEC_ENUMTYPE(char* nom, char parameters[30][30], int size);
void ADD_DEC_COMPOSITETYPE(char* nom, PARAMETER *parameters, int size);
void ADD_DEC_ARRAYTYPE(char* nom, TSYM type, char* interval);
void ADD_DEC_NEWTYPE(char* nom, TSYM type);
//fin proto-types semantique
//fonctions du analyseur semantique

void Erreurs_Sem(enum Erreurs_Semantique err){
    int ind_err = err;
    printf("\nErreur Semantique numero %d\t:%s\n", ind_err, mess_err_sem[ind_err].mes);
    //getch();
    exit(EXIT_FAILURE);
}

void TEST_ALREADY_DEC(char *dec){
    int i;
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(TABSYM_CONST[i].id==idCourant)
            if(!strcmp(dec, TABSYM_CONST[i].NOM))   Erreurs_Sem(DDEC);
    }
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(TABSYM_VAR[i].id==idCourant)
            if(!strcmp(dec, TABSYM_VAR[i].NOM)) Erreurs_Sem(DDEC);
    }
    for(i=0; i<CMP_TABSYM_NEW_TYPE ; i++){
        if(TABSYM_NEW_TYPE[i].id==idCourant)
            if(!strcmp(dec, TABSYM_NEW_TYPE[i].NOM))    Erreurs_Sem(DDEC);
    }
    for(i=0; i<CMP_TABSYM_ARRAY_TYPE ; i++){
        if(TABSYM_ARRAY_TYPE[i].id==idCourant)
            if(!strcmp(dec, TABSYM_ARRAY_TYPE[i].NOM))  Erreurs_Sem(DDEC);
    }
    for(i=0; i<CMP_TABSYM_COMPOSITE_TYPE; i++){
        if(TABSYM_COMPOSITE_TYPE[i].id==idCourant)
            if(!strcmp(dec, TABSYM_COMPOSITE_TYPE[i].NOM))  Erreurs_Sem(DDEC);
    }
    for(i=0; i<CMP_TABSYM_ENUMERATION_TYPE ; i++){
        if(TABSYM_ENUMERATION_TYPE[i].id==idCourant)
            if(!strcmp(dec, TABSYM_ENUMERATION_TYPE[i].NOM))    Erreurs_Sem(DDEC);
    }
}

void CHECK_AFF_OPERANT(TYPE_OPERS operant){
    int i;
    int cpt = TAB_TYPING_CORRESPONDENCE[AffCourante.target].CPT_OPERS;
    for(i=0; i<cpt; i++)
        if(operant == TAB_TYPING_CORRESPONDENCE[AffCourante.target].OPERS_POSSIBLE[i])  return;
    Erreurs_Sem(NCT);
}

void CHECK_AFF_OPERATION(enum AdaTokens operation){
    int i;
    int cpt = TAB_TYPING_CORRESPONDENCE[AffCourante.target].CPT_OPERAS;
    for(i=0; i<cpt; i++)
        if(operation == TAB_TYPING_CORRESPONDENCE[AffCourante.target].OPERAS_POSSIBLE[i])   return;
    Erreurs_Sem(NCT);
}

TYPE_OPERS CONVERT(TSYM tsym){
    switch(tsym){
        case BOOLEAN: return TO_BOOLEAN; break;
        case INTEGER: return TO_INTEGER; break;
        case NATURAL: return TO_NATURAL; break;
        case POSITIVE: return TO_POSITIVE; break;
        case CHARACTER: return TO_CHARACTER; break;
        case STRING: return TO_STRING; break;
    }
}

TYPE_OPERS CHECK_IDF_USE(char *nom){
    int i;
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(TABSYM_CONST[i].id==idCourant)
            if(!strcmp(nom, TABSYM_CONST[i].NOM))   return CONVERT(TABSYM_CONST[i].TIDF);
    }
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(TABSYM_VAR[i].id==idCourant)
            if(!strcmp(nom, TABSYM_VAR[i].NOM)) return CONVERT(TABSYM_VAR[i].TIDF);
    }
    Erreurs_Sem(INDEC);
}

int GET_ADRESSE(char *nom){
    int i;
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(!strcmp(nom, TABSYM_VAR[i].NOM)) return TABSYM_VAR[i].ADRESSE;
    }
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(!strcmp(nom, TABSYM_CONST[i].NOM))   return TABSYM_CONST[i].ADRESSE;
    }
}

TSYM GET_TYPE(int adr){
    PARAMETER PARAM[30];
    int i, j, k, l;
    int adrPere, indice=0;
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(TABSYM_VAR[i].TIDF == COMPOSITETYPE){
            adrPere = GET_ADRESSE(TABSYM_VAR[i].NOM);
            for(j=0; j<CMP_TABSYM_COMPOSITE_TYPE; j++){
                if(!strcmp(TABSYM_VAR[i].nomType , TABSYM_COMPOSITE_TYPE[j].NOM)){
                    for(k=0; k<TABSYM_COMPOSITE_TYPE[j].CPT; k++){
                        for(l=0; l<TABSYM_COMPOSITE_TYPE[j].PARAM[k].size; l++){
                            indice++;
                            if((adrPere+indice-1) == adr)   return TABSYM_COMPOSITE_TYPE[j].PARAM[k].TIDF;
                        }
                    }
                }
            }
        }
        if(adr == TABSYM_VAR[i].ADRESSE) return TABSYM_VAR[i].TIDF;
    }
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(adr == TABSYM_CONST[i].ADRESSE)   return TABSYM_CONST[i].TIDF;
    }
}

TSYM GET_TSYM(char *nom){
    int i;
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(TABSYM_VAR[i].id==idCourant)
            if(!strcmp(nom, TABSYM_VAR[i].NOM)) return TABSYM_VAR[i].TIDF;
    }
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(TABSYM_CONST[i].id==idCourant)
            if(!strcmp(nom, TABSYM_CONST[i].NOM))   return TABSYM_CONST[i].TIDF;
    }
}

int CHECK_PARAMETER_COMPOSITE(char* strName, char*successeur, char* predecesseur, TSYM *type){
    int i, j, k, indice = 0;
    for(i=0; i<CMP_TABSYM_COMPOSITE_TYPE; i++){
        if(!strcmp(strName, TABSYM_COMPOSITE_TYPE[i].NOM)){
            for(j=0; j<TABSYM_COMPOSITE_TYPE[i].CPT; j++){
                for(k=0; k<TABSYM_COMPOSITE_TYPE[i].PARAM[j].size; k++){
                    indice++;
                    if(!strcmp(successeur, TABSYM_COMPOSITE_TYPE[i].PARAM[j].NOMS[k])){
                        *type = TABSYM_COMPOSITE_TYPE[i].PARAM[j].TIDF;
                        return GET_ADRESSE(predecesseur)+indice-1;
                    }
                }
            }
        }
    }
    Erreurs_Sem(CNE);
}

char* CHECK_VAR_COMPOSITE_TYPE(char *idf){
    int i;
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(!strcmp(TABSYM_VAR[i].NOM, idf))
            return TABSYM_VAR[i].nomType;
    }
    Erreurs_Sem(VNS);
}

TYPE_OPERS CHECK_IDF_UPDATE(char *nom){
    int i;
    for(i=0; i<CMP_TABSYM_VAR ; i++){
        if(TABSYM_VAR[i].id==idCourant)
            if(!strcmp(nom, TABSYM_VAR[i].NOM)) return CONVERT(TABSYM_VAR[i].TIDF);
    }
    for(i=0; i<CMP_TABSYM_CONST ; i++){
        if(TABSYM_CONST[i].id==idCourant)
            if(!strcmp(nom, TABSYM_CONST[i].NOM))   Erreurs_Sem(CCVNA);
    }
    Erreurs_Sem(INDEC);
}

TSYM CHECK_TYPE_EXIST(char *dec){
    int i;

    for(i=0; i<CMP_TABSYM_NEW_TYPE; i++){
        if(!strcmp(dec, TABSYM_NEW_TYPE[i].NOM)){
            return NEWTYPE;
        }
    }
    for(i=0; i<CMP_TABSYM_ARRAY_TYPE; i++){
        if(!strcmp(dec, TABSYM_ARRAY_TYPE[i].NOM)){
            return ARAYTYPE;
        }
    }
    for(i=0; i<CMP_TABSYM_COMPOSITE_TYPE; i++){
        if(!strcmp(dec, TABSYM_COMPOSITE_TYPE[i].NOM)){
            return COMPOSITETYPE;
        }
    }
    for(i=0; i<CMP_TABSYM_ENUMERATION_TYPE; i++){
        if(!strcmp(dec, TABSYM_ENUMERATION_TYPE[i].NOM)){
            return ENUMERATIONTYPE;
        }
    }
    Erreurs_Sem(TND);
}

void ADD_DEC_FUNC(char *nom){
    STR_TAB_SYM_IDF_FUNC str;
    TEST_ALREADY_DEC(nom);
    strcmp(str.NOM, nom);
    str.id=++idCourant;
    str.id_parent=idParent;
    TAB_SYM_FUNC[CMP_TABSYM_FUNC++] = str;
}

void ADD_DEC_PROC(char *nom){
    STR_TAB_SYM_IDF_PROC str;
    TEST_ALREADY_DEC(nom);
    strcmp(str.NOM, nom);
    str.id=++idCourant;
    str.id_parent=idParent;
    TAB_SYM_PROC[CMP_TABSYM_PROC++] = str;
}

void ADD_DEC_CONST(char decls[30][30], int size, TSYM type){
    int i;
    STR_TAB_SYM_CONST str;
    for(i=0; i<size; i++){
        TEST_ALREADY_DEC(decls[i]);
        strcpy(str.NOM, decls[i]);
        str.TIDF = type;
        str.ADRESSE = OFFSET++;
        str.id = idCourant;
        TABSYM_CONST[CMP_TABSYM_CONST++] = str;
    }
}

int GET_SIZE_COMPOSITE(char *nomType){
    PARAMETER PARAM[30];
    int size = 0;
    int i, j;

    for(i=0; i<CMP_TABSYM_COMPOSITE_TYPE; i++){
        if(!strcmp(nomType, TABSYM_COMPOSITE_TYPE[i].NOM)){
            for(j=0; j<TABSYM_COMPOSITE_TYPE[i].CPT; j++){
                size += TABSYM_COMPOSITE_TYPE[i].PARAM[j].size;
            }
            return size;
        }
    }
}

int GET_OFFSET(TSYM type, char *nomType){

    int offset;
    if(type == BOOLEAN || type == INTEGER || type == NATURAL || type == POSITIVE || type == FLOAT || type == CHARACTER
       || type == STRING){
        return OFFSET++;
    }else if(type == COMPOSITETYPE){
        offset = OFFSET;
        OFFSET += GET_SIZE_COMPOSITE(nomType);
        return offset;
    }
}

void ADD_DEC_VARS(char decls[30][30], int size, TSYM type, char *nomType){
    int i;
    STR_TAB_SYM_VAR str;
    for(i=0; i<size; i++){
        TEST_ALREADY_DEC(decls[i]);
        strcpy(str.NOM, decls[i]);
        strcpy(str.nomType, nomType);
        str.TIDF = type;
        str.ADRESSE = GET_OFFSET(type, nomType); //OFFSET++;  il faut la remplacer par une fonction qui traite tout les types
        str.id = idCourant;
        TABSYM_VAR[CMP_TABSYM_VAR++] = str;
    }
}

void ADD_DEC_ENUMTYPE(char* nom, char parameters[30][30], int size){
    int i;
    STR_TAB_SYM_ENUMERATION_TYPE str;
    TEST_ALREADY_DEC(nom);
    str.CPT = size;
    for(i=0; i<size; i++){
        strcpy(str.PARAM[i], parameters[i]);
    }
    str.id = idCourant;
    TABSYM_ENUMERATION_TYPE[CMP_TABSYM_ENUMERATION_TYPE++] = str;
}

void ADD_DEC_COMPOSITETYPE(char* nom, PARAMETER *parameters, int size){
    int i;
    STR_TAB_SYM_COMPOSITE_TYPE str;
    TEST_ALREADY_DEC(nom);
    strcpy(str.NOM, nom);
    str.CPT = size;
    for(i=0; i<size; i++){
        str.PARAM[i] = parameters[i];
    }
    str.id = idCourant;
    TABSYM_COMPOSITE_TYPE[CMP_TABSYM_COMPOSITE_TYPE++] = str;
}

void ADD_DEC_ARRAYTYPE(char* nom, TSYM type, char* interval){
    STR_TAB_SYM_ARRAY_TYPE str;
    TEST_ALREADY_DEC(nom);
    strcpy(str.NOM, nom);
    str.TIDF = type;
    str.start=-1;
    str.end=-1;
    strcpy(str.interval, interval);
    str.id = idCourant;
    TABSYM_ARRAY_TYPE[CMP_TABSYM_ARRAY_TYPE++] = str;
}

void ADD_DEC_NEWTYPE(char* nom, TSYM type){
    STR_TAB_SYM_NEW_TYPE str;
    TEST_ALREADY_DEC(nom);
    strcpy(str.NOM, nom);
    str.TIDF=type;
    str.id = idCourant;
    TABSYM_NEW_TYPE[CMP_TABSYM_NEW_TYPE++] = str;
}

//fin fonctions du analyseur semantique