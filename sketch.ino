#include <DHT11.h> //引用DHT11温湿度传感器的库
#include "Adafruit_SGP30.h"// 引用SGP30空气质量/二氧化碳传感器的库

Adafruit_SGP30 sgp;//创建SGP30传感器对象

DHT11 dht11(7);// 定义DHT11连接在数字引脚7上

 const int IOPin = 2;//定义一个输出引脚（用于控制水泵）
 const int sensorPin = A0;// 模拟引脚A0用于读取土壤湿度传感器
 const int HE30APin = 13;// 定义引脚13（用于控制加湿器）
 const int airValue = 1023;   // 干燥空气中的读数（把探头拔出来测）
const int waterValue = 350;  // 纯水中的读数（把探头完全浸入水中测）

  void setup(){
   Serial.begin(9600);//初始化波特率为9600
  while (!Serial) { delay(10); } // 
  Serial.println("SGP30 test");
  if (! sgp.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.print("Found SGP30 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);//尝试启动SGP30传感器，如果找不到则报错并停止程序
    pinMode(2,OUTPUT);
    pinMode(7,INPUT); // 引脚7设置为输入模式（读取DHT11数据）
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);//引脚2、12、13设置为输出模式（控制设备）
                     
  } 

  void loop(){
     if (! sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
     }//调用sgp.IAQmeasure()进行测量
    Serial.print("eCO2 ");
     Serial.print(sgp.eCO2); 
     Serial.println(" ppm");//打印等效二氧化碳浓度（eCO2）值

     int temperature = 0;
    int humidity = 0;
    int result = dht11.readTemperatureHumidity(temperature, humidity);
    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    } else {
        Serial.println(DHT11::getErrorString(result));
        /*调用dht11.readTemperatureHumidity()。如果读取成功，打印温度和湿度；如果失败，打印错误信息。*/
    
    }
    if(humidity<60){
      digitalWrite(13,HIGH);
    } else{
      digitalWrite(13,LOW);
    }//逻辑判断: 如果空气湿度小于60%，开启引脚13的设备（可能是加湿器或排风扇，根据硬件连接判断）；否则关闭。
     int sensorValue = analogRead(A0);//使用analogRead(A0)读取模拟值
       int soilhumidity = map(sensorValue,waterValue,airValue,100,0); //使用map()函数将模拟值（0-1023）映射为百分比（0%-100%）
        soilhumidity = constrain(soilhumidity, 0, 100);//约束土壤湿度数值位于0-100
        Serial.print("Soilhumidity:");
        Serial.print(soilhumidity);
        Serial.println("%");
        if( soilhumidity<62){
         digitalWrite(2,HIGH);
        }else{
          digitalWrite(2,LOW);
        }//逻辑判断: 如果土壤湿度小于62%，开启引脚2的设备（通常是水泵进行灌溉）；否则关闭。
        delay(1000);//延迟1秒

  }