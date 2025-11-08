void modus_10() {
  if (millis() > kr_change + 70) {   // tempo van de komeet
    fase_sl++;
    if (fase_sl > 42) fase_sl = 0;

    komeet();
    changes = true;
    kr_change = millis();
  }
}

void komeet() {
  // Eerst alles zacht goud
  for (int i = 0; i <= 42; i++) {
    pixels1.setPixelColor(i, fade(GOUD, 0.5));
  }

  // Komeet kop (helderste punt)
  pixels1.setPixelColor(fase_sl, fade(WIT, 0.6));

  // Staart: 4 pixels achter de kop, steeds zachter
  int pos = fase_sl;
  for (uint8_t t = 1; t <= 4; t++) {
    pos--;
    if (pos < 0) pos = 42;     // wrap-around

    float strength = (float)(4 - t) / 4.0;  // 1.0 → 0.25
    pixels1.setPixelColor(pos, fade(WIT, strength));
  }
}