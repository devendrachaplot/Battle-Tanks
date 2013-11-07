int MouseClickEvent(const Position &MousePosition){
    MouseClick=MousePosition;

    
    //here we used the global variable n to uniquely identify the screen to decide action
    switch(n){
        case 1:{//this refers to the main menu
            if(Exit.IsInside(MousePosition)){ SaveScore();PocketTanks.Close();}
            else if(SinglePlayer.IsInside(MousePosition)){NumberOfPlayers=1;SinglePlayerScreen();}
            else if(DoublePlayer.IsInside(MousePosition)){NumberOfPlayers=2;DoublePlayerScreen();}
			else if(Instructions.IsInside(MousePosition)){InstructionsScreen();}
            else if(HighScores.IsInside(MousePosition)){HighScoresScreen();}
			break;
        }
        case 2:{//1st player screen
               
            if(Back1.IsInside(MousePosition)){
                GameMenuScreen();
                }
            if((TankNameOffensive1.IsInside(MousePosition)||TankImageOffensive1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=1.2;
                TankNameDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight  ()) , Position(Width/2, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameNormal1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width*4/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/2, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                TankImageNormal1.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width*4/5, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
            }
            else if((TankNameDefensive1.IsInside(MousePosition)||TankImageDefensive1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=0.8;
                TankNameOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameNormal1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width*4/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/5, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                TankImageNormal1.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width*4/5, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);}
            else if((TankNameNormal1.IsInside(MousePosition)||TankImageNormal1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=1;
                TankNameDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/2, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameOffensive1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/5, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                 TankImageDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height/6) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/2, Height/6) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false); 
                }
            if(Continue1.IsInside(MousePosition)){Tank2Attack=1; WeaponShop(1,1);}
            if((DifficultyEasy.IsInside(MousePosition))&&(Selection2==0)){
            Selection2++;
            Difficulty=1;
            PocketTanks.RenderRectangle(Position(Width/2, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width/2, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            PocketTanks.RenderRectangle(Position(Width*4/5, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width*4/5, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            }
            else if((DifficultyMedium.IsInside(MousePosition))&&(Selection2==0)){
            Selection2++;
            Difficulty=2;
            PocketTanks.RenderRectangle(Position(Width/5, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width/5, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            PocketTanks.RenderRectangle(Position(Width*4/5, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width*4/5, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            }
            else if((DifficultyHard.IsInside(MousePosition))&&(Selection2==0)){
            Selection2++;
            Difficulty=3;
            PocketTanks.RenderRectangle(Position(Width/2, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width/2, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            PocketTanks.RenderRectangle(Position(Width/5, Height*5/8) +Position(-0.5*DifficultyEasy.GetWidth(),-0.5*DifficultyEasy.GetHeight()) , Position(Width/5, Height*5/8) +Position(+0.5*DifficultyEasy.GetWidth(),+0.5*DifficultyEasy.GetHeight()), Black, false);
            }
            break;
        }
        case 3:{// 2nd player screen


            if((TankNameOffensive1.IsInside(MousePosition)||TankImageOffensive1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=1.2;
                TankNameDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight  ()) , Position(Width/2, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameNormal1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width*4/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/2, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                TankImageNormal1.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width*4/5, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
            }
            else if((TankNameDefensive1.IsInside(MousePosition)||TankImageDefensive1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=0.8;
                TankNameOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameNormal1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width*4/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/5, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                TankImageNormal1.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width*4/5, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);}
            else if((TankNameNormal1.IsInside(MousePosition)||TankImageNormal1.IsInside(MousePosition))&&(Selection1==0)){
                Selection1++;
                Tank1Attack=1;
                TankNameDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/2, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankNameOffensive1.Erase();                                
                PocketTanks.RenderRectangle(Position(Width/5, Height*3/8) +Position(-0.5*TankNameDefensive1.GetWidth(),-0.5*TankNameDefensive1.GetHeight()) , Position(Width/5, Height*3/8) +Position(+0.5*TankNameDefensive1.GetWidth(),+0.5*TankNameDefensive1.GetHeight()), Black, false);
                TankImageOffensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/5, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false);
                 TankImageDefensive1.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*5/24) +Position(-0.5*TankImageDefensive1.GetWidth(),-0.5*TankImageDefensive1.GetHeight()) , Position(Width/2, Height*5/24) +Position(+0.5*TankImageDefensive1.GetWidth(),+0.5*TankImageDefensive1.GetHeight()), Black, false); 
                }

            
            if((TankNameOffensive2.IsInside(MousePosition)||TankImageOffensive2.IsInside(MousePosition))&&(Selection2==0)){
                Selection2++;
                Tank2Attack=1.2;
                TankNameDefensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight  ()) , Position(Width/2, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankNameNormal2.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()) , Position(Width*4/5, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankImageDefensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width/2, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false);
                TankImageNormal2.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width*4/5, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false);
            }
            else if((TankNameDefensive2.IsInside(MousePosition)||TankImageDefensive2.IsInside(MousePosition))&&(Selection2==0)){
                Selection2++;
                Tank2Attack=0.8;
                TankNameOffensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()) , Position(Width/5, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankNameNormal2.Erase();                                
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()) , Position(Width*4/5, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankImageOffensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width/5, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false);
                TankImageNormal2.Erase();
                PocketTanks.RenderRectangle(Position(Width*4/5, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width*4/5, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false);}
            else if((TankNameNormal2.IsInside(MousePosition)||TankImageNormal2.IsInside(MousePosition))&&(Selection2==0)){
                Selection2++;
                Tank2Attack=1;
                TankNameDefensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()) , Position(Width/2, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankNameOffensive2.Erase();                                
                PocketTanks.RenderRectangle(Position(Width/5, Height*19/24) +Position(-0.5*TankNameDefensive2.GetWidth(),-0.5*TankNameDefensive2.GetHeight()) , Position(Width/5, Height*19/24) +Position(+0.5*TankNameDefensive2.GetWidth(),+0.5*TankNameDefensive2.GetHeight()), Black, false);
                TankImageOffensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/5, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width/5, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false);
                 TankImageDefensive2.Erase();
                PocketTanks.RenderRectangle(Position(Width/2, Height*15/24) +Position(-0.5*TankImageDefensive2.GetWidth(),-0.5*TankImageDefensive2.GetHeight()) , Position(Width/2, Height*15/24) +Position(+0.5*TankImageDefensive2.GetWidth(),+0.5*TankImageDefensive2.GetHeight()), Black, false); 
                }
            if(Back2.IsInside(MousePosition)){GameMenuScreen();}
            else if (Continue2.IsInside(MousePosition)){WeaponShop(2,1);}
            break;
        }
        case 4:
        case 5:
        case 6:{
            WeaponSelection();
            break;
        }
        
        case 7:{
        
            char PowerChar[32], AngleChar[32];
			//GameplayScreen
			//Inputing Power And Angle
			float x = MousePosition.GetXDistance();
			float y = MousePosition.GetYDistance();
			//Displaying Power 
			if(x>=Width/7 && x<=Width*2/7){
				if(y>=Height*26/30 && y<=Height*27/30){
					Power = (x*7/Width - 1)*100;
					sprintf(PowerChar,"%d",(int)Power);
					PocketTanks.RenderRectangle( Position(Width/7, Height*26/30) , Position(Width*2/7, Height*27/30), Black, True);
					PocketTanks.RenderRectangle( Position(Width/7, Height*26/30) , Position(x, Height*27/30), Red, True);
					PocketTanks.RenderRectangle( Position(Width*9/28, Height*26/30) , Position(Width*11/28, Height*27/30), Black, True);
					PocketTanks.RenderText( Position(Width*9/28, Height*26/30) , Position(Width*11/28, Height*27/30), PowerChar, White, Black);
				}
				//Deleting initial nose of tank
				if(y>=Height*28/30 && y<=Height*29/30){ 
                   if (PlayerNumber==1)
                    {PocketTanks.RenderLine(Position(Width/7,TerrainHeight[(int)(Width*10/7)]-0.3),Position(Width/7+0.4*cos((Angle)*3.14159/180),
					TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin((Angle)*3.14159/180)),Black,0.1);}
                   else if (PlayerNumber==2)
                    {PocketTanks.RenderLine(Position(Width*6/7,TerrainHeight[(int)(Width*60/7)]-0.3),Position(Width*6/7-0.4*cos((Angle)*3.14159/180),
					TerrainHeight[(int)(Width*60/7)]-0.3-0.4*sin((Angle)*3.14159/180)),Black,0.1);}
                   
					//Loading Tank BMP for Player1

					PhotoPosition = Position(Width/7 - 0.5*TankBMP1.GetWidth(), TerrainHeight[(int)(Width/7*10)] - TankBMP1.GetHeight());
					TankBMP1.SetPosition(PhotoPosition);
					TankBMP1.Draw();

					//Loading Tank BMP for Player2

					PhotoPosition = Position(Width*6/7 - 0.5*TankBMP2.GetWidth(), TerrainHeight[(int)(Width/7*60)] - TankBMP2.GetHeight());
					TankBMP2.SetPosition(PhotoPosition);
					TankBMP2.Draw();

                    //Displaying Angle
					Angle = (x*7/Width - 1)*180-90;
					sprintf(AngleChar,"%d",(int)Angle);
					PocketTanks.RenderRectangle( Position(Width/7, Height*28/30) , Position(Width*2/7, Height*29/30), Black, True);
					PocketTanks.RenderRectangle( Position(Width/7, Height*28/30) , Position(x, Height*29/30), Blue, True);
					PocketTanks.RenderRectangle( Position(Width*9/28, Height*28/30) , Position(Width*11/28, Height*29/30), Black, True);
					PocketTanks.RenderText( Position(Width*9/28, Height*28/30) , Position(Width*11/28, Height*29/30), AngleChar, White, Black);
                    //to display the pointer
                    if (PlayerNumber==1){
                        PocketTanks.RenderLine(Position(Width/7,TerrainHeight[(int)(Width*10/7)]-0.3),Position(Width/7+0.4*cos((Angle)*3.14159/180),
					    TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin((Angle)*3.14159/180)),Red,0.1);
				    }
                    else if (PlayerNumber==2){
                        PocketTanks.RenderLine(Position(Width*6/7,TerrainHeight[(int)(Width*60/7)]-0.3),Position(Width*6/7-0.4*cos((Angle)*3.14159/180),
					    TerrainHeight[(int)(Width*60/7)]-0.3-0.4*sin((Angle)*3.14159/180)),Blue,0.1);
				    }
                    
				}
			}
			else if(Fire.IsInside(MousePosition)){FireWeapon();}
			else if(Player1Wins.IsInside(MousePosition)|| Player2Wins.IsInside(MousePosition)||CpuWins.IsInside(MousePosition)){
				GameOver.Load("Exit1.xpm");
				PhotoPosition = Position(Width/2-3.0,Height/2-5.0) ;
				GameOver.SetPosition(PhotoPosition);
				GameOver.Draw();
				Yes.Load("yes.xpm");
				PhotoPosition = Position(Width/2-1.3,Height/2-3.5) ;
				Yes.SetPosition(PhotoPosition);
				Yes.Draw();
				No.Load("no.xpm");
				PhotoPosition = Position(Width/2+0.7,Height/2-3.5) ;
				No.SetPosition(PhotoPosition);
				No.Draw();		
			}
			else if (No.IsInside(MousePosition)){ SaveScore();PocketTanks.Close();}		
			else if (Yes.IsInside(MousePosition)){GameMenuScreen();}	
			else {SelectWeapon();}
			break;
		}
		
		case 8:{
			//Instructions Screen
			if(Back3.IsInside(MousePosition)){GameMenuScreen();}
			break;
		}
		case 9:{
			//High Scores Screen
        	if(Back4.IsInside(MousePosition)){GameMenuScreen();}
			break;
		}
        default:{break;}
    }   
    return 1;
}
