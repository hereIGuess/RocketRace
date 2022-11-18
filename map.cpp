#include "map.h"

//originally had ofGetWindowWidth & Height but it would run an exception error
//(because this would run before the window was set)
//didn't bother trying to fix it though so enjoy 'random' numbers
ofVec2f screen = ofVec2f(500, 400);