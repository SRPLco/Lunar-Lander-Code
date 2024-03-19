
#include "Wire.h" //allows communication over i2c devices

const int pressuretransducermin = 1 ;//min bar value of transducer being used
const int pressuretransducermax = 100; //max bar value of transducer being used
const int baudRate = 9600; //constant integer to set the baud rate for serial monitor
const int sensorreadDelay = 500; //constant integer to set the sensor read delay in milliseconds

const int pressureInput1 = A0;//select the analog input pin for the pressure transducer
const int pressureInput2 = A1;
const int pressureInput3 = A2;
const int pressureInput4 = A3;
const int pressureInput5 = A4;
const int pressureInput6 = A5;
const int pressureInput7 = A6;
const int pressureInput8 = A7;

const int voltZero1 = 1.0405; //analog reading of pressure transducer at 0bar(volt)
const int voltZero2 = 1.04;
const int voltZero3 = 1.04;
const int voltZero4 = 1.04;
const int voltZero5 = 1.04;
const int voltZero6 = 1.039;
const int voltZero7 = 1.0415;
const int voltZero8 = 1.0385;

const int voltMax1 = 5.00375; //analog reading of pressure transducer at 100bar(volt)
const int voltMax2 = 5.003;
const int voltMax3 = 5;
const int voltMax4 = 5.004;
const int voltMax5 = 5.00475;
const int voltMax6 = 5.00225;
const int voltMax7 = 5.006;
const int voltMax8 = 4.99875;

float pressureVolt1 = 0;//variable to store the value coming from the pressure transducer
float pressureVolt2 = 0;
float pressureVolt3 = 0;
float pressureVolt4 = 0;
float pressureVolt5 = 0;
float pressureVolt6 = 0;
float pressureVolt7 = 0;
float pressureVolt8 = 0; 

float signalValue1 = 0; //8bit reading of each PT
float signalValue2 = 0;
float signalValue3 = 0;
float signalValue4 = 0;
float signalValue5 = 0;
float signalValue6 = 0;
float signalValue7 = 0;
float signalValue8 = 0;

float P1 =0; //pressure of each PT
float P2 =0;
float P3 =0;
float P4 =0;
float P5 =0;
float P6 =0;
float P7 =0;
float P8 =0;

void setup() //setup routine, runs once when system turned on or reset
{
  Serial.begin(baudRate); //initializes serial communication at set baud rate bits per second
}

void loop() //loop routine runs over and over again forever
{
  analogReadResolution(12);
  signalValue1 = analogRead(pressureInput1); //reads 12bit value from input pin and assigns to variable
  signalValue2 = analogRead(pressureInput2);
  signalValue3 = analogRead(pressureInput3);
  signalValue4 = analogRead(pressureInput4);
  signalValue5 = analogRead(pressureInput5);
  signalValue6 = analogRead(pressureInput6);
  signalValue7 = analogRead(pressureInput7);
  signalValue8 = analogRead(pressureInput8);
  Serial.print(signalValue1,3);
  Serial.print("bit");
  //Serial.print(signalValue8,3);
  //Serial.println("bit");

  pressureVolt1 = (signalValue1*3.3)/(4095); //transfer 12bit to voltage,arduino voltage input is 0~3.3v
  pressureVolt2 = (signalValue2*3.3)/(4095);
  pressureVolt3 = (signalValue3*3.3)/(4095);
  pressureVolt4 = (signalValue4*3.3)/(4095);
  pressureVolt5 = (signalValue5*3.3)/(4095);
  pressureVolt6 = (signalValue6*3.3)/(4095);
  pressureVolt7 = (signalValue7*3.3)/(4095);
  pressureVolt8 = (signalValue8*3.3)/(4095);

  Serial.print(pressureVolt1,3);
  Serial.print("V"); //prints label to serial
  // Serial.print(pressureVolt2,3);
  //Serial.println("V");
   //Serial.print(pressureVolt3,3);
  //Serial.println("V");
 
  P1 = ( (pressureVolt1-voltZero1)*( (pressuretransducermax-pressuretransducermin)/(voltMax1-voltZero1) ) ); //conversion equation to convert analog reading to bar
  P2 = ( (pressureVolt2-voltZero2)*( (pressuretransducermax-pressuretransducermin)/(voltMax2-voltZero2) ) );
  P3 = ( (pressureVolt3-voltZero3)*( (pressuretransducermax-pressuretransducermin)/(voltMax3-voltZero3) ) );
  P4 = ( (pressureVolt4-voltZero4)*( (pressuretransducermax-pressuretransducermin)/(voltMax4-voltZero4) ) );
  P5 = ( (pressureVolt5-voltZero5)*( (pressuretransducermax-pressuretransducermin)/(voltMax5-voltZero5) ) );
  P6 = ( (pressureVolt6-voltZero6)*( (pressuretransducermax-pressuretransducermin)/(voltMax6-voltZero6) ) );
  P7 = ( (pressureVolt7-voltZero7)*( (pressuretransducermax-pressuretransducermin)/(voltMax7-voltZero7) ) );
  P8 = ( (pressureVolt8-voltZero8)*( (pressuretransducermax-pressuretransducermin)/(voltMax8-voltZero8) ) );
  Serial.print(P1, 3); //prints value from previous line to serial
  Serial.println("bar");
  //Serial.print(P2, 3); //prints value from previous line to serial
  //Serial.println("bar");
  //Serial.print(P3, 3); //prints value from previous line to serial
  //Serial.println("bar");
  //Serial.println(); //prints label to serial
  delay(sensorreadDelay); //delay in milliseconds between read values
}
