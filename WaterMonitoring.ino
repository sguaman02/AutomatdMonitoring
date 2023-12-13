#define trig_pin 8
#define echo_pin 9
#define USONIC_DIV 0.034
int sensor=A0, soil;
const int dry=565;
const int wet=346;



void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(trig_pin,OUTPUT);
pinMode(echo_pin,INPUT);
digitalWrite(trig_pin,LOW);
Serial.println( " Irrigation System ");
delay(6000);

}
 
void loop() {
  long ping_time;
  long distance;
  int percentage_water;

  digitalWrite(trig_pin,HIGH);
  delay(11);
  digitalWrite(trig_pin,LOW);
  ping_time=pulseIn(echo_pin,HIGH);
  distance= ping_time*USONIC_DIV/2;
  percentage_water=map(distance,12,2,0,100);
  
//////////////////////////////Ultrasonic Sensor code///////////////////////////////////
  if(percentage_water<0)
{
  percentage_water=0;
}
else if (percentage_water>100)
{
  percentage_water=100;
}
Serial.print("Percentage: ");
Serial.print(percentage_water);
Serial.print("%  Distance: ");
Serial.print(distance);
Serial.println(" cm");


/////////////////////////////////Soil moisture code/////////////////////////////////////////
  
  soil=analogRead(sensor);
  int percentage = map(soil,wet,dry,100,0);
  Serial.print("Soil Moisture is:");
  Serial.print( soil);
  Serial.print(" Moisture percentage: ");
  Serial.print(percentage);
  Serial.println("%");
  delay(2000);
  if (percentage > 75) {
    digitalWrite(7, LOW);
    Serial.println("Water Pump is OFF ");
  } else {
    digitalWrite(7, HIGH);
   Serial.println("Water Pump is ON");
  }
 
  if (percentage < 55) {
    Serial.println("Moisture : LOW");
  } else if (percentage > 55 && percentage < 73) {
    Serial.println("Moisture : MID ");
  } else if (percentage > 75) {
    Serial.println("Moisture : HIGH ");
  }
}
