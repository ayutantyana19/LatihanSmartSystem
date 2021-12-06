#include <main.h>


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sinyalOutputTerkonversi = analogRead(A0);

  //5 karena tegangan kerja dari Uno adalah 5volt,
  //1023 karena rentang ADC beresolusi 10bit, adalah dari 0 - 1023
  float sinyalOutput = (sinyalOutputTerkonversi/1023.0) * 5000;

  // LM35 Linier Tarnsfer Function
  // S = B + (MP)
  // S = sinyal putput (mV)
  // B = offset ketika nilai pembacaan 0, menurut pabrik, itu adalah 0
  // M = Slope linier, dalam hal sensor LM35, menurut pabrik, itu adalah 10mV
  // P = Data lingkungan (Celcius)
  // P = B + (S / M)
  // P = B / (S + M)
  // P = S / B + M

  //10(S) = 7(B) + 3(MP)
  //3(MP) = 10(S) - 7(B)
  // S = B + (MP)
  // (MP) = S - B
  // (M x P) = S
  // P = S / M

  float celcius = (sinyalOutput / 10.0);

  Serial.print(sinyalOutput);
  Serial.print(" mV");
  Serial.print(" - ");
  Serial.print(sinyalOutputTerkonversi);
  Serial.print(" ADC");
  Serial.print(" - ");
  Serial.print(celcius);
  Serial.println(" Celcius");


  delay(100);
}