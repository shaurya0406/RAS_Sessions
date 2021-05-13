#include <Arduino.h>
// LEd1 on for 1 sec and off for 1sec
// led2 on for 2 sec and off for 2 sec
// led3 its on for only 500ms and off for 1 sec
//led4 on for 1500 and off for 2000ms

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

unsigned long current_time = 0; 
unsigned long previous_LED1_Time = 0;
unsigned long previous_LED2_Time = 0;
unsigned long previous_LED3_Time = 0;
unsigned long previous_LED4_Time = 0;

byte LED1_State = 0;
byte LED2_State = 0;
byte LED3_State = 0;
byte LED4_State = 0;
// if(current_time-previous_LED1_Time = 1000)
// {
//   if(LEdis off)
//     led true
//   else 
//     led false
// }


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  //delay(1000); //the crystal gets stopped
                // no clock freq that means the arduino is not performing any task
                // arduino gets paused
  current_time = millis();


}

void update_LED1()
{
    if(LED1_State)
    {
       if(current_time-previous_LED1_Time == 1000)
       {
         LED1_State = !LED1_State;
         previous_LED1_Time += 1000;
       } 
    }
    else
    {
     if(current_time-previous_LED1_Time == 1000)
       {
         LED1_State = !LED1_State;
         previous_LED1_Time += 1000;
       } 
    }
    digitalWrite(LED1,LED1_State);
}

void update_LED2()
{
    if(LED2_State) //if led2 is on
    {
       if(current_time-previous_LED2_Time == 2000) // whether 2000 ms have been passed since LED2 is switched on state
       {
         LED2_State = !LED2_State; // Led2 state is off
         previous_LED2_Time += 2000; // update prev_Timer += off_time
       } 
    }
    else
    {
     if(current_time-previous_LED2_Time == 2000)
       {
         LED2_State = !LED2_State;
         previous_LED2_Time += 2000;
       } 
    }
    digitalWrite(LED2,LED2_State); // we are giving output
}
// led3 its on for only 500ms and off for 1 sec
void update_LED3()
{
    if(LED3_State) //Whether LED3 is on
    {
       if(current_time-previous_LED3_Time == 1000) // Whether 500ms passed or not
       {
         LED3_State = !LED3_State;  // Set to off
         previous_LED3_Time += 1000; //Updating the timer with the off_time
       } 
    }
    else
    {
     if(current_time-previous_LED3_Time == 1000) 
       {
         LED3_State = !LED3_State;
         previous_LED3_Time += 500;
       } 
    }
    digitalWrite(LED3,LED3_State);
}
void update_LED3()
{
    if(LED4_State) //Whether LED3 is on
    {
       if(current_time-previous_LED4_Time == 2000) // Whether 500ms passed or not
       {
         LED4_State = !LED4_State;  // Set to off
         previous_LED4_Time += 2000; //Updating the timer with the off_time
       } 
    }
    else
    {
     if(current_time-previous_LED4_Time == 2000) 
       {
         LED4_State = !LED4_State;
         previous_LED4_Time += 1500;
       } 
    }
    digitalWrite(LED4,LED4_State);
}

//current_time 3500
//prev    1500
//state 1

//The update interval is greater of the 2 time intervals
//when the led is off we only have the on time = 1500MS 
//when the led is on we have to update it by the off time = 2000ms 