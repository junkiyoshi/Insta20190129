#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int scale = 30;

	this->cam.begin();
	ofRotateX(-90);

	for (int v = 0; v < 360; v += 10) {

		int u_start = v * 5 + ofGetFrameNum();
		for (int u = u_start; u <= u_start + 330; u += 5) {

			int tmp_u = u % 360 - 180;
			if (tmp_u > -170 && tmp_u < 170) {
			
				ofDrawLine(this->make_apple_point(tmp_u * DEG_TO_RAD, v * DEG_TO_RAD) * scale, this->make_apple_point((tmp_u + 10) * DEG_TO_RAD, v * DEG_TO_RAD) * scale);
			}
		}

		ofDrawLine(this->make_apple_point(-180 * DEG_TO_RAD, v * DEG_TO_RAD) * scale, this->make_apple_point(-160 * DEG_TO_RAD, v * DEG_TO_RAD) * scale);
		ofDrawLine(this->make_apple_point(170 * DEG_TO_RAD, v * DEG_TO_RAD) * scale, this->make_apple_point(180 * DEG_TO_RAD, v * DEG_TO_RAD) * scale);

		int tmp_u = (u_start + 350) % 360 - 180;
		if (tmp_u > -170 && tmp_u < 170) {
		
			ofDrawSphere(this->make_apple_point(tmp_u * DEG_TO_RAD, v * DEG_TO_RAD) * scale, 5);
		}
	}	

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_apple_point(float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち リンゴ局面 apple surface P.33 

	float x = (4 + 3.8 * cos(u)) * cos(v);
	float y = (4 + 3.8 * cos(u)) * sin(v);
	float z = -5 * log10(1 - 0.315 * u) + 5 * sin(u) + 2 * cos(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
