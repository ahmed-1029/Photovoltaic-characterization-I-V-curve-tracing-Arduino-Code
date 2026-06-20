# Photovoltaic-characterization-I-V-curve-tracing-Arduino-Code
Those few lines of code change the PWM signal coming out of pin 3 in the Arduino to change the gate voltage of the transistors used. Pins A0 and A1 receive the current and voltage measured, respectively. Having the current and voltage throughout the change in PWM (PWM sweep), the I-V curve of the PV could be traced successfully.
const int gatePin = 3;     
const int currentPin = A0;
const int voltagePin = A1;

float sensitivity = 0.185;
float offsetVoltage = 2.5;

float voltageScale = 11.0;

void setup() {
  Serial.begin(9600);
  pinMode(gatePin, OUTPUT);

  Serial.println("PWM,Voltage(V),Current(A)");
}

void loop() {

  for (int pwm = 130; pwm <= 255; pwm += 2) {

    analogWrite(gatePin, pwm);
    delay(200);

  
    int adcCurrent = analogRead(currentPin);
    float currentVoltage = adcCurrent * (5.0 / 1023.0);
    float current = (currentVoltage - offsetVoltage) / sensitivity;

    int adcVoltage = analogRead(voltagePin);
    float vA1 = adcVoltage * (5.0 / 1023.0);
    float vin = vA1 * voltageScale;

    Serial.print(pwm);
    Serial.print(",");
    Serial.print(vin, 3);
    Serial.print(",");
    Serial.println(current, 3);
  }

  analogWrite(gatePin, 0);  

  while (true) {
  
  }
}
