#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"
#include "ofxKinect.h"

int
main() {
  ofAppGlutWindow window;
  ofSetupOpenGL(&window, 640, 480, OF_WINDOW);
  ofRunApp(new ofApp());
}
