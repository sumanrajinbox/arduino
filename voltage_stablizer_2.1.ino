// ===Voltage stablizer ======== version 2.0 ====================
const int sensor_pin = A4;
const int led_pin = 9;
const int fadeAmount = 1;
const int fade_delay = 0;
const int max_value = 254;
int bright = 0;
int current_bright = 1;
int sensorValue ;
int inc_value ;
int dec_value ;
void setup() {
  Serial.begin(9600);
}
void loop() {
  sensorValue = analogRead(sensor_pin);
  int  current_bright2 = map(sensorValue, 0, 1023, 0, max_value);
  current_bright = max_value - current_bright2+1 ;
  Serial.print(" sensor_value -> ");
  Serial.print(current_bright2);
//  Serial.print(" current_bright -> ");
//  Serial.print(current_bright);

  Serial.print(" bright -> ");
  Serial.println(bright);


  //fade in =================================
  if (bright < current_bright) {
    inc_value  = current_bright - bright ;
    bright = bright + inc_value;
  analogWrite(led_pin, bright);
  }
  //fade out ================================
  if (bright > current_bright) {
    dec_value  = bright - current_bright ; 
    bright = bright - dec_value;
      analogWrite(led_pin, bright);
  }

  current_bright = 0;
  analogWrite(led_pin, bright);
  delay(500);
}
