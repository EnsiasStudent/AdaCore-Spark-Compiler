//
// Created by Adnane on 03/02/2019.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
//analyseur lexical
enum Errors_Lex{
    ERR_CAR_INC, ERR_FICH_VID, ERR_ID_LONG, BAD_IDENTIFIER_DEFINITION, BAD_NUMBER_DEFINITION
};

enum AdaTokens {
    ABORT_TOKEN, ABS_TOKEN, ABSTRACT_TOKEN, ACCEPT_TOKEN, ACCESS_TOKEN, ALIASED_TOKEN, ALL_TOKEN, AMPERSAND_TOKEN,
    AND_TOKEN, APOSTROPHE_TOKEN, ARRAY_TOKEN, ARROW_TOKEN, ASSIGNEMENT_TOKEN, AT_TOKEN, BEGIN_TOKEN, BODY_TOKEN, BOX_TOKEN,
    BOOLEAN_TOKEN, CASE_TOKEN, CHARACTER_TOKEN, CHARACTER_LITERAL_TOKEN, COLON_TOKEN, COMMA_TOKEN, COMMENT_TOKEN, CONSTANT_TOKEN, DECLARE_TOKEN,
    DELAY_TOKEN, DELTA_TOKEN, DIGITS_TOKEN, DO_TOKEN, DOT_TOKEN, DOUBLE_DOT_TOKEN, DOUBLE_STAR_TOKEN, DURATION_TOKEN, ELSE_TOKEN,
    ELSIF_TOKEN, END_TOKEN, EOF_TOKEN, ENTRY_TOKEN, EQUAL_TOKEN, ERROR_TOKEN, EXCEPTION_TOKEN, EXIT_TOKEN, FALSE_TOKEN, FOR_TOKEN, FUNCTION_TOKEN,
    GENERIC_TOKEN, GOTO_TOKEN, GREATER_OR_EQUAL_TOKEN, GREATER_TOKEN, HYPHEN_TOKEN, IDENTIFIER_TOKEN, IF_TOKEN, IN_TOKEN,
    INEQUALITY_TOKEN, INTEGER_TOKEN, INTERFACE_TOKEN, IS_TOKEN, LEFT_LABEL_TOKEN, LEFT_PARATHESIS_TOKEN, LESS_OR_EQUAL_TOKEN,
    LESS_TOKEN, LIMITED_TOKEN, LOOP_TOKEN, MOD_TOKEN, NATURAL_TOKEN, NEW_LINE_TOKEN, NEW_TOKEN, NOT_TOKEN, NULL_TOKEN,
    OF_TOKEN, OR_TOKEN, OTHERS_TOKEN, OUT_TOKEN, OVERRIDING_TOKEN, PACKAGE_TOKEN, PLUS_TOKEN, POSITIVE_TOKEN,
    PRAGMA_TOKEN, PRIVATE_TOKEN, PROCEDURE_TOKEN, PROTECTED_TOKEN, RAISE_TOKEN, RANGE_TOKEN, RECORD_TOKEN, REM_TOKEN,
    RENAMES_TOKEN, REQUEUE_TOKEN, RETURN_TOKEN, REVERSE_TOKEN, RIGHT_LABEL_TOKEN, RIGHT_PARENTHESIS_TOKEN, SELECT_TOKEN,
    SEMICOLON_TOKEN, SEPARATE_TOKEN, SLASH_TOKEN, SOME_TOKEN, SPACE_TOKEN, STAR_TOKEN, STRING_TOKEN, STRING_LITERAL_TOKEN, SUBTYPE_TOKEN,
    SYNCHRONIZED_TOKEN, TAGGED_TOKEN, TASK_TOKEN, TERMINATE_TOKEN, THEN_TOKEN, TRUE_TOKEN, TYPE_CHARACTER_TOKEN, TYPE_STRING_TOKEN, TYPE_TOKEN, TYPE_INTEGER_TOKEN,TYPE_FLOAT_TOKEN, UNTIL_TOKEN, USE_TOKEN,
    VERTICAL_TOKEN, VERTICAL_LINE_TOKEN, WHEN_TOKEN, WHILE_TOKEN, WITH_TOKEN, XOR_TOKEN, FLOAT_TOKEN, GET_TOKEN, PUT_TOKEN, No_Ada_Predefined_Word,
    No_Special_Ada_Case
};
#define MAX 30
FILE *stream = NULL;
int current;

