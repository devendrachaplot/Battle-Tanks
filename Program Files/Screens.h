//As the name suggests, this is the main menu screen
void GameMenuScreen(){
    n=1; //Unique identifaction index
    //This index actually represents the present screen.
    //This index is used to display screens too.
    Selection1=0; 
    Selection2=0;
    ClearScreen(); //Previously defined function
    //The following Loads bitmap images of various components of the 
    //Game Menu Screen
    Background.Load("Background.xpm");
    Background.SetPosition(Position(0,0));
	Background.Draw();
    //The following codes display the buttons(The bitmaps which says 
    //Single Player, Double Player, etc.)
    SinglePlayer.Load("SinglePlayer.xpm");
    BmpMove(SinglePlayer,Position(-5,Height/8*2),Position(Width/10,Height/8*2));
	
    DoublePlayer.Load("DoublePlayer.xpm");
    BmpMove(DoublePlayer,Position(-5,Height/8*3),Position(Width/10,Height/8*3));

    Instructions.Load("Instructions.xpm");
    BmpMove(Instructions,Position(-5,Height/8*4),Position(Width/10,Height/8*4));
	
    HighScores.Load("HighScores.xpm");
    BmpMove(HighScores,Position(-5,Height/8*5),Position(Width/10,Height/8*5));
	
    Exit.Load("Exit.xpm");
    BmpMove(Exit,Position(-5,Height/8*6),Position(Width/10,Height/8*6));
}



void SinglePlayerScreen(){//Player selects type of tank and difficulty level after choosing the Single Player mode.
    n=2;//Unique identification of this screen
    PocketTanks.Erase(Position(0,0),Width,Height);
    
    ClearScreen();//To clear screen by erasing all the previously loaded bitmaps
    
    //Loadinh Bitmaps for the Tanks Selection and for Difficulty level selection
    TankTypeScreen.Load("TankTypeScreen.xpm");
    TankTypeScreen.SetPosition(Position(-1.5,-1.5));
    TankTypeScreen.Draw();
    //Loading various tank bitmaps
    TankNameOffensive1.Load("TankNameOffensive.xpm");
    TankNameOffensive1.SetPosition(Position(Width/5, Height*3/8) +Position(-0.5*TankNameOffensive1.GetWidth(),-0.5*TankNameOffensive1.GetHeight()));
	TankNameOffensive1.Draw();
    
    TankNameDefensive1.Load("TankNameDefensive.xpm");
    TankNameDefensive1.SetPosition(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()));
	TankNameDefensive1.Draw();
	
    TankNameNormal1.Load("TankNameNormal.xpm");
    TankNameNormal1.SetPosition(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameNormal1.GetWidth(),-0.5*TankNameNormal1.GetHeight()));
	TankNameNormal1.Draw();

    TankImageOffensive1.Load("TankImageOffensive.xpm");
    TankImageOffensive1.SetPosition(Position(Width/5, Height/6) +Position(-0.5*TankImageOffensive1.GetWidth(),-0.5*TankImageOffensive1.GetHeight()));
	TankImageOffensive1.Draw();
    
    TankImageDefensive1.Load("TankImageDefensive.xpm");
    TankImageDefensive1.SetPosition(Position(Width/2, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()));
	TankImageDefensive1.Draw();
	
    TankImageNormal1.Load("TankImageNormal.xpm");
    TankImageNormal1.SetPosition(Position(Width*4/5, Height/6) +Position(-0.5*TankImageNormal1.GetWidth(),-0.5*TankImageNormal1.GetHeight()));
	TankImageNormal1.Draw();
	//Loading the difficulty level bitmaps
	SelectDifficulty.Load("SelectDifficulty.xpm");
    SelectDifficulty.SetPosition(Position(Width/2, Height/2) +Position(-0.5*SelectDifficulty.GetWidth(),-0.5*SelectDifficulty.GetHeight()));
	SelectDifficulty.Draw();
	
	DifficultyEasy.Load("DifficultyEasy.xpm");
    DifficultyEasy.SetPosition(Position(Width/5, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()));
	DifficultyEasy.Draw();
	
	DifficultyMedium.Load("DifficultyMedium.xpm");
    DifficultyMedium.SetPosition(Position(Width/2, Height*5/8) +Position(-0.5*DifficultyMedium.GetWidth(),-0.5*DifficultyMedium.GetHeight()));
	DifficultyMedium.Draw();

    DifficultyHard.Load("DifficultyHard.xpm");
    DifficultyHard.SetPosition(Position(Width*4/5, Height*5/8) +Position(-0.5*DifficultyHard.GetWidth(),-0.5*DifficultyHard.GetHeight()));
	DifficultyHard.Draw();

    Back1.Load("Back1.xpm");
    PhotoPosition = Position(Width/4,Height/8*7) + Position(-0.5*Back1.GetWidth(),-0.5*Back1.GetHeight());
    Back1.SetPosition(PhotoPosition);
	Back1.Draw();
	
    Continue1.Load("Continue1.xpm");
    PhotoPosition = Position(Width*3/8,Height/8*7) + Position(-0.5*Continue1.GetWidth(),-0.5*Continue1.GetHeight());
    Continue1.SetPosition(PhotoPosition);
	Continue1.Draw();
	

}



