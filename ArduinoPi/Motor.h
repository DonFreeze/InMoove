/* Robo Project
 * Servo Motor Class
 */
#include <Servo.h>
#include "Arduino.h"

class Motor
{

public:
    void init(int pin, int initial_angle, int max_angle, int min_angle);   // constructor of the Motor class
    void setAngle(int angle);                                              // sets the angle
    int getCurrAngle();                                                    // returns the currently set angle value
    int getMaxAngle();    
    int getMinAngle();    

private:
    int max_angle;  // maximal angle the servo can handle
    int min_angle;  // minimal angle the servo can handle
    int curr_angle; // angle which is currently set
    int pin;        // pin at which the servo is connected
    Servo myservo;  // servo object to control a servo
    
};
