//
// Created by Adnane on 03/02/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include "Interpreteur.c"
//================================================================================================================================

//declaration syntaxique
//------------------------------------declaration--------------------------------------------------------
enum ERREUR_SYNTAXIQUE {     ABORT_ERR, ABS_ERR, ABSTRACT_ERR, ACCEPT_ERR, ACCESS_ERR, ALIASED_ERR, ALL_ERR,
    AMPERSAND_ERR, AND_ERR, APOSTROPHE_ERR, ARRAY_ERR, ARROW_ERR, ASSIGNEMENT_ERR, AT_ERR, BEGIN_ERR, BODY_ERR, BOX_ERR,
    CASE_ERR, CHARACTER_LITERAL_ERR, COLON_ERR, COMMA_ERR, COMMENT_ERR, CONSTANT_ERR, DECLARE_ERR,
    DELAY_ERR, DELTA_ERR, DIGITS_ERR, DO_ERR, DOT_ERR, DOUBLE_DOT_ERR, DOUBLE_STAR_ERR, ELSE_ERR,
    ELSIF_ERR, END_ERR, EOF_ERR, ENTRY_ERR, EQUAL_ERR, ERROR_ERR, EXCEPTION_ERR, EXIT_ERR, FOR_ERR, FUNCTION_ERR,
    GENERIC_ERR, GOTO_ERR, GREATER_OR_EQUAL_ERR, GREATER_ERR, HYPHEN_ERR, IDENTIFIER_ERR, IF_ERR, IN_ERR,
    INEQUALITY_ERR, INTERFACE_ERR, IS_ERR, LEFT_LABEL_ERR, LEFT_PARATHESIS_ERR, LESS_OR_EQUAL_ERR,
    LESS_ERR, LIMITED_ERR, LOOP_ERR, MOD_ERR, NEW_LINE_ERR, NEW_ERR, NOT_ERR, NULL_ERR,
    INTEGER_ERR, OF_ERR, OR_ERR, OTHERS_ERR, OUT_ERR, OVERRIDING_ERR, PACKAGE_ERR, PLUS_ERR,
    PRAGMA_ERR, PRIVATE_ERR, PROCEDURE_ERR, PROTECTED_ERR, RAISE_ERR, RANGE_ERR, RECORD_ERR, REM_ERR,
    RENAMES_ERR, REQUEUE_ERR, RETURN_ERR, REVERSE_ERR, RIGHT_LABEL_ERR, RIGHT_PARENTHESIS_ERR, SELECT_ERR,
    SEMICOLON_ERR, SEPARATE_ERR, SLASH_ERR, SOME_ERR, SPACE_ERR, STAR_ERR, STRING_LITERAL_ERR, SUBTYPE_ERR,
    SYNCHRONIZED_ERR, TAGGED_ERR, TASK_ERR, TERMINATE_ERR, THEN_ERR, TYPE_ERR, UNTIL_ERR, USE_ERR,
    VERTICAL_ERR, VERTICAL_LINE_ERR, WHEN_ERR, WHILE_ERR, WITH_ERR, XOR_ERR,PACK_ERR, MAIN_PROC_ERR,
    ID_PROC_ERR, PARAM_ERR, ID_FUNC_ERR, ID_NEWTYPE_ERR, DECTYPE_ERR, ARG_ENUM_ERR, VAR_RECORD_ERR,
    DECARRAY_ERR, INST_ERR, ID_CASE_ERR, PARAMFOR_ERR, AFFECT_ERR, FACT_ERR, GET_ERR, PUT_ERR
};

struct MESSAGE_ERREUR_SYNTAXIQUE {
    enum ERREUR_SYNTAXIQUE CODE_ERR;
    char MES[100];
};

