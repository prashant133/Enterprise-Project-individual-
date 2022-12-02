
#define BLYNK_TEMPLATE_ID "TMPLsVp8rbj0"
#define BLYNK_DEVICE_NAME "Alarm System"
#define BLYNK_AUTH_TOKEN "DSmU6Azm3zKPs0n9_4AFRQWRLMrEjeDJ"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vianet2.5";
char pass[] = "9863668331";



//defines pin number
const int trigPin = D0;
const int echopin = D1;
const int buzzer = D2;
const int yellowled = D8;


//defines variables
long duration;
float distance;
int safteyDistance;



void setup() {
  pinMode(trigPin, OUTPUT);//Sets the trigPin as an Output
  pinMode(echopin, INPUT); //Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(yellowled,OUTPUT);

  Serial.begin(9600);//Starts the serial communication
  Blynk.begin(auth, ssid, pass);

}

void loop() {
  // Blynk.run();
  //clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  //Reads the echo{in, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);

  //calculating the distance
  distance = duration * 0.01723;


  Blynk.virtualWrite(V0, distance);
  Blynk.virtualWrite(V1, duration);
  Blynk.virtualWrite(V2, yellowled);


  safteyDistance = distance;
  if (safteyDistance <= 10) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(yellowled,HIGH);
    Serial.print("SafteyDistance: ");
    Serial.println(safteyDistance);

  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(yellowled,LOW);
   
  }
  





}