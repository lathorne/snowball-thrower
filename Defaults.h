
#ifndef _DEFAULTS_H_
#define _DEFAULTS_H_

// ONLY ONE OF THESE SHOULD BE UNCOMMENTED AT A TIME
#define BREED
// #define RELEASE

// ONLY ONE OF THESE SHOULD BE UNCOMMENTED AT A TIME
// #define DIVISOR 1 // this is for eggs that are 10,240 base steps
// #define DIVISOR 1.15 // this is for eggs that are 8,960 base steps
// #define DIVISOR 1.6 // this is for eggs that are base 6,400 steps
#define DIVISOR 2 // this is for eggs that are 5,120 base steps
// #define DIVISOR 2.667 // this is for eggs with 3,840 base steps (will need to revise due to decimal)
// #define DIVISOR 4 // this is for eggs that are 2,560 base steps
// #define DIVISOR 8 // this is for eggs that are 1,280 base steps

typedef enum {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	X,
	Y,
	A,
	B,
	L,
	R,
	THROW,
	NOTHING,
	TRIGGERS,
	HOME,
	PLUS
} Buttons_t;

typedef struct {
	Buttons_t button;
	uint16_t duration;
} command; 

#ifdef BREED
static const command step[] = {

	// Setup controller - necessary for normal Switch, but not for Switch Lite
	{ NOTHING,  250 },
	{ TRIGGERS,   5 },
	{ NOTHING,  150 },
	{ TRIGGERS,   5 },
	{ NOTHING,  150 },
	{ A,          5 },
	{ NOTHING,  250 },

	//***********************BREEDING LOOP************************//
	
	// PREREQS:
	// FULL PARTY, WITH NO OTHER EGGS
	// START ON ROUTE 5
	// MENU HOVERING OVER MAP OPTION
	// EGG READY IN ROUTE 5 DAY CARE
	// PROPER POKEMON IN THE DAY CARE
	// CARKOL IN SLOT THAT ISN'T SLOT ONE
	// START ON BIKE
	// TEXT SPEED SET TO FAST

	// MAY WANT OVAL AND SHINY CHARMS

	// NEED TO CHECK THE TIMES TO OPTIMIZE PROCESS
	// SET UP FOR DREEPY, WILL NOT WORK WITH ANYTHING THAT REQUIRES MORE STEPS
	// NEED TO MAKE SURE THERE IS ALWAYS AN EGG READY WHEN ONE HATCHES

	// MIGHT WANT TO SET UP BIKE BOOST TO MAKE THE PROCESS FASTER

	// This is where the repetition starts
	// Fly to nursery
	{ X, 	      5 }, // open menu
	{ NOTHING,	 35 },
	{ A,	      5 }, // select map
	{ NOTHING,	115 }, // wait for map to open
	{ UP,	      5 }, // move up to the nursery
	{ NOTHING,	  5 }, // wait a bit
	{ DOWN,	      3 }, // move back down to the nursery
	{ NOTHING,	 30 }, // wait for a bit
	{ A,	      5 }, // select nursery
	{ NOTHING,	 30 },
	{ A,	      5 }, // confirm flying to nursery
	{ NOTHING,	120 },
	{ PLUS,       5 },
	{ NOTHING,   30 },
	{ LEFT,      22 }, 
	{ UP,	      8 }, // move toward nursery lady
	
	// Grab egg from nursery - added 5 to each of the breaks for the french version
	{ A,	      5 },
	{ NOTHING,   65 }, // there's an egg, do you want it? 
	{ A, 	      5 }, // accept egg
	{ NOTHING,  195 }, // You have received an egg! 
	{ A,	      5 }, // confirm
	{ NOTHING,  105 }, // where do you want to send Egg to?
	{ A,	      5 }, // add to party
	{ NOTHING,  115 }, // select a Pokemon to swap from party
	{ A,	      5 }, 
	{ NOTHING,  105 }, // wait 
	{ A,          5 }, // first slot in party
	{ NOTHING,  115 }, // egg will be added to your party, this is very close here
	{ A,	      5 },
	{ NOTHING,   95 }, // Raise it well! // HAVING AN ISSUE HERE, SOMETIMES THE NEXT A MISSES AND IT STAYS HERE
	{ A,	      5 }, // egg received
	{ NOTHING,   85 }, // could be less time here

	// Run around with the egg until it hatches
	{ DOWN,		 30 },
	{ NOTHING,	 10 }, // wait
	{ PLUS,	      5 }, // getting on bike
	{ NOTHING,	 10 },
	{ RIGHT, 	700/DIVISOR },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600/DIVISOR }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600/DIVISOR },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600/DIVISOR }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600/DIVISOR }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600/DIVISOR }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600/DIVISOR }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600/DIVISOR }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	450/DIVISOR }, // Oh? could be less time here 

	{ A,		  5 },
	{ NOTHING,	700 }, // Egg is hatching
	{ A,		  5 },
	{ NOTHING,	150 } // Waiting for the screen to fade back to the player
	
	//***********************END OF BREEDING LOOP*****************//

};
#endif

