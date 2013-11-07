//this fuction is used to clear the screen
// in this, we clear all the bitmaps used in the project(so far)
//this was done because erasing a bitmap  already erased does not give an error
void ClearScreen(){
	PocketTanks.Erase(Position(0,0),Width,Height);
	SinglePlayer.Erase();
	DoublePlayer.Erase();
	Sound.Erase();
	Exit.Erase();
	HighScores.Erase();
	Back1.Erase();
	Back2.Erase();
	Continue1.Erase();
	Continue2.Erase();
	Instructions.Erase();
	InstructionsWindow.Erase();
	Back3.Erase();
	Background.Erase();
	Sky.Erase();
	TerrainTexture.Erase();
	WeaponShopBmp.Erase();
	Player1.Erase();
	Player2.Erase();
	Select5Weapons.Erase();
	InputBackground.Erase();
	TankBMP1.Erase();
	TankBMP2.Erase();
	PowerBMP.Erase();
	AngleBMP.Erase();
	Fire.Erase();
	W.Erase();
	ProjectileErase.Erase();
	Player1Wins.Erase();
	Player2Wins.Erase();
	CpuWins.Erase();
	GameOver.Erase();
	Yes.Erase();
	No.Erase();
	Back4.Erase();
	HighScoresBackground.Erase();
	for (int i=0;i<MAX_WEAPONS;i++){
		WeaponName[i].Erase();
		WeaponIcon[i].Erase();
	}

}
