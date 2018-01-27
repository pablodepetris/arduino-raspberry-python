  char incomingData;
  String receivedCommand;

int stringToNumber(String thisString) 
{
  int i, value, length;
  length = thisString.length();
  char blah[(length+1)];
  for(i=0; i<length; i++) 
  {
    blah[i] = thisString.charAt(i);
  }
  blah[i]=0;
  value = atoi(blah);
  return value;
}

boolean validateInput(String input)
{
  return((input[0]>=48 && input[0]<=49)&&(input[1]>=48 && input[1]<=57)&& (input[2]>=48 && input[2]<=49));
}

void setup(){
  Serial.begin(9600);
  Serial.println("Arduino Ready");
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}
ps -fea 


void loop(){

  if (Serial.available() > 0) 
  {
    incomingData = Serial.read();
    receivedCommand+=incomingData;
    if (receivedCommand.length()==3)
    {
      if (validateInput(receivedCommand))
      {
         digitalWrite(stringToNumber(receivedCommand.substring(0,2)),(receivedCommand[2]=='0')?LOW:HIGH);  
      }
        Serial.print( digitalRead(13)?"1":"0");
        Serial.print( digitalRead(12)?"1":"0");
        Serial.print( digitalRead(11)?"1":"0");
        Serial.print( digitalRead(10)?"1":"0");
        Serial.println( digitalRead(9)?"1":"0");
       receivedCommand="";
    }
  }  
}
