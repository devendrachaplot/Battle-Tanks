void FireWeapon()//This function is called when weapon is fired. It calls other functions based on the selected weapon
  {int k; //called when the fire button is clicked
    Tank1Damage=0;
    Tank2Damage=0;
    for ( k=0;k<5;k++){
			if ((Player1Weapons[k]==SelectedWeapon)&&(PlayerNumber==1)){ //To identify the weapon.
				Player1Chance[k]++; 
                break;
				
			}
			else if ((Player2Weapons[k]==SelectedWeapon)&&(PlayerNumber==2)){
				 Player2Chance[k]++;
				 break;
			}
	}	
	switch(SelectedWeapon){
        case 0:{ //default weapon, hence no condition
                    SingleShot();break;}
        //if the conditions for a particular condition are satisfied, the corresponding functions are called
        case 1:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
					ThreeShots();break;}
        case 2:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    FiveShots();break;}
        case 3:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    SpaceLaser();break;}
        case 4:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    EarthMover();break;}
        case 5:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    Cruiser();break;}
        case 6:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    SuperBullet();break;}
        case 7:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    PotShots();break;}
        case 8:{ if (((PlayerNumber==1)&&(Player1Chance[k]==1))||((PlayerNumber==2)&&(Player2Chance[k]==1))||PlayerNumber==0)
                    MagicHeal();break;}
    }
}

void Damage(){//Function to calculate the damage caused by a particular weapon
	
	//This takes care of tank's type i.e.offensive or defensive or normal:
	//and calculats damage accordingly
	if(PlayerNumber==1){
	    Tank1Health-=Tank1Attack*Tank1Attack*Tank1Damage;//if tank1 hits itself
	    Tank2Health-=Tank1Attack*Tank2Attack*Tank2Damage;//if tank1 hits tank2
    }
    else if(PlayerNumber==2){
        Tank1Health-=Tank2Attack*Tank1Attack*Tank1Damage;//if tank2 hits tank1
	    Tank2Health-=Tank2Attack*Tank2Attack*Tank2Damage;//if tank2 hits itself
    }
    else if(PlayerNumber==0){
        Tank1Health-=Tank2Attack*Tank1Attack*Tank1Damage;//if tank2 hits tank1
	    Tank2Health-=Tank2Attack*Tank2Attack*Tank2Damage;//if tank2 hits itself
    }
    /*The above logic can be explained as follows:
    Consider the case when tank1 hits tank2 where tank1 is offensive and 
    tank2 is defensive. In such a case Tank1Attack=1.2 and Tank2Attack=0.8.
    The damage inflicted on tank2 is 1.2*0.8 i.e it is increased 
    by a factor of 1.2 because of offense of tank1,
    and it is multiplied by 0.8 to take into account tank2's defense.
    */
	

     
    if(Tank1Health<0){Tank1Health=0;}//To avoid negative health
    if(Tank2Health<0){Tank2Health=0;}
    if(NumberOfPlayers==2){PlayerNumber=PlayerNumber%2+1;}//To change turn in multiplayer. 1 changes to 2 and 2 to 1.
	else{
		if(PlayerNumber==1){PlayerNumber=0;}//To switch chance between player1 and cpu(player0)
		else{PlayerNumber=1;}
	}
    GameLoad();//To continue with the game..
	
			

}
/*The functions that follow describe the properties of each weapon.
The codes of various weapons has beem described in the subsequent lines.
For functions with more than one shot, similar code is used repeatedly as required.
All of these follow the same sequence as the first one
*/
void SingleShot(){//This function simulates trajectory and calculates damage for weapon Single Shot.
    float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	//the required scaling to fit the screen
	theta = Angle*3.14159/180;//in raidans
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));//to calculate x and y
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){//To simulate the trajectory of shots	
		t+=0.005;
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
      //The function uses simple physics laws mapped into the screen by changing some scaling factors  
		
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
        W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();

	}
	//This calcuates the damage incurred by the tank 
	Tank1Damage+=100*DamageCalculator(x,y,Width/7,1.5);//To calculate damage
	Tank2Damage+=100*DamageCalculator(x,y,Width*6/7,1.5);
    
    int Begin=(x-0.4)>0?(x-0.4)*10.0:0;
    for(int m=Begin;m<=(x+0.4)*10&&m<Width*10;m++){
	    if(TerrainHeight[m]<(sqrt(0.16-((m/10.0-x)*(m/10.0-x)))+y-0.2)){TerrainHeight[m]=sqrt(0.16-((m/10.0-x)*(m/10.0-x)))+y-0.2;}
	    if(TerrainHeight[m]>Height*5/6){TerrainHeight[m]=Height*5/6;}
    }
    Damage();//To apply the changes in the health 	
}



