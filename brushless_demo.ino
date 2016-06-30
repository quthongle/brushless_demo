#include "Servo.h"

Servo esc;

#define ESC_PIN 9

#define ESC_PWM_MIN      1000
#define ESC_PWM_MAX      2000

void writeToEsc(int throttle)
{
	esc.write(throttle);
}

void escInit()
{
	pinMode(ESC_PIN,OUTPUT);
	esc.attach(ESC_PIN, ESC_PWM_MIN, ESC_PWM_MAX);
	writeToEsc(0);
}

void setup()
{
	Serial.begin(9600);// serial baudrate 9600
	escInit();
	Serial.println("starting....");
}

int i = 0;
int speed = ESC_PWM_MIN;
int rep = 0;

void loop() {
	if (rep <3) {
		speed = ESC_PWM_MIN + i;
		esc.writeMicroseconds(speed);
		Serial.println(speed);
		i++;
		if ((speed == 0) || (speed == ESC_PWM_MIN + 400 /* can be 
replaced by ESC_PWM_MAX */)) i = 0;
		}
	else {
		esc.writeMicroseconds(ESC_PWM_MIN);
	}
delay(100);
}
