//robot 14

#define S0 A0
#define S1 A1
#define S2 A2
#define S3 A3
#define ColorSensor A5

int lux, r, g, b;
int t, d;

void back() {
analogWrite(5, 255);
analogWrite(6, 0);
analogWrite(10, 0);
analogWrite(11, 255);
}
void forward(){
analogWrite(5, 0);
analogWrite(6, 255);

analogWrite(10, 255);
analogWrite(11, 0);
}
void stop(){ 
analogWrite(5, 0);
analogWrite(6, 0);
analogWrite(10, 0);
analogWrite(11, 0);
}
void rightAround(){
analogWrite(5, 255);
analogWrite(6, 0);
analogWrite(10, 255);
analogWrite(11,0);
}
void leftAround(){
analogWrite(5, 0);
analogWrite(6, 255);
analogWrite(10, 0);
analogWrite(11,255);  
}
void left() {
  analogWrite(5, 0);
analogWrite(6, 0);
analogWrite(10, 255);
analogWrite(11,0);  
}
void right() {
  analogWrite(5, 0);
analogWrite(6, 255);
analogWrite(10, 0);
analogWrite(11,0);  
}


void setup() {
Serial.begin(9600);
  // put your setup code here, to run once:
  //Motor A
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
//Motor B
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
//color

pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(ColorSensor, INPUT);
pinMode(8, OUTPUT);
pinMode(9, INPUT);
digitalWrite(S0, 0);
digitalWrite(S1, 1);
}

void loop() {
  //black()
digitalWrite(S2, 1);
digitalWrite(S3, 0);
lux = pulseIn(ColorSensor, HIGH);
//red
digitalWrite(S2, 0);
digitalWrite(S3, 0);
r = pulseIn(ColorSensor, HIGH);
//green
digitalWrite(S2, 1);
digitalWrite(S3, 1);
g = pulseIn(ColorSensor, HIGH);
//blue
digitalWrite(S2, 0);
digitalWrite(S3, 1);
b = pulseIn(ColorSensor, HIGH);
us();

//print
if(d <= 10) {
  stop();
}
else if(r < g && r < b) {
delay(1000);
forward();
}
else if(lux <= 700) {
  right();
}
else if(lux >= 1300) {
  left();
}
else {
forward();
}
// Serial.print("L: ");
// Serial.println(lux);
// Serial.print("r: ");
// Serial.println(r);
// Serial.print("g: ");
// Serial.println(g);
// Serial.print("b: ");
// Serial.println(b);
// delay(10000);
}

int us() {
digitalWrite(8, LOW);
delayMicroseconds(20);
digitalWrite(8, HIGH);
delayMicroseconds(20);
digitalWrite(8, LOW);
t = pulseIn(9, HIGH);
d = t*0.034/2;
delay(4);
return d;
}