#include<LiquidCrystal.h>

LiquidCrystal lcd(11,8,5,4,3,2);

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int yellowPin = 7;
int health = 100;
int x = 1;
int y = 1;
int score = 0;
int monsterCheck = 0;
int rat1 = 0;
int rat2 = 0;
int rat3 = 0;
int rat4 = 0;
int rat5 = 0;
int gold1 = 0;
int gold2 = 0;
int gold3 = 0;
int gold4 = 0;
int randNum = 0;
int led = 13;
int movePin = 6;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(movePin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(10,1);
  lcd.print("AWDADQWDQD!");
  
  int x = 1;
  int y = 1;
  int z = 0;
  int input = 0;
  int score = 0;
  int hunger = 0;
  int health = 100;

  String param;
  int map[8][8];
  map[0][0] = 1;
  map[0][1] = 1;
  map[0][2] = 1;
  map[0][3] = 1;
  map[0][4] = 1;
  map[0][5] = 1;
  map[0][6] = 1;
  map[0][7] = 1;
  map[1][0] = 1;
  map[2][0] = 1;
  map[3][0] = 1;
  map[4][0] = 1;
  map[5][0] = 1;
  map[6][0] = 1;
  map[7][0] = 1;
  map[1][7] = 1;
  map[2][7] = 1;
  map[3][7] = 1;
  map[4][7] = 1;
  map[5][7] = 1;
  map[6][7] = 1;
  map[7][7] = 1;
  map[7][6] = 1;
  map[7][5] = 1;
  map[7][4] = 1;
  map[7][3] = 1;
  map[7][2] = 1;
  map[7][1] = 1;
  map[7][0] = 1;
  
  }

void loop() {

  lcd.setCursor(0,1);
  lcd.print(x,DEC);

  health -= 5;

  
  
  int mapVal = map[x][y];
  String userInput;
  int input;
  //String moove = "move";

  Serial.print("X");
  Serial.print(x);
  Serial.print("y");
  Serial.print(y);
  Serial.println();


  if(health == 100){
    setColor(255,255,255);
  }
  if(health > 90 && health < 100){
    setColor(178,183,243);
   }
  if(health > 80 && health < 90){
    setColor(56,69,246);
    }
  if(health > 70 && health < 80){
    setColor(4,20,247);
    }
  if(health > 60 && health < 70){
    setColor(4,247,150);
    }
  if(health > 50 && health < 60){
    setColor(233,247,4);
    }
  if(health > 40 && health < 50){
    setColor(246,204,90);
    }
  if(health > 30 && health < 40){
    setColor(233,173,6);
    }
  if(health > 20 && health < 30){
    setColor(246,122,92);
    }
  if(health > 5 && health < 20){
    setColor(242,76,35);
    }
  if(health == 0){
    setColor(0,0,0);
  }

  

    if(x == 5 && y == 5){
      Serial.println("You made it!");
    }

    if((x == 1 && y == 4) && rat1 == 0)
    {
      Serial.println("Theres a monster here");
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
      
    }
    if((x == 1 && y == 6) && rat2 == 0)
    {
      Serial.println("Theres a monster here");
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
    }
    if((x == 3 && y == 4) && rat3 == 0)
    {
      Serial.println("Theres a monster here");
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
    }
    if((x == 6 && y == 1) && rat4 == 0)
    {
      Serial.println("Theres a monster here");
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
      delay(100);
      digitalWrite(led,HIGH);
    }



    if((x == 1 && y ==2) && gold1 == 0)
    {
      Serial.println("Theres a pile of gold here\n\n");
      digitalWrite(yellowPin,HIGH);
    }
    if((x == 3 && y ==2) && gold2 == 0)
    {
      Serial.println("Theres a pile of gold here\n\n");
      digitalWrite(yellowPin,HIGH);
    }
    if((x == 2 && y ==5) && gold3 == 0)
    {
      Serial.println("Theres a pile of gold here\n\n");
      digitalWrite(yellowPin,HIGH);
    }
    if((x == 5 && y ==6) && gold4 == 0)
    {
      Serial.println("Theres a pile of gold here\n\n");
      digitalWrite(yellowPin,HIGH);
    }
    getInstructions();
    Serial.println("Make your Move");
    while(!Serial.available()){}
    userInput = Serial.readString();
    Serial.println(userInput);
    userInput.trim();
    
    

    if(userInput == "move"){
      digitalWrite(movePin,HIGH);
      delay(100);
      digitalWrite(movePin,LOW);
      delay(100);
      digitalWrite(movePin,HIGH);
      delay(100);
      digitalWrite(movePin,LOW);
      delay(100);
      digitalWrite(movePin,HIGH);
      delay(100);
      digitalWrite(movePin,LOW);
      delay(100);
      digitalWrite(movePin,HIGH);
      delay(100);
      digitalWrite(movePin,LOW);
      delay(100);
      
      digitalWrite(yellowPin, LOW);
      //input = action(userInput);
      Serial.println("Where would you like to go?");
      while(!Serial.available()){}
      userInput = Serial.readString();
      input = action(userInput);
      
      userInput.trim();
      
      if(checkSquare(input,x,y) == 0){
      Serial.println("You cant go that way");
      }
      else{
      if(userInput == "north" && y <= 6){
        y++;
        Serial.println("Moving North");
      }
      if(userInput == "east" && x <= 6){
        x++;
        Serial.println("Moving East");
      }
      if(userInput =="south" && y > 1){
        y--;
        Serial.println("Moving South");
      }
      if(userInput == "west" && x > 1){
        x--;
        Serial.println("Moving West");
        }
    
      }
    }

    if(userInput == "take"){
    if((x ==1 && y == 2) && gold1 == 0){
      Serial.print("you take the gold");
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      score += 100;
      gold1++;
      }
    if((x == 3 && y ==2) && gold2 == 0){
      Serial.print("You take the gold");
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      score += 100;
      gold2++;
    }
    if((x ==2 && y == 5) && gold3 == 0){
      Serial.print("you take the gold");
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      score += 100;
      gold3++;
      }
    if((x == 5 && y ==6) && gold4 == 0){
      Serial.print("You take the gold");
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      digitalWrite(yellowPin,HIGH);
      delay(100);
      digitalWrite(yellowPin,LOW);
      delay(100);
      score += 100;
      gold4++;
   }
  }


  
  if(userInput == "attack"){
    if((x ==1 && y == 4) && rat1 == 0){
      int randNum = (random(10,20) % 10);
      if(randNum > 5){
      Serial.print("you slay the beast");
      score += 100;
      rat1++;
      Serial.print(randNum);
      }
      else{
        Serial.println("You whiff");
      }
      }
    if((x == 1 && y ==6) && rat2 == 0){
      Serial.print("You attack");
      score += 100;
      rat2++;
    }
    if((x ==3 && y == 4) && rat3 == 0){
      Serial.print("You attack");
      score += 100;
      rat3++;
      }
    if((x == 6 && y ==1) && rat4 == 0){
      Serial.print("You attack");
      score += 100;
      rat4++;
    }
   
    else{Serial.print("you whiff");}
    
}
}

