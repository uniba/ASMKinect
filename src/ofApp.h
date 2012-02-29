#include "ofxKinect.h"

#pragma once

class ofApp: public ofBaseApp {
private:
  
  int step;
  int width;
  
  vector<ofPrimitiveMode> mode;
  int currentMode;
  
  ofEasyCam cam;
  ofxKinect kinect;
  
public:
  
  void setup() {
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetFrameRate(60);
    ofSetSmoothLighting(true);
    ofBackground(0xff, 0xff, 0xff);
    
    step = 2;
    width = 1;
    
    mode.push_back(OF_PRIMITIVE_TRIANGLES);
    mode.push_back(OF_PRIMITIVE_TRIANGLE_STRIP);
    mode.push_back(OF_PRIMITIVE_TRIANGLE_FAN);
    mode.push_back(OF_PRIMITIVE_LINES);
    mode.push_back(OF_PRIMITIVE_LINE_STRIP);
    mode.push_back(OF_PRIMITIVE_LINE_LOOP);
    mode.push_back(OF_PRIMITIVE_POINTS);
    
    currentMode = 0;
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
  };
  
  void update() {
    kinect.update();
    
    if (!kinect.isFrameNew()) {
      return;
    }
  };

  void draw() {
    ofSetColor(0x0, 0x0, 0x0);
    cam.begin();
    
    int w = kinect.getWidth();
    int h = kinect.getHeight();
    ofMesh mesh;
    
    mesh.setMode(mode[currentMode]);
    
    for (int y = 0; y < h; y += step) {
      for (int x = 0; x < w; x += step) {
        if (kinect.getDistanceAt(x, y) < 0) {
          continue;
        }
        mesh.addColor(kinect.getColorAt(x, y));
        // mesh.addColor(ofColor(0xf, 0xf, 0xf));
        mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
      }
    }
    
    glPointSize(width);
    glLineWidth(width);
    
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    glDisable(GL_DEPTH_TEST);
    ofPopMatrix();
    
    cam.end();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
  };
  
  void exit() {
    kinect.close();
  }

  void keyPressed(int key) {
    switch(key) {
      case 'm':
        currentMode = ++currentMode % mode.size();
        break;
      case '<':
        if (--step < 1) {
          step = 1;
        }
        break;
      case '>':
        ++step;
        break;
      case '-':
        --width;
        break;
      case '+':
        ++width;
        break;
    }
  };
  
  void keyReleased(int key) {
    
  };
  
  void mouseMoved(int x, int y) {
    
  };
  
  void mouseDragged(int x, int y, int button) {
    
  };

  void mousePressed(int x, int y, int button) {
    
  };
  
  void mouseReleased(int x, int y, int button) {
    
  };
  
  void windowResized(int w, int h) {
    
  };
  
  void dragEvent(ofDragInfo dragInfo) {
    
  };
  
  void gotMessage(ofMessage msg) {
    
  };
};
