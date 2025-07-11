/*******************************************************************
 * Name:    8bit_binary_counter                                    *
 * Purpose: Displays numbers from 0 to 255 on LEDs in binary form. *
 * Author:  Pedro Bernardo                                         *
 *******************************************************************/

short GREEN_LED_13 = 13;
short BLUE_LED_12 = 12;
short BLUE_LED_11 = 11;
short BLUE_LED_10 = 10;
short BLUE_LED_9 = 9;
short BLUE_LED_8 = 8;
short BLUE_LED_7 = 7;
short GREEN_LED_6 = 6;

void setup() {
  pinMode(GREEN_LED_13, OUTPUT);
  pinMode(BLUE_LED_12, OUTPUT);
  pinMode(BLUE_LED_11, OUTPUT);
  pinMode(BLUE_LED_10, OUTPUT);
  pinMode(BLUE_LED_9, OUTPUT);
  pinMode(BLUE_LED_8, OUTPUT);
  pinMode(BLUE_LED_7, OUTPUT);
  pinMode(GREEN_LED_6, OUTPUT);
}

void loop() {
  _Bool bit_array[8];

  // Iterate through all values from 0 to 255
  for (short i = 0; i <= 255; i++) {
    String current_value = String(i, BIN);

    // Always display in 8 bit format. Example 111 -> 00000111
    while (current_value.length() < 8) {
      current_value = "0" + current_value;
    }

    // Get each bit and store it in an array
    for (short j = 0; j < 8; j++) {
      bit_array[j] = (_Bool)(current_value[j] - '0');  // Convert the string(bit) -> int(bit) -> bool
    }

    // Update LEDs based on bits
    if (bit_array[0]) //Most significant bit
      digitalWrite(GREEN_LED_6, HIGH);
    else
      digitalWrite(GREEN_LED_6, LOW);

    if (bit_array[1])
      digitalWrite(BLUE_LED_7, HIGH);
    else
      digitalWrite(BLUE_LED_7, LOW);

    if (bit_array[2])
      digitalWrite(BLUE_LED_8, HIGH);
    else
      digitalWrite(BLUE_LED_8, LOW);

    if (bit_array[3])
      digitalWrite(BLUE_LED_9, HIGH);
    else
      digitalWrite(BLUE_LED_9, LOW);

    if (bit_array[4])
      digitalWrite(BLUE_LED_10, HIGH);
    else
      digitalWrite(BLUE_LED_10, LOW);

    if (bit_array[5])
      digitalWrite(BLUE_LED_11, HIGH);
    else
      digitalWrite(BLUE_LED_11, LOW);

    if (bit_array[6])
      digitalWrite(BLUE_LED_12, HIGH);
    else
      digitalWrite(BLUE_LED_12, LOW);

    if (bit_array[7])
      digitalWrite(GREEN_LED_13, HIGH);
    else
      digitalWrite(GREEN_LED_13, LOW);

    delay(100); //Delay between each binary output
  }
}
