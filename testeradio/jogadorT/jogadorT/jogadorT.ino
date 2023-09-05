#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RH_NRF24.h>
#include "jogador.h"
MotorPair motors(PH_IN1, PH_IN2, PH_IN3, PH_IN4);
RH_NRF24 radio(7, 8); // CE, CSN
const uint64_t pipe = 0xA2E8F0F0E1LL ;

Message message;


void setup() {
  Serial.begin(9600);
  //radio.begin();
  //radio.openReadingPipe(0, pipe);
  //radio.setPALevel(RF24_PA_MIN);
  //radio.startListening();
  while (!Serial) 
    ; // wait for serial port to connect. Needed for Leonardo only
  if (!radio.init())
    Serial.println("init failed");
  // Defaults after init are 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!radio.setChannel(1))
    Serial.println("setChannel failed");
  if (!radio.setRF(RH_NRF24::DataRate2Mbps, RH_NRF24::TransmitPower0dBm))
    Serial.println("setRF failed");   
}

int rSpeed = 0;
int lSpeed = 0;
int velocidade = 0;

void loop() {
  
  if (radio.available()) {
    Serial.println("Radio available");      
    //radio.recv(&message, sizeof(message));
    uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (radio.recv(buf, &len)){
      

      if (PLAYER == 0) {
        int velocidade = ((((char*)buf)[0] - '0')*10) + (((char*)buf)[1] - '0');
        lSpeed = velocidade;
        rSpeed = velocidade;
        //lSpeed = message.left_speed0;
        //rSpeed = message.right_speed0;
      }
      else if (PLAYER == 1) {
        int velocidade = ((((char*)buf)[0] - '0')*10) + (((char*)buf)[1] - '0');
        lSpeed = velocidade;
        rSpeed = velocidade;
        //lSpeed = message.left_speed0;
        //rSpeed = message.right_speed0;
      }
      else if (PLAYER == 2) {
        int velocidade = ((((char*)buf)[0] - '0')*10) + (((char*)buf)[1] - '0');
        lSpeed = velocidade;
        rSpeed = velocidade;
        //lSpeed = message.left_speed0;
        //rSpeed = message.right_speed0;
      }
    //Serial.println(messageToString(message));
    Serial.println((char*)buf);
    Serial.println(velocidade);

    }
  }
  else {
    Serial.println("Radio not available");
  }
  Serial.println(lSpeed);
  Serial.println(rSpeed);

  if (lSpeed > 255)
    lSpeed = 255;
  else if (lSpeed < -255)
    lSpeed = -255;
  if (rSpeed > 255)
    rSpeed = 255;
  else if (rSpeed < -255)
    rSpeed = -255;
  
  motors.setSpeed(lSpeed, rSpeed);
  //motors.setSpeed(0, 0);
}
