/*************************************************************
* vMath.c
* Author: Michael Johnston
* Date: 9/23/2026
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vect.h"
#include "vMath.h"
//static memory
    //static vect myVect[10];
//Dynamic memory
static vect *myVect = NULL;
//keep track of array size;
static int arSize = 10;
//keep track of list count;
static int cnt = 0;
//add 2 vectors
vect add(vect a, vect b){
    vect fin;
    strcpy(fin.name,"ans");
    fin.x=a.x+b.x;
    fin.y=a.y+b.y;
    fin.z=a.z+b.z;
    return fin;
}
//sub 2 vectors;
vect sub(vect a, vect b){
    vect fin;
    strcpy(fin.name,"ans");
    fin.x=a.x-b.x;
    fin.y=a.y-b.y;
    fin.z=a.z-b.z;
    return fin;
}
//mult 2 vectors;
vect vMult(vect a, vect b){
    vect fin;
    strcpy(fin.name,"ans");
    //dot mult

    //cross mult

    return fin;
}
//mult a vector by value c
vect sMult(vect a, float c){
    vect fin;
    strcpy(fin.name,"ans");
    fin.x=a.x * c;
    fin.y=a.y * c;
    fin.z=a.z * c;
    return fin;
}
/*************************************************************/
// vector Array commands
vect addVect(vect d){
    if(cnt>=arSize){
        arSize=arSize*2;
        vect *tempArray = realloc(myVect, arSize * sizeof(vect));
        if(tempArray!=NULL){
            myVect = tempArray;
        }else{
            printf("Memory Allocation failed");
        }
    }
    for(int lcv=0;lcv<arSize;lcv++){
        if(myVect[lcv].name[0] == '\0'){
            myVect[lcv] = d;
            cnt++;
            return d;
        }
    }
    printf("Error: vector not added\n");
    return d;
    //return added vect value;
}

