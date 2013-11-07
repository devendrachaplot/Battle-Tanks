//Including the predefined header files//
#include <cstdio>
#include "rect.h"
#include "ezwin.h"
#include "bitmap.h"
#include <ctime>
#include <cmath>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cassert>

//Including the files of the program
#include "VariablesDeclaration.h"
#include "BitmapDeclaration.h"
#include "Functions.h"

#include "BmpMove.h"
#include "ClearScreen.h"
#include "MouseClickEvent.h"
#include "WeaponShop.h"
#include "GamePlayFunctions.h"
#include "GamePlayScreen.h"
#include "Screens.h"
#include "Fire.h"
#include "ScoreManagement.h"


using namespace std;

//The main function
int ApiMain(){
    //Initialy the High Scores from the hard disk is loaded to the memory
    int  s,i;
    int High_Score;
    long int FilePos;
    FILE *FilePointer;
    s=sizeof(int);
    
    FilePointer= fopen("high.txt","rb");
    FilePos=0;
    for(i=0;i<10;i++)
    {
    FilePos=i*s;
    fseek(FilePointer,FilePos,SEEK_SET);
    fread(&High_Score,s,1,FilePointer);
    HighScore[i]=High_Score;
    }
    fclose(FilePointer);
    
    //Game begins over here
    int j;
    for(j = 0; j < MAX_WEAPONS; ++j){
        WeaponName[j].SetWindow(PocketTanks);//to set array of BitMaps
        WeaponIcon[j].SetWindow(PocketTanks);
    }
    PocketTanks.Open();//Opens the SimpleWindow PocketTanks.
	//GamePlayScreen();
    GameMenuScreen();//Calls the GameMenuScreen function where the main menu of the game is displayed.
    // Whenever mouse is clicked MouseClickEvent function will be called where 
    PocketTanks.SetMouseClickCallback(MouseClickEvent);	
   
}

