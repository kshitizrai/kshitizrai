const int led1=9;
const int led2=10;
const int led3=11;
const int button=2;
const int led=8;
int timedelay=50;
int brightness=0;
int j=1;
int count=1;
int fadeamount1=5;
int fadeamount2=5;
int fadeamount3=5;
boolean currentbutton=LOW;
boolean lastbutton=LOW;
boolean ledon=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  }
boolean debounce(boolean last)
{
  boolean current = digitalRead(button);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(button);
  }
  return (current);

}

void debounce2()
{currentbutton=debounce (lastbutton);
ledon=digitalRead(button);
  if(lastbutton==LOW && currentbutton==HIGH)
  {count++;
  //Serial.println(count);
  
    if(count==6)
  {count=1;}
  }
  lastbutton=currentbutton;
  digitalWrite(led,ledon);
    if(ledon==LOW)
  timedelay=50*count;
 Serial.println(timedelay);
  
}
void loop() {
  // put your main code here, to run repeatedly:
debounce2();
do
  {
    brightness=brightness+fadeamount1;
    debounce2();
      Serial.print("led1=");
    Serial.println(brightness);
    analogWrite(led1,brightness);
    delay(timedelay);
  }while(brightness>0 && brightness<255);
  if(brightness>=255 || brightness<=0)
  fadeamount1=-fadeamount1;
  if(brightness>=255)
  j=1;
  if(brightness<=0)
  j=0;
  if(j==0)
  brightness=255;
  if(j==1)
  brightness=0;
  do
  {
    brightness=brightness+fadeamount2;
    Serial.print("led2=");
    debounce2();
    Serial.println(brightness);
    analogWrite(led2,brightness);
    delay(timedelay);
  }while(brightness>0 && brightness<255);
  if(brightness>=255 || brightness<=0)
  fadeamount2=-fadeamount2;
  if(brightness>=255)
  j=1;
  if(brightness<=0)
  j=0;
  if(j==0)
  brightness=255;
  if(j==1)
  brightness=0;
   do
  {
    brightness=brightness+fadeamount3;
      Serial.print("led3=");
      debounce2();
    Serial.println(brightness);
    analogWrite(led3,brightness);
      delay(timedelay);
  }while(brightness>0 && brightness<255);
  if(brightness>=255 || brightness<=0)
  fadeamount3=-fadeamount3;
  
  
}
