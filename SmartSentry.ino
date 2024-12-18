#define PIR_SENSOR_PIN 19    // Pin sensor PIR (sesuaikan dengan koneksi Anda)
#define BUZZER_PIN 18        // Pin buzzer (sesuaikan dengan koneksi Anda)

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(115200);
  
  // Atur pin sensor PIR sebagai input
  pinMode(PIR_SENSOR_PIN, INPUT);
  
  // Atur pin buzzer sebagai output
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Pesan awal
  Serial.println("Sistem Keamanan Rumah Siap!");
}

void loop() {
  // Baca status sensor PIR
  int pirStatus = digitalRead(PIR_SENSOR_PIN);
  
  // Jika sensor mendeteksi gerakan
  if (pirStatus == HIGH) {
    Serial.println("Gerakan Terdeteksi! Mengaktifkan Buzzer!");
    
    // Aktifkan buzzer
    aktivasiBuzzer();
    
    // Tunggu sebentar untuk mencegah multiple trigger
    delay(5000);  // 5 detik
  }
}

void aktivasiBuzzer() {
  // Pola bunyi buzzer untuk alarm
  for (int i = 0; i < 3; i++) {
    // Bunyi tinggi
    tone(BUZZER_PIN, 1000, 500);  // 1000 Hz selama 500 milidetik
    delay(600);
    
    // Bunyi rendah
    tone(BUZZER_PIN, 500, 500);   // 500 Hz selama 500 milidetik
    delay(600);
  }
  
  // Matikan buzzer
  noTone(BUZZER_PIN);
}