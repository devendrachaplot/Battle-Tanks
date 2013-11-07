void GameLoad(){
    srand((unsigned int) time(0));
    ClearScreen();	

	Sky.SetPosition(Position(0,0));
	Sky.Draw();
	
    float k=0;
    for(int j=0;j<10*Width;j+=1,k+=0.1){
	//colouring the terrain with rectangles
		TerrainTexture.SetPosition(Position(k,TerrainHeight[j]));
		TerrainTexture.Draw();
	}
	
	//loading BMP for Background of Input Section

    PhotoPosition = Position(0,Height*5/6);
    InputBackground.SetPosition(PhotoPosition);
	InputBackground.Draw();
	
	//Drawing Rectangles for velocity of projection of weapons

	PhotoPosition = Position(Width/22,Height/60*53) + Position(0,-0.5*PowerBMP.GetHeight());
    PowerBMP.SetPosition(PhotoPosition);
	PowerBMP.Draw();

	PocketTanks.RenderRectangle( Position(Width/7, Height*26/30) , Position(Width*2/7, Height*27/30), Black,True);
	PocketTanks.RenderRectangle( Position(Width*9/28, Height*26/30) , Position(Width*11/28, Height*27/30), Black,True);
	PocketTanks.RenderText( Position(Width*9/28, Height*26/30) , Position(Width*11/28, Height*27/30), "0", White, Black);
	
	//drawing rectangles for angle of projection of the weapon

	PhotoPosition = Position(Width/22,Height/60*57) + Position(0,-0.5*AngleBMP.GetHeight());
    AngleBMP.SetPosition(PhotoPosition);
	AngleBMP.Draw();

	PocketTanks.RenderRectangle( Position(Width/7, Height*28/30) , Position(Width*2/7, Height*29/30), Black,True);
	PocketTanks.RenderRectangle( Position(Width*9/28, Height*28/30) , Position(Width*11/28, Height*29/30), Black,True);
	PocketTanks.RenderText( Position(Width*9/28, Height*28/30) , Position(Width*11/28, Height*29/30), "0", White, Black);


	Fire.SetPosition(Position(Width*24/28, Height *27/30));
	Fire.Draw();

    char HealthChar[5]; 
    char WindChar[32];  
    
    
    Wind=rand()%21-10;
    sprintf(WindChar,"Wind   %d",Wind);
    PocketTanks.RenderRectangle( Position(Width*3/7, Height/30) , Position(Width*4/7, Height*2/30), Black, True);
	PocketTanks.RenderText( Position(Width*3/7, Height/30) , Position(Width*4/7, Height*2/30), WindChar, White, Black);
	if(Wind>0){PocketTanks.RenderRectangle( Position(Width/2, Height*2/30) , Position(Width/2+Wind/4.0, Height*2.5/30), Red, True);}
	else if(Wind<0){PocketTanks.RenderRectangle( Position(Width/2+Wind/4.0, Height*2/30) , Position(Width/2, Height*2.5/30), Blue, True);}
    
    
	//Loading Tank BMP for Player1

	PhotoPosition = Position(Width/7 - 0.5*TankBMP1.GetWidth(), TerrainHeight[(int)(Width/7*10)] - TankBMP1.GetHeight());
    TankBMP1.SetPosition(PhotoPosition);
	TankBMP1.Draw();

	//Loading Tank BMP for Player2

	PhotoPosition = Position(Width*6/7 - 0.5*TankBMP2.GetWidth(), TerrainHeight[(int)(Width/7*60)] - TankBMP2.GetHeight());
    TankBMP2.SetPosition(PhotoPosition);
	TankBMP2.Draw();
	
	//Showing Health of Player 1 Tank
	sprintf(HealthChar,"%d",Tank1Health);
	PocketTanks.RenderRectangle( Position(Width/7, Height/30) , Position(Width*2/7, Height*2/30), Black, True);
	PocketTanks.RenderText( Position(Width/7, Height/30) , Position(Width*2/7, Height*2/30), HealthChar, White, Black);
	
	//Showing Health of Player 2 Tank
	sprintf(HealthChar,"%d",Tank2Health);
	PocketTanks.RenderRectangle( Position(Width*5/7, Height/30) , Position(Width*6/7, Height*2/30), Black, True);
	PocketTanks.RenderText( Position(Width*5/7, Height/30) , Position(Width*6/7, Height*2/30), HealthChar, White, Black);

	//loop to load bitmaps of the selected weapons 	
		    WeaponIcon[0].Load("WeaponIcon0.xpm");
		    WeaponIcon[0].SetPosition( Position(Width*(12)/28 - 0.5*WeaponIcon[0].GetWidth(), Height*26/30 - 0.4*WeaponIcon[0].GetHeight()));
		    WeaponIcon[0].Draw();
	char WeaponIconNumber[16];
	if(PlayerNumber==1){
	    for(int i=0,j=2; i<5; i++, j+=2){
		     if (Player1Chance[i]==0){
			    sprintf(WeaponIconNumber,"WeaponIcon%d.xpm",Player1Weapons[i]);
				WeaponIcon[Player1Weapons[i]].Load(WeaponIconNumber);
				WeaponIcon[Player1Weapons[i]].SetPosition(Position(Width*(12+j)/28 - 0.5*WeaponIcon[Player1Weapons[i]].GetWidth(), Height*26/30 - 0.4*WeaponIcon[Player1Weapons[i]].GetHeight()));
				WeaponIcon[Player1Weapons[i]].Draw();
			 }
        }
	}
    else if(PlayerNumber==2){
		 for(int i=0,j=2; i<5; i++, j+=2){
			if (Player2Chance[i]==0){	
				sprintf(WeaponIconNumber,"WeaponIcon%d.xpm",Player2Weapons[i]);
				WeaponIcon[Player2Weapons[i]].Load(WeaponIconNumber);
				WeaponIcon[Player2Weapons[i]].SetPosition(Position(Width*(12+j)/28 - 0.5*WeaponIcon[Player2Weapons[i]].GetWidth(), Height*26/30 - 0.4*WeaponIcon[Player2Weapons[i]].GetHeight()));
				WeaponIcon[Player2Weapons[i]].Draw();
			}	    
		}
	}
	else{
		for(int i=0,j=2; i<5; i++, j+=2){
			if (CpuChance[i]==0){	
				sprintf(WeaponIconNumber,"WeaponIcon%d.xpm",CpuWeapons[i]);
				WeaponIcon[CpuWeapons[i]].Load(WeaponIconNumber);
				WeaponIcon[CpuWeapons[i]].SetPosition(Position(Width*(12+j)/28 - 0.5*WeaponIcon[CpuWeapons[i]].GetWidth(), Height*26/30 - 0.4*WeaponIcon[CpuWeapons[i]].GetHeight()));
				WeaponIcon[CpuWeapons[i]].Draw();
			}	    
		}
	}
	
	SelectedWeapon=0;
	WeaponName[0].Load("WeaponName0.xpm");
	WeaponName[0].SetPosition(Position(Width*18/28 - 0.5*WeaponName[0].GetWidth(), Height*28/30 - 0.3*WeaponName[0].GetHeight()));
    WeaponName[0].Draw();
    
    if(!Tank1Health||!Tank2Health){GameOverScreen();}//when the game is over
    
    else if (PlayerNumber==0){//cpu's turn
		CpuSelectWeapon();
		CpuInput();
		FireWeapon();
	}
}


