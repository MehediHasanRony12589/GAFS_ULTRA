#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <SoftwareSerial.h>

// SoftwareSerial GPS_Serial(8, 9);//TX, RX
SoftwareSerial GSM_Serial(10, 11);//TX, RX

// TinyGPSPlus gps;//GPS object

//Data initialization
float   lattitude,longitude;//GPS variable for lattitude & longitude.
String  Authority_Contact = "+8801612891659";
String  Fire_Service_1    = "+8801631677652";
String  Fire_Service_2    = "+8801633143261";
int     GasSensorData;
int     SaftyLimit        = 170;

//Analog Pin Declaration
#define block_A   A1
#define block_B   A2
#define block_C   A3
#define Kitchen   8
#define exust_fan 9

//Message sending variable
int message_Limit = 1;
int message_Count = 0;

//Digital Pin Declaration
#define gasValue    0
#define emergancy   4
#define gasLine     2
#define waterPump   3  

#define flameSens_1 5
#define flameSens_2 6
#define flameSens_3 7

#define voiceAlart  12
#define buzzerPin 13

void setup()
{
    lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight

  Serial.begin(9600);
  Serial.println("Device Activated");
  // GPS_Serial.begin(9600);
  // GPS_Serial.listen();
  GSM_Serial.begin(9600);
  lcd.init();
lcd.backlight();
lcd.clear();
 
  pinMode(gasValue, INPUT_PULLUP);
 
  pinMode(flameSens_1, INPUT_PULLUP);
  pinMode(flameSens_2, INPUT_PULLUP);
  pinMode(flameSens_3, INPUT_PULLUP);

  pinMode(waterPump, OUTPUT);
  pinMode(voiceAlart, OUTPUT);
  pinMode(exust_fan, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(Kitchen, OUTPUT);
  pinMode(gasLine, OUTPUT);
  pinMode(emergancy, OUTPUT);

  pinMode(block_A, OUTPUT);
  pinMode(block_B, OUTPUT);
  pinMode(block_C, OUTPUT);

  digitalWrite(block_A, LOW);
  digitalWrite(block_B, LOW);
  digitalWrite(block_C, LOW);
  digitalWrite(Kitchen, LOW);
  digitalWrite(gasLine, LOW);

  digitalWrite(exust_fan,  HIGH);
  digitalWrite(waterPump,  HIGH);
  digitalWrite(voiceAlart, HIGH);
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(emergancy, HIGH);

  delay(50);
   
    lcd.setCursor(4,0);
    lcd.print ("WELCOME TO  ");
    lcd.setCursor(2,1);
    lcd.print ("CPI,DEPT OF MT");
    lcd.setCursor(1,2);
    lcd.print ("MADE AND POWERED BY");
    lcd.setCursor(2,3);
    lcd.print ("CREATIVITY ICON");
    delay(6000);
    lcd.clear();
}

void loop()
{
  GasDetection();
  FireDetection();
}

void FireDetection()
{
  bool A = digitalRead(flameSens_1);
  bool B = digitalRead(flameSens_2);
  bool C = digitalRead(flameSens_3);
  bool gasLeak = digitalRead(gasValue);

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print ("ZONE 1 NORMAL");
  lcd.setCursor(1,1);
  lcd.print ("ZONE 2 NORMAL");
  lcd.setCursor(1,2);
  lcd.print ("ZONE 3 NORMAL");
  lcd.setCursor(1,3);
  lcd.print ("HAVE A GOOD DAY");
  delay(1000);
  lcd.clear();

  if (!A)
  {
    digitalWrite(waterPump, LOW);
    digitalWrite(gasLine, HIGH);
    digitalWrite(block_A, HIGH);
    digitalWrite(voiceAlart, LOW);
    digitalWrite(emergancy, LOW);

      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print ("  DANGER!!  ");
      lcd.setCursor(0,1);
      lcd.print ("ZONE 1 FIRE DETECTED");
      lcd.setCursor(3,2);
      lcd.print ("ELECTRICTY OFF");
      lcd.setCursor(0,3);
      lcd.print ("PUMP ON,GAS LINE OFF");
      delay(5000);
      lcd.clear();

    // for(int i = 1; i <= message_Limit; i++)
    // {
      Serial.println("Entered into the 1st loop");
      Serial.println("Messege Count Increased: " + String(message_Count) + ".");
      //Sent Messages to corresponding contacts
      Authority_SMS(gasLeak);
      delay(500);
      Fire_Service_SMS(Fire_Service_1);
      delay(500);
      Fire_Service_SMS(Fire_Service_2);
      delay(500);

    // }
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print ("SMS SENT ZONE 1");
      lcd.setCursor(2,1);
      lcd.print ("Sussfully Done");
      lcd.setCursor(5,2);
      lcd.print ("POWERED BY");
      lcd.setCursor(2,3);
      lcd.print ("CREATIVITY ICON");
      delay(2000);
      lcd.clear();
  }

  else if (!B)
  {
    digitalWrite(waterPump, LOW);
    digitalWrite(gasLine, HIGH);
    digitalWrite(block_B, HIGH);
    digitalWrite(voiceAlart, LOW);
    digitalWrite(emergancy, LOW);

      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print ("  DANGER!!  ");
      lcd.setCursor(0,1);
      lcd.print ("ZONE 2 FIRE DETECTED");
      lcd.setCursor(3,2);
      lcd.print ("ELECTRICTY OFF");
      lcd.setCursor(0,3);
      lcd.print ("PUMP ON,GAS LINE OFF");
      delay(5000);
      lcd.clear();

    // for(int i = 1; i <= message_Limit; i++)
    // {
      Serial.println("Entered into the 2nd loop");
      Serial.println("Messege Count Increased: " + String(message_Count) + ".");
      //Sent Messages to corresponding contacts
      Authority_SMS(gasLeak);
      delay(500);
      Fire_Service_SMS(Fire_Service_1);
      delay(500);
      Fire_Service_SMS(Fire_Service_2);
      delay(500);

    // }
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print ("SMS SENT ZONE 2");
      lcd.setCursor(2,1);
      lcd.print ("Sussfully Done");
      lcd.setCursor(5,2);
      lcd.print ("POWERED BY");
      lcd.setCursor(2,3);
      lcd.print ("CREATIVITY ICON");
      delay(2000);
      lcd.clear();
  }

  else if (!C)
  {
    digitalWrite(waterPump, LOW);
    digitalWrite(block_C, HIGH);
    digitalWrite(gasLine, HIGH);
    digitalWrite(voiceAlart, LOW);
    digitalWrite(emergancy, LOW);

      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print ("  DANGER!!  ");
      lcd.setCursor(0,1);
      lcd.print ("ZONE 3 FIRE DETECTED");
      lcd.setCursor(3,2);
      lcd.print ("ELECTRICTY OFF");
      lcd.setCursor(0,3);
      lcd.print ("PUMP ON,GAS LINE OFF");
      delay(5000);
      lcd.clear();
   
    // for(int i = 1; i <= message_Limit; i++)
    // {
      Serial.println("Entered into the 3rd loop");
      Serial.println("Messege Count Increased: " + String(message_Count) + ".");
      //Sent Messages to corresponding contacts
      Authority_SMS(gasLeak);
      delay(500);
      Fire_Service_SMS(Fire_Service_1);
      delay(500);
      Fire_Service_SMS(Fire_Service_2);
      delay(500);

     
    // }
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print ("SMS SENT ZONE 3");
      lcd.setCursor(2,1);
      lcd.print ("Sussfully Done");
      lcd.setCursor(5,2);
      lcd.print ("POWERED BY");
      lcd.setCursor(2,3);
      lcd.print ("CREATIVITY ICON");
      delay(2000);
      lcd.clear();
  }

  else
  {
    digitalWrite(voiceAlart, HIGH);
    digitalWrite(waterPump, HIGH);
    digitalWrite(emergancy, HIGH);
   
    digitalWrite(gasLine, LOW);
    digitalWrite(block_A, LOW);
    digitalWrite(block_B, LOW);
    digitalWrite(block_C, LOW);

    lcd.clear();
      lcd.setCursor(5,0);
      lcd.print (" CALM DOWN ");
      lcd.setCursor(1,1);
      lcd.print ("EVERTHING IS FINE");
      lcd.setCursor(5,2);
      lcd.print ("POWERED BY");
      lcd.setCursor(2,3);
      lcd.print ("CREATIVITY ICON");
      delay(1000);
      lcd.clear();
  }
}

void GasDetection()
{
  bool gasDetected = digitalRead(gasValue);
  // Serial.print("Gas Level: ");
  // Serial.println(GasSensorData);

  if (gasDetected == LOW)
  {  
    Serial.println("Gas Detected");
    digitalWrite(gasLine, HIGH);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(emergancy, LOW);
    digitalWrite(exust_fan, LOW);
    digitalWrite(Kitchen, HIGH);
   
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print ("  DANGER!!  ");
      lcd.setCursor(4,1);
      lcd.print ("GAS DETECTED");
      lcd.setCursor(3,2);
      lcd.print ("ELECTRICTY OFF");
      lcd.setCursor(0,3);
      lcd.print ("FAN ON,GAS LINE OFF");
      delay(3000);
      lcd.clear();

   
    // for(int i = 1; i <= message_Limit; i++)
    // {
      Serial.println("Entered into the gas detection loop");
      Serial.println("Messege Count Increased: " + String(message_Count) + ".");
      //Sent Messages to corresponding contacts
      Authority_SMS(gasDetected);
      delay(500);
      // Fire_Service_SMS(Fire_Service_2);
      // delay(500);
      // Fire_Service_SMS(Fire_Service_1);
    // }
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print ("SMS SENT Gas Line");
      lcd.setCursor(2,1);
      lcd.print ("Sussfully Done");
      lcd.setCursor(5,2);
      lcd.print ("POWERED BY");
      lcd.setCursor(2,3);
      lcd.print ("CREATIVITY ICON");
      delay(2000);
      lcd.clear();
  }
 
  else
  {
    message_Count = 0;
    Serial.println("Gas not Detected");
    delay(1000);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(emergancy, HIGH);
    digitalWrite(exust_fan, HIGH);
    digitalWrite(Kitchen, LOW);
    digitalWrite(gasLine, LOW);
   
   lcd.clear();
    lcd.setCursor(2,0);
    lcd.print ("GAS LIMIT NORMAL");
    lcd.setCursor(2,1);
    lcd.print ("ELECTRICTY ON");
    lcd.setCursor(2,2);
    lcd.print ("POWERED BY");
    lcd.setCursor(2,3);
    lcd.print ("CREATIVITY ICON");
    delay(1000);
    lcd.clear();
  }
}

void Authority_SMS(bool kitchenRoom)
{
  if (!kitchenRoom)
  {
    GSM_Serial.print("\r");
    delay(500);                 
    GSM_Serial.print("AT+CMGF=1\r");
    delay(500);
    GSM_Serial.print("AT+CMGS=\""+ Authority_Contact +"\"\r");   
    delay(500);

    GSM_Serial.print("Alart Alart Alart! Gas leakage detected on your Restaurant's Kitchen, Please quickly check your gas line");
    // GSM_Serial.print("https://www.google.com/maps/place/23.437173,91.136987");
    delay(1000);
    GSM_Serial.write(0x1A);
    delay(1000);
  }

  else
  {
    GSM_Serial.print("\r");
    delay(500);                 
    GSM_Serial.print("AT+CMGF=1\r");
    delay(500);
    GSM_Serial.print("AT+CMGS=\""+ Authority_Contact +"\"\r");   
    delay(500);

    GSM_Serial.print("Alart Alart Alart! Fire detected on our building. Please take necessary steps to reduce fire.");
    // GSM_Serial.print("https://www.google.com/maps/place/23.437173,91.136987");
    delay(1000);
    GSM_Serial.write(0x1A);
    delay(1000);
  }
}

void Fire_Service_SMS(String Number)
{
  GSM_Serial.print("\r");
  delay(1000);
  GSM_Serial.print("AT+CMGF=1\r");
  delay(1000);
  GSM_Serial.print("AT+CMGS=\""+ Number +"\"\r");
  delay(1000);
  GSM_Serial.print("Fire detected on Sohrawardy Udyan, Please  quickly arrive at this GPS location with proper safety instruments. https://www.google.com/maps/place/23.7315365, 90.3987483");
      // GSM_Serial.print(lattitude, 6);
      // GSM_Serial.print(",");
      // GSM_Serial.print(longitude, 6);
      // GSM_Serial.print(23.437173);
      // GSM_Serial.print(",");
      // GSM_Serial.print(91.136987);
 
  delay(1000);
  GSM_Serial.write(0x1A);
  delay(1000);
}