struct MESSAGE_ERREUR_SYNTAXIQUE MES_ERR_SYN[] = {
        {ABORT_ERR,"ABORT ERRONE"},{ABS_ERR,"ABS ERRONE"},{ABSTRACT_ERR,"ABSTRACT ERRONE"},{ACCEPT_ERR,"ACCEPT ERRONE"},
        {ACCESS_ERR,"ACCESS ERRONE"},{ALIASED_ERR,"ALIASED ERRONE"},{ALL_ERR,"ALL ERRONE"},{AMPERSAND_ERR,"AMPERSAND ERRONE"},
        {AND_ERR,"AND_ERRONE"},{APOSTROPHE_ERR,"APOSTROPHE ERRONE"}, {ARRAY_ERR, "ARRAY ERRONE"}, {ARROW_ERR, "ARROW ERRONE"},
        {ASSIGNEMENT_ERR,"ASSIGNEMENT ERRONE"},{AT_ERR,"AT ERRONE"}, {BEGIN_ERR,"BEGIN ERRONE"}, {BODY_ERR, "BODY ERRONE"},
        {BOX_ERR, "BOX ERRONE"},{CASE_ERR, "CASE ERRONE"}, {CHARACTER_LITERAL_ERR, "CHARACTER LITTERAL ERRONE"},
        {COLON_ERR, "COLON ERRONE"},{COMMA_ERR, "COMMA ERRONE"}, {COMMENT_ERR, "COMMENT ERRONE"}, {CONSTANT_ERR, "CONSTANT ERRONE"},
        {DECLARE_ERR, "DECLARE ERRONE"}, {DELAY_ERR, "DELAY ERRONE"}, {DELTA_ERR, "DELTA_ERR"}, {DIGITS_ERR, "DIGITS_ERR"},
        {DO_ERR, "DO ERRONE"}, {DOT_ERR, "DOT ERRONE"}, {DOUBLE_DOT_ERR, "DOUBLE DOT ERRONE"}, {DOUBLE_STAR_ERR, "DOUBLE STAR ERRONE"},
        {ELSE_ERR, "ELSE ERRONE"}, {ELSIF_ERR, "ELSIF ERRONE"}, {END_ERR, "END ERRONE"},
        {EOF_ERR, "EOF ERRONE"}, {ENTRY_ERR, "ENTRY ERRONE"},{EQUAL_ERR, "EQUAL ERRONE"},
        {ERROR_ERR, "ERROR ERRONE"}, {EXCEPTION_ERR, "EXCEPTION ERRONE"}, {EXIT_ERR, "EXIT ERRONE"}, {FOR_ERR, "FOR_ERRONE"},
        {FUNCTION_ERR, "FUNCTION ERRONE"}, {GENERIC_ERR, "GENERIC ERRONE"}, {GOTO_ERR, "GOTO ERRONE"},
        {GREATER_OR_EQUAL_ERR, "GREATER OR EQUAL ERRONE"}, {GREATER_ERR, "GREATER ERRONE"}, {HYPHEN_ERR, "HYPHEN ERRONE"},
        {IDENTIFIER_ERR, "IDENTIFIER ERRONE"}, {IF_ERR, "IF ERRONE"}, {IN_ERR, "IN ERRONE"}, {INEQUALITY_ERR, "INEQUALITY ERRONE"},
        {INTERFACE_ERR, "INTERFACE ERRONE"}, {IS_ERR, "IS ERRONE"}, {LEFT_LABEL_ERR, "LEFT LABEL ERRONE"},
        {LEFT_PARATHESIS_ERR, "LEFT PARATHESIS ERRONE"}, {LESS_OR_EQUAL_ERR, "LESSS OR EQUAL ERRONE"},
        {PACK_ERR, "FORMAT DE PACKAGE ERRONE"},
        {MAIN_PROC_ERR, "SYMBOLE \"PROCEDURE\" MANQUANT"},
        {ID_PROC_ERR, "IDENTIFIANT DE PROCEDURE MANQUANT"},
        {PARAM_ERR, "PARAMETRE MANQUANT"}, {ID_FUNC_ERR, "IDENTIFIANT DE FONCTION MANQUANT"},
        {ID_NEWTYPE_ERR, "IDENTIFIANT NOUVEAU TYPE MANQUANT"},
        {DECTYPE_ERR, "DECLARATION TYPE ERRONE"}, {ARG_ENUM_ERR, "ARGUMANT ENUM MANQUANT"},
        {VAR_RECORD_ERR, "VARIABLE RECORD MANQUANT"},
        {DECARRAY_ERR, "DECLARATION TABLEAU ERRONE"}, {INST_ERR, "INSTRUCTION MANQUANT"},
        {ID_CASE_ERR, "IDENTIFIANT DU CASE MANQUANT"},
        {PARAMFOR_ERR, "PARAMETRES DE LA BOUBLE FOR ERRONE"},
        {AFFECT_ERR, "AFFECTATION ERRONE"},
        {FACT_ERR, "FACT ERRONE"}, {GET_ERR, "GET ERRONE"}, {PUT_ERR, "PUT ERRONE"}
};
//fin declaration syntaxique
//proto-types syntaxique
void PROGRAMME();
void CONTEXTE();
void LISTPACK();
void PACK();
void PROCFONC();
void ENTETE();
void PROCENTETE();
void ARGS();
void ARG();
TSYM TYPE();
void FONCENTETE();
void DECL();
void DECVARCONS();
void DECTYPE();
void ENUM();
void RECORD();
void DECREC();
void NEXTDECREC();
void ARRAY();
void ARRAYPARAM();
void MODULE();
void NEW();
void SUBTYPE();
void INSTS();
void INST();
void WRITE();
void READ();
void IF();
void CASE();
void NEXTCASE();
void LOOP();
void WHILE();
void FOR();
void PARAMFOR();
void CONDITION();
void AFFECT();
void BLOCK();
void DECBLOCK();
void FACTINIT();
void CONDS();
void COND();
void FACTCOND();
void EXPR();
void T1();
void MULTDIVMOD();
void T2();
void AUXMULTDIVMOD();
void PUISS();
void T3();
void AUXPUISS();
void FACTEXPR();
//fin proto-types syntaxique

//fin fonctions génération du code

void ERREUR_SYN(enum ERREUR_SYNTAXIQUE err){
    int ind_err = err;
    printf("\nErreur Syntaxique numero %d\t:%s\n", ind_err, MES_ERR_SYN[ind_err].MES);
    exit(EXIT_FAILURE);
}

void TEST_SYMBOLE (enum AdaTokens TK, enum ERREUR_SYNTAXIQUE COD_ERR){
    memset(scSem, '\0', strlen(scSem));
    strcpy(scSem, Sym_Cour.Nom);
    if (Sym_Cour.token == TK) {
        next_Sym();
    }
    else
        ERREUR_SYN(COD_ERR);
}

void PROGRAMME(){
    CONTEXTE();
    PROCFONC();
    GENERER1(HLT);
}

