#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alsa/asoundlib.h>

int main() {
	snd_rawmidi_t* midiout = NULL;
	snd_rawmidi_open(NULL, &midiout, "virtual", 0);

	char line[100];
	int nbr = 0;
	FILE *fp;
	fp = popen("adb logcat", "r");
	while (1) {
		fgets(line, sizeof(line), fp);
		if (memcmp(line, "D/HexKey::p",11) == 0) {
			snd_rawmidi_write(midiout, (char[]){0x90, atoi(line+23), 100}, 3);
			printf("play :");
			printf(line+23);
		}
		if (memcmp(line, "D/HexKey::s",11) == 0) {
			snd_rawmidi_write(midiout, (char[]){0x90, atoi(line+23), 0}, 3);
			printf("stop :");
			printf(line+23);
		}
	}

	snd_rawmidi_close(midiout);
	midiout = NULL;
	return 0;
}

