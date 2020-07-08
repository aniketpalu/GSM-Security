#define smoke 8
#define flame 9

#define buzzer 7

void setup() {

Serial.begin(9600);
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"+918624851213\"\r");
delay(1000);
Serial.println("Hello Sir");
delay(1000);
Serial.println("I m started");
delay(1000);
Serial.println((char)26);
pinMode(smoke, INPUT);

pinMode(flame, INPUT);



pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   delay(1000);
   Serial.print("Gas");
  Serial.print(digitalRead(8));
  Serial.println("");
  Serial.println("Flame");
  Serial.print(digitalRead(9));
  int varF=digitalRead(flame);
  int varS=digitalRead(smoke);
/*if(digitalRead(alcohol)>0)
{
  digitalWrite(buzzer,HIGH);
  Serial.println("Sending SMS");
  alcoholSMS();
}
else
{
  digitalWrite(buzzer,LOW);
 
 }
*/
 if(varS==0)
{
   delay(1000);
  digitalWrite(buzzer,HIGH);
  Serial.println("Sending MQ2 SMS");
  MQ2SMS();
}
else
{
  digitalWrite(buzzer,LOW);  
}

if(varF== 0)
{
  delay(1000);
  Serial.println("Sending Flame SMS");
  digitalWrite(buzzer,HIGH);
  flameSMS();
}
else
{
  digitalWrite(buzzer,LOW);
}
}
/*
void alcoholSMS()
{
       Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+918805450291\"\r"); // Replace x with mobile number
     Serial.println("Alcohol Alert");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     delay(100);
     digitalWrite(buzzer,HIGH);
}
*/
void flameSMS()
{

Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"+918624851213\"\r");
delay(1000);
Serial.println("Hello Sir");
delay(1000);
Serial.println("There is Fire, Come Soon!");
delay(1000);
Serial.println((char)26);
}

void MQ2SMS()
{
      
Serial.println("AT+CMGF=1");
delay(1000);
Serial.println("AT+CMGS=\"+918624851213\"\r");
delay(1000);
Serial.println("Hello Sir");
delay(1000);
Serial.println("Gas is leaking, Come Soon");
delay(1000);
Serial.println((char)26);
     
}
