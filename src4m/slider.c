/**
 * slider.c
 *
 * David J. Malan
 * malan@harvard.edu
 *
 * Demonstrates a slider.
 */

// standard libraries
#include <stdio.h>
#include <string.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/ginteractors.h>
#include <spl/gwindow.h>

int main(void)
{
    // instantiate window
    GWindow window = newGWindow(320, 240);

    // instantiate slider
    GLabel left = newGLabel("0");
    addToRegion(window, left, "SOUTH");
    GSlider slider = newGSlider(0, 100, 50);
    setActionCommand(slider, "sli");
    addToRegion(window, slider, "SOUTH");
    GLabel right = newGLabel("100");
    addToRegion(window, right, "SOUTH");

    // listen for events
    while (true)
    {
        // wait for event
        GActionEvent event = waitForEvent(ACTION_EVENT);

        // if window was closed
        if (getEventType(event) == WINDOW_CLOSED)
        {
            break;
        }

        // if action command is "slide"
        if (strcmp(getActionCommand(event), "sli") == 0)
        {
            printf("slider was slid to %i\n", getValue(slider));
        }
    }

    // that's all folks
    closeGWindow(window);
    return 0;
}
