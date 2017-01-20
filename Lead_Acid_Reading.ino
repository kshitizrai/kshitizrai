#include<SD.h>
#include<SPI.h>
const int reading=A0;
const int CSpin=10;
int value;
float vin,vout;
float R2=10000.00;
float R1=46100.00;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
 pinMode(CSpin,OUTPUT);
 if(!SD.begin(CSpin))
 {
  Serial.println("Card Failure");
  return;
 }
 Serial.println("Chal Pada");

}

void loop() {
  // put your main code here, to run repeatedly:
 value=analogRead(reading);
 delay(1000);
 vin=(value*5.00)/(1023);
 vout= vin*(R1+R2)/R2;
 Serial.println(vout);
 File leadacid = SD.open("leadAcid.csv" , FILE_WRITE);
 if(leadacid)
 { //Serial.println("Oh Yess");
  leadacid.print(millis());
  leadacid.print(",");
  leadacid.println(vout);
  leadacid.close();
 }
  else
  Serial.println("Nahi Write huya");
}
