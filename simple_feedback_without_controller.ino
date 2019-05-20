/* This is an example code for a BUCK converter circuit made with arduino
 * I've used arduino NANO. We have to set the timer of the PWM on pin D3
 * The feedback is connected to A1 and we set the desired voltage with a
 * potnetiometer connected to A0.
 * 
 * Subscribe: http://www.youtube.com/c/electronoobs
 * webpage: http://www.electronoobs.com/eng_circuitos_tut10.php
 */

 
int Vcontrol = A1;
int feedback = A0;
int PWM = 3;
int pwm = 0;

void setup() {
  pinMode(Vcontrol, INPUT);
  pinMode(feedback, INPUT);
  pinMode(PWM, OUTPUT);  
  TCCR2B = TCCR2B & B11111000 | B00000001;    // pin 3 and 11 PWM frequency of 31372.55 Hz
}

void loop() {  
  float voltage = analogRead(Vcontrol);
  float output  = analogRead(feedback);

  if (voltage > output)
   {
    pwm = pwm-1;
    pwm = constrain(pwm, 1, 127);
   }

  if (voltage < output)
   {
    pwm = pwm+1;
    pwm = constrain(pwm, 1, 127);
   }

   analogWrite(PWM,pwm);
}