typedef struct{
    enum AdaTokens token;
    char Nom[MAX+1];
} Tsym_Cour;

Tsym_Cour Sym_Cour;

typedef struct { enum Errors_Lex  CODE_ERR; char mes[40];} Erreurs;
Erreurs MES_ERR[100] ={
        {ERR_CAR_INC,"caractere inconnu"}, {ERR_FICH_VID,"erreur lors de l'ouverture du fichier"},
        {ERR_ID_LONG, "Nom identifiant trop long"}, {BAD_IDENTIFIER_DEFINITION, "Eviter deux underscore successifs"}
};

//fin analyseur lexical

enum AdaTokens isAda(){
    if(!strcasecmp(Sym_Cour.Nom,"abort")){Sym_Cour.token=ABORT_TOKEN;return ABORT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"abs")) {Sym_Cour.token=ABS_TOKEN;return ABS_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"abstract")) {Sym_Cour.token=ABSTRACT_TOKEN;return ABSTRACT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"accept")) {Sym_Cour.token=ACCEPT_TOKEN;return ACCEPT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"access")) {Sym_Cour.token=ACCESS_TOKEN;return ACCESS_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"aliased")) {Sym_Cour.token=ALIASED_TOKEN;return ALIASED_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"all")) {Sym_Cour.token=ALL_TOKEN;return ALL_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"and")) {Sym_Cour.token=AND_TOKEN;return AND_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"array")) {Sym_Cour.token=ARRAY_TOKEN;return ARRAY_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"at")) {Sym_Cour.token=AT_TOKEN;return AT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"begin")) {Sym_Cour.token=BEGIN_TOKEN;return BEGIN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"body")) {Sym_Cour.token=BODY_TOKEN;return BODY_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"boolean")) {Sym_Cour.token=BOOLEAN_TOKEN;return BOOLEAN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"case")) {Sym_Cour.token=CASE_TOKEN;return CASE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"constant")) {Sym_Cour.token=CONSTANT_TOKEN;return CONSTANT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"declare")) {Sym_Cour.token=DECLARE_TOKEN;return DECLARE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"delay")) {Sym_Cour.token=DELAY_TOKEN;return DELAY_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"delta")) {Sym_Cour.token=DELTA_TOKEN;return DELTA_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"digits")) {Sym_Cour.token=DIGITS_TOKEN;return DIGITS_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"do")) {Sym_Cour.token=DO_TOKEN;return DO_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"else")) {Sym_Cour.token=ELSE_TOKEN;return ELSE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"elsif")) {Sym_Cour.token=ELSIF_TOKEN;return ELSIF_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"end")) {Sym_Cour.token=END_TOKEN;return END_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"entry")) {Sym_Cour.token=ENTRY_TOKEN;return ENTRY_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"exception")) {Sym_Cour.token=EXCEPTION_TOKEN;return EXCEPTION_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"exit")) {Sym_Cour.token=EXIT_TOKEN;return EXIT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"false")) {Sym_Cour.token=FALSE_TOKEN;return FALSE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"float")) {Sym_Cour.token=FLOAT_TOKEN;return FLOAT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"get")) {Sym_Cour.token=GET_TOKEN;return GET_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"put")) {Sym_Cour.token=PUT_TOKEN;return PUT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"for")) {Sym_Cour.token=FOR_TOKEN;return FOR_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"function")) {Sym_Cour.token=FUNCTION_TOKEN;return FUNCTION_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"generic")) {Sym_Cour.token=GENERIC_TOKEN;return GENERIC_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"goto")) {Sym_Cour.token=GOTO_TOKEN;return GOTO_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"integer")) {Sym_Cour.token=INTEGER_TOKEN;return INTEGER_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"if")) {Sym_Cour.token=IF_TOKEN;return IF_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"in")) {Sym_Cour.token=IN_TOKEN;return IN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"interface")) {Sym_Cour.token=INTERFACE_TOKEN;return INTERFACE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"is")) {Sym_Cour.token=IS_TOKEN;return IS_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"limited")) {Sym_Cour.token=LIMITED_TOKEN;return LIMITED_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"loop")) {Sym_Cour.token=LOOP_TOKEN;return LOOP_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"mod")) {Sym_Cour.token=MOD_TOKEN;return MOD_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"new")) {Sym_Cour.token=NEW_TOKEN;return NEW_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"natural")) {Sym_Cour.token=NATURAL_TOKEN;return NATURAL_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"positive")) {Sym_Cour.token=POSITIVE_TOKEN;return POSITIVE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"character")) {Sym_Cour.token=CHARACTER_TOKEN;return CHARACTER_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"duration")) {Sym_Cour.token=DURATION_TOKEN;return DURATION_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"not")) {Sym_Cour.token=NOT_TOKEN;return NOT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"null")) {Sym_Cour.token=NULL_TOKEN;return NULL_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"of")) {Sym_Cour.token=OF_TOKEN;return OF_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"or")) {Sym_Cour.token=OR_TOKEN;return OR_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"others")) {Sym_Cour.token=OTHERS_TOKEN;return OTHERS_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"out")) {Sym_Cour.token=OUT_TOKEN;return OUT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"overriding")) {Sym_Cour.token=OVERRIDING_TOKEN;return OVERRIDING_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"package")) {Sym_Cour.token=PACKAGE_TOKEN;return PACKAGE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"pragma")) {Sym_Cour.token=PRAGMA_TOKEN;return PRAGMA_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"private")) {Sym_Cour.token=PRIVATE_TOKEN;return PRIVATE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"procedure")) {Sym_Cour.token=PROCEDURE_TOKEN;return PROCEDURE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"protected")) {Sym_Cour.token=PROTECTED_TOKEN;return PROTECTED_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"raise")) {Sym_Cour.token=RAISE_TOKEN;return RAISE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"range")) {Sym_Cour.token=RANGE_TOKEN;return RANGE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"record")) {Sym_Cour.token=RECORD_TOKEN;return RECORD_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"rem")) {Sym_Cour.token=REM_TOKEN;return REM_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"renames")) {Sym_Cour.token=RENAMES_TOKEN;return RENAMES_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"requeue")) {Sym_Cour.token=REQUEUE_TOKEN;return REQUEUE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"return")) {Sym_Cour.token=RETURN_TOKEN;return RETURN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"reverse")) {Sym_Cour.token=REVERSE_TOKEN;return REVERSE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"select")) {Sym_Cour.token=SELECT_TOKEN;return SELECT_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"separate")) {Sym_Cour.token=SEPARATE_TOKEN;return SEPARATE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"some")) {Sym_Cour.token=SOME_TOKEN;return SOME_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"subtype")) {Sym_Cour.token=SUBTYPE_TOKEN;return SUBTYPE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"string")) {Sym_Cour.token=STRING_TOKEN;return STRING_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"synchronized")) {Sym_Cour.token=SYNCHRONIZED_TOKEN;return SYNCHRONIZED_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"tagged")) {Sym_Cour.token=TAGGED_TOKEN;return TAGGED_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"task")) {Sym_Cour.token=TASK_TOKEN;return TASK_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"terminate")) {Sym_Cour.token=TERMINATE_TOKEN;return TERMINATE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"then")) {Sym_Cour.token=THEN_TOKEN;return THEN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"true")) {Sym_Cour.token=TRUE_TOKEN;return TRUE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"type")) {Sym_Cour.token=TYPE_TOKEN;return TYPE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"until")) {Sym_Cour.token=UNTIL_TOKEN;return UNTIL_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"use")) {Sym_Cour.token=USE_TOKEN;return USE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"when")) {Sym_Cour.token=WHEN_TOKEN;return WHEN_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"while")) {Sym_Cour.token=WHILE_TOKEN;return WHILE_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"with")) {Sym_Cour.token=WITH_TOKEN;return WITH_TOKEN;}
    else if(!strcasecmp(Sym_Cour.Nom,"xor")) {Sym_Cour.token=XOR_TOKEN;return XOR_TOKEN;}
    return No_Ada_Predefined_Word;
}

