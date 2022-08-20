
# 🏠 Smart Home Project

This is my final project for my embedded systems diploma.
The diploma covered the core concepts of embedded systems and I've tried to apply these concepts in a practical project! :)
## System Requirements
These are the requirements to implement smart home application:
- Remoted controlled by mobile or laptop
- Login system including usernames and passwords
- Usernames and passwords must be kept in memory even if the system power is off
- If passwords are entered wrong more than 3 times, the system should fire up an alarm
### Specifications -LCD
- LCD is used for login
- LCD must display the running devices in normal operation
- With every system action LCD must print a message

### Specifications -EEPROM
- Storing new users to the system
### Specifications -TTL/Bluetooth
- Transmitting/Receiving between the microcontroller and PC/mobile
- With every action a message must be printed on PC/mobile screen
- Transmitting/Receiving the commands to run the system
### Specifications -Temperature Sensor, DC motor
- Temperature sensor reads the ambient temperatue, if the temperature exceeds 35 °C, the system should run the DC motor "Fan", if the temperature falls behind 30°C, the DC motor must be turned off
### Specifications -Door
- The actuator used is a servo motor to control the opening door
- The door opens up only if the user's password is entered correctly, it should remain closed otherwise

## Components used
- AVR ATMEGA32
- 16x2 LCD
- AT24C16A (16Kb EEPROM)
- DC motor
- Servo Motor SG-90
- Bluetooth module HC-05
- LM35 temperature sensor
- H-Bridge
- Buzzer

## Drivers Implemented
### LCD Driver
- Operation mode: 4 bit
### Temperature sesnor
- Utilizes MC's internal ADC for analog readings conversion
### UART
- Baudrate: 9600 bit/sec
- Operation mode: Interrupts for receiving and transmitting
- Used for serial communcations between MC and PC/mobile through bluetooth
### I2C
- Data transfer speed: 400KHz
- Single master single slave connection
- Used for communicating between MC and EEPROM for reading/writing operations
### ADC
- Speed: 125KHz
- Operation mode: Polling
### Bluetooth
- Implemented the UART communcation protocol for receiving and transmitting data
### EEPROM
- Used I2C protocol for communication
- Can read/write every memory address by changing the data frame
### DC Motor
- Connected to the H-Bridge and operating on full speed
### Servo Motor
- Used PWM (Fast PWM mode) for operation
## Smart Home System State Diagram
![State diagram](https://user-images.githubusercontent.com/78038233/185661064-c1db51c2-1317-4fab-8180-c726b0b83f66.PNG)

## 🔗 Smart home demo
[Smart home project demo](https://drive.google.com/file/d/16_I1k_2VBO2R4m-A5Yu4stME-1ol_NHQ/view?usp=sharing)
