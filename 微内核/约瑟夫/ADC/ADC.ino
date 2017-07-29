#define TEMP0 (10)
#define TEMP1 (60)
#define ADC0 (815)
#define ADC1 (397)

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
short int tempx;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  int ADCX = analogRead(analogInPin);
  // print the results to the serial monitor:
  tempx = convert_adc2temperature(ADCX,ADC0,ADC1,TEMP0,TEMP1);
  Serial.print(tempx);
  Serial.print("\n");

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(500);
}

short int convert_adc2temperature(short int ax,short int a0,short int a1,short int temp0,short int temp1)
{
    short int tempx;
    tempx = temp0+(ax-a0)*(temp1-temp0)/(a1-a0);
    return tempx;
}

