
int layer[4]={A0,A1,A2, A3};
int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};
int time = 250;
int testTime = 1000;

void setup() {
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  turnEverythingOff();
}

void loop() {
  /*turnEverythingOn();
  delay(1000);
  turnEverythingOff();
  //individualTest();
  delay(1000);
  layerStackUp();
  layerStackUp();
  layerStackDown();
  delay(1000);
  turnEverythingOff();
  delay(1000);*/

  //turnOnCenter2Cube();
  
  //turnEverythingOff();


  aroundEdgeDown(75, true);
  delay(10);
  wallUp(105, true);
  delay(10);
  wallDown(105, true);
  delay(10);
  pillarUp(105, true);
}

void wallDown(int x, bool keepLast){
  //turnEverythingOff();

  for(int i=3;i >= 0; i--){
    digitalWrite(layer[i], 0);

    digitalWrite(column[0], 1);
    digitalWrite(column[1], 1);
    digitalWrite(column[2], 1);
    digitalWrite(column[3], 1);

    digitalWrite(column[4], 1);
    digitalWrite(column[7], 1);
    digitalWrite(column[8], 1);
    digitalWrite(column[11], 1);

    digitalWrite(column[12], 1);
    digitalWrite(column[13], 1);
    digitalWrite(column[14], 1);
    digitalWrite(column[15], 1);
    

    if(i != 0){
      delay(x);
      digitalWrite(layer[i], 1);
    }else{
      if(!keepLast){
        delay(x);
        digitalWrite(layer[i], 1);
      }
    }
    
  }
}

void wallUp(int x, bool keepLast){
  //turnEverythingOff();

  for(int i=0;i < 4; i++){
    digitalWrite(layer[i], 0);

    digitalWrite(column[0], 1);
    digitalWrite(column[1], 1);
    digitalWrite(column[2], 1);
    digitalWrite(column[3], 1);

    digitalWrite(column[4], 1);
    digitalWrite(column[7], 1);
    digitalWrite(column[8], 1);
    digitalWrite(column[11], 1);

    digitalWrite(column[12], 1);
    digitalWrite(column[13], 1);
    digitalWrite(column[14], 1);
    digitalWrite(column[15], 1);
    

    if(i != 3){
      delay(x);
      digitalWrite(layer[i], 1);
    }else{
      if(!keepLast){
        delay(x);
        digitalWrite(layer[i], 1);
      }
    }
  }
}

void pillarUp(int x, bool keepLast){
  //turnEverythingOff();

  for(int i=0;i < 4; i++){
    digitalWrite(layer[i], 0);

    digitalWrite(column[0], 1);
    digitalWrite(column[3], 1);
    digitalWrite(column[12], 1);
    digitalWrite(column[15], 1);

    digitalWrite(column[1], 0);
    digitalWrite(column[2], 0);

    digitalWrite(column[4], 0);
    digitalWrite(column[7], 0);
    digitalWrite(column[8], 0);
    digitalWrite(column[11], 0);

    digitalWrite(column[13], 0);
    digitalWrite(column[14], 0);

    

    if(i != 3){
      delay(x);
      digitalWrite(layer[i], 1);
    }else{
      if(!keepLast){
        delay(x);
        digitalWrite(layer[i], 1);
      }
    }
  }
}


void aroundEdgeDown(int x, bool keepLast)
{
  //turnEverythingOff();

  for(int i = 4; i != 0; i--)
    {
      digitalWrite(layer[i-1], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[10], 0);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      digitalWrite(column[4], 0);
      delay(x);
      digitalWrite(column[4], 1);
      digitalWrite(column[8], 0);
      delay(x);
      digitalWrite(column[8], 1);
      digitalWrite(column[12], 0);
      delay(x);
      digitalWrite(column[12], 1);
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      digitalWrite(column[15], 0);
      delay(x);
      digitalWrite(column[15], 1);
      digitalWrite(column[14], 0);
      delay(x);
      digitalWrite(column[14], 1);
      digitalWrite(column[11], 0);
      delay(x);
      digitalWrite(column[11], 1);
      digitalWrite(column[7], 0);
      delay(x);
      digitalWrite(column[7], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);


      if(i-1 != 0){
        digitalWrite(layer[i-1], 1);
      }else{
        if(!keepLast){
          digitalWrite(layer[i-1], 1);
        }
      }

    }
}

void spiral(){
  int timer=40;
  //digitalWrite(layer[1], 0);

  for(int i=0;i<16;i++){
    digitalWrite(layer[1], 0);
    digitalWrite(column[i], 1);

    digitalWrite(layer[2], 0);
    digitalWrite(column[16-i], 1);

    delay(timer);

    digitalWrite(layer[1], 0);
    digitalWrite(column[i], 0);

    digitalWrite(layer[2], 0);
    digitalWrite(column[16-i], 0);

    
  }

  

  delay(1000);

  
}

void doPattern(int leds[], bool whatLayers[]){
  for(int i=0;i<4;i++){
    if(whatLayers[i] == true){
      digitalWrite(layer[i], 0);
      digitalWrite(layer[i], 1);

      for(int j=0;j<16;j++){
        digitalWrite(column[j], leds[j]);
      }
    }
  }
}

void turnOnCenter2Cube(){
  turnEverythingOff();
  delay(1000);

  digitalWrite(layer[1], 0);
  digitalWrite(layer[2], 0);

  digitalWrite(column[5], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[9], 1);
  digitalWrite(column[10], 1);

  delay(1000);
}




////////////////////////////////

void turnEverythingOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}

void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0);
  }
}

void individualTest()
{
  int t = 250;
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], 0);
    for(int j = 0; j<16; j++)
    {
      digitalWrite(column[j], 1);
      delay(t);
      digitalWrite(column[j], 0);
    }
    digitalWrite(layer[i], 1);
  }
}
void individualLayer(int a)
{
  digitalWrite(layer[a], 0);
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i],1);
    
  }
}
void individualLayerOff(int a)
{
  digitalWrite(layer[a], 1);
}

void layerStackUp()
{
  int t = 250;
  individualLayer(0);
  delay(t);
  individualLayer(1);
  delay(t);
  individualLayer(2);
  delay(t);
  individualLayer(3);
  delay(t);
  individualLayerOff(0);
  delay(t);
  individualLayerOff(1);
  delay(t);
  individualLayerOff(2);
  delay(t);
  individualLayerOff(3);
  delay(t);
}
void layerStackDown()
{
  int t = 250;
  individualLayer(3);
  delay(t);
  individualLayer(2);
  delay(t);
  individualLayer(1);
  delay(t);
  individualLayer(0);
  delay(t);
  individualLayerOff(3);
  delay(t);
  individualLayerOff(2);
  delay(t);
  individualLayerOff(1);
  delay(t);
  individualLayerOff(0);
  delay(t);
}
void pickAnLED(int c,int a)
{
   digitalWrite(layer[a], 0);
  digitalWrite(column[c], 1);
  
}

void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}

void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
  turnEverythingOff();
}
void heartbeat()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 1);
  }
  for(int j = 0;j<255; j+=5)
  {
    for(int i = 0; i<4; i++)
    {
      analogWrite(layer[i], j);
    }
    delay(100);
    
  }
  
  for(int j = 255;j>0; j-=5)
  {
    for(int i = 0; i<4; i++)
    {
      analogWrite(layer[i], j);
    }
    delay(100);
  }
}