vect findVect(vect a){
    vect d;
    //in work
    for(int lcv=0;lcv<arSize;lcv++){
        if(!strcmp(a.name,myVect[lcv].name)){
            return myVect[lcv];
        }
    }
    d.name[0] = '\0';
    return d;
    //return found vect;
}
void clear(){
    //clear array
    for (int lcv=0;lcv<arSize;lcv++){
        myVect[lcv].name[0] = '\0';
        myVect[lcv].x = 0;
        myVect[lcv].y = 0;
        myVect[lcv].z = 0;
    }
}
vect delete(vect a){
    //in work
    return a;
    //return deleted vect
}
vect replace(vect a,vect d){
    //chosen name is replaced with vect d
    //return old vect
    //in work
    for(int lcv=0;lcv<arSize;lcv++){
        if(!strcmp(a.name,myVect[lcv].name)){
            myVect[lcv].x=a.x;
            myVect[lcv].y=a.y;
            myVect[lcv].z=a.z;
            strcpy(myVect[lcv].name,a.name);

        }
    }
    return a;
}
/*************************************************************/
//User Interface commnads
void help(){
    //give detail about program
    printf("This progam is a vector calculator, the following actions can be called:\nvectName = x x x\nvectName = x,x,x\nVector math\nvectA +/-/* vectB\nlist\nquit\n");
}
void quit(){
    //ends the program - program will run until this is called
}
void list(){
    //list the array
    for(int lcv=0;lcv<arSize;lcv++){
        if((myVect[lcv].name[0] != '\0')){
            printf("%s: %f %f %f\n",myVect[lcv].name,myVect[lcv].x,myVect[lcv].y,myVect[lcv].z);
        }
    }
}
void vector(){
    //vector operation
        //vector math
        //new vector
        //find vector
}
void parseEntry(){
    //will create initial list if empty;
    if (myVect==NULL){
        printf("here at malloc\n");
        myVect = malloc(arSize * sizeof(vect));
        
    }
    //will parse the user input and call appropiate command
    printf("please input a command or vector\n");
    printf(">>> ");
    char input[100];
    fgets(input,99,stdin);
    char *myPtr = strtok(input, " ");
    char *command = myPtr;

    if(!strcmp(command,"list")||!strcmp(command,"list\n")){
        list();
        parseEntry();
    }else
    if(!strcmp(command,"clear")||!strcmp(command,"clear\n")){
        clear();
        parseEntry();
    }else
    if(!strcmp(command,"quit")||!strcmp(command,"quit\n")){
        quit();
    }else
    if(!strcmp(command,"help")||!strcmp(command,"help\n")){
        help();
        parseEntry();
    }else{
        //vector command
        vect nVect;
        strcpy(nVect.name,myPtr);
        nVect.name[strcspn(nVect.name, "\n")] = '\0';
        myPtr = strtok(NULL, " ");

        //vector = vector math



        //find vector
        if (myPtr == NULL){
            vect tempVect=findVect(nVect);
            if((tempVect.name[0] != '\0')){
            printf("%s: %f %f %f\n",tempVect.name,tempVect.x,tempVect.y,tempVect.z);
            }else{
                printf("vector not in list\n");
            }
        }
        //add vectors
        if(myPtr != NULL){
            vect tempVect;
            if(!strcmp(myPtr,"+")){
                vect myVectA=findVect(nVect);
                myPtr = strtok(NULL, " ");
                vect myVectB;
                if(myPtr != NULL){
                    strcpy(myVectB.name,myPtr);
                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                    myVectB=findVect(myVectB);
                }
                tempVect=add(myVectA,myVectB);
                printf("%s: %f %f %f\n",tempVect.name,tempVect.x,tempVect.y,tempVect.z);
            }
        //sub vectors
            if(!strcmp(myPtr,"-")){
                vect myVectA=findVect(nVect);
                myPtr = strtok(NULL, " ");
                vect myVectB;
                if(myPtr != NULL){
                    strcpy(myVectB.name,myPtr);
                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                    myVectB=findVect(myVectB);
                }
                tempVect=sub(myVectA,myVectB);
                printf("%s: %f %f %f\n",tempVect.name,tempVect.x,tempVect.y,tempVect.z);
            }
        //mult vector
            if(!strcmp(myPtr,"*")){
                float firstFloat = atof(nVect.name);
                vect myVectA=findVect(nVect);
                myPtr = strtok(NULL, " ");
                vect myVectB;
                // num * vector
                if(firstFloat!=0){
                    strcpy(myVectB.name,myPtr);
                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                    myVectB=findVect(myVectB);
                    printf("%s vect\n",myVectB.name);
                    printf("%f float\n",firstFloat);
                    printf("%s: %f %f %f\n",myVectB.name,myVectB.x,myVectB.y,myVectB.z);
                    tempVect=sMult(myVectB,firstFloat);
                }else
                // vector * num
                if(myPtr != NULL){
                    float myFloat = atof(myPtr);
                    if(myFloat==0){
                    //vector * vector
                    strcpy(myVectB.name,myPtr);
                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                    myVectB=findVect(myVectB);
                    tempVect=vMult(myVectA,myVectB);
                    }else{
                        tempVect=sMult(myVectA,myFloat);
                    }
                }
                
                printf("%s: %f %f %f\n",tempVect.name,tempVect.x,tempVect.y,tempVect.z);
            }
        }

        //new vector
        if (myPtr != NULL){
            //new vector

            //existing vectors

            //all numbers
            if(!strcmp(myPtr,"=")){
                myPtr = strtok(NULL, " ");
                if (myPtr != NULL){
                    float tempFloat = atof(myPtr);
                    if (tempFloat != 0){
                        nVect.x = tempFloat;
                        myPtr = strtok(NULL, " ");
                        if (myPtr != NULL){
                            nVect.y = atof(myPtr);
                            myPtr = strtok(NULL, " ");
                        }
                        if (myPtr != NULL){
                            nVect.z = atof(myPtr);
                            myPtr = strtok(NULL, " ");
                        }
                    }else{
                        if(myPtr != NULL){
                            vect tempVect;
                            strcpy(tempVect.name,myPtr);
                            tempVect.name[strcspn(tempVect.name, "\n")] = '\0';
                            vect myVectA=findVect(tempVect);
                            myPtr = strtok(NULL, " ");
                            if(!strcmp(myPtr,"+")){
                                myPtr = strtok(NULL, " ");
                                vect myVectB;
                                if(myPtr != NULL){
                                    strcpy(myVectB.name,myPtr);
                                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                                    myVectB=findVect(myVectB);
                                }   
                                tempVect=add(myVectA,myVectB);
                            }
                            if(!strcmp(myPtr,"-")){
                                myPtr = strtok(NULL, " ");
                                vect myVectB;
                                if(myPtr != NULL){
                                    strcpy(myVectB.name,myPtr);
                                    myVectB.name[strcspn(myVectB.name, "\n")] = '\0';
                                    myVectB=findVect(myVectB);
                                }   
                                tempVect=sub(myVectA,myVectB);
                            }
                            nVect.x = tempVect.x;
                            nVect.y = tempVect.y;
                            nVect.z = tempVect.z;
                        }
                    }
                }


                vect tempVect=findVect(nVect);
                if((tempVect.name[0] == '\0')){
                    addVect(nVect);
                }else{
                    replace(nVect,nVect);
                }
                
            } 
        }

        parseEntry();
    }
}

//*************************************************************** */
//Dynamic memory functions

//save the array to a CVS file
void save(){

}

//load a given file
void load(FILE f){
    
}
