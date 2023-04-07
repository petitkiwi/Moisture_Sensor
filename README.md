# Moisture_Sensor
*27/03/2023*

A moisture sensor was fabricated to measure the moisture levels in a prototype during the drying phase, which is crucial when using biomaterials that contain water for manufacturing prototypes. One of the primary concerns with such materials is the shrinkage that occurs during the drying process, leading to changes in the prototype's shape and size. Proper ingredient selection and accurate anticipation of the shrinkage is thus essential to ensuring the prototype's final dimensions match the original design. The moisture sensor used in this study consists of several components, including an Arduino Nano microcontroller, an LED, a resistor, wires, and a display screen. This setup provides real-time feedback on material humidity levels, indicating whether they were "wet" or "dry," and displaying the corresponding percentage of humidity.

The given code is an Arduino program written in C++ that reads the analog value from a moisture sensor connected to the A0 pin of the Arduino board and displays the moisture level on a 0.96 inch I2C OLED screen using the Adafruit_SSD1306 and Adafruit_GFX libraries. The program also controls an LED, which lights up brighter as the moisture level increases.

In the main loop, the program reads the analog value from the sensor and converts it into a percentage value for the moisture level (using the map function). The moisture level is then printed on the OLED screen and used to adjust the brightness of the LED. The program also determines if the moisture level is above or below a certain threshold (50\% in this case), and displays the corresponding status on the OLED screen.


The program can be updated (comments) to include a new functionality that saves the time, moisture level, and status (dry or wet) in a CSV file via USB, using the Arduino's built-in Serial communication.

This program can be useful in applications where moisture levels need to be monitored and recorded over time, such as in the case of  soft robotics prototypes using bioplastics. By adding the capability to save the data to a CSV file, the program can be used to collect data over an extended period, which can be analyzed and used to observe the moisture evolution over time. The program can be further modified to include additional sensors and data logging capabilities, allowing for a more comprehensive understanding of the properties of the bioplastics soft robotics prototypes. Such observations can help in optimizing the materials and design for better performance and longevity.
