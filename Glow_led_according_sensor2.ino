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
 // Serial.begin(9600);
}
void loop() {
  sensorValue = analogRead(sensor_pin);
  int  current_bright2 = map(sensorValue, 0, 1023, 0, max_value);
  current_bright = max_value - current_bright2+1 ;
  
//  Serial.print(" current_bright -> ");
//  Serial.print(current_bright);
//  Serial.print(" current_bright-2 -> ");
//  Serial.print(current_bright2);
//  Serial.print(" bright -> ");
//  Serial.println(bright);


  //fade in =================================
  if (bright < current_bright) {
    inc_value  = current_bright - bright ;
    for (int i = 1 ; i <= inc_value ; i++) {
      bright = bright + 1;

//      Serial.print(" current_bright -> ");
//      Serial.print(current_bright);
//      Serial.print(" current_bright-2 -> ");
//      Serial.print(current_bright2);
//
//      Serial.print(" inc_value -> ");
//      Serial.print(inc_value);
//      Serial.print(" in_bright -> ");
//      Serial.println(bright);
      analogWrite(led_pin, bright);
      delay(fade_delay);
    }

  }
  //fade out ================================
  if (bright > current_bright) {
    dec_value  = bright - current_bright ;
    for (int j = 1 ; j <= dec_value ; j++) {
      bright = bright - 1;
//      Serial.print(" current_bright -> ");
//      Serial.print(current_bright);
//      Serial.print(" current_bright-2 -> ");
//      Serial.print(current_bright2);
//      Serial.print(" dec_value -> ");
//      Serial.print(dec_value);
//      Serial.print(" out_bright -> ");
//      Serial.println(bright);
      analogWrite(led_pin, bright);
      delay(fade_delay);
    }
  }

  current_bright = 0;
  analogWrite(led_pin, bright);
//  Serial.println();
//  Serial.println(" ======================================Main loop ==========================");
  delay(1);
}
