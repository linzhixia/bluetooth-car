bluetooth-car
=============
This is a bluetooth car using Arduino Leonardo board and Android device as the controller.

The car has three wheels-except the rear one, the other two wheels both have a dedicated
motors. It finishes turning by using the speed difference between these two drive wheels.

Leonardo is the cpu of the car. Bluetooth serial module finishes the communication between
the car and the controller, and L298N module drives the motor. The power supply voltage
should higher than 5.5v. All the modules and the materials are easy to get in taobao.

The Android controller use bluetooth function to send control message. At any time, only
press left/right buttons will not cause moving. You should put left/right buttons with 
foward/backward buttons combination. The up/down buttons are the speed shifters. Tap up
button will increase the speed, but it may harder to control the path.
