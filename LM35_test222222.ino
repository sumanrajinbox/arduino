const int lm35_pin = A1;  /* LM35 O/P pin */
int led = 9;           // the pin that the LED is attached to
void setup() {
  Serial.begin(9600);
 pinMode(led, OUTPUT);
  
}

void loop() {
float temp_val ;
  temp_val =  read_temperature(lm35_pin);

   int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin); /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
//  Serial.print("Temperature = ");
//  Serial.print(temp_val);
//  Serial.print(" Degree Celsius\n");
  
led_function(led,255);
 
  delay(200);
}

int read_temperature(int lm35_pin){ 
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin); /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  return  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
}

void led_function(int led,float brightness){
  float x ;
  int fadeAmount = 1;
  while(x == brightness){
      brightness = brightness + fadeAmount;
     analogWrite(led, brightness);
    }
  
  }
