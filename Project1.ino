
const int button=2;
const int led=9;
boolean lastbutton=LOW;
boolean currentbutton=LOW;
int count=0;
boolean ledon=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  currentbutton=debounce (lastbutton);
  if(lastbutton==LOW && currentbutton==HIGH)
  {
    count++;
    ledon=!ledon;
     if(count==10)
  {count=0;

  }
  Serial.print("CountNEW=");
  Serial.println(count);
  }
  lastbutton=currentbutton;
  digitalWrite(led,ledon);

 
  
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

