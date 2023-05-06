// C++ code
//
int m1 = 4;
int m2 = 5;
int m3 = 6;
int m4 = 7;

char input;

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  int potentiometer = analogRead(A0);
  int potent = potentiometer/4;

  analogWrite(10, potent);
  analogWrite(11, potent);


  while(Serial.available())
  {
    input =Serial.read();
    if(input == 'F')
    {
      forward();
    }
    else if (input== 'R')
    {
      right();      
    }
    else if (input== 'L')
    {
      left();    
    }  
    else if (input== 'G')
    {
      backward();    
    }      
    else if (input== 'S')
    {
      stop();    
    }  
  }

}

void forward()
  {
  digitalWrite(m2, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void stop()
  {
  digitalWrite(m2, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void backward()
  {
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void right()
  {
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void left()
  {
  digitalWrite(m2, LOW);
  digitalWrite(m1, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
