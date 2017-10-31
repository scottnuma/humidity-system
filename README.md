Humidity Controls System

I designed a system to regulate the humidity of a room using closed-loop feedback. The Arduino Pro micro toggles the vent based on the current humidity and calibrated threshold.

I chose to use the [RHT03 Humidity and Temperature Sensor](https://www.sparkfun.com/products/10167). This requires the [DHT sensor library](https://github.com/adafruit/DHT-sensor-library) and the [Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor). Both of these can be installed using the Arduino library manager. The sensor reads the percent humidity in the room. The sensor is suprisingly sensitive; it can detect the moisture in your breath. I can't say though if the readings are accurate though. The temperature readings were about +/- 10 degrees Farhenheit of the actual temperature.

I used a servo to actuate the vent fan. To allow manual use of the vent's switch, I only attach the servo (and therefore lock in its angle) when I'm toggling the switch. This also reduces on time for the servo.

I used a potentiometer to tune the threshold for the system. The process for tuning the system meant lowering the threshold to 0% and slowly increasing it until the system turned the vent off. This method of feedback made using a 7-segment display or LED to display the threshold unnecessary and also friendlier.

Adafruit's [Perma-Proto breadboard](https://www.adafruit.com/product/571) was great for putting together a "wall-mountable" system after prototyping. The Arduino Pro Micro is great for this project as it fits directly on the board and can be powered through micro-USB.


