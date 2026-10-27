/*************************************************************
* vMath.h
* Author: Michael Johnston
* Date: 9/23/2026
**************************************************************/
// vector math
vect add(vect a, vect b);
vect sub(vect a, vect b);
vect vMult(vect a, vect b);
vect sMult(vect a, float c);
/*************************************************************/
// vector Array commands
vect addVect(vect d);
    //return added vect value;
vect findVect(vect a);
    //return found vect;
void clear();
    //clear array
vect delete(vect a);
    //return deleted vect
vect replace(vect a,vect d);
    //chosen name is replaced with vect d
    //return old vect
/*************************************************************/
//User Interface commands
void help();
    //give detail about program
void quit();
    //ends the program - program will run until this is called
void list();
    //list the array
/*void clear();*/
    //clear array - arleady defined
void vector();
    //vector operation
        //vector math
        //new vector
        //find vector
void parseEntry();
    //will parse the user input and call appropiate command

////UI memory commands
void save();
//save current file to a CVS file
void load(char f[]);
//load a CVS file and overrides the current array