int move(String i){
  if (i == "north"){
    return 1;
  }
  if (i == "east"){
    return 2;
  }
  if (i == "south"){
    return 3;
  }
  if (i == "west"){
    return 4;
  }
  else{
    return 0;
  }
}

int action(String userInput){

int  mapVal = map[x][y];
  if(userInput == "move"){
    
    Serial.print("What direction would you like to move?");
    String input;
    input = Serial.read();
    return move(input);
  
}
  if(userInput == "look"){
    return 5;
  }
  if(userInput == "attack"){
    if(mapVal % 2 == 0 && mapVal != 0)
    {
      Serial.println("You Attack");
      score += 50;
    }
    return 6;
  }
  if(userInput == "use"){
    return 7;
  }
  if(userInput == "help"){
    
    return 8;
  }
  if(userInput == "take"){
    if(mapVal % 2 != 0)
    {
      Serial.println("You Take the Gold\n\n");
      score += 100;
    }
    return 9;
  }
  
else return 0;
}


void getInstructions(){
  Serial.println("Use these words to complete actions:");
  Serial.println("look");
  Serial.println("attack");
  Serial.println("move");
  Serial.println("use");
  Serial.println("help");
  Serial.println("take");
  Serial.println(" ");

}


int checkSquare(int n,int x, int y){
  if(n == 1){
    if(map[x + 1][y] == 1){
    return 0;
    }
    else return 1;
  }
  if(n == 2){
    if(map[x][y+1] == 1){
    return 0;
    }
    else return 2;
  }
  if(n == 3){
    if(map[x][y-1] == 1){
      return 0;
    }
    else return 3;
  }
  if(n == 4){
    if(map[x][y-1] == 1){
      return 0;
    }
    else return 4;
  }
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;

   #endif
   analogWrite(redPin,red);
   analogWrite(greenPin,green);
   analogWrite(bluePin,blue);
}