void DoublePlayerScreen(){//This function allows both players to select different types of tanks.
    n=3; //This variable as mentioned earlier defines the screen to be displayed.

    ClearScreen();//Erase all previous Bitmaps
    //loading the required bitmaps for the buttons

    PocketTanks.RenderRectangle(Position(0,0),Position(Width,Height),Black,True);

    CaptionPlayer1.Load("CaptionPlayer1.xpm");
    CaptionPlayer1.SetPosition(Position(Width/2, Height/20) +Position(-0.5*CaptionPlayer1.GetWidth(),-0.5*CaptionPlayer1.GetHeight()));
	CaptionPlayer1.Draw();

    CaptionPlayer2.Load("CaptionPlayer2.xpm");
    CaptionPlayer2.SetPosition(Position(Width/2, Height*9.5/20) +Position(-0.5*CaptionPlayer2.GetWidth(),-0.5*CaptionPlayer2.GetHeight()));
	CaptionPlayer2.Draw();

    TankNameOffensive1.Load("TankNameOffensive.xpm");
    TankNameOffensive1.SetPosition(Position(Width/5, Height*3/8) +Position(-0.5*TankNameOffensive1.GetWidth(),-0.5*TankNameOffensive1.GetHeight()));
	TankNameOffensive1.Draw();
    
    TankNameDefensive1.Load("TankNameDefensive.xpm");
    TankNameDefensive1.SetPosition(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()));
	TankNameDefensive1.Draw();
	
    TankNameNormal1.Load("TankNameNormal.xpm");
    TankNameNormal1.SetPosition(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameNormal1.GetWidth(),-0.5*TankNameNormal1.GetHeight()));
	TankNameNormal1.Draw();

    TankImageOffensive1.Load("TankImageOffensive.xpm");
    TankImageOffensive1.SetPosition(Position(Width/5, Height*5/24) +Position(-0.5*TankImageOffensive1.GetWidth(),-0.5*TankImageOffensive1.GetHeight()));
	TankImageOffensive1.Draw();
    
    TankImageDefensive1.Load("TankImageDefensive.xpm");
    TankImageDefensive1.SetPosition(Position(Width/2, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()));
	TankImageDefensive1.Draw();
	
    TankImageNormal1.Load("TankImageNormal.xpm");
    TankImageNormal1.SetPosition(Position(Width*4/5, Height*5/24) +Position(-0.5*TankImageNormal1.GetWidth(),-0.5*TankImageNormal1.GetHeight()));
	TankImageNormal1.Draw();

    TankNameOffensive2.Load("TankNameOffensive.xpm");
    TankNameOffensive2.SetPosition(Position(Width/5, Height*19/24) +Position(-0.5*TankNameOffensive2.GetWidth(),-0.5*TankNameOffensive2.GetHeight()));
	TankNameOffensive2.Draw();
    
    TankNameDefensive2.Load("TankNameDefensive.xpm");
    TankNameDefensive2.SetPosition(Position(Width/2, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()));
	TankNameDefensive2.Draw();
	
    TankNameNormal2.Load("TankNameNormal.xpm");
    TankNameNormal2.SetPosition(Position(Width*4/5, Height*19/24) +Position(-0.5*TankNameNormal2.GetWidth(),-0.5*TankNameNormal2.GetHeight()));
	TankNameNormal2.Draw();

    TankImageOffensive2.Load("TankImageOffensive.xpm");
    TankImageOffensive2.SetPosition(Position(Width/5, Height*15/24) +Position(-0.5*TankImageOffensive2.GetWidth(),-0.5*TankImageOffensive2.GetHeight()));
	TankImageOffensive2.Draw();
    
    TankImageDefensive2.Load("TankImageDefensive.xpm");
    TankImageDefensive2.SetPosition(Position(Width/2, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()));
	TankImageDefensive2.Draw();
	
    TankImageNormal2.Load("TankImageNormal.xpm");
    TankImageNormal2.SetPosition(Position(Width*4/5, Height*15/24) +Position(-0.5*TankImageNormal2.GetWidth(),-0.5*TankImageNormal2.GetHeight()));
	TankImageNormal2.Draw();

    
    
    Back2.Load("Back2.xpm"); 
    PhotoPosition = Position(Width/4,Height/8*7.5) + Position(-0.5*Back2.GetWidth(),-0.5*Back2.GetHeight());
    Back2.SetPosition(PhotoPosition);
	Back2.Draw();
	//The following is the code for loading bitmaps for second player screem
    Continue2.Load("Continue2.xpm");
    PhotoPosition = Position(Width/4*3,Height/8*7.5) + Position(-0.5*Continue2.GetWidth(),-0.5*Continue2.GetHeight());
    Continue2.SetPosition(PhotoPosition);
	Continue2.Draw();
	
}


