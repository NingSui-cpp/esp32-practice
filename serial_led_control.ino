int ledPin = 5;

void setup(){
  Serial.begin(115200);
  pinMode(5,OUTPUT);
}

void loop(){
  if(Serial.available()){
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if(cmd == "ON"){
      digitalWrite(5,HIGH);
      Serial.println("Light ON");
    }
    else if(cmd == "OFF"){
      digitalWrite(5,LOW);
      Serial.println("Light OFF");
    }
    else{
      Serial.println("Unknown command");
    }
  }
}