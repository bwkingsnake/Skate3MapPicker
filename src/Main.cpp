#include "header.h"

int main() {

	bool spotMapsEnabled = getSpotMapsSetting();
	bool oneUpMapsEnabled = getOneUpMapsSetting();
	bool trueRandomEnabled = getTrueRandomSetting();

	trueRandom(spotMapsEnabled, oneUpMapsEnabled, trueRandomEnabled);  

}