void ThreeShots(){//Three shots weapon shoots three bullets at the same time
//This function simulates trajectory and calculates damage for weapon Three Shots.
    float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	 //The function uses simple physics laws mapped into the screen by changing some scaling factors  
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		t+=0.005;
      //The next part shows how the projectile moves in the space 
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1-t,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1+t,y-0.1));
		W.Draw();
		W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1-t,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1+t,y-0.1));
		ProjectileErase.Draw();

	}
	//This part calculates the damage caused to each of the tanks
	Tank1Damage+=200*DamageCalculator(x,y,Width/7,0.5);
	Tank2Damage+=200*DamageCalculator(x,y,Width*6/7,0.5);
	Tank1Damage+=200*DamageCalculator(x+t,y,Width/7,0.5);
	Tank2Damage+=200*DamageCalculator(x+t,y,Width*6/7,0.5);
	Tank1Damage+=200*DamageCalculator(x-t,y,Width/7,0.5);
	Tank2Damage+=200*DamageCalculator(x-t,y,Width*6/7,0.5);
    
    Damage();//Applies the damage to the tanks
}


void FiveShots(){//Five Shots weapong fires Five bullets at the same time 
    //This function simulates the trajectory of the five shots weapon
    float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	 //The function also uses simple physics laws mapped into the screen by changing some scaling factors  
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		t+=0.005;
   //The next part shows how the projectiles moves in the space 
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1-t,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1-2*t,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1+t,y-0.1));
		W.Draw();
		W.SetPosition(Position(x-0.1+2*t,y-0.1));
		W.Draw();
		W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1-t,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1-2*t,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1+t,y-0.1));
		ProjectileErase.Draw();
		ProjectileErase.SetPosition(Position(x-0.1+2*t,y-0.1));
		ProjectileErase.Draw();

	}
	//Damage calculation 
	Tank1Damage+=175*DamageCalculator(x,y,Width/7,0.5);
	Tank2Damage+=175*DamageCalculator(x,y,Width*6/7,0.5);
	Tank1Damage+=175*DamageCalculator(x+t,y,Width/7,0.5);
	Tank2Damage+=175*DamageCalculator(x+t,y,Width*6/7,0.5);
	Tank1Damage+=175*DamageCalculator(x+2*t,y,Width/7,0.5);
	Tank2Damage+=175*DamageCalculator(x+2*t,y,Width*6/7,0.5);
	Tank1Damage+=175*DamageCalculator(x-t,y,Width/7,0.5);
	Tank2Damage+=175*DamageCalculator(x-t,y,Width*6/7,0.5);
	Tank1Damage+=175*DamageCalculator(x-2*t,y,Width/7,0.5);
	Tank2Damage+=175*DamageCalculator(x-2*t,y,Width*6/7,0.5);
    
    Damage();//Applying damage to the tanks
}
void SpaceLaser(){//This weapon produces a beam of yellow laser which flashes on the screen
   //and causes damage to the tank. This function simulates the trajectory and appearance of the 
   //SpaceLaser weapon
 	float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	//The function also uses simple physics laws mapped into the screen by changing some scaling factors
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		t+=0.005;
        
	//The motion of the weapon is shown here	
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
        W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();

	}
	for (int j=0;j<5;j++){//This shows how the weapon attacks.
	//The laser keeps blinking at the position where the projectile hits
	//the terrain.
		for(int i=0;i<999;i++){
		    PocketTanks.RenderRectangle( Position(x-1,0) , Position(x+1, y), Yellow, True);

	        PhotoPosition = Position(Width/7 - 0.5*TankBMP1.GetWidth(), TerrainHeight[(int)(Width/7*10)] - TankBMP1.GetHeight());
            TankBMP1.SetPosition(PhotoPosition);
	        TankBMP1.Draw();

	        PhotoPosition = Position(Width*6/7 - 0.5*TankBMP2.GetWidth(), TerrainHeight[(int)(Width/7*60)] - TankBMP2.GetHeight());
            TankBMP2.SetPosition(PhotoPosition);
	        TankBMP2.Draw();
	    }	
		for(int i=0;i<999;i++){
		    PocketTanks.RenderRectangle( Position(x-1,0) , Position(x+1, y), Black, True);
		    PhotoPosition = Position(Width/7 - 0.5*TankBMP1.GetWidth(), TerrainHeight[(int)(Width/7*10)] - TankBMP1.GetHeight());
            TankBMP1.SetPosition(PhotoPosition);
	        TankBMP1.Draw();

	        PhotoPosition = Position(Width*6/7 - 0.5*TankBMP2.GetWidth(), TerrainHeight[(int)(Width/7*60)] - TankBMP2.GetHeight());
            TankBMP2.SetPosition(PhotoPosition);
	        TankBMP2.Draw();
	    }		
	}
	 //Calculating damage accoding to the proximity of target from the landing point of the weapon
    if(abs(Width/7-x)<1.25){Tank1Damage+=200;}
    if(abs(Width*6/7-x)<1.25){Tank2Damage+=200;}
    Damage();//Applying damage
}


