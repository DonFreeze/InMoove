#include "interpreter.h"
#include "MotorManager.h"

unsigned char message[TOTAL_MSG_LENGTH+1];
int messageLength = 0;

MotorManager* motor_manager = new MotorManager;
  
void setup(){
    Serial.begin(9600);
    message[TOTAL_MSG_LENGTH] = '\n';
    motor_manager->init();
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
}
 
void loop(){
    if (Serial.available() > 0){
      readOnSerial();
    }
}

void readOnSerial(){
  unsigned char receivedByte = Serial.read();
  if(receivedByte){
    buildMessage(receivedByte);
    interpretCompleteMessage();
  }
}

void buildMessage(unsigned char receivedByte){
  checkMessageStart(receivedByte);
  if(messageLength > 0){
    addToMessage(receivedByte);
  }
}

void checkMessageStart(unsigned char receivedByte){
  if(receivedByte == MSG_START_SEQ){
    resetMessage();
    addToMessage(receivedByte);
  }
}

void resetMessage(){
  messageLength = 0;
}

void addToMessage(unsigned char byte){
  message[messageLength] = byte;
  messageLength++;   
}

void interpretCompleteMessage(){
    if(messageLength == TOTAL_MSG_LENGTH){
    interpret(&message[0], motor_manager);
    resetMessage();
  }  
}

