//A comprehensive list of all the functions created by us and used in the program

void ClearScreen();//Clears the screen by erasing all bitmap images.
void DoublePlayerScreen();//This function allows both players to select different types of tanks. 
void GameMenuScreen();//This is the main menu of the game where user can select single player mode, double player mode,instructions, high scores or exit.
int MouseClickEvent(const Position &MousePosition);//Whenever mouse is clicked this function is called. It handles all mouse click events.
void SinglePlayerScreen();//Player selects type of tank and difficulty level after choosing the Single Player mode.
void TerrainGenerator();//Generates a random terrain
void WeaponShop(int,int);//Generates weapon shop where players can select weapons.
void WeaponSelection();//This function lets players to select weapons and stores the selected weapons in array
void GamePlayScreen();//This loads the game screen where gameplay begins.
void SelectWeapon();//User selects which weapon to fire
void CpuSelectWeapon();//This function randomly selects weapons for CPU in Single Player mode.
void CpuInput();//This function randomly selects Angle and Power for generating artificial trajectory for CPU in Single Player mode
void BmpMove(BitMap &Image,const Position &Start,const Position &End);//This function takes care of the movement of buttons on the screen
void wait (float seconds );//This function is used to wait for specified time before executing next command.
void InstructionsScreen();//This function displays the INSTRUCTIONS screen.
void GameLoad ();//Loads terrain, tanks,weapons etc for the game to start.
void FireWeapon();//This function is called when weapon is fired. It calls other functions based on the selected weapon.
void SingleShot();//This function simulates trajectory and calculates damage for weapon Single Shot.
void ThreeShots();//This function simulates trajectory and calculates damage for weapon Three Shot.
void FiveShots();//This function simulates trajectory and calculates damage for weapon Five Shots.
void SpaceLaser();//This function simulates trajectory and calculates damage for weapon Space Laser.
void EarthMover();//This function simulates trajectory and calculates damage for weapon EarthMover.
void Cruiser();//This function simulates trajectory and calculates damage for weapon Cruiser.
void SuperBullet();//This function simulates trajectory and calculates damage for weapon SuperBullet.
void PotShots();//This function simulates trajectory and calculates damage for weapon PotShots.
void MagicHeal();//This function increases health of player by 200units.
void Damage();//Calculates and enforces the changes in damage incurred by the tanks.
void HighScoresScreen();//The function loads High-Score screen.
void CpuWeaponSelection();//This functions selects the weapon to be fired by CPU.
int SaveScore();//This funtion operates on a file to change the existing high-scores.
float DamageCalculator(float XHit,float YHit,float XTank,float ImpactDistance);//
void GameOverScreen();//This function will be called when the game comes to an end, i.e. When the health of a player reaches zero.