void EarthMover(){//The Earthmover destroys the terrain quite badly and takes the tank to a lower physical level
   //if it hits at the right spot.The function describes the mechanism to trigger the trajectory of the weapon
   float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	//The function also uses simple physics laws mapped into the screen by changing some scaling factors
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		t+=0.005;
        
		//The terrain gets damaged in a circular manner with centre at the point of landing of the missile.
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
        W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();

	}
	//Calculating the damage incurred by the tanks
	Tank1Damage+=300*DamageCalculator(x,y,Width/7,3);
	Tank2Damage+=300*DamageCalculator(x,y,Width*6/7,3);
   //Destroying the terrain 
	int Begin=(x-2.9)>0?(x-2.9)*10.0:0;
	for(int m=Begin;m<=(x+2.9)*10&&m<Width*10;m++){
	    if(TerrainHeight[m]<(sqrt(9.0-((m/10.0-x)*(m/10.0-x)))+y)){TerrainHeight[m]=sqrt(9.0-((m/10.0-x)*(m/10.0-x)))+y;}
	    if(TerrainHeight[m]>Height*5/6){TerrainHeight[m]=Height*5/6;}
    }
    
    Damage();	//Applying the damage caused.
}


void Cruiser(){
   //The weapon Criuser is an along the ground weapon.
   //It goes along the terrain for a distance and then explodes.
   //This function simulates trajectory and calculates damage for weapon Cruiser 
   float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	//The function also uses simple physics laws mapped into the screen by changing some scaling factors
	while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		t+=0.005;
        
		//Traversal of the weapon
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
        W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();

	}
    if (PlayerNumber==1)
     {for (int i=0;i<50;i++)
      { for(int j=0;j<999;j++)
        PocketTanks.RenderLine(Position(x,TerrainHeight[(int)(x*10)]),Position(x,TerrainHeight[(int)(x*10)]),Red,0.2);
        x=x+0.1;
        if(abs(x-Width*6/7)<=0.4){break;}
      }
     }
	else 
	  {for (int i=0;i<50;i++)
		  { for(int j=0;j<999;j++)
		    PocketTanks.RenderLine(Position(x,TerrainHeight[(int)(x*10)]),Position(x,TerrainHeight[(int)(x*10)]),Red,0.2);
		    x=x-0.1;
		    if(abs(x-Width/7)<=0.4){break;}
		  }
	   }
   //Calculating damage based on proximity to landing point.
    if( (PlayerNumber==1)&&(abs(x-Width*6/7)<=1)){Tank2Damage+=200;}
    if((PlayerNumber==2)&&(abs(Width/7-x)<=1)){Tank1Damage+=200;}
	else  if((PlayerNumber==0)&&(abs(Width/7-x)<=1)){Tank1Damage+=200;}
	
	int Begin=(x-0.9)>0?(x-0.9)*10.0:0;
    for(int m=Begin;m<=(x+0.9)*10&&m<Width*10;m++){
	    if(TerrainHeight[m]<(sqrt(1.0-((m/10.0-x)*(m/10.0-x)))+y)){TerrainHeight[m]=sqrt(1.0-((m/10.0-x)*(m/10.0-x)))+y;}
	    if(TerrainHeight[m]>Height*5/6){TerrainHeight[m]=Height*5/6;}
    }
    Damage();//Applying damage to tanks

}


