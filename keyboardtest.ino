#include <Keyboard.h>
#include <Mouse.h>



const byte Pin_Mouse_Left = 7;
const byte Pin_Mouse_Right = 8;
const byte Pin_Reload = 9;
const byte Pin_Recenter = 10;
const byte Pin_Joybutton = 4;



boolean state = true;

void setup() {  
  Serial.begin(9600);
  Keyboard.begin();
  Mouse.begin();
  pinMode(Pin_Mouse_Left, INPUT_PULLUP); 
  pinMode(Pin_Mouse_Right, INPUT_PULLUP);
  pinMode(Pin_Reload, INPUT_PULLUP);
  pinMode(Pin_Recenter, INPUT_PULLUP);
  pinMode(Pin_Joybutton, INPUT_PULLUP);

}

void loop() {

  int sensorValueY = analogRead(A1);
  int sensorValueX = analogRead(A0);

   if (digitalRead(Pin_Mouse_Left) == LOW){
      Mouse.press(MOUSE_LEFT);
      Serial.println("press mouse left");
      //시청자 분께서 하는 말씀 잘 듣는 척 하기.
} else {
      Mouse.release(MOUSE_LEFT);

}

if (digitalRead(Pin_Mouse_Right) == LOW){
      Mouse.press(MOUSE_RIGHT);
      Serial.println("press mouse right");
} else {
      Mouse.release(MOUSE_RIGHT);
}

if (digitalRead(Pin_Reload) == LOW){
      Keyboard.press('r');
      Serial.println("press Reload");
} else {
      Keyboard.release('r');
}

if (digitalRead(Pin_Recenter) == LOW){
      Keyboard.press(KEY_BACKSPACE);
      Serial.println("press Recenter");
} else {
      Keyboard.release(KEY_BACKSPACE);
}

if (digitalRead(Pin_Joybutton) == LOW){
      Keyboard.press('p');
      Serial.println("press Joybutton");
} else {
      Keyboard.release('p');
}


 { // Y+

      if (sensorValueY < 300)
      {
        Keyboard.press('w');
      }
      else
      {
        Keyboard.release('w');
      }
    }

  

  { //Y-

      if (sensorValueY > 700)      {
        Keyboard.press('s');
      }
      else
      {
        Keyboard.release('s');
      }
    }

  

  { //X

      if (sensorValueX < 300)
      {
        Keyboard.press('a');
      }
      else
      {
        Keyboard.release('a');
      }
    }


  { //X-

      if (sensorValueX > 700)
      {
        Keyboard.press('d');
      }
      else
      {
        Keyboard.release('d');
      }

  }
  delay (20);
}
