AI Greenhouse
AI Greenhouse - bu loyiha o'simliklarni kamera orqali nazorat qilish, Arduino orqali sug'orish va o'simliklarning holatini o'rganish, shuningdek, unumdorlikni oshirishga qaratilgan. Tizim ESP32-CAM modulidan foydalanib, veb-server orqali video uzatadi va turli sensorlar yordamida atrof-muhit parametrlarini monitoring qiladi.

Ishlatilgan Komponentlar
ESP32-CAM Moduli
Arduino Uno
Rele Moduli
Servo Motor
Tuproq Namligi Sensori
DHT22 Harorat va Namlik Sensori
Bluetooth Moduli (HC-05 yoki HC-06)
LCD Display (I2C interfeysi bilan)
Ulanish simlari
Breadboard
Fayllar Ko'rib Chiqilishi
arduino_uno.ino: Sensorlar, rele va servo motorni boshqarish uchun asosiy Arduino kodi.
app_httpd.cpp: ESP32-CAM uchun HTTP server funksiyalarini bajaradi.
camera_index.h: Kamera veb interfeysi uchun HTML va JavaScript.
camera_pins.h: ESP32-CAM modulining pin konfiguratsiyalarini belgilaydi.
Esp32_CameraWebServer.ino: ESP32-CAM veb serveri uchun asosiy kod.
partitions.csv: ESP32 uchun bo'lim sxemasi.
ci.json: Loyihaning maqsad platformalarini belgilovchi konfiguratsiya fayli.
Zarur Kutubxonalar
Arduino IDE'de ESP32 board paketi
DHT kutubxonasi
Servo kutubxonasi
SoftwareSerial kutubxonasi
ESPAsyncWebServer kutubxonasi
AsyncTCP kutubxonasi
Sozlash va O'rnatish
Apparat Ulanishlari:

DHT22 sensorini 2-piniga ulang.
Rele modulini 3-piniga ulang.
Servo motorni 4-piniga ulang.
Tuproq namligi sensorini analog pin A0-ga ulang.
Bluetooth modulini 10 (RX) va 11 (TX) pinlariga ulang.
Kutubxonalarni O'rnatish:

Arduino IDE-ni oching.
Sketch -> Include Library -> Manage Libraries menyusiga o'ting.
Zarur kutubxonalarni qidiring va o'rnating.
Kodini Yuklash:

Arduino IDE-da Esp32_CameraWebServer.ino faylini oching.
To'g'ri board va portni tanlang.
Kodni ESP32-CAM moduliga yuklang.
Funksionallik
Veb Server
ESP32-CAM kamera orqali video uzatadigan veb serverni joylashtiradi.
Server ESP32-CAM-ga tayinlangan IP manzili orqali kirish mumkin.
Monitoring
Tizim harorat, namlik va tuproq namligini o'qiydi.
Ma'lumotlar ulanish LCD ekranida ko'rsatiladi va Bluetooth orqali ham yuborilishi mumkin.
Boshqarish
Tuproq namligi o'qilmalari asosida rele boshqariladi.
Harorat o'qilmalari va Bluetooth buyruqlari asosida servo motor boshqariladi.
Bluetooth buyruqlari rele va servo motorni qo'lda boshqarish imkonini beradi.
Bluetooth Buyruqlari
1: Rele ni yoqing.
2: Rele ni o'chiring.
3: Servo ni 90 darajaga harakatlantiring.
4: Servo ni 0 darajaga harakatlantiring.
Loyihaning Umumiy Jarayoni
Ma'lumotlarni Yig'ish va Monitoring:

ESP32-CAM kamera orqali o'simliklarni kuzatadi va sensorlar orqali harorat, namlik va tuproq namligi ma'lumotlarini yig'adi.
Ma'lumotlarni ChatGPT-ga Yuborish:

Yig'ilgan ma'lumotlar ESP32 tomonidan ChatGPT API orqali yuboriladi.
Tahlil va Qaror Qabul Qilish:

ChatGPT yig'ilgan ma'lumotlarni tahlil qiladi va o'simlik holatini baholaydi.
Agar o'simlikning holati yomon bo'lsa, ChatGPT Arduino-ga o'simlikni yaxshilash uchun kerakli choralarni ko'rish buyruqlarini yuboradi.
Boshqarish:

Arduino sug'orish tizimini boshqaradi va kerak bo'lsa, rele orqali suv quyadi yoki servo motor yordamida ventilyatsiyani boshqaradi.
Kod Ko'rib Chiqilishi
arduino_uno.ino
Sensorlar, rele va servo motorni boshqarish uchun asosiy Arduino kodi.

app_httpd.cpp
ESP32-CAM uchun HTTP server funksiyalarini bajaradi.

camera_index.h
Kamera veb interfeysi uchun HTML va JavaScript.

camera_pins.h
ESP32-CAM modulining pin konfiguratsiyalarini belgilaydi.

Esp32_CameraWebServer.ino
ESP32-CAM veb serveri uchun asosiy kod.

partitions.csv
ESP32 uchun bo'lim sxemasi.

ci.json
Loyihaning maqsad platformalarini belgilovchi konfiguratsiya fayli.

Foydalanish
Veb Serverga Kirish:

Esp32_CameraWebServer.ino kodida sozlangan Wi-Fi tarmog'iga ulaning.
Veb brauzerda ESP32-CAM IP manzilini kiriting.
Avtomatik Boshqarish:

Rele va servo motor sensor o'qilmalari asosida avtomatik ravishda boshqariladi.
Bluetooth Orqali Qo'lda Boshqarish:

Bluetooth terminal dasturi orqali tizimga buyruqlar yuboring.
Eslatmalar
Bluetooth moduli smartfoningiz bilan to'g'ri ulanishini ta'minlang.
Tuproq namligi ostonasini o'z o'simliklaringiz uchun kerakli darajada sozlang.
LCD ekrani I2C pinlariga to'g'ri ulanganligini ta'minlang.
Nosozliklarni Tuzatish
Agar LCD ma'lumotlarni ko'rsatmasa, I2C manzili va ulanishlarni tekshiring.
Agar Bluetooth javob bermasa, to'g'ri ulanish va RX/TX ulanishlarini tekshiring.
Agar sensorlar to'g'ri o'qilmasa, ulanishlarni tekshiring va nosoz komponentlarni almashtiring.