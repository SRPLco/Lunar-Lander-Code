int in1 = 11;

void setup() {
  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);
}

void loop() {
  digitalWrite(in1, LOW);
  delay(3000);
  digitalWrite(in1, HIGH);
  delay(3000);
  //if(in1<10){in1 = in1+1;}
  //else{in1 = in1-8;}
}