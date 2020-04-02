#ifndef STANDARDDISPLAY_H
#define STANDARDDISPLAY_H

void LEDLightUP (int pos1, int pos2, int time) {

	//first digit
	int first = time/10;
	//second digit
	int last = time % 10;
	leds[pos1] = current_colors[first];
	leds[pos1 + 1] = current_colors[last];
	//leds[pos1 - 1] = current_colors[last]; //alternate led mounting
	leds[pos2] = current_colors[last];
	leds[pos2 + 1] = current_colors[first];
	//leds[pos2 - 1] = current_colors[first]; //alternate led mounting
}

void ColorSetDisplay() {
	for (int i = 0; i < 10; i++) {
		leds[i] = current_colors[9 - i];
		//leds[i] = current_colors[i]; //alternate led mounting
	}
}

void timeDisplay(byte h, byte m, byte s) {
	fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
	LEDLightUP(10,6,h);
	LEDLightUP(12,4,m);
	LEDLightUP(14,2,s);
//	LEDLightUP(11,7,s); //alternate led mounting
//	LEDLightUP(13,5,m); //alternate led mounting
//	LEDLightUP(15,3,h); //alternate led mounting
	if (config.DisplayMode == 0) {
		ColorSetDisplay();
	}
}

#endif
