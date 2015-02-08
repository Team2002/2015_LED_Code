const int CLK = P1_2;
const int DAT = P2_3;
int pixInBuf = 8;
void writebit(boolean state)
{
  digitalWrite(DAT,state);
  digitalWrite(CLK,HIGH);
  delayMicroseconds(2);
  digitalWrite(CLK,LOW);
}


void writePixel(int red, int green, int blue)
{

  //msb
  //brg


  writebit(true);
  for(int i = 0; i < 7; i++)
      writebit(((blue << (i)) & 0x40) > 0);


    writebit(true);
  for(int i = 0; i < 7; i++)
      writebit(((red << (i)) & 0x40) > 0);

     writebit(true);
  for(int i = 0; i < 7; i++)
      writebit(((green << (i)) & 0x40) > 0);

}

void setup()
{
  pinMode(CLK,OUTPUT);
  pinMode(DAT,OUTPUT);
  digitalWrite(CLK,LOW);
}
void pixelclear()
{
  for(int i =0; i < 24 * 12 ; i++)
      writebit(false);
}


void loop()
{
  pixelclear();
  for(int i = 0; i < 32; i++)
  {
    writePixel(i * 4,0,max(127 - (i * 4),0));
  }
}
