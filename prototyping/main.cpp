#include <iostream>
#include <wiringPi.h>

int ledPin = 14;
int trigPin = 15;//triug physical pin 10
int echoPin = 18;//echo physical pin 12
int sensval = 0;
int duration;
int distance;
int main(){
	wiringPiSetupGpio();
	pinMode (ledPin, OUTPUT);
	pinMode (trigPin, OUTPUT);
	pinMode (echoPin,INPUT);
	for(;;){
	//Clearing trigPin
	digitalWrite(trigPin, LOW);
	delay(2);
	// Sets the trigPin HIGH for 0.010 seconds
	digitalWrite(trigPin, HIGH);
	delay(10);
	digitalWrite(trigPin, LOW);
	//Reads echoPin, returns travel time in seconds
	while(digitalRead(echoPin) == LOW);
	long startTime = micros();
	while(digitalRead(echoPin) == HIGH);
	long travelTime = micros() - startTime;
	int distance = travelTime / 58;
	std::cout << distance << std::endl;
	//Centimeters 182.88 = 6ft
	digitalWrite (ledPin, HIGH);//physical 8
	std::cout << "HIGHING" << std::endl ;
	delay(500);
	digitalWrite (ledPin, LOW); //physical 8
	std::cout << "LOWING" << std::endl;
	delay(500);
	}
	return 0;
}
