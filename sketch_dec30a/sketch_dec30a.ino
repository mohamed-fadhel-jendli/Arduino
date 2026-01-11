#include <DHT.h>
#include <LiquidCrystal_I2C.h>

DHT dht(2, DHT11);
int temp; 
int humidity;

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  dht.begin();
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  temp = dht.readTemperature();
  humidity = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Temperature : ");
  lcd.print(temp);
  lcd.print(" C ");
  lcd.setCursor(0,1);
  lcd.print("Humidity : ");
  lcd.print(humidity);
  lcd.print(" % ");
}