#ifdef RELEASE
static const command step[] = {

	// Setup controller - necessary for normal Switch, but not for Switch Lite
	{ NOTHING,  250 },
	// { TRIGGERS,   5 },
    { NOTHING,    5 },
	{ NOTHING,  150 },
	// { TRIGGERS,   5 },
    { NOTHING,    5 },
	{ NOTHING,  150 },
	{ A,          5 },
    { NOTHING,    5 },

	// Skipping the first seven commands
	// { NOTHING,   50 },
	// { NOTHING,   30 }, 
	// { NOTHING,    5 },
	// { NOTHING,   30 }, 
	// { NOTHING,    5 },
	// { NOTHING,   30 },
	// { NOTHING,    5 },

	//***********************RELEASE LOOP*************************//

	// 1ST ROW
	
	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 
	{ RIGHT,      5 }, // move to the next pokemon
	{ NOTHING,	  5 }, 

	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 
	{ RIGHT,      5 }, // move to the next pokemon
	{ NOTHING,	  5 }, 

	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 
	{ RIGHT,      5 }, // move to the next pokemon
	{ NOTHING,	  5 }, 

	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 
	{ RIGHT,      5 }, // move to the next pokemon
	{ NOTHING,	  5 },

	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 
	{ RIGHT,      5 }, // move to the next pokemon
	{ NOTHING,	  5 }, 

	{ A,		  5 }, 
	{ NOTHING,	  5 }, 
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move to release choice
	{ NOTHING,    5 },
	{ A,		  5 }, // select to release
	{ NOTHING,	 35 }, // do you really want to release this pokemon?
	{ UP,		  5 }, 
	{ NOTHING,	  5 },
	{ A,		  5 }, // yes
	{ NOTHING,	 60 }, // --- was released. Bye, bye --_!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 	
	{ DOWN,		  5 }, // DONE WITH ROW: move to next row
	{ NOTHING, 	  5 },

	//END OF ROW - AFTER THE FIFTH TIME, NEED TO SKIP NEXT SECTION AND CHANGE BOXES INSTEAD

	{ LEFT,	      5 }, // going back to the start of the row
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },

	// CHANGING BOXES HERE

	// { R,		  5 }, // Change box
	// { NOTHING,   10 },
	// { UP,		  5 },
	// { NOTHING,	  5 },
	// { UP,		  5 }, 
	// { NOTHING,    5 },
	// { UP,		  5 },
	// { NOTHING,	  5 },
	// { UP,		  5 }, // move back to top row
	// { NOTHING,    5 },
	// { LEFT,	      5 }, 
	// { NOTHING,	  5 },
	// { LEFT,	      5 },
	// { NOTHING,	  5 },
	// { LEFT,	      5 },
	// { NOTHING,	  5 },
	// { LEFT,	      5 },
	// { NOTHING,	  5 },
	// { LEFT,	      5 }, // move back to first slot in box
	// { NOTHING,	  5 },
	
};
#endif 

// end of header file
#endif