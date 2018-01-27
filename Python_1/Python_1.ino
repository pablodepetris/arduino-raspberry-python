char incomingData;
String receivedCommand;

int stringToNumber(String thisString) 
{
  int i, value, length;
  length = thisString.length();
  char blah[(length+1)];
  for(i=0; i<length; i++)     {       
    blah[i] = thisString.charAt(i);    
  }    
  blah[i]=0;    
  value = atoi(blah);    
  return value; 
} 
void setup() {    
  Serial.begin(9600);    
  Serial.println("Arduino Ready");    
  pinMode(13, OUTPUT);    
  pinMode(12, OUTPUT);    
  pinMode(11, OUTPUT);    
  pinMode(10, OUTPUT);    
  pinMode(9, OUTPUT); 
} 
void loop() {    
  if (Serial.available() > 0) 
  {
    incomingData = Serial.read();
    receivedCommand+=incomingData;
    if (receivedCommand.length()==3)
    {
      digitalWrite(stringToNumber(receivedCommand.substring(0,2)),(receivedCommand[2]=='0')?LOW:HIGH);
      Serial.print("pin: ");
      Serial.print(receivedCommand.substring(0,2));
      Serial.print(" at level: ");
      Serial.println((receivedCommand[2]=='0')?"LOW":"HIGH");
      receivedCommand="";
    }
  }  
}