void CONTEXTE(){
    switch(Sym_Cour.token){
        case WITH_TOKEN :   next_Sym();
            LISTPACK();
            TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
            CONTEXTE(); break;
        case USE_TOKEN  :   next_Sym();
            LISTPACK();
            TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
            CONTEXTE(); break;
    }
}

void LISTPACK(){
    PACK();
    while(Sym_Cour.token == COMMA_TOKEN){
        next_Sym();
        PACK();
    }
}

void PACK(){
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    while(Sym_Cour.token == DOT_TOKEN){
        next_Sym();
        if(Sym_Cour.token == STAR_TOKEN){   next_Sym(); break;  }
        else if(Sym_Cour.token != IDENTIFIER_TOKEN) ERREUR_SYN(PACK_ERR);
        else next_Sym();
    }
}

void PROCFONC(){
    ENTETE();
    DECL();
    GENERER2(INT, OFFSET);
    TEST_SYMBOLE(BEGIN_TOKEN, BEGIN_ERR);
    INSTS();
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    idCourant--;
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void ENTETE(){
    switch(Sym_Cour.token){
        case PROCEDURE_TOKEN :  PROCENTETE();   break;
        case FUNCTION_TOKEN :   FONCENTETE();   break;
        default : ERREUR_SYN(MAIN_PROC_ERR); break;
    }
}

void PROCENTETE(){
    TEST_SYMBOLE(PROCEDURE_TOKEN, PROCEDURE_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    ADD_DEC_PROC(scSem);
    if(Sym_Cour.token == LEFT_PARATHESIS_TOKEN){
        next_Sym();
        ARGS();
        TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    }
    TEST_SYMBOLE(IS_TOKEN, IS_ERR);
}

void ARGS(){
    if(Sym_Cour.token == IDENTIFIER_TOKEN){
        ARG();
        while(Sym_Cour.token == SEMICOLON_TOKEN){
            next_Sym();
            ARG();
        }
    }
}

void ARG(){
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    while(Sym_Cour.token == COMMA_TOKEN){
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    }
    TEST_SYMBOLE(COLON_TOKEN, COLON_ERR);   //: <=> TWO POINTS
    switch(Sym_Cour.token){
        case OUT_TOKEN  :   next_Sym(); break;
        case IN_TOKEN   :   next_Sym();
            if(Sym_Cour.token == OUT_TOKEN) next_Sym();
            break;
    }
    TYPE();
    if(Sym_Cour.token == ASSIGNEMENT_TOKEN){
        next_Sym();
        FACTINIT();
    }
}

void FACTINIT(){
    /*if(Sym_Cour.token == TRUE_TOKEN || Sym_Cour.token == FALSE_TOKEN ||
       Sym_Cour.token == TYPE_STRING_TOKEN){
        switch(Sym_Cour.token){
            case TRUE_TOKEN : CHECK_AFF_OPERANT(TO_BOOLEAN); break;
            case FALSE_TOKEN : CHECK_AFF_OPERANT(TO_BOOLEAN); break;
            case TYPE_STRING_TOKEN : CHECK_AFF_OPERANT(TYPE_STRING_TOKEN); break;
        }
        next_Sym();
    }
    else*/
    AffCourante.boolean = true;
    EXPR();
}

TSYM TYPE(){
    char nom[30];
    switch(Sym_Cour.token){
        case BOOLEAN_TOKEN  :   next_Sym(); return BOOLEAN;
        case INTEGER_TOKEN  :   next_Sym(); return INTEGER;
        case NATURAL_TOKEN  :   next_Sym(); return NATURAL;
        case POSITIVE_TOKEN :   next_Sym(); return POSITIVE;
        case FLOAT_TOKEN    :   next_Sym(); return FLOAT;
        case CHARACTER_TOKEN:   next_Sym(); return CHARACTER;
        case DURATION_TOKEN :   next_Sym(); return DURATION;
        case STRING_TOKEN   :   next_Sym(); return STRING;
        case IDENTIFIER_TOKEN       :   strcpy(nom, Sym_Cour.Nom); next_Sym(); return CHECK_TYPE_EXIST(nom);
        default : ERREUR_SYN(TYPE_ERR); break;
    }
}

void FONCENTETE(){
    TEST_SYMBOLE(FUNCTION_TOKEN, FUNCTION_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, ID_FUNC_ERR);
    ADD_DEC_FUNC(scSem);
    if(Sym_Cour.token == LEFT_PARATHESIS_TOKEN){
        next_Sym();
        ARGS();
        TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    }
    TEST_SYMBOLE(RETURN_TOKEN, RETURN_ERR);
    TYPE();
    TEST_SYMBOLE(IS_TOKEN, IS_ERR);
}

void DECL(){
    idParent=idCourant;
    switch(Sym_Cour.token){
        case IDENTIFIER_TOKEN       :   DECVARCONS();   DECL(); break;
        case TYPE_TOKEN     :   DECTYPE();  DECL(); break;
        case SUBTYPE_TOKEN  :   DECTYPE();  DECL(); break;
        case PROCEDURE_TOKEN:   PROCFONC(); DECL(); break;
        case FUNCTION_TOKEN :   PROCFONC(); DECL(); break;
    }
}

void DECVARCONS(){
    char decls[30][30];
    int i=0;
    char nomType[30];
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    strcpy(decls[i++], scSem);
    while(Sym_Cour.token == COMMA_TOKEN){
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(decls[i++], scSem);
    }
    TEST_SYMBOLE(COLON_TOKEN, COLON_ERR);
    if(Sym_Cour.token == CONSTANT_TOKEN){
        next_Sym();
        ADD_DEC_CONST(decls, i, TYPE());
        TEST_SYMBOLE(ASSIGNEMENT_TOKEN, ASSIGNEMENT_ERR);
        AffCourante.target = GET_TSYM(decls[0]);
        GENERER2(LDA, GET_ADRESSE(decls[0]));
        FACTINIT();
        GENERER1(STO);
    }else{
        strcpy(nomType, Sym_Cour.Nom);
        ADD_DEC_VARS(decls, i, TYPE(), nomType);
        if(Sym_Cour.token == ASSIGNEMENT_TOKEN){
            next_Sym();
            AffCourante.target = GET_TSYM(decls[0]);
            GENERER2(LDA, GET_ADRESSE(decls[0]));
            FACTINIT();
            GENERER1(STO);
        }
    }
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void DECTYPE(){
    switch(Sym_Cour.token){
        case TYPE_TOKEN :   next_Sym();
            TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
            strcpy(nom_create_type,scSem);
            TEST_SYMBOLE(IS_TOKEN, IS_ERR);
            switch(Sym_Cour.token){
                case LEFT_PARATHESIS_TOKEN      :   ENUM(); break;
                case RECORD_TOKEN   :   RECORD();   break;
                case ARRAY_TOKEN    :   ARRAY();    break;
                case MOD_TOKEN      :   MODULE();   break;
                case NEW_TOKEN      :   NEW();  break;
                default : ERREUR_SYN(DECTYPE_ERR); break;
            }
            TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);   break;
        case SUBTYPE_TOKEN  :   SUBTYPE();  break;
    }
}

void ENUM(){
    char parameters[30][30];
    int i=0;
    TEST_SYMBOLE(LEFT_PARATHESIS_TOKEN, LEFT_PARATHESIS_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    strcpy(parameters[i++], scSem);
    if(Sym_Cour.token == ASSIGNEMENT_TOKEN){
        next_Sym();
        EXPR();
    }
    while(Sym_Cour.token == COMMA_TOKEN){
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(parameters[i++], scSem);
        if(Sym_Cour.token == ASSIGNEMENT_TOKEN){
            next_Sym();
            EXPR();
        }
    }
    ADD_DEC_ENUMTYPE(nom_create_type, parameters, i);
    TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
}

void RECORD(){
    TEST_SYMBOLE(RECORD_TOKEN, RECORD_ERR);
    DECREC();
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(RECORD_TOKEN, RECORD_ERR);
}

void DECREC(){
    PARAMETER parameters[30];
    int i=0, j=0;
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    strcpy(parameters[i].NOMS[j++], scSem);
    while(Sym_Cour.token == COMMA_TOKEN){
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(parameters[i].NOMS[j++], scSem);
    }
    TEST_SYMBOLE(COLON_TOKEN, COLON_ERR);   //: <=> TWO POINTS
    parameters[i].TIDF=TYPE();
    parameters[i++].size=j;    j=0;
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
    //NEXTDECREC();
    while(Sym_Cour.token != END_TOKEN){
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(parameters[i].NOMS[j++], scSem);
        while(Sym_Cour.token == COMMA_TOKEN){
            next_Sym();
            TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
            strcpy(parameters[i].NOMS[j++], scSem);
        }
        TEST_SYMBOLE(COLON_TOKEN, COLON_ERR);   //: <=> TWO POINTS
        parameters[i].TIDF=TYPE();
        parameters[i++].size=j; j=0;
        TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
    }
    ADD_DEC_COMPOSITETYPE(nom_create_type, parameters, i);
}

/*void NEXTDECREC(){
    if(Sym_Cour.token == COMMA_TOKEN)
        DECREC();
}*/

void ARRAY(){
    TEST_SYMBOLE(ARRAY_TOKEN, ARRAY_ERR);
    TEST_SYMBOLE(LEFT_PARATHESIS_TOKEN, LEFT_PARATHESIS_ERR);
    ARRAYPARAM();
    TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    TEST_SYMBOLE(OF_TOKEN, OF_ERR);
    ADD_DEC_ARRAYTYPE(nom_create_type, TYPE(), "positive");
}

void ARRAYPARAM(){
    enum AdaTokens ul = Sym_Cour.token;
    char *token = (char*) calloc(strlen(Sym_Cour.Nom)+1, sizeof(char));
    strcpy(token, Sym_Cour.Nom);
    next_Sym();
    switch(Sym_Cour.token){
        case DOUBLE_DOT_TOKEN   :   Sym_Cour.token = ul;    AffCourante.target = INTEGER; AffCourante.boolean = true; EXPR();   EXPR(); break;
        case RANGE_TOKEN        :   Sym_Cour.token = ul;    TYPE(); TEST_SYMBOLE(LESS_TOKEN, LESS_ERR);
            TEST_SYMBOLE(GREATER_TOKEN, GREATER_ERR);   break;
        default                 :   ERREUR_SYN(DECARRAY_ERR); break;
    }
}

void MODULE(){
    TEST_SYMBOLE(MOD_TOKEN, MOD_ERR);
    AffCourante.target = INTEGER;
    AffCourante.boolean = true;
    EXPR();
}

void NEW(){
    TEST_SYMBOLE(NEW_TOKEN, NEW_ERR);
    ADD_DEC_NEWTYPE(nom_create_type, TYPE());
}

void SUBTYPE(){
    TEST_SYMBOLE(SUBTYPE_TOKEN, SUBTYPE_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, ID_NEWTYPE_ERR);
    TEST_SYMBOLE(IS_TOKEN, IS_ERR);
    AffCourante.target = TYPE();
    TEST_SYMBOLE(RANGE_TOKEN, RANGE_ERR);
    EXPR();
    TEST_SYMBOLE(DOUBLE_DOT_TOKEN, DOUBLE_DOT_ERR);
    EXPR();
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void INSTS(){
    INST();
    while(Sym_Cour.token==IF_TOKEN || Sym_Cour.token==CASE_TOKEN || Sym_Cour.token==LOOP_TOKEN || Sym_Cour.token==WHILE_TOKEN ||
          Sym_Cour.token==FOR_TOKEN || Sym_Cour.token==IDENTIFIER_TOKEN || Sym_Cour.token==DECLARE_TOKEN || Sym_Cour.token==BEGIN_TOKEN ||
          Sym_Cour.token==PUT_TOKEN || Sym_Cour.token==GET_TOKEN ){
        INST();
    }
}

void INST(){
    switch(Sym_Cour.token){
        case IF_TOKEN       :   IF();   break;
        case CASE_TOKEN     :   CASE(); break;
        case LOOP_TOKEN     :   LOOP(); break;
        case WHILE_TOKEN    :   WHILE();break;
        case FOR_TOKEN      :   FOR();  break;
        case PUT_TOKEN      :   WRITE(); break;
        case GET_TOKEN      :   READ(); break;
        case IDENTIFIER_TOKEN       :   AFFECT();break;
        case DECLARE_TOKEN  :   BLOCK(); break;
        case BEGIN_TOKEN    :   BLOCK(); break;
        default             :   ERREUR_SYN(INST_ERR);   break;
    }
}

void WRITE(){
    TEST_SYMBOLE(PUT_TOKEN, PUT_ERR);
    TEST_SYMBOLE(LEFT_PARATHESIS_TOKEN, LEFT_PARATHESIS_ERR);
    AffCourante.boolean = false;
    EXPR();
    // printf("\n\nDans write nom : %s  ul : %d\n\n", Sym_Cour.Nom, Sym_Cour.token);
    GENERER1(PRN);
    TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void READ(){
    char predecesseur[20];
    char successeur[20];
    char strName[20];
    int adr;
    TSYM type;
    TEST_SYMBOLE(GET_TOKEN, GET_ERR);
    TEST_SYMBOLE(LEFT_PARATHESIS_TOKEN, LEFT_PARATHESIS_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, ID_CASE_ERR);
    CHECK_IDF_UPDATE(scSem);
    if(Sym_Cour.token == DOT_TOKEN){
        strcpy(predecesseur, scSem);
        strcpy(strName, CHECK_VAR_COMPOSITE_TYPE(predecesseur));
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(successeur, scSem);
        adr = CHECK_PARAMETER_COMPOSITE(strName, successeur, predecesseur, &type);
        AffCourante.target = type;
        AffCourante.boolean = true;
    }else  { adr = GET_ADRESSE(scSem);
        AffCourante.target = GET_TSYM(scSem);
        AffCourante.boolean = true; }

    GENERER2(LDA, adr);
    GENERER1(INN);
    //printf("\n\nDans write nom : %s  ul : %d\n\n", Sym_Cour.Nom, Sym_Cour.token);
    TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void IF(){
    int INDICE_BZE[100], INDICE_BRN[100];
    int i, n=0;

    TEST_SYMBOLE(IF_TOKEN, IF_ERR);
    CONDITION();
    GENERER1(BZE);
    INDICE_BZE[n]=PC-1;
    TEST_SYMBOLE(THEN_TOKEN, THEN_ERR);
    INSTS();
    GENERER1(BRN);
    INDICE_BRN[n]=PC-1;

    PCODE[INDICE_BZE[n++]].SUITE.data.i=PC;
    while(Sym_Cour.token == ELSIF_TOKEN){
        next_Sym();
        CONDITION();
        GENERER1(BZE);
        INDICE_BZE[n]=PC-1;
        TEST_SYMBOLE(THEN_TOKEN, THEN_ERR);
        INSTS();
        GENERER1(BRN);
        INDICE_BRN[n]=PC-1;
        PCODE[INDICE_BZE[n++]].SUITE.data.i=PC;
    }
    if(Sym_Cour.token == ELSE_TOKEN){
        next_Sym();
        INSTS();
    }
    for(i=0; i<n; i++){
        PCODE[INDICE_BRN[i]].SUITE.data.i=PC;
    }
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(IF_TOKEN, IF_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void CASE(){
    int INDICE_BZE[100], INDICE_BRN[100], adr;
    int i, n=0;
    char idfCase[40];

    TEST_SYMBOLE(CASE_TOKEN, CASE_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, ID_CASE_ERR);
    CHECK_IDF_USE(scSem);
    strcpy(idfCase, scSem);
    adr = GET_ADRESSE(scSem);
    GENERER2(LDA, adr);
    GENERER1(LDV);
    TEST_SYMBOLE(IS_TOKEN, IS_ERR);
    TEST_SYMBOLE(WHEN_TOKEN, WHEN_ERR);
    AffCourante.target = INTEGER;
    AffCourante.boolean = true;
    //NEXTCASE();
    EXPR();
    while(Sym_Cour.token == VERTICAL_TOKEN){
        next_Sym();
        EXPR();
    }
    GENERER1(EQL);
    GENERER1(BZE);
    INDICE_BZE[n]=PC-1;
    TEST_SYMBOLE(ARROW_TOKEN, ARROW_ERR);   // => IMPLIQUE
    INSTS();
    GENERER1(BRN);
    INDICE_BRN[n]=PC-1;
    PCODE[INDICE_BZE[n++]].SUITE.data.i=PC;

    while(Sym_Cour.token == WHEN_TOKEN){
        next_Sym();

        if(Sym_Cour.token != OTHERS_TOKEN){
            //NEXTCASE();
            GENERER2(LDA, adr);
            GENERER1(LDV);
            AffCourante.target = INTEGER;
            AffCourante.boolean = true;
            EXPR();
            while(Sym_Cour.token == VERTICAL_TOKEN){
                next_Sym();
                EXPR();
            }
            GENERER1(EQL);
            GENERER1(BZE);
            INDICE_BZE[n]=PC-1;
            TEST_SYMBOLE(ARROW_TOKEN, ARROW_ERR);   // => IMPLIQUE
            INSTS();
            GENERER1(BRN);
            INDICE_BRN[n]=PC-1;
            PCODE[INDICE_BZE[n++]].SUITE.data.i=PC;
        }
        else{
            next_Sym();
            TEST_SYMBOLE(ARROW_TOKEN, ARROW_ERR);   // => IMPLIQUE
            INSTS();
            break;
        }
    }
    for(i=0; i<n; i++){
        PCODE[INDICE_BRN[i]].SUITE.data.i=PC;
    }
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(CASE_TOKEN, CASE_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

/*void NEXTCASE(){
    EXPR();
    while(Sym_Cour.token == VERTICAL_TOKEN){
        next_Sym();
        EXPR();
    }
    GENERER1(EQL);
    GENERER1(BZE);
    INDICE_BZE[n]=PC-1;
    TEST_SYMBOLE(ARROW_TOKEN, ARROW_ERR);   // => IMPLIQUE
    INSTS();
    GENERER1(BRN);
    INDICE_BRN[n]=PC-1;
    PCODE[INDICE_BZE[n++]].SUITE=PC;
}*/

void LOOP(){
    int LABEL_BRN, BZE_INDICE;
    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    LABEL_BRN=PC;
    GENERER1(BZE);
    BZE_INDICE=PC-1;
    INSTS();
    GENERER2(BRN, LABEL_BRN);
    PCODE[BZE_INDICE].SUITE.data.i=PC;
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void WHILE(){
    int BZE_INDICE, LABEL_BRN;
    TEST_SYMBOLE(WHILE_TOKEN, WHILE_ERR);
    LABEL_BRN=PC;
    CONDITION();
    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    GENERER1(BZE);
    BZE_INDICE=PC-1;
    INSTS();
    GENERER2(BRN, LABEL_BRN);
    PCODE[BZE_INDICE].SUITE.data.i=PC;
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

typedef struct {
    int adr, BZE_INDICE, LABEL_BRN;
    DATA debut, fin;
    enum AdaTokens ulTmp;
    int reverse;
}INFO_FOR;
INFO_FOR infoFor;

void FOR(){
    char idfFor[30];
    DATA data;

    TEST_SYMBOLE(FOR_TOKEN, FOR_ERR);
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    strcpy(idfFor, scSem);
    CHECK_IDF_UPDATE(idfFor);
    infoFor.adr = GET_ADRESSE(idfFor);
    GENERER2(LDA, infoFor.adr);
    AffCourante.target = GET_TSYM(idfFor);
    TEST_SYMBOLE(IN_TOKEN, IN_ERR);
    if(Sym_Cour.token == REVERSE_TOKEN) { infoFor.reverse = 1;  next_Sym(); }

    PARAMFOR();

    GENERER3(LDI, infoFor.debut, INTEGER);
    GENERER1(STO);

    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    infoFor.LABEL_BRN=PC;
    GENERER2(LDA, infoFor.adr);
    GENERER1(LDV);
    GENERER3(LDI, infoFor.fin, INTEGER);

    if(infoFor.reverse != 1)    GENERER1(LEQ);
    else GENERER1(GEQ);

    GENERER1(BZE);
    infoFor.BZE_INDICE=PC-1;

    INSTS();

    GENERER2(LDA, infoFor.adr);
    GENERER2(LDA, infoFor.adr);
    GENERER1(LDV);
    data.i=1;
    GENERER3(LDI, data, INTEGER);

    if(infoFor.reverse != 1)    GENERER1(ADD);
    else GENERER1(SUB);

    GENERER1(STO);
    GENERER2(BRN, infoFor.LABEL_BRN);
    PCODE[infoFor.BZE_INDICE].SUITE.data.i=PC;

    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(LOOP_TOKEN, LOOP_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void PARAMFOR(){
    enum AdaTokens ul = Sym_Cour.token;
    char debut[20];
    strcpy(debut, Sym_Cour.Nom);

    next_Sym();
    switch(Sym_Cour.token){
        case DOUBLE_DOT_TOKEN   :   Sym_Cour.token = ul;    /*infoFor.debut=*//*EXPR();*/
            TEST_SYMBOLE(TYPE_INTEGER_TOKEN, INTEGER_ERR);
            infoFor.debut.i = atoi(debut);  /*infoFor.fin=*//*EXPR();*/
            TEST_SYMBOLE(TYPE_INTEGER_TOKEN, INTEGER_ERR);
            infoFor.fin.i = atoi(scSem);  break;

        case RANGE_TOKEN        :   Sym_Cour.token = ul;    TYPE(); /*infoFor.debut=*/EXPR();
            TEST_SYMBOLE(DOUBLE_DOT_TOKEN, DOUBLE_DOT_ERR); /*infoFor.fin=*/EXPR(); break;
        default                 :   ERREUR_SYN(PARAMFOR_ERR); break;
    }
}

void AFFECT(){
    char predecesseur[20];
    char successeur[20];
    char strName[20];
    int adr;
    TSYM type;
    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
    CHECK_IDF_UPDATE(scSem);
    if(Sym_Cour.token == DOT_TOKEN){
        strcpy(predecesseur, scSem);
        strcpy(strName, CHECK_VAR_COMPOSITE_TYPE(predecesseur));
        next_Sym();
        TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
        strcpy(successeur, scSem);
        adr = CHECK_PARAMETER_COMPOSITE(strName, successeur, predecesseur, &type);
        AffCourante.target = type;
        AffCourante.boolean = true;

    }else  { adr = GET_ADRESSE(scSem);
        AffCourante.target = GET_TSYM(scSem);
        AffCourante.boolean = true; }

    GENERER2(LDA, adr);

    switch(Sym_Cour.token){
        case ASSIGNEMENT_TOKEN  :   next_Sym(); EXPR(); GENERER1(STO); TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR); break;
        case COLON_TOKEN        :   next_Sym(); LOOP(); break;
        default                 :   ERREUR_SYN(AFFECT_ERR); break;
    }
}

void BLOCK(){
    if(Sym_Cour.token == DECLARE_TOKEN){
        next_Sym(); DECBLOCK();
    }
    TEST_SYMBOLE(BEGIN_TOKEN, BEGIN_ERR);
    INSTS();
    TEST_SYMBOLE(END_TOKEN, END_ERR);
    TEST_SYMBOLE(SEMICOLON_TOKEN, SEMICOLON_ERR);
}

void DECBLOCK(){
    switch(Sym_Cour.token){
        case IDENTIFIER_TOKEN       :   DECVARCONS();   DECL(); break;
        case TYPE_TOKEN                 :   DECTYPE();  DECL(); break;
        case SUBTYPE_TOKEN              :   DECTYPE();  DECL(); break;
    }
}

void CONDITION(){
    enum AdaTokens ul;
    if(Sym_Cour.token == LEFT_PARATHESIS_TOKEN){
        next_Sym();
        CONDITION();
        TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
        while(Sym_Cour.token == AND_TOKEN || Sym_Cour.token == OR_TOKEN || Sym_Cour.token == XOR_TOKEN || Sym_Cour.token == NOT_TOKEN){
            ul = Sym_Cour.token;
            next_Sym();
            CONDITION();
            switch(ul){
                case AND_TOKEN : GENERER1(AND); break;
                case OR_TOKEN : GENERER1(OR); break;
                case XOR_TOKEN : GENERER1(XOR); break;
                case NOT_TOKEN : GENERER1(NOT); break;
            }
        }
    }else
        CONDS();
}

void CONDS(){
    enum AdaTokens ul;
    COND();
    while(Sym_Cour.token == AND_TOKEN || Sym_Cour.token == OR_TOKEN || Sym_Cour.token == XOR_TOKEN || Sym_Cour.token == NOT_TOKEN){
        ul = Sym_Cour.token;
        next_Sym();
        CONDITION();
        switch(ul){
            case AND_TOKEN : GENERER1(AND); break;
            case OR_TOKEN : GENERER1(OR); break;
            case XOR_TOKEN : GENERER1(XOR); break;
            case NOT_TOKEN : GENERER1(NOT); break;
        }
    }
}

void COND(){
    enum AdaTokens ul;
    DATA data;
    if(Sym_Cour.token == FALSE_TOKEN || Sym_Cour.token == TRUE_TOKEN){
        if(Sym_Cour.token == FALSE_TOKEN){ data.b=false; GENERER3(LDI, data, BOOLEAN); }
        else { data.b=true; GENERER3(LDI, data, BOOLEAN); }
        next_Sym();
        return;
    }

    /*if(Sym_Cour.token == IDENTIFIER_TOKEN ){
        AffCourante.target = GET_TSYM(Sym_Cour.Nom);

        next_Sym();
    }else{*/
    AffCourante.target = FLOAT;
    AffCourante.boolean = true;
    EXPR();
    //}

    if(Sym_Cour.token == EQUAL_TOKEN || Sym_Cour.token == INEQUALITY_TOKEN || Sym_Cour.token == LESS_TOKEN ||
       Sym_Cour.token == LESS_OR_EQUAL_TOKEN || Sym_Cour.token == GREATER_TOKEN || Sym_Cour.token == GREATER_OR_EQUAL_TOKEN){
        ul = Sym_Cour.token;
        next_Sym();
        EXPR();
        switch(ul){
            case EQUAL_TOKEN :  GENERER1(EQL); break;
            case INEQUALITY_TOKEN : GENERER1(NEQ); break;
            case LESS_TOKEN : GENERER1(LSS); break;
            case LESS_OR_EQUAL_TOKEN : GENERER1(LEQ); break;
            case GREATER_TOKEN : GENERER1(GTR); break;
            case GREATER_OR_EQUAL_TOKEN : GENERER1(GEQ); break;
        }
    }
}

void EXPR(){
    MULTDIVMOD();
    T1();
}

void T1(){
    enum AdaTokens ul;
    if(Sym_Cour.token == PLUS_TOKEN || Sym_Cour.token == HYPHEN_TOKEN){
        ul = Sym_Cour.token;
        switch(Sym_Cour.token){
            case PLUS_TOKEN : CHECK_AFF_OPERATION(PLUS_TOKEN); break;
            case HYPHEN_TOKEN : CHECK_AFF_OPERATION(HYPHEN_TOKEN); break;
        }
        next_Sym();
        MULTDIVMOD();
        T1();
        if(ul == PLUS_TOKEN)    GENERER1(ADD);
        else    GENERER1(SUB);
    }
}

void MULTDIVMOD(){
    AUXMULTDIVMOD();
    T2();
}

void T2(){
    enum AdaTokens ul;
    if(Sym_Cour.token == STAR_TOKEN || Sym_Cour.token == SLASH_TOKEN || Sym_Cour.token == MOD_TOKEN){
        ul = Sym_Cour.token;
        switch(Sym_Cour.token){
            case STAR_TOKEN : CHECK_AFF_OPERATION(STAR_TOKEN); break;
            case SLASH_TOKEN : CHECK_AFF_OPERATION(SLASH_TOKEN); break;
            case MOD_TOKEN : CHECK_AFF_OPERATION(MOD_TOKEN); break;
        }
        next_Sym();
        AUXMULTDIVMOD();
        T2();
        switch(ul){
            case STAR_TOKEN :  GENERER1(MUL); break;
            case SLASH_TOKEN : GENERER1(DIV); break;
            case MOD_TOKEN : GENERER1(MOD); break;
        }
    }
}

void AUXMULTDIVMOD(){
    if(Sym_Cour.token == LEFT_PARATHESIS_TOKEN){
        next_Sym();
        EXPR();
        TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    }else   PUISS();
}

void PUISS(){
    AUXPUISS();
    T3();
}

void T3(){
    if(Sym_Cour.token == DOUBLE_STAR_TOKEN){
        CHECK_AFF_OPERATION(DOUBLE_STAR_TOKEN);
        next_Sym();
        AUXPUISS();
        T3();
        GENERER1(DBLSTR);
    }
}

void AUXPUISS(){
    if(Sym_Cour.token == LEFT_PARATHESIS_TOKEN){
        next_Sym();
        EXPR();
        TEST_SYMBOLE(RIGHT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_ERR);
    }else   FACTEXPR();
}

void FACTEXPR(){
    char predecesseur[20];
    char successeur[20];
    char strName[20];
    int adr;
    TSYM type;
    char idf[30];
    DATA data;
    if(Sym_Cour.token == TYPE_CHARACTER_TOKEN || Sym_Cour.token == TYPE_INTEGER_TOKEN || /*Sym_Cour.token == TYPE_NATURAL_TOKEN ||*/
       Sym_Cour.token == TYPE_FLOAT_TOKEN || Sym_Cour.token == IDENTIFIER_TOKEN || Sym_Cour.token == TYPE_STRING_TOKEN){

        switch(Sym_Cour.token){
            case TYPE_CHARACTER_TOKEN : if(AffCourante.boolean)   CHECK_AFF_OPERANT(TO_TYPE_CHARACTER_TOKEN); data.c = Sym_Cour.Nom[0];
                GENERER3(LDI, data, CHARACTER); next_Sym(); break;
            case TYPE_STRING_TOKEN : if(AffCourante.boolean)   CHECK_AFF_OPERANT(TO_TYPE_STRING_TOKEN); strcpy(data.s, Sym_Cour.Nom);
                GENERER3(LDI, data, STRING); next_Sym(); break;
            case TYPE_INTEGER_TOKEN : if(AffCourante.boolean)   CHECK_AFF_OPERANT(TO_TYPE_INTEGER_TOKEN); data.i = atoi(Sym_Cour.Nom);
                GENERER3(LDI, data, INTEGER); next_Sym(); break;
            case TYPE_FLOAT_TOKEN : if(AffCourante.boolean)   CHECK_AFF_OPERANT(TO_TYPE_FLOAT_TOKEN); data.f = atof(Sym_Cour.Nom);
                GENERER3(LDI, data, FLOAT); next_Sym(); break;
            case IDENTIFIER_TOKEN :
                strcpy(idf, Sym_Cour.Nom);
                next_Sym();
                if(Sym_Cour.token == DOT_TOKEN){
                    strcpy(predecesseur, idf);
                    strcpy(strName, CHECK_VAR_COMPOSITE_TYPE(predecesseur));
                    next_Sym();
                    TEST_SYMBOLE(IDENTIFIER_TOKEN, IDENTIFIER_ERR);
                    strcpy(successeur, scSem);
                    adr = CHECK_PARAMETER_COMPOSITE(strName, successeur, predecesseur, &type);
                    if(AffCourante.boolean)   CHECK_AFF_OPERANT(type);
                }else  { if(AffCourante.boolean)   CHECK_AFF_OPERANT(CHECK_IDF_USE(idf));
                    adr = GET_ADRESSE(idf); }

                GENERER2(LDA, adr);
                GENERER1(LDV);  break;
        }

    }else   ERREUR_SYN(FACT_ERR);
}