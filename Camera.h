/*
Author: Erik Babonis and Rylee Hopper
Project 2 
Simulated Pi-Camera interface used for capturing frames during car operation.
*/


#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>


//Minimal simulated Pi Camera
class Camera {
public:
    Camera() = default;
    ~Camera() = default;

    // Start streaming
    void startStreaming() {
        std::cout << "Camera Streaming started.\n";
    }

    // Stop streaming
    void stopStreaming() {
        std::cout << "Camera Streaming stopped.\n";
    }

    // Capture a single frame at car coords
    void captureFrame(float x, float y) {
        std::cout << "Camera Capturing frame at (" << x << ", " << y << ")\n";
    }
};

#endif
