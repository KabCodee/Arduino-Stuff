// libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// creating an object "screen" thru Adafruit
Adafruit_SSD1306 screen(128, 64, &Wire, -1);

int playerX = 56;
int playerY = 56;
int obstacleX = playerX;
int obstacleY = 0;
int rightBttn = 7;
int leftBttn = 6;
bool gameOver = false;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  screen.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  pinMode(rightBttn, INPUT_PULLUP);
  pinMode(leftBttn, INPUT_PULLUP);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    
    if(gameOver == true){
    screen.clearDisplay();
    screen.setCursor(8, 8);
    screen.setTextSize(2);
    screen.setTextColor(WHITE);
    screen.println("U LOSE");
    screen.setTextSize(1);
    screen.setCursor(15, 30);
    screen.println("PRESS RIGHT");
    screen.display();
    score = 0;
    delay(200);
  }
   if (gameOver == true && digitalRead(rightBttn) == LOW){
    screen.clearDisplay();
    obstacleY = 0;
    obstacleX = playerX;
    playerX = 56;
    playerY = 56;
    gameOver = false;
   }
    if(playerX < obstacleX + 8 &&
    playerX + 8 > obstacleX &&
    playerY < obstacleY + 8 &&
    playerY + 8 > obstacleY){
    gameOver = true;
    return;
  }
   if(obstacleY == 64 && gameOver == false){
     score += 1;

  }

  if(digitalRead(rightBttn) == LOW){
    playerX += 2;
  }
  if(digitalRead(leftBttn) == LOW){
    playerX -= 2;
  }
  if(obstacleY == 64){
    obstacleY = 0;
    obstacleX = playerX;
    
  }
  obstacleY += 4;
  String SCORE = "Score: " + String(score);
  screen.clearDisplay();
  screen.setCursor(0, 0);
  screen.setTextColor(WHITE);
  screen.println(SCORE);
  screen.fillRect(playerX, playerY, 8, 8, WHITE);
  screen.fillRect(obstacleX, obstacleY, 8, 8, WHITE);
  screen.display();
  playerX = constrain(playerX, 0, 120);


}
