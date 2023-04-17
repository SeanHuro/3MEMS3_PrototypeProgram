// Creates names for each connected pin
const int motorA = 5;
const int motorB = 6;
const int Button_Go = 10;
const int Button_StopUp = 11;
const int Button_StopDown = 12;

// Initialise variables
bool location = false; // Tells system where the platform is. false = bottom of stairs, true = top of stairs
bool running = false; // Tells the system if the motor is running
int i = 0; // For deceleration loop


void setup()
{
  // Initialises digital pins as an OUTPUT
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);

  // Initialises digital pins as an INPUT
  pinMode(Button_Go, INPUT);
  pinMode(Button_StopUp, INPUT);
  pinMode(Button_StopDown, INPUT);
}


void motor_deceleration(){ // Creates a function to stop the motor over 2 second period
  for (i=255; i>0; i--){
    analogWrite(motorA, i); // Motor speed decreases with each increment
    delay(2000/255); // i decreases by 1 approximately every 8 ms
  }
}


void motor_up(){ // Creates a function for the motor to raise the platform
  analogWrite(motorA, 255);  // Sets the speed of the motor to max
  digitalWrite(motorB, LOW); // Sets the motor to spin counter-clockwise
}


void motor_down(){ // Creates a function for the motor to lower the platform
  analogWrite(motorA, 255);  // Sets the speed of the motor to max
  digitalWrite(motorB, HIGH); // Sets the motor to spin clockwise
}


void loop(){

  if (digitalRead(Button_Go) == HIGH && location == false){ // Only runs if platforms as bottom of the stairs and Button_Go is pressed
    running = true; // Tells the system the motor is now running
    while (running == true){ // Continues to repeat as long as motor is running
      motor_up(); // Runs the motor up function

      if (digitalRead(Button_StopUp) == HIGH){ //Runs if Button_StopUp is pressed
        motor_deceleration(); // Runs deceleration function
        location = true; // Tells system platform is now at the top of the stairs
        running = false; // Tells system motor is no longer running; Stops while loop from repeating
        digitalWrite(motorA, LOW); // Sets motor speed to 0
      }
    }
  }

  if (digitalRead(Button_Go) == HIGH && location == true){ // Only runs if platforms as top of the stairs and Button_Go is pressed
    running = true; // Tells the system the motor is now running
    while (running == true){ // Continues to repeat as long as motor is running
      motor_down(); // Runs the motor down function

      if (digitalRead(Button_StopDown) == HIGH){ //Runs if Button_StopDown is pressed
        motor_deceleration(); // Runs deceleration function
        location = true; // Tells system platform is now at the bottom of the stairs
        running = false; // Tells system motor is no longer running; Stops while loop from repeating
        digitalWrite(motorA, LOW); // Sets motor speed to 0
      }
    }
  }
}



