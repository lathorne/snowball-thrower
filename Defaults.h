
#ifndef _DEFAULTS_H_
#define _DEFAULTS_H_

// ONLY ONE OF THESE SHOULD BE UNCOMMENTED AT A TIME
#define BREED_3840
// #define BREED_5120
// #define BREED_8960
// #define BREED_10240
// #define RELEASE

// this will dictate both the amount of pokemon and the number of boxes released (still a work in progress)
#define NUM_BOXES 15

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

#ifdef BREED_3840
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
	{ RIGHT, 	700 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    400 }, // Oh? This needs testings

	{ A,		  5 },
	{ NOTHING,	700 }, // Egg is hatching
	{ A,		  5 },
	{ NOTHING,	150 } // Waiting for the screen to fade back to the player
	
	//***********************END OF BREEDING LOOP*****************//
};
#endif


#ifdef BREED_5120
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
	{ RIGHT, 	350 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    300 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	300 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    300 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	300 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    300 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	300 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    300 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	225 }, // Oh? could be less time here 

	{ A,		  5 },
	{ NOTHING,	700 }, // Egg is hatching
	{ A,		  5 },
	{ NOTHING,	150 } // Waiting for the screen to fade back to the player
	
	//***********************END OF BREEDING LOOP*****************//

};
#endif

#ifdef BREED_8960
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
	{ RIGHT, 	700 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, // Oh? This needs to be tested here

	{ A,		  5 },
	{ NOTHING,	700 }, // Egg is hatching
	{ A,		  5 },
	{ NOTHING,	150 } // Waiting for the screen to fade back to the player
	
	//***********************END OF BREEDING LOOP*****************//

};
#endif

#ifdef BREED_10240
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
	{ RIGHT, 	700 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 },
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	600 }, 
	{ UP, 		  5 },
	{ NOTHING,	 10 },
	{ LEFT,	    600 }, 
	{ DOWN,		  5 },
	{ NOTHING,	 10 },
	{ RIGHT,	450 }, // Oh? could be less time here 

	{ A,		  5 },
	{ NOTHING,	700 }, // Egg is hatching
	{ A,		  5 },
	{ NOTHING,	150 } // Waiting for the screen to fade back to the player
	
	//***********************END OF BREEDING LOOP*****************//

};
#endif

#ifdef RELEASE
static const command step[] = {

	// Setup controller - necessary for normal Switch, but not for Switch Lite (won't bother Switch Lite)
	// STARTS ON 0TH COMMAND
	{ NOTHING,  250 },
    { NOTHING,    5 },
	{ NOTHING,  150 },
    { NOTHING,    5 },
	{ NOTHING,  150 },
	{ A,          5 },
    { NOTHING,    5 },

	//***********************RELEASE LOOP*************************//

	// 1ST ROW
	// STARTS ON 7TH COMMAND
	{ A,		 20 }, 
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
	{ NOTHING,	 60 }, // --- was released. Bye, bye ---!
	{ A,		  5 }, // confirm
	{ NOTHING,    5 }, 


	{ RIGHT,      5 }, // move to the next pokemon THIS COMMAND 21
	{ NOTHING,	  5 }, 
	{ NOTHING,   10 },
	// THIS SECTION IS 16 COMMANDS LONG, NEED TO TRAVERSE THIS FIVE TIMES AND THEN THE SECTION BELOW ONCE 
		
	{ DOWN,		  5 }, // DONE WITH ROW: move to next row THIS IS COMMAND 24
	{ NOTHING, 	  5 },
	{ LEFT,	      5 }, // going back to the start of the row
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 }, // THIS IS COMMAND 35
	// END TRAVERSING THIS SECTION ONCE

	// CHANGING BOXES HERE
	{ NOTHING,   10 },
	{ R,		  5 }, // Change box THIS IS COMMAND 37
	{ NOTHING,   15 },
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, 
	{ NOTHING,    5 },
	{ UP,		  5 },
	{ NOTHING,	  5 },
	{ UP,		  5 }, // move back to top row
	{ NOTHING,    5 },
	{ LEFT,	      5 }, 
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 },
	{ NOTHING,	  5 },
	{ LEFT,	      5 }, // move back to first slot in box
	{ NOTHING,	  5 },
	
};
#endif 

// end of header file
#endif