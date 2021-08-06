#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

int Entrance = 1;
int Exit = 2;
int pirentrance;
int pirexit;
int people = 0;
int nopeople = 0;
int buzzer = 6;

Servo myservo;

bool isEntrance = false; 
bool isExit = false; 
int servo = 7;
void setup ()
{
  myservo.attach(servo);
  lcd.begin(16,2);

}

void loop ()
{
  lcd.setCursor(0,0);
  lcd.print("MonitoringSystem");
  pirentrance = digitalRead(1);
  pirexit = digitalRead(2);

    
  if (pirentrance == HIGH && isEntrance == false)
  {
    myservo.write(0);
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print("Someone Entered");
    delay(1000);
    lcd.clear();
    people += 1;
    isEntrance = true;
  }
    else if(pirentrance == LOW && isEntrance == true)
    {
    isEntrance = false;

    }

  else 
  {
     myservo.write(90);
  }
  
  if (pirexit == HIGH && isExit == false)
  {
    myservo.write(0);                      
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print("Someone left");
    delay(1000);
    lcd.clear();
    people -= 1;
    isExit = true;
    }
    else if(pirexit == LOW && isExit == true)
    {
    isExit = false;

    }

    else 
  {
     myservo.write(90);
  }
 
   lcd.setCursor(12, 1); 
  lcd.setCursor(0, 1);
  lcd.print("# of people:");
  lcd.print(people);
  


  if (people > 10)
  {
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print (" Maximum limit");
    lcd.setCursor(0,1);
    lcd.print ("   GET OUT!!!!");
    delay(500);
    tone(buzzer, 4000);
    delay(100);
    noTone(buzzer);
    delay(100);
    lcd.clear();
    
  }
  
   else if (people < 0 )
   {
  people = nopeople;
   lcd.setCursor(0,1);
    lcd.print("                    ");
  lcd.setCursor(12, 1); 
  lcd.setCursor(0, 1);
  lcd.print("# of people:");
  lcd.print(nopeople);
   }
    
  }