void SuperBullet(){//Super bullet is a weapon which defies gravity and also can go through the terrain
    //This function simulates trajectory and calculates damage for weapon SuperBullet.
    float x,y,theta, t;
	if (PlayerNumber==0){
		do{
				for(Angle=-30;Angle<30;Angle++){
				theta = Angle*3.14159/180;
				x = (Width*6/7-0.4*cos(theta));
				y = (TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));			
				
				t=0;
				while(x<(Width)&&x>0&&y>0&&y<Height*5/6){
					x = Width*6/7-(0.5+t)*cos(theta);
					y=TerrainHeight[(int)(Width*10*6/7)]-0.25-(0.5+t)*sin(theta);
					t += 0.1;
					if((abs(Width/7-x)<0.5)&&(TerrainHeight[(int)(Width*10/7)]-y>0)&&(TerrainHeight[(int)(Width*10/7)]-y<0.25)){break;}
					}
				if((abs(Width/7-x)<0.5)&&(TerrainHeight[(int)(Width*10/7)]-y>0)&&(TerrainHeight[(int)(Width*10/7)]-y<0.25)){break;}
				}
				if((abs(Width/7-x)<0.5)&&(TerrainHeight[(int)(Width*10/7)]-y>0)&&(TerrainHeight[(int)(Width*10/7)]-y<0.25)){break;}
		}while((abs(Width/7-x)<0.5)&&(TerrainHeight[(int)(Width*10/7)]-y>0)&&(TerrainHeight[(int)(Width*10/7)]-y<0.25));
	}
	switch(Difficulty){
	        case 1: {Angle+=rand()%7-3;break;}
	        case 2: {Angle+=rand()%5-2;break;}
	        case 3: {Angle+=rand()%3-1;break;}
	    }
	theta = Angle*3.14159/180;
	t=0;
	x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	W.Load("W.xpm");
	ProjectileErase.Load("ProjectileErase.xpm");
	
	while(x<(Width)&&x>0&&y>0&&y<Height*5/6){	
		if(PlayerNumber==1){x = Width/7+(0.5+t)*cos(theta);}
		else {x = Width*6/7-(0.5+t)*cos(theta);}
		if(PlayerNumber==1){y=TerrainHeight[(int)(Width*10/7)]-0.25-(0.5+t)*sin(theta);}
		else {y=TerrainHeight[(int)(Width*10*6/7)]-0.25-(0.5+t)*sin(theta);}
		t+=0.1;
        		
		W.SetPosition(Position(x-0.1,y-0.1));
		W.Draw();
        W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
		ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		ProjectileErase.Draw();
		if(t>1){
		    if((abs(Width/7-x)<0.5)&&(TerrainHeight[(int)(Width*10/7)]-y>0)&&(TerrainHeight[(int)(Width*10/7)]-y<0.25)){
		        Tank1Damage+=350;
		        break;
	        }
	        else if((abs(Width*6/7-x)<0.5)&&(TerrainHeight[(int)(Width*10*6/7)]-y>0)&&(TerrainHeight[(int)(Width*10*6/7)]-y<0.25)){
		        Tank2Damage+=350;
		        break;
	        }
        }
	}
    Damage();	
}


