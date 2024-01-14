#include <WiFi.h>
#include <time.h>

const char* ssid = "SNet";
const char* password = "albusseverus";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 3600;

const String lampOnTime = "12:39:00";
const String lampOffTime = "12:40:00";

const int lampPin = 2;

void setup() {
  pinMode(lampPin, OUTPUT);
  Serial.begin(115200);

  connectToWiFiNetwork();
  synchronizeTime();
}

void loop() {
  delay(1000);
  handleTimeEvents();
}

void connectToWiFiNetwork() {
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected.");
}

void synchronizeTime() {
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  handleTimeEvents();
}

void handleTimeEvents() {
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }

  char currentDateTime[9];
  strftime(currentDateTime, sizeof(currentDateTime), "%H:%M:%S", &timeinfo);

  checkAndControlLamp(currentDateTime);
  printTimeInfo(&timeinfo);
}

void checkAndControlLamp(const char* currentTime) {
  int comparisonLampOn = strcmp(currentTime, lampOnTime.c_str());
  int comparisonLampOff = strcmp(currentTime, lampOffTime.c_str());

  if (comparisonLampOn == 0) {
    digitalWrite(lampPin, HIGH);
  } else if (comparisonLampOff == 0) {
    digitalWrite(lampPin, LOW);
  }
}

void printTimeInfo(struct tm* timeinfo) {
  // Print time-related information
  Serial.printf("%s %s %d %d %s\n",
                timeinfo, "%A, %B %d %Y %H:%M:%S",
                timeinfo, "%A",
                timeinfo, "%B",
                timeinfo, "%d",
                timeinfo, "%Y",
                timeinfo, "%H",
                timeinfo, "%I",
                timeinfo, "%M",
                timeinfo, "%S");

  // Print time variables
  char timeHour[3];
  strftime(timeHour, sizeof(timeHour), "%H", timeinfo);
  Serial.println(timeHour);

  char timeWeekDay[10];
  strftime(timeWeekDay, sizeof(timeWeekDay), "%A", timeinfo);
  Serial.println(timeWeekDay);

  Serial.println();
}
