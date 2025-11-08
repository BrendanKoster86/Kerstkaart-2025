void modus_2(){
  slee_2();
  muts_2();
  vonkel();
  kar_2();
}


void slee_2() {
  if (millis() > sl_change + 250) {
    fase_sl ++;
    slee_lampjes_2();
    changes = true;
    sl_change = millis();
  }
}


void muts_2() {
  if (millis() > mu_change + 750) {
    fase_mu ++;
    muts_lampjes_2();
    changes = true;
    mu_change = millis();
  }
}

void kies_kar_sneeuw_2(){
  kar_sneeuw[0] = random(33, 43);
  kar_sneeuw[1] = random(33, 43);
  kar_sneeuw[2] = 0;
}

void kar_2(){
  /* lampjes bovenop het karretje
   * lampjes 11 t/m 15,  29 t/m 31 en 33 t/m 42
   */
  if (millis() > kr_change + 500) {
    kies_kar_sneeuw_2();
    kr_change = millis();
  }
  if (millis() > kr_change2 + 500) {
    for (int i = 33; i <= 42; i++){
      kar_lampjes(i);
    }
    changes = true;
    sn_change = millis();
  }
}

void slee_lampjes_2() {
  /* De besturing van lampjes 0 t/m 10
   * 1 = het lampje boven voor en 11 het achterste lampje
   * Basis idee is om golven wit en geel/oranje af te wisselen
   * In modus 2 wordt de hele rand erbij betrokken
   */
  if (fase_sl > 15) {
    fase_sl = 1;
  }
  uint32_t kleuren[] = {fade(GOUD, .5), fade(GOUD, .75), GOUD, fade(GOUD, .75), fade(GOUD, .5), fade(GROEN, .5), fade(GROEN, .75), GROEN, fade(GROEN, .75), fade(GROEN, .5), fade(ROOD, .5), fade(ROOD, .75), ROOD, fade(ROOD, .75), fade(ROOD, .5)};
  int j;
  for (int i = 0; i <= 31; i++) {
    if (i <= 18) {
      j = i + 16 - fase_sl;
    } else if (i >= 25){
      j = i + 11 - fase_sl;
    }
    while (j < 0) {
      j = j+15;
    }
    while (j >= 15) {
      j = j-15;
    }

    if ((i <= 18) || (i >= 25)) {
      pixels1.setPixelColor(i, kleuren[j]); 
    }
  }
  
}

void muts_lampjes_2(){
  /* De muts gaat om de lampjes op de rand van de muts... het bolletje is apart
   * Dit gaat om lampjes 20 t/m 24
   */
  if (fase_mu > 3) {
    fase_mu = 1;
  }
  if (fase_mu == 1) {
    pixels1.setPixelColor(22, fade(GEEL, .75));
    pixels1.setPixelColor(20, UIT);
    pixels1.setPixelColor(24, UIT);
  } else if (fase_mu == 2) {
    pixels1.setPixelColor(22, UIT);
    pixels1.setPixelColor(21, fade(GEEL, .75));
    pixels1.setPixelColor(23, fade(GEEL, .75));
  } else if (fase_mu == 3) {
    pixels1.setPixelColor(21, UIT);
    pixels1.setPixelColor(23, UIT);
    pixels1.setPixelColor(20, fade(GEEL, .75));
    pixels1.setPixelColor(24, fade(GEEL, .75));
  }
}