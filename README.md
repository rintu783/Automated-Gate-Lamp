# Automated-Gate-Lamp
ESP32 Gate Lamp Control
This Arduino code is designed for controlling a gate lamp based on specific time events using an ESP32 microcontroller. The code connects to a WiFi network for time synchronization and automatically turns the lamp on and off at predefined times.

Requirements
Arduino IDE (version 1.8.19 or higher)
ESP32 Development Board
WiFi network credentials (SSID and password)
NTP (Network Time Protocol) server (default is "pool.ntp.org")

Configuration
Open the gatelamp.ino file in the Arduino IDE.

Set your WiFi network credentials:

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

Customize the NTP server if needed:
const char* ntpServer = "pool.ntp.org";

Adjust the GMT offset and daylight offset based on your timezone:

const long gmtOffset_sec = 19800;  // Example: GMT+5:30
const int daylightOffset_sec = 3600;  // Example: Daylight saving time offset

Define the lamp on and off times:

const String lampOnTime = "06:00:00";
const String lampOffTime = "12:00:00";

Set the GPIO pin connected to the lamp:

const int lampPin = 2;

Usage

Connect the ESP32 development board to your computer.
Open the Arduino IDE and upload the code to the ESP32.
Monitor the serial console for information about WiFi connection and time synchronization.
The lamp will automatically turn on and off at the specified times.

Troubleshooting
If you encounter any issues, refer to the troubleshooting section in the code or visit Espressif's ESPtool documentation for assistance.

License
This code is provided under the MIT License.