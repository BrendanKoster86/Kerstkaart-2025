void modus_9() {
  if (millis() > kr_change + 120) {  // sneeuw valt langzaam
    fase_sl++;
    if (fase_sl > 20000) fase_sl = 0; // overflow vermijden, verder niets

    sneeuw_dwarrelt();
    changes = true;
    kr_change = millis();
  }
}

void sneeuw_dwarrelt() {
  for (int i = 0; i <= 42; i++) {
    // Basis: zacht goud warm kerstsfeertje (heel subtiel)
    pixels1.setPixelColor(i, fade(GOUD, 0.25));
  }

  // Elke update 2 sneeuwvlokken random erbij
  int flake1 = random(0, 43);
  int flake2 = random(0, 43);

  // Middenhelder lichtflitsjes
  pixels1.setPixelColor(flake1, fade(WIT, 0.75));
  pixels1.setPixelColor(flake2, fade(WIT, 0.45));

  // Soms een heldere vallende ster van boven naar beneden
  if (fase_sl % 10 == 0) {
    int k = fase_sl % 43;
    pixels1.setPixelColor(k, WIT); // echte highlight
  }
}