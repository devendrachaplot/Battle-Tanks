void wait (float seconds )
{
  clock_t endwait;
  endwait = clock () + (seconds * CLOCKS_PER_SEC)/1000;
  while (clock() < endwait){}
}

#define Steps 30

void BmpMove(BitMap &Image,const Position &Start,const Position &End){
    float StartX=Start.GetXDistance();
    float StartY=Start.GetYDistance();
    float EndX=End.GetXDistance();
    float EndY=End.GetYDistance();
    Position Present=Start;
    for(int k=0;k <= Steps+1;k++){
        PhotoPosition = Present + Position(-0.5*Image.GetWidth(),-0.5*Image.GetHeight());
        Image.SetPosition(PhotoPosition);
	    Image.Draw();
	    Present = Present + Position((EndX-StartX)/Steps,(EndY-StartY)/Steps);
	    wait(1);
    }
    putchar(10);
}
