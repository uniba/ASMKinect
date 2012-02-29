#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"
#include "ofxKinect.h"

int
main() {
  ofAppGlutWindow window;
  ofSetupOpenGL(&window, 2560, 1024, OF_FULLSCREEN);
  ofRunApp(new ofApp());
}
