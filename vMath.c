/*************************************************************
* vMath.c
* Author: Michael Johnston
* Date: 9/23/2026
**************************************************************/
#include <stdio.h>
#include "vect.h"
//add 2 vectors
vect add(vect a, vect b){
    vect fin;
    fin.x=a.x+b.x;
    fin.y=a.y+b.y;
    fin.z=a.z+b.z;
    return fin;
}
//sub 2 vectors;
vect sub(vect a, vect b){
    vect fin;
    fin.x=a.x-b.x;
    fin.y=a.y-b.y;
    fin.z=a.z-b.z;
    return fin;
}
//mult 2 vectors;
vect vMult(vect a, vect b){
    vect fin;
    //dot mult

    //cross mult

    return fin;
}
//mult a vector by value c
vect sMult(vect a, float c){
    vect fin;
    fin.x=a.x * c;
    fin.y=a.y * c;
    fin.z=a.z * c;
    return fin;
}
/*************************************************************/
// vector Array commands
vect addVect(vect d){
    for(int lcv;lcv<10;lcv++){
        if(myVect[lcv] == NULL){
            myVect[lcv] = vect d;
            return d;
        }
    }
    return d;
    //return added vect value;
}

vect findVect(char* name){
    //in work
    vect a;
    return a;
    //return found vect;
}
void clear(){
    //clear array
}
vect delete(char* name){
    //in work
    vect a;
    return a;
    //return deleted vect
}
vect replace(char* name,vect d){
    //chosen name is replaced with vect d
    //return old vect
    //in work
    vect a;
    return a;
}
/*************************************************************/
//User Interface commnads
void help(){
    //give detail about program
}
void quit(){
    //ends the program - program will run until this is called
}
void list(){
    //list the array
/*void clear();*/
    //clear array - arleady defined
}
void vector(){
    //vector operation
        //vector math
        //new vector
        //find vector
}
void parseEntry(){
    //will parse the user input and call appropiate command
}
