/**
 * bounce.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Bounces a circle back and forth in a window.
 */

// standard libraries
#include <stdio.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);

    // instantiate circle
    GOval circle = newGOval(0,110, 20, 20);
    setColor(circle, "BLACK");
    setFilled(circle, true);
    add(window, circle);
    
    // initial velocity
    double velocity = 2.0;
    // bounce forever
    while (true)
    {
        // move circle along x-axis
        move(circle, 0,velocity);
        // bounce off right edge of window


        
        printf("circle's location: %.2f, %.2f\n", getX(circle) + getWidth(circle)/2, getY(circle) + getWidth(circle)/2);
        // linger before moving again
        pause(10);
    }
}