void Erreur(enum Errors_Lex err){
    int ind_err = err;
    printf("\nErreur Lexical numero %d\t:%s\n", ind_err, MES_ERR[ind_err].mes);
    //getch();
    exit(EXIT_FAILURE);
}

enum AdaTokens Read_number(){
    int i = 0;
    int flagDot = 0;
    while((isdigit(current) || current == '.') && !isspace(current) && current!=EOF){
        if(current=='.')
        {
            if(flagDot == 1)
            {
                while(isalnum(current) || current == '.')
                {
                    current = fgetc(stream);
                }
                Erreur(BAD_NUMBER_DEFINITION);
            }
            else
            {   Sym_Cour.Nom[i++] = (char) current;
                flagDot = 1;
                current = fgetc(stream);
                if(!isdigit(current))
                {
                    if(isalpha(current))
                    {
                        while(isalpha(current))
                        {
                            current = fgetc(stream);
                        }
                        Erreur(BAD_NUMBER_DEFINITION);
                    }
                    else
                        Erreur(BAD_NUMBER_DEFINITION);
                }
                else if(isdigit(current)){
                    Sym_Cour.Nom[i++] = (char) current;
                    current = fgetc(stream);
                }
            }

        }
        else if (isdigit(current)){
            Sym_Cour.Nom[i++] = (char) current;
            current = fgetc(stream);
        }
    }
    if(isalpha(current))
    {
        while(isalnum(current))
        {
            current = fgetc(stream);
        }
        Erreur(BAD_NUMBER_DEFINITION);
    }
    else
    {
        if(flagDot == 1) {
            Sym_Cour.Nom[i] = '\0';
            Sym_Cour.token = TYPE_FLOAT_TOKEN;
            return TYPE_FLOAT_TOKEN;
        }
        if(flagDot == 0) {
            Sym_Cour.Nom[i] = '\0';
            Sym_Cour.token = TYPE_INTEGER_TOKEN;
            return TYPE_INTEGER_TOKEN;
        }
    }
}

