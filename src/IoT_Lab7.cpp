/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/aiden/Desktop/IoT-Engineering/VisualStudioCodeProjects/IoT_Lab7/src/IoT_Lab7.ino"
/*
 * Project IoT_Lab7
 * Description:
 * Author:
 * Date:
 */

#include <blynk.h>
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 11 "c:/Users/aiden/Desktop/IoT-Engineering/VisualStudioCodeProjects/IoT_Lab7/src/IoT_Lab7.ino"
OledWingAdafruit display;

#define TEMP_IN A4

SYSTEM_THREAD(ENABLED);

void setup() {
    Blynk.begin("73qv8BwuKMLO12l24EkloLOIlUSz1iA3", IPAddress(167, 172, 234, 162), 8080);
    pinMode(TEMP_IN, INPUT);

    display.setup();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,0);
}

void loop() {
    Blynk.run();
    display.loop();

    uint64_t reading = analogRead(TEMP_IN);
    double voltage = (reading * 3.3) / 4095.0;
    double celcius = (voltage - 0.5) * 100;

    double americanTemp = celcius * 1.8 + 32.0;

    if (display.pressedA()){
      display.clearDisplay();
      display.println("Push Sent");
      display.display();
      Blynk.notify("The temperature is "+String(int(celcius)) + "c, "+String(int(americanTemp))+"f.");
      delay(3000);
      display.clearDisplay();
    }

    Blynk.virtualWrite(V0, int(celcius));
    Blynk.virtualWrite(V1, int(americanTemp));

    display.println(String(int(celcius)) + "c, "+String(int(americanTemp))+"f");
    display.display();
    display.clearDisplay();
    display.setCursor(0,0);

}