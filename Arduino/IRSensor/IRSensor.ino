int out = 12;
int ena = 13;

void setup(){
    pinMode(out, INPUT);
    pinMode(ena, OUTPUT);
    digitalWrite(ena, LOW);
    Serial.begin(9600);
}

void loop(){
    Serial.print(digitalRead(out));
}