enum AdaTokens Read_word(){
    enum AdaTokens checker;
    int i = 0;
    while((('a'<= current && current <= 'z')||('A' <= current && current <= 'Z')||('0' <= current && current <= '9') || (current == '_'))&& current != EOF && current != ' ' && current != '\n' && current != '\t'){
        Sym_Cour.Nom[i++] = (char)current;
        current = fgetc(stream);
        if(Sym_Cour.Nom[i-1] == '_' && current == '_'){
            Erreur(BAD_IDENTIFIER_DEFINITION);
        }
        if(i == MAX) Erreur(ERR_ID_LONG);
    }
    Sym_Cour.Nom[i] = '\0';
    checker = isAda();
    if(checker != No_Ada_Predefined_Word){
        return checker;
    }
    Sym_Cour.token = IDENTIFIER_TOKEN;
    return IDENTIFIER_TOKEN;
}

enum AdaTokens specialCase(){
    int i = 0;
    Sym_Cour.Nom[i++] = (char) current;
    Sym_Cour.Nom[i++] = '\0';
    Sym_Cour.Nom[i] = '\0';
    if(current == ','){Sym_Cour.token=COMMA_TOKEN;current=fgetc(stream);return COMMA_TOKEN;}
    else if(current == ';'){Sym_Cour.token=SEMICOLON_TOKEN;current=fgetc(stream);return SEMICOLON_TOKEN;}
    else if(current == '&'){Sym_Cour.token=AMPERSAND_TOKEN;current=fgetc(stream);return AMPERSAND_TOKEN;}
    else if(current == '+'){Sym_Cour.token=PLUS_TOKEN;current=fgetc(stream);return PLUS_TOKEN;}
    else if(current == '('){Sym_Cour.token=LEFT_PARATHESIS_TOKEN;current=fgetc(stream);return LEFT_PARATHESIS_TOKEN;}
    else if(current == ')'){Sym_Cour.token= RIGHT_PARENTHESIS_TOKEN;current=fgetc(stream);return RIGHT_PARENTHESIS_TOKEN;}
    else if(current == '|'){Sym_Cour.token= VERTICAL_LINE_TOKEN;current=fgetc(stream);return VERTICAL_LINE_TOKEN;}
    else if(current == '"') {
        i = 0;
        current=fgetc(stream);
        while(current != '\n' && current != '"') {
            Sym_Cour.Nom[i++] = (char) current;
            current = fgetc(stream);
        }
        Sym_Cour.Nom[i] = '\0';
        Sym_Cour.token = TYPE_STRING_TOKEN;
        current = fgetc(stream);
        return TYPE_STRING_TOKEN;
    }
    else if(current == '\'') {
        current = fgetc(stream);
        if(current == '\'') {
            Sym_Cour.Nom[0] = ' ';
            Sym_Cour.token = TYPE_CHARACTER_TOKEN;
            current = fgetc(stream);
            return TYPE_CHARACTER_TOKEN;
        }
        else {
            Sym_Cour.Nom[0] = (char)current;
            current = fgetc(stream);
            if(current == '\'') {
                Sym_Cour.token = TYPE_CHARACTER_TOKEN;
                current = fgetc(stream);
                return TYPE_CHARACTER_TOKEN;
            }
            else if(isalpha(current)) {
                Sym_Cour.token = APOSTROPHE_TOKEN;
                current = fgetc(stream);
                return APOSTROPHE_TOKEN;
            }
        }
    }

