#include <Servo.h>

Servo servohori; //horizontal servo(BOTTOM SERVO)
int servoh = 0; //assign servo at 0 degree
int servohLimitHigh = 180; //maximum range of servo is 180 degree(it is variable you can also change)
int servohLimitLow = 10;   //minimum range of servo is 10 degree(it is variable you can also change)

Servo servoverti; //vertical servo(TOP SERVO) 
int servov = 0; 
int servovLimitHigh = 180;
int servovLimitLow = 10;

int ldrtopr = 1; //top right LDR A1 pin
int ldrtopl = 2; //top left LDR A2 pin

int ldrbotr = 0; // bottom right LDR A0 pin
int ldrbotl = 3; // bottom left LDR A3 pin


 void setup () 
 {
  servohori.attach(10); //horizontal servo connected to arduino pin 10
  servohori.write(0);
  
  servoverti.attach(9); //vertical servo connected to arduino pin 9
  servoverti.write(0);
  delay(500); //delay
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  
  
  int topl = analogRead(ldrtopl); //read analog values from top left LDR
  int topr = analogRead(ldrtopr); //read analog values from top right LDR
  int botl = analogRead(ldrbotl); //read analog values from bottom left LDR
  int botr = analogRead(ldrbotr); //read analog values from bottom right LDR
  
  
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs

  if (avgtop < avgbot)
  {
    servoverti.write(servov -1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(8);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov +1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(8);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh -1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(8);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh +1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(8);
  }
  else 
  {
    servohori.write(servoh); // write means run servo
  }
  delay(50);
}
