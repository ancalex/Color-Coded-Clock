#ifndef VERBISDISPLAY_H
#define VERBISDISPLAY_H

void LEDLightUP (int pos, int time) {
	//first digit
	int first = time/10;
	//second digit
	int last = time % 10;
	for (int i = 0; i < 4; i++) {
	leds[pos + i] = current_colors[first];
	leds[8 + pos + i] = current_colors[first];
	leds[4 + pos + i] = current_colors[last];
	leds[12 + pos + i] = current_colors[last];
	}
}

void ColorSetDisplay() {
	for (int i = 0; i < 8; i++) {
		leds[16 + i] = current_colors[i + 1];
		leds[40 + i] = current_colors[i + 1];
	}
}

void timeDisplay(byte h, byte m, byte s) {
	fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
	LEDLightUP(0,h);
	LEDLightUP(24,m);
	LEDLightUP(48,s);
	if (config.DisplayMode == 0) {
		ColorSetDisplay();
	}
}



#endif