    else if(current == '-'){
        current=fgetc(stream);
        if(current == '-'){
            while(current != '\n'){
                current = fgetc(stream);
            }
            Sym_Cour.Nom[1] = '-';
            Sym_Cour.token = COMMENT_TOKEN;
            return COMMENT_TOKEN;
        }
        Sym_Cour.token = HYPHEN_TOKEN;
        return HYPHEN_TOKEN;
    }
    else if(current == '*'){
        current=fgetc(stream);
        if(current == '*'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = DOUBLE_STAR_TOKEN;
            current = fgetc(stream);
            return DOUBLE_STAR_TOKEN;
        }
        Sym_Cour.token = STAR_TOKEN;
        return STAR_TOKEN;
    }
    else if(current == '.'){
        current = fgetc(stream);
        if(current == '.'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = DOUBLE_DOT_TOKEN;
            current = fgetc(stream);
            return DOUBLE_DOT_TOKEN;
        }
        Sym_Cour.token = DOT_TOKEN;
        return DOT_TOKEN;
    }
    else if(current == '='){
        current = fgetc(stream);
        if(current == '>'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = ARROW_TOKEN;
            current = fgetc(stream);
            return ARROW_TOKEN;
        }
        Sym_Cour.token = EQUAL_TOKEN;
        return EQUAL_TOKEN;
    }
    else if(current == ':'){
        current = fgetc(stream);
        if(current == '='){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = ASSIGNEMENT_TOKEN;
            current = fgetc(stream);
            return ASSIGNEMENT_TOKEN;
        }
        Sym_Cour.token = COLON_TOKEN;
        return COLON_TOKEN;
    }
    else if(current == '/'){
        current = fgetc(stream);
        if(current == '='){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = INEQUALITY_TOKEN;
            current = fgetc(stream);
            return INEQUALITY_TOKEN;
        }
        Sym_Cour.token = SLASH_TOKEN;
        return SLASH_TOKEN;
    }
    else if(current == '>'){
        current = fgetc(stream);
        if(current == '='){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = GREATER_OR_EQUAL_TOKEN;
            current = fgetc(stream);
            return GREATER_OR_EQUAL_TOKEN;
        }
        if(current == '>'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = RIGHT_LABEL_TOKEN;
            current = fgetc(stream);
            return RIGHT_LABEL_TOKEN;
        }
        Sym_Cour.token = GREATER_TOKEN;
        return GREATER_TOKEN;
    }
    else if(current == '<'){
        current = fgetc(stream);
        if(current == '='){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = LESS_OR_EQUAL_TOKEN;
            current = fgetc(stream);
            return LESS_OR_EQUAL_TOKEN;
        }
        else if(current == '<'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = LEFT_LABEL_TOKEN;
            current = fgetc(stream);
            return LEFT_LABEL_TOKEN;
        }
        if(current == '>'){
            Sym_Cour.Nom[1] = (char) current;
            Sym_Cour.token = BOX_TOKEN;
            current = fgetc(stream);
            return BOX_TOKEN;
        }
        Sym_Cour.token = LESS_TOKEN;
        return LESS_TOKEN;
    }
    return No_Special_Ada_Case;
}

enum AdaTokens next_Sym(){
    if (current != EOF){
        enum AdaTokens checker = specialCase();
        if( checker != No_Special_Ada_Case) return checker;
        else if(current == ' ' || current == '\n' || current == '\t' || current == '\r') {current = fgetc(stream);return next_Sym();}
        else if('0'<= current &&  current <= '9') return Read_number();
        else if(('a'<= current && current <= 'z')||('A' <= current && current <= 'Z')) return Read_word();
        else {printf("ERROR_CARACTER_UNKNOWN "); Erreur(ERR_CAR_INC);}
    }
    else {Sym_Cour.token=EOF_TOKEN; return EOF_TOKEN;}
}
