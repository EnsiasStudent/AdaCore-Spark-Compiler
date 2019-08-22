#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include "analyseur_semantique.c"

//-----------------------------declaration pour generation de code ----------------------------------------------
enum MNEMONIQUES {ADD, SUB, MUL, DIV, EQL, NEQ, GTR, LSS, GEQ, LEQ, AND, OR, XOR, NOT, MOD, DBLSTR,
    PRN, INN, INT, LDI, LDA, LDV, STO, BRN, BZE, HLT};

//-------------------JUSTE POUR LE TEST --------------------------------------------------------------------------
struct p_code{  enum MNEMONIQUES code;
    char name[10];  };
struct p_code   tab_p_code[]={  {ADD, "ADD"}, {SUB, "SUB"}, {MUL, "MUL"}, {DIV, "DIV"}, {EQL, "EQL"},
                                {NEQ, "NEQ"}, {GTR, "GTR"}, {LSS, "LSS"}, {GEQ, "GEQ"}, {LEQ, "LEQ"},
                                {AND, "AND"}, {OR, "OR"}, {XOR, "XOR"}, {NOT, "NOT"}, {MOD, "MOD"},
                                {DBLSTR, "DBLSTR"}, {PRN, "PRN"}, {INN, "INN"}, {INT, "INT"}, {LDI, "LDI"},
                                {LDA, "LDA"}, {LDV, "LDV"}, {STO, "STO"}, {BRN, "BRN"}, {BZE, "BZE"}, {HLT, "HTL"}
};
//-----------------------------------------------------------------------------------------------------------------
typedef struct {
    int i;  //integer, natural, positive
    float f;    //float
    bool b; //boolean
    char c; //character
    char s[500];   //string
}DATA;

typedef struct{
    DATA data;
    TSYM type;
}INFO;

typedef struct {
    enum MNEMONIQUES MNE;
    INFO SUITE;
} INSTRUCTION;

#define TAILLECODE 1000
INSTRUCTION PCODE[TAILLECODE];
int PC = 0;
int SP;
#define TAILLEMEM 600

INFO MEM[TAILLEMEM];
void GENERER1(enum MNEMONIQUES);
void GENERER2 (enum MNEMONIQUES, int);
//-----------------------------fin declaration pour generation de code ------------------------------------------------------------------------

//fonctions génération du code

void GENERER1(enum MNEMONIQUES M){
    PCODE[PC++].MNE = M;
}

void GENERER2(enum MNEMONIQUES M, int A){
    PCODE[PC].MNE = M;
    PCODE[PC].SUITE.data.i = A;
    PCODE[PC++].SUITE.type = INTEGER;
}

void GENERER3(enum MNEMONIQUES M, DATA D, TSYM type){
    PCODE[PC].MNE = M;
    PCODE[PC].SUITE.data = D;
    PCODE[PC++].SUITE.type = type;
}
