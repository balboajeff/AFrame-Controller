#include <Mouse.h>

/* Not So Wireless Wireless Joystick USB Example
 * by: Alex Wende
 * SparkFun Electronics
 * date: 9/28/16
 * 
 * license: Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)
 * Do whatever you'd like with this code, use it for any purpose.
 * Please attribute and keep this license.
 * 
 * This example sends ASCII arrow key characters over USB when the left
 * joystick is moved or a space character when right trigger button is pressed.
 */

#include "Keyboard.h"

#define H_JOYSTICK    A2
#define V_JOYSTICK    A3
#define R_TRIGGER     3

void setup() {
  pinMode(R_TRIGGER, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  uint16_t hStick = analogRead(H_JOYSTICK);
  uint16_t vStick = analogRead(V_JOYSTICK);

  if(hStick > 766) Keyboard.press(KEY_LEFT_ARROW);
  else if(hStick < 255) Keyboard.press(KEY_RIGHT_ARROW);
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if(vStick > 266) Keyboard.press(KEY_DOWN_ARROW);
  else{
    Keyboard.release(KEY_DOWN_ARROW);
  }
  ////////
 if(vStick < 766) Keyboard.press(KEY_UP_ARROW);
  else{
    Keyboard.release(KEY_UP_ARROW);
  }
  ///////

  if(digitalRead(R_TRIGGER) == LOW){
    Keyboard.press(' ');
  }
  else{
    Keyboard.release(' ');
  }
  ////////////camera up and down
  if(analogRead(A0)>750)
  {
    Mouse.press(MOUSE_LEFT);
    Mouse.move(0, -2);
    Mouse.press(MOUSE_LEFT);
  }
  if(analogRead(A0)<250)
  {
    Mouse.press(MOUSE_LEFT);
    Mouse.move(0, 2);
    Mouse.press(MOUSE_LEFT);
  }
  /////////////////end camera up and down

  ///////////////Camera left and right
  if(analogRead(A1)>750)
  {
    Mouse.press(MOUSE_LEFT);
    Mouse.move(-2, 0);
    Mouse.press(MOUSE_LEFT);
  }
  if(analogRead(A1)<250)
  {
    Mouse.press(MOUSE_LEFT);
    Mouse.move(2, 0);
    Mouse.press(MOUSE_LEFT);
  }
  ////////
  if(digitalRead(3) == LOW)
     {
    Mouse.press(MOUSE_LEFT);
     }
  else
  {
    Mouse.release();
    } 
    
  }
  

    
      


