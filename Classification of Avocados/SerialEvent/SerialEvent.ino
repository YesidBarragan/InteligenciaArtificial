
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int byteRead;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  pinMode(13,OUTPUT);
}

void loop() {
  // print the string when a newline arrives:
  if (Serial.available()> 0) {
   // Serial.println(inputString); 
    byteRead=Serial.parseInt(); 
    if (byteRead==1){
      digitalWrite(13,HIGH);
    }else if(byteRead==0){
      digitalWrite(13,LOW);
    }
    
  }
}

