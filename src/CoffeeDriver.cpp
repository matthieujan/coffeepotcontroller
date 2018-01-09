#include "CoffeeDriver.h"

CoffeeDriver::CoffeeDriver()
{
    this->m_value = 0;
}

CoffeeDriver::~CoffeeDriver()
{

}

bool CoffeeDriver::get()
{
    return this->m_value;
}

void CoffeeDriver::set(bool value)
{
    Py_SetProgramName("servoControl");
    Py_Initialize();
    if(value){
	PyRun_SimpleString("import RPi.GPIO as GPIO\n"
                       "import time\n"
                       "GPIO.setmode(GPIO.BOARD)\n"
                       "GPIO.setup(11,GPIO.OUT)\n"
                       "pwm=GPIO.PWM(11,50)\n"
                       "pwm.start(6)\n"
		       "time.sleep(1)\n"
                       "pwm.ChangeDutyCycle(4)\n"
		       "time.sleep(1)\n"
                       "pwm.ChangeDutyCycle(6)\n"
		       "time.sleep(1)\n"
                       "pwm.stop()\n"
                       "GPIO.cleanup()\n");
        this->m_value = 3.5;
    }else{
        this->m_value = 5;
	PyRun_SimpleString("import RPi.GPIO as GPIO\n"
		       "import time\n"
                       "GPIO.setmode(GPIO.BOARD)\n"
                       "GPIO.setup(11,GPIO.OUT)\n"
                       "pwm=GPIO.PWM(11,50)\n"
                       "pwm.start(3.5)\n"
		       "time.sleep(1)\n"
                       "pwm.ChangeDutyCycle(6)\n"
                       "pwm.stop()\n"
                       "GPIO.cleanup()\n");
        this->m_value = 5;
    }
}
