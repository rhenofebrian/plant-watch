# plant-watch
**Environment Monitoring & Plant Fall Detection (Blynk-Based App)**

Plant-Watch adalah aplikasi berbasis **Blynk IoT** untuk memantau suhu lingkungan/ruangan serta memberikan notifikasi peringatan apabila pot tanaman mengalami guncangan atau terjatuh. Aplikasi ini dirancang sebagai base app untuk sistem pemantauan tanaman berbasis IoT.

## 🚀 Fitur Utama
- **Real-time Temperature Monitoring**  
  Memantau suhu lingkungan menggunakan sensor DHT.

- **Plant Fall Detection**  
  Menggunakan ball switch untuk mendeteksi guncangan atau kondisi pot yang terjatuh.

- **Warning Notification**  
  Aplikasi akan mengirimkan peringatan melalui Blynk ketika terjadi pergerakan abnormal.

- **Live Dashboard**  
  Tampilan dashboard pada Blynk App untuk memonitor kondisi sensor secara langsung.

---

## 🛠️ Teknologi & Perangkat yang Digunakan
- **Microcontroller:** ESP32  
- **Sensors:**  
  - DHT11 / DHT22 (suhu & kelembapan)  
  - Ball Switch (fall detection)  
- **Platform:** Blynk IoT  
- **Additional Components:** Breadboard, jumper wires, USB cable

---

## 📡 Cara Kerja Singkat
1. ESP32 membaca data suhu dari sensor DHT.  
2. Ball switch mendeteksi adanya guncangan atau perubahan posisi pot.  
3. Data dikirim ke Blynk IoT.  
4. Pengguna bisa melihat suhu secara realtime di aplikasi Blynk.  
5. Jika terdeteksi pot berguncang atau jatuh, sistem mengirim notifikasi warning.
