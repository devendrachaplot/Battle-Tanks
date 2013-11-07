//global declarartions
float Width=24; //width of the SimpleWindow-can be modified easily
float Height=14;//height of the simple window-also can be modified easily
float TerrainHeight[240]; //array to store randomly generated terrain
SimpleWindow PocketTanks("Pocket Tanks",Width,Height); //SimpleWindow used in the program
Position PhotoPosition;//to set position of bitmap
int n=0;//variable to identify each screen
int Count;
int Player1Weapons[5];
int Player2Weapons[5];
int CpuWeapons[5];
Position MouseClick;
int SelectedWeapon;
float Power, Angle;
int Counter;
int PlayerNumber;
int Tank1Health;
int Tank2Health;
int Tank1Damage;
int Tank2Damage;
int NumberOfPlayers;
int HighScore[10]={};
int Player1Chance[6]={};
int Player2Chance[6]={};
int CpuChance[6]={};
int Wind;
int Weapon1Chance[8]={};
int Weapon2Chance[8]={};
float Tank1Attack=1;
float Tank2Attack=1;
int Difficulty=2;
int Selection1=0;
int Selection2=0;


