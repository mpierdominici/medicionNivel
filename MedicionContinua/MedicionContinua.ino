#include <NewPing.h>

#define ECHO_PIN 8
#define TRIGGER_PIN 7 
#define MAX_DISTANCE 200
#define NUMER_MUESTRAS_PROMEDIO 5
//#define DEBUGG
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
unsigned int dMicroSec=0;
byte dCm=0;
byte newSerialData;
void loop() {
#ifdef  DEBUGG
  dMicroSec=sonar.ping_median(NUMER_MUESTRAS_PROMEDIO,MAX_DISTANCE);
  dCm=sonar.convert_cm(dMicroSec);
  Serial.print("Distancia en centirmetros:");
  Serial.println(dCm);
  delay(1000);
#else
  if(Serial.available()){//si llego algo por uart
    newSerialData=Serial.read();//saco el bayte del uart
    dMicroSec=sonar.ping_median(NUMER_MUESTRAS_PROMEDIO,MAX_DISTANCE);
    dCm=sonar.convert_cm(dMicroSec);
    Serial.write(dCm);
      
  }
  


  


#endif


}
