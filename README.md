Smart Irrigation System

This project is an intelligent irrigation system that utilizes an Arduino UNO board, various sensors (such as DHT11, SGP30, soil moisture sensor), a water pump module, a humidifier module, a UV lamp module, and the ASRPRO voice module for unmanned plant cultivation.


Features

Monitors temperature, humidity, and soil moisture.

Uses a water pump for automatic irrigation.

Implements voice interaction control (for pump and humidifier) via the ASRPRO module.

Acquires eCO2 concentration data from the air using the SGP30 module.<img width="488" height="1138" alt="屏幕截图 2026-02-24 213802" src="https://github.com/user-attachments/assets/a7cc24b9-ff2c-46c3-be55-ab7a42fffd7b" />


Hardware Components

1.Arduino UNO microcontroller

2.DHT11 sensor for measuring temperature and humidity

3.SGP30 sensor for measuring eCO2 concentration

4.Soil moisture sensor for measuring soil moisture

5.Water pump — automatically waters based on soil moisture levels

6.Humidifier — automatically humidifies based on air humidity

7.ASRPRO voice module

8.Controls the UV lamp, water pump, and humidifier via the voice module
![00B6964355244B190F29D1986A5139FF](https://github.com/user-attachments/assets/0211a3a6-3c1a-4ebd-9c16-b88308321c79)
<img width="1686" height="1014" alt="屏幕截图 2026-02-20 224021" src="https://github.com/user-attachments/assets/671c6945-00c3-4f0e-a4df-d6016348def7" />


Software Components

1.Arduino IDE for programming the Arduino UNO board<img width="1777" height="1138" alt="屏幕截图 2026-02-24 183958" src="https://github.com/user-attachments/assets/7b03bf46-8447-460a-a445-6a32c8900406" />
<img width="1512" height="931" alt="屏幕截图 2026-02-24 184012" src="https://github.com/user-attachments/assets/aaa01e29-e667-47db-bdee-8a1944e0f304" />


2.Tianwen Block for programming the ASRPRO voice module


Future Improvements

1.Use an ESP32 microcontroller to implement the Internet of Things (IoT).

2.Integrate Artificial Intelligence (AI) to utilize image recognition for monitoring plant diseases.

3.Implement automatic water replenishment equipped with an ultrasonic sensor to prevent overflow.

4.put the data of humidity measured from the DHT11 into the SGP30 sensor to compenstate for the deviation