//Function for displaying Instructions
void InstructionsScreen(){
	
	n=8;//n=8 represents instruction screen
	ClearScreen();
	//Loads the main instruction Bitmap
	InstructionsWindow.Load("InstructionsWindow.xpm");
    InstructionsWindow.SetPosition(Position(0,0));
	InstructionsWindow.Draw();
	//Loading the "BACK" button.
	Back3.Load("Back3.xpm"); 
    PhotoPosition = Position(Width/24*9.5,Height/8*7.1) + Position(-0.5*Back3.GetWidth(),-0.5*Back3.GetHeight());
    Back3.SetPosition(PhotoPosition);
	Back3.Draw();

}

//Function for displaying High Scores
void HighScoresScreen(){
	n=9;//n=9 represents High Score screen.
    ClearScreen();
	//displaing the background
	HighScoresBackground.Load("HighScoresScreen.xpm");
	HighScoresBackground.SetPosition(Position(0,0));
	HighScoresBackground.Draw();

	//Displaying HighScores of various players
    
 	//Displaying the High Scores (int)	after converting them to string
	for ( int i=0;i<10;i++){string  Result;
	stringstream convert;   // stream used for the conversion

    convert << HighScore[i];      // insert the textual representation of 'HighScore' in the characters in the stream

	Result = convert.str(); // set 'Result' to the contents of the stream
	PocketTanks.RenderText(Position(Width*2/3-0.5*HighScores.GetWidth(),Height/100*(28 + 6*i)-0.5*HighScores.GetHeight()),Position(Width*2/3 + 0.5*HighScores.GetWidth(),Height/100*(28 + 6*i)-0.5*HighScores.GetHeight()) ,
	 Result, Black);
	}
	//loading the required bitmaps for the buttons
    Back4.Load("Back4.xpm"); 
    PhotoPosition = Position(Width*2/3,Height/8*7.1) + Position(-0.5*Back4.GetWidth(),-0.5*Back4.GetHeight());
    Back4.SetPosition(PhotoPosition);
	Back4.Draw();
}

