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