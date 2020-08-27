# ProxBelt
## Description
Simple social distancing device
## How does it work?
The distance sensor waits until the nearest object in front of you is 6 ft or less, then sends a signal to the pi to play a random audio clip through the speaker
## What is needed?
* Raspberry Pi w/ bluetooth functionality
* Bluetooth Speaker
* Distance Sensor
## Setting up
1. Use bluetoothctl to trust and pair bluetooth speaker
2. Change the macaddress in the code for your bluetooth speaker (there is a comment where you need to change)
3. Compile
## Compiling
``` g++ ProxShirt.cpp -o main -lwiringPi -pthread ```
## How to use
1. Turn speaker on (maybe use pairing mode if needed)
2. Run code
## Libraries
  * iostream
  * wiringPi
  * thread
  * cstdio
  * stdlib