void SelectWeapon (){
	char IconBmp[20];
    char NameBmp[20];
    int j;
    if(WeaponIcon[0].IsInside(MouseClick)){
        WeaponName[0].Load("WeaponName0.xpm"); 
		WeaponName[0].SetPosition(Position(Width*18/28 - 0.5*WeaponName[0].GetWidth(), Height*28/30 - 0.3*WeaponName[0].GetHeight()));
		WeaponName[0].Draw();
		SelectedWeapon = 0;
	}
	else{
        for(int i=0;i<=8;i++){
        
            sprintf(IconBmp,"WeaponIcon%d.xpm",i);
            sprintf(NameBmp,"WeaponName%d.xpm",i);
		    if(WeaponIcon[i].IsInside(MouseClick)){
		            if (PlayerNumber==1){
					    for ( j=0;j<5;j++){
						    if (Player1Weapons[j]==i)
						    break;
                        }
					    if (j<5&&Player1Chance[j]==0){	
						    WeaponName[i].Load(NameBmp); 
						    WeaponName[i].SetPosition(Position(Width*18/28 - 0.5*WeaponName[i].GetWidth(), Height*28/30 - 0.3*WeaponName[i].GetHeight()));
						    WeaponName[i].Draw();
						    SelectedWeapon = i;
						    break;
				        }
			     	}
				    else if (PlayerNumber==2){
					    for ( j=0;j<5;j++){
						    if (Player2Weapons[j]==i)
						    break;
                        }
					    if (j<5&&Player2Chance[j]==0){	
						    WeaponName[i].Load(NameBmp); 
						    WeaponName[i].SetPosition(Position(Width*18/28 - 0.5*WeaponName[i].GetWidth(), Height*28/30 - 0.3*WeaponName[i].GetHeight()));
						    WeaponName[i].Draw();
						    SelectedWeapon = i;
						    break;
				        }
			     	}
       		}
	    }
    }
}

void CpuSelectWeapon(){
	int i;
	for(i=0;i<5;i++){
		if(CpuChance[i]==0){
			SelectedWeapon=CpuWeapons[i];
			CpuChance[i]++;
			break;
		}
		if(i==5){SelectedWeapon=0;}	
	}
}	

void CpuInput(){//AI
	srand((unsigned int) time(0));
	float x,y,theta,velocity, t, g;
	g = 50;
	for(int i=0;i<15;i++){
		Power = rand()%50+25;
		for(Angle=90;Angle>10;Angle--){
			x = (Width*6/7-0.4*cos(theta));
			y = (TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));			
			velocity = Power*0.7;
			theta = Angle*3.14159/180;
			t=0;
			while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){
				x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2;
				y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;
				t += 0.01;
				}
			if(abs(x-Width/7)<0.3){break;}
		}
		if(abs(x-Width/7)<0.3){break;}
	}
	//if (NumberOfPlayers==2) {Angle+=rand()%11-5;}
	//if (NumberOfPlayers==1){
	    switch(Difficulty){
	        case 1: {Angle+=rand()%21-10;break;}
	        case 2: {Angle+=rand()%17-8;break;}
	        case 3: {Angle+=rand()%11-5;break;}
	    }
}
