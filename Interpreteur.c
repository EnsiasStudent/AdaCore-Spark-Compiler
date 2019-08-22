//
// Created by Adnane on 03/02/2019.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<conio.h>
#include "generation_code.c"

void INTER_INST(INSTRUCTION INST){
    int adr;
    INFO val1, val2;
    switch(INST.MNE){
        case INT: OFFSET=SP=INST.SUITE.data.i; PC++;   break;
        case LDI: MEM[++SP]=INST.SUITE; PC++; break;
        case LDA: MEM[++SP]=INST.SUITE; PC++;   break;
        case STO: val1=MEM[SP--];   adr=MEM[SP--].data.i;  MEM[adr]=val1;  PC++;   break;
        case LDV: adr=MEM[SP--].data.i; MEM[++SP]=MEM[adr]; PC++;   break;

        case EQL: val1=MEM[SP--];   val2=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i==val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i==val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i==(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f==val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f==val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f==(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i==val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i==val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i==(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i==val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i==val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i==(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c==val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c==(int)val2.data.c);
                    break;
                case STRING : MEM[++SP].data.b=(!strcasecmp(val1.data.s, val2.data.s));  break;
            }
            PC++;   break;

        case NEQ: val1=MEM[SP--];   val2=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i!=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i!=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i!=(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f!=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f!=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f!=(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i!=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i!=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i!=(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i!=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i!=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i!=(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c!=val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c!=(int)val2.data.c);
                    break;
                case STRING : MEM[++SP].data.b=strcasecmp(val1.data.s, val2.data.s);  break;
            }
            PC++;   break;

        case LEQ: val2=MEM[SP--];   val1=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<=(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f<=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f<=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f<=(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<=(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<=(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c<=val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c<=(int)val2.data.c);
                    break;
            }
            PC++;   break;

        case GEQ: val2=MEM[SP--];   val1=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>=(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f>=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f>=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f>=(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>=(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>=val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>=val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>=(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c>=val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c>=(int)val2.data.c);
                    break;
            }
            PC++;   break;

        case GTR: val2=MEM[SP--];   val1=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f>val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f>val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f>(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i>val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i>val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i>(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c>val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c>(int)val2.data.c);
                    break;
            }
            PC++;   break;

        case LSS: val2=MEM[SP--];   val1=MEM[SP--];

            switch(val1.type){
                case BOOLEAN : MEM[++SP].data.b=(val1.data.b==val2.data.b); break;
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<(int)val2.data.c);
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.f<val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.f<val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.f<(int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<(int)val2.data.c);
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.i<val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.b=(val1.data.i<val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.i<(int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.b=(val1.data.c<val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.b=(val1.data.c<(int)val2.data.c);
                    break;
            }
            PC++;   break;

        case BZE: if (MEM[SP--].data.b==false)   PC=INST.SUITE.data.i;
            else  PC++;   break;
        case BRN: PC=INST.SUITE.data.i;    break;

        case ADD: val1=MEM[SP--];   val2=MEM[SP--];
            ++SP;
            switch(val1.type){
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE ){
                        MEM[SP].data.i = MEM[SP].data.f = (val1.data.i + val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f = (val1.data.i + val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i + (int)val2.data.c);
                    }
                    break;
                case FLOAT :   if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.f + val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f =(val1.data.f + val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.f + (int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i + val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i + val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i + (int)val2.data.c);
                    }
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i + val2.data.i);
                    else if(val2.type == FLOAT)  MEM[++SP].data.i= MEM[SP].data.f = (val1.data.i + val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.i=MEM[SP].data.f=(val1.data.i + (int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.c + val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[++SP].data.i=MEM[SP].data.f=(val1.data.c + (int)val2.data.c);
                    break;
            }
            PC++;   break;

        case MUL: val1=MEM[SP--];   val2=MEM[SP--];
            ++SP;
            switch(val1.type){
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE ){
                        MEM[SP].data.i= MEM[SP].data.f = (val1.data.i * val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i = (val1.data.i * val2.data.f);
                        MEM[SP].data.f = (val1.data.i * val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * (int)val2.data.c);
                    }
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.f * val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f =(val1.data.f * val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.f * (int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * (int)val2.data.c);
                    }
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * val2.data.i);
                    else if(val2.type == FLOAT)  MEM[SP].data.i= MEM[SP].data.f = (val1.data.i * val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.i * (int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.c * val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.c * (int)val2.data.c);
                    break;
            }
            PC++;   break;

        case SUB: val2=MEM[SP--];   val1=MEM[SP--];
            ++SP;
            switch(val1.type){
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE ){
                        MEM[SP].data.i= MEM[SP].data.f = (val1.data.i - val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f = (val1.data.i - val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - (int)val2.data.c);
                    }
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.f - val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f =(val1.data.f - val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.f - (int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - (int)val2.data.c);
                    }
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - val2.data.i);
                    else if(val2.type == FLOAT)  MEM[SP].data.i= MEM[SP].data.f = (val1.data.i - val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.i - (int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.c - val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.c - (int)val2.data.c);
                    break;
            }
            PC++;   break;

        case DIV: val2=MEM[SP--];   val1=MEM[SP--];
            ++SP;
            switch(val1.type){
                case INTEGER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE ){
                        MEM[SP].data.i= MEM[SP].data.f = (val1.data.i / val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f = (val1.data.i / val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / (int)val2.data.c);
                    }
                    break;
                case FLOAT : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.f / val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f =(val1.data.f / val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  MEM[++SP].data.i=MEM[SP].data.f=(val1.data.f / (int)val2.data.c);
                    break;
                case NATURAL : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                    {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / val2.data.i);
                    }
                    else if(val2.type == FLOAT)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / val2.data.f);
                    }
                    else if(val2.type == CHARACTER)  {
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / (int)val2.data.c);
                    }
                    break;
                case POSITIVE : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / val2.data.i);
                    else if(val2.type == FLOAT)  MEM[SP].data.i= MEM[SP].data.f = (val1.data.i / val2.data.f);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.i / (int)val2.data.c);
                    break;
                case CHARACTER : if(val2.type == INTEGER || val2.type == NATURAL || val2.type == POSITIVE )
                        MEM[++SP].data.i=MEM[SP].data.f=(val1.data.c / val2.data.i);
                    else if(val2.type == CHARACTER)  MEM[SP].data.i=MEM[SP].data.f=(val1.data.c / (int)val2.data.c);
                    break;
            }
            PC++;   break;

        case INN: adr=MEM[SP--].data.i;
            switch(GET_TYPE(adr)){
                case INTEGER : scanf("%d", &MEM[adr].data.i);  break;
                case FLOAT : scanf("%f", &MEM[adr].data.f);  break;
                case NATURAL : scanf("%d", &MEM[adr].data.i);  break;
                case POSITIVE : scanf("%d", &MEM[adr].data.i);  break;
                case CHARACTER : scanf("%c", &MEM[adr].data.c);  break;
                case STRING : scanf("%s", MEM[adr].data.s);  break;
            }
            PC++; break;

        case PRN:
            switch(MEM[SP].type){
                case INTEGER : printf("\n%d\n", MEM[SP--].data.i);   break;
                case FLOAT : printf("\n%f\n", MEM[SP--].data.f);   break;
                case NATURAL : printf("\n%d\n", MEM[SP--].data.i);   break;
                case POSITIVE : printf("\n%d\n", MEM[SP--].data.i);   break;
                case CHARACTER : printf("\n%c\n", MEM[SP--].data.c);   break;
                case STRING : printf("\n%s\n", MEM[SP--].data.s);  break;
            }
            PC++; break;
        case AND: val1=MEM[SP--];   val2=MEM[SP--];
            if(val1.data.b && val2.data.b) MEM[++SP].data.b = true;
            else MEM[++SP].data.b = false;
            PC++;  break;
        case OR: val1=MEM[SP--];   val2=MEM[SP--];
            if(val1.data.b || val2.data.b) MEM[++SP].data.b = true;
            else MEM[++SP].data.b = false;
            PC++;  break;
    }
}

void INTER_PCODE(){
    PC=0;
    while (PCODE[PC].MNE!=HLT){
        INTER_INST(PCODE[PC]);
        //if(PC-1 == 16)
        //printf("4 case : %d   5 case : %d\n", MEM[4].data.i, MEM[5].data.i);
        //if(PC == 11)    printf("\n\t(SP = %d) a = %d    i = %d \n",SP, MEM[0].data.i, MEM[1].data.i);
    }
}
