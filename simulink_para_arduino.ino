// Toolbox for control to servo motor
#include <Servo.h>

// Create servo object to control a servo
Servo myServo1;

// Create a union to easily convert float to byte
union BtoF
{
  byte b[16];
  float fval;
};

// Name for Union
BtoF u1;

// Create to buffer
const int buffer_size = 16;
byte buf[buffer_size];

// Create the variable to be read
float myVal1;

// Setup
void setup()
{
  Serial.begin(115200);
  myServo1.attach(9);
}

// Main loop
void loop()
{
  if (Serial.available() > 0)
  {
    char caractere = Serial.read();    
    
    if (caractere == 'A')
    {
      // Read Matlab data
      myVal1 = readFromMatlab(caractere);

      // Control to Servo Motor
      int servoPosition1 = myVal1;
      servoPosition1 = constrain(servoPosition1, 0, 180);
      myServo1.write(servoPosition1);

    }
    else
    {
      Serial.write("Problema no header!");    
    }
  }
}

float readFromMatlab(char caractere)
{
  if (caractere == 'A')
  {
    // Read a sequence of bytes from the serial port until a specific character or sequence of characters is found
    int bytesRead = Serial.readBytesUntil('\r\n', buf, buffer_size);
    for (int i = 0; i < buffer_size; i++)
    {
      u1.b[i] = buf[i];
    }
    float output = u1.fval;
    return output;
  }
  else
  {
    Serial.write("Problema no header!");
  }
}