void PotShots(){
    float x,y,theta,velocity, t, g;
	g = 50;
	velocity = Power*0.7;	
    srand((unsigned int) time(0));
    int ShotAngle;
    for(int shot=1;shot<=5;shot++){
        ShotAngle=Angle+(rand()%10)-5;
	    theta = ShotAngle*3.14159/180;
	    t=0;
	    x = (PlayerNumber==1)?(Width/7+0.4*cos(theta)):(Width*6/7-0.4*cos(theta));
	    y = (PlayerNumber==1)?(TerrainHeight[(int)(Width*10/7)]-0.3-0.4*sin(theta)):(TerrainHeight[(int)(Width*10*6/7)]-0.3-0.4*sin(theta));
	    W.Load("W.xpm");
	    ProjectileErase.Load("ProjectileErase.xpm");
	
	    while(y<TerrainHeight[(int)(x*10)]&&x<(Width)&&x>0){	
		    if(PlayerNumber==1){x = (Width/7) +0.5*cos(theta)+ velocity*cos(theta)*t+Wind*t/2.0;}
		    else {x = (Width*6/7) -0.5*cos(theta)- velocity*cos(theta)*t+Wind*t/2.0;}
		    if(PlayerNumber==1){y = TerrainHeight[(int)(Width*10/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		    else {y = TerrainHeight[(int)(Width*10*6/7)] - 0.4-0.4*sin(theta) - velocity*t*sin(theta) + g*t*t;}
		    t+=0.005;
            
		
		    W.SetPosition(Position(x-0.1,y-0.1));
		    W.Draw();
            W.Load("W.xpm");
	        ProjectileErase.Load("ProjectileErase.xpm");
		    ProjectileErase.SetPosition(Position(x-0.1,y-0.1));
		    ProjectileErase.Draw();

	    }
	    Tank1Damage+=150*DamageCalculator(x,y,Width/7,0.5);
	    Tank2Damage+=150*DamageCalculator(x,y,Width*6/7,0.5);
        
    }
    Damage();	
}


void MagicHeal(){
    if(PlayerNumber==1){Tank1Damage-=200;}
    else {Tank2Damage-=200;}
    Damage();
}

float DamageCalculator(float XHit,float YHit,float XTank,float ImpactDistance){
    if((XTank-XHit)*(XTank-XHit)+(TerrainHeight[(int)(XTank*10)]-YHit)*(TerrainHeight[(int)(XTank*10)]-YHit)<ImpactDistance*ImpactDistance){
        return(sqrt((ImpactDistance*ImpactDistance)-(XTank-XHit)*(XTank-XHit)-(TerrainHeight[(int)(XTank*10)]-YHit)*(TerrainHeight[(int)(XTank*10)]-YHit))/ImpactDistance);
    }
    else return 0;
}
    
void GameOverScreen(){//code to be run when the game is over i.e when the health of one of the players reaches 0
    int Score;
    if(NumberOfPlayers==2){Score=(Tank1Health>0)?Tank1Health:Tank2Health;}//in double player:winner's health is given as score
	else if (NumberOfPlayers==1){
	    if(Tank1Health>0){Score=Tank1Health;}
    }//in single player, if cpu wins, it is not taken into consideration
	for(int i=0;i<10;i++){//score is sorted into highscore array as per it's absolute position
		if (Score>HighScore[i]){
			for (int j=9;j>i;j--){HighScore[j]=HighScore[j-1];}//sorting scores in highscore array
			HighScore[i]=Score;
	    	break;			
		}
	}
	
	//to load corresponding bitmap as per result
	if (Tank1Health>0){
		Player1Wins.Load("WinPlayer1.xpm");
		PhotoPosition = Position(Width/2-3.0,Height/2-5.0) ;
		Player1Wins.SetPosition(PhotoPosition);
		Player1Wins.Draw();
	}
	else {
		if(NumberOfPlayers==2){
			Player2Wins.Load("WinPlayer2.xpm");
			PhotoPosition = Position(Width/2-3.0,Height/2-5.0);
			Player2Wins.SetPosition(PhotoPosition);
			Player2Wins.Draw();
		}
		else{
			CpuWins.Load("WinCPU.xpm");
			PhotoPosition = Position(Width/2-3.0,Height/2-5.0);
			CpuWins.SetPosition(PhotoPosition);
			CpuWins.Draw();
		}
	}
}
    

