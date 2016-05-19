//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// height and width of paddle
#define PADDLE_HEIGHT 10
#define PADDLE_WIDTH 100

// height and width of brick
#define BRICK_HEIGHT 10
#define BRICK_WIDTH 38

// height and width of ball
#define BALL_HEIGHT 25
#define BALL_WIDTH 25

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(int argc, char *argv[])
{
    // seed pseudorandom number generator
    srand48(time(NULL));
    
    // INITIALIZE VELOCITY
    double velocity = 3;
    double x_velocity = velocity;
    double y_velocity = velocity;

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
playagain:
	waitForClick();
	setLocation(ball, (getWidth(window) - getWidth(ball))/2, (getHeight(window) - getHeight(ball))/2);	
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {	
    	//MAKE THE PADDLE FOLLOW CURSOR
        // check for mouse event
   	    GEvent cursor = getNextEvent(MOUSE_EVENT);
        // if we heard one
        if (cursor != NULL)
        {
        	printf("hello world");
            // if the event was movement
            if (getEventType(cursor) == MOUSE_MOVED)
            {
                // make the paddle horizontally follow the cursor
                double x = getX(cursor) - getWidth(paddle)/2;
                double y = HEIGHT - 10*PADDLE_HEIGHT;
                setLocation(paddle, x, y);
            }
        }
     
      
        // make the ball bounce off the edges
       
        move(ball, x_velocity,y_velocity);
        
        // bounce off right or left edge of window 
        if ((getX(ball) + getWidth(ball) >= getWidth(window)) || getX(ball) <= 0 )
        {
            x_velocity = -x_velocity;
        }
		//bounce off the top edge of window
	    else if (getY(ball) <= 0)
 		{
 			y_velocity = -y_velocity;
 		}
        // linger before moving again
        pause(20);
 
 		
 		
 		// BOUNCE IF BALL COLLIDES WITH SOMETHING
 		GObject collision = detectCollision(window, ball);
 		
 		//bounce up if collide with paddle
 		if (strcmp(getType(collision), "GRect") == 0)
 		{
 			y_velocity = -y_velocity;
 			if(collision != paddle)
 			{
 				removeGWindow(window, collision);
 				points++;
 				setSize(paddle, getWidth(paddle)*.96, PADDLE_HEIGHT);
 			}
 		}
 		
 		//LOSE one life if ball collide the bottom
 		if (getY(ball) + getHeight(ball) >= getHeight(window))
 		{
 			lives--;
 			if(lives <=0)
 				goto gameover;
 				
 			goto playagain; 			
 		}   
 		updateScoreboard(window, label, points); 
 		
 		if (points == ROWS*COLS)
 			goto gameover;
    }
    
    
    
//THE GAME IS OVER *****************            
gameover:
	// wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

//********************************************************************************************************/

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
	//y-location of first brick
	int y = 80;
    // TODO
   	for(int row = 0; row < ROWS; row++)
   	{
   	//x-location of first brick
 	int x = 1;  		
   		for(int col = 0; col < COLS; col++)
   		{
			
   			GRect brick = newGRect(x, y, BRICK_WIDTH, BRICK_HEIGHT);
   			setFilled(brick, true);
   			//fill the brick with colors based on their row number
   			
   			//MAKE VT just to look cool
   			if((col == 1 && row < 4) || (col == 3 && row < 4) || (col==2 && row == 4)
   				|| (col == 6 && row == 0) || (col == 8 && row == 0) || (col == 7))
   			{
   				setColor(brick,"BLUE");
   				goto addtowindow;
   			}	
   			//fill the bricks with colors row by row
   			switch(row)
   			{
   				case 0:
   					setColor(brick,"RED");break;
   				case 1:
   					setColor(brick, "ORANGE");break;
   				case 2:
   					setColor(brick, "YELLOW"); break;
   				case 3:
   					setColor(brick, "GREEN"); break;
   				case 4:
   					setColor(brick, "CYAN"); break;
   			}
   			addtowindow:
   				add(window, brick);
   				//same row, but move to next column
   				x+=40;
   		}
   		//move to next row, after reaching the last column
   		y+=12;
   	}
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval((WIDTH - BALL_WIDTH)/2, (HEIGHT - BALL_HEIGHT)/2, BALL_WIDTH, BALL_HEIGHT);
    setFilled(ball, true);
    setColor(ball, "GRAY");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
	//declare a new rectangular, fill with BLUE, then add to window;
    GRect paddle = newGRect((WIDTH - PADDLE_WIDTH)/2, HEIGHT - 10*PADDLE_HEIGHT, PADDLE_WIDTH, PADDLE_HEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "BLUE");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    add(window, label);
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
