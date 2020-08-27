//To Do: Add button to connect
#include <iostream>
#include <wiringPi.h>
#include <thread>
#include <cstdio>
#include <stdlib.h> //Used for rand and srand

std::string command;

std::string warnings[5] = {"./sounds/v1.wav","./sounds/v2.wav","./sounds/v3.wav","./sounds/v4.wav","./sounds/v5.wav"};

int BtnConn = 2; //physical pin 3

int RLed = 14; //physical pin 8
int GLed = 23; //physical pin 16
int BLed = 24; //physical pin 18

int trigPin = 15; //trig physical pin 10
int echoPin = 18; //echo physical pin 12

int duration;
int distance;


int main() {

  srand (time(NULL)); //Initialize random seed
  bool radius();
  void sound();
  void led();
  command = "sudo service bluetooth restart";
  const char *bltrst = command.c_str();
  system(bltrst);
  delay(500);
  std::string macaddress = "30:C0:1B:6B:05:3B"; //Change this address for your speaker
  command = "bluetoothctl connect " + macaddress;
  const char *bltcom = command.c_str(); //used to convert into a string that system() can use
  system(bltcom);
  delay(3000);

  wiringPiSetupGpio();

  pinMode (BtnConn, INPUT);
  pullUpDnControl(BtnConn, PUD_UP); //Pull up to 3.3v

  pinMode (echoPin, INPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (RLed, OUTPUT);
  pinMode (GLed, OUTPUT);
  pinMode (BLed, OUTPUT);

  while(true){
    
    if(digitalRead(BtnConn) == 0){ //when button is pressed down
        system(bltcom);
        delay(3000);	
    }
    if(radius() == true) {
      std::thread t1(led);
      sound();
      t1.join();
    }
  }
}

void sound() {

  //std::string macaddress = "30:C0:1B:6B:05:3B";
  //command = "bluetoothctl connect " + macaddress;
  //const char *bltcom = command.c_str(); //used to convert into a string that system() can use
  //system(bltcom);

  command = "aplay " + warnings[rand() % 5 + 0]; //RNG between 0 and 5
  const char *playcom = command.c_str();
  system(playcom);
}

void led() {

	for(int x = 0; x < 6; x++){
	digitalWrite (RLed, HIGH); //physical 8
	digitalWrite (GLed, HIGH);
	digitalWrite (BLed, HIGH);
	delay(500);
	digitalWrite (RLed, LOW); //physical 8
	digitalWrite (GLed, LOW);
	digitalWrite (BLed, LOW);
	delay(500);
	}
}

bool radius() {

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
  if (distance <= 180) { //6 feet in cm
    return true;
  }
  return false;
}
