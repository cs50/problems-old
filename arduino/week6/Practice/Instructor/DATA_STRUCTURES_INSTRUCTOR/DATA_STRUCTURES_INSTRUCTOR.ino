/****************************************************************************
 * DATA_STRUCTURES
 *
 * Computer Science 50
 * Christopher Bartholomew
 * Data Structure Solutions Created by: Nate Hardison 
 * 
 * Choose one of the three methods to create various data structures using lights on the arduino board.
 *
 * Demonstrates use of stacks/queues/single linked lists
 * 
 * BONUS:
 * 1. Create one using a Hash Table / Hash Function
 ***************************************************************************/
 
#include <stdlib.h>
#include <avr-libc.h>
#include <arduino.h>
#define MAX_PINS 6
#define EMPTY 0

void setup()
{
	// begin reading from serial
	Serial.begin(9600); 

        // init pins
        init_pinmode();
        
	// give user options
	display_menu();      
}

/*********************************************************************************************************************************************
 * TODO: Queue
 **********************************************************************************************************************************************/
 
// data structure that is used for Queue 
typedef struct
{
    // the index of the first element in the queue
    int head;

    // storage for the elements in the queue
    int pins[MAX_PINS];

    // the size of the queue
    int size;
}
queue;

// queue pin config
int queue_pins[MAX_PINS] = { 1, 2, 3, 4, 5, 6 };
// declare a queue (as a global variable)
queue q;

bool enqueue(int num)
{
      // if we're at capacity, we can't add anything more to our queue
    if (q.size == MAX_PINS)
    {
        return false;
    }

    // calculate the index of the "last" slot in the queue
    int last = (q.head + q.size) % MAX_PINS;

    // add the new element to our queue
    q.pins[last] = num;

    // adjust the size appropriately
    q.size++;

    return true;
}

bool dequeue(void)
{
      // if nothing's in our queue, we can't retrieve anything!
    if (q.size == 0)
    {
        return NULL;
    }

    // grab the first element in our queue
    int first = q.pins[q.head];

    // adjust the head of our queue to point to the next element
    // wrap back to the beginning if necessary
    q.head = (q.head + 1) % MAX_PINS;

    // adjust the size appropriately
    q.size--;

    return first;
}

/*********************************************************************************************************************************************
 * END
 **********************************************************************************************************************************************/

/*********************************************************************************************************************************************
 * TODO: Stack
 **********************************************************************************************************************************************/
 
 // Data Structure that is used for Stack
typedef struct
{
    // storage for the elements in the stack
    int pins[MAX_PINS];

    // the number of elements currently in the stack
    int size;
}
stack;

// stack pin config
int stack_pins[MAX_PINS] = { 6, 5, 4, 3, 2, 1 };

// declare a stack (as a global variable)
stack s;

// global variable used for serial read
int incomingByte = 0;  

bool push(int num)
{
      // if we're at capacity, we can't add anything more to our stack
    if (s.size == MAX_PINS)
    {
        return false;
    }

    // add the new element to our stack
    s.pins[s.size] = num;

    // adjust the size appropriately
    s.size++;

    return true;
}

int pop(int i)
{
  
    // if nothing's in our stack, we can't retrieve anything!
    if (s.size == 0)
    {
        return NULL;
    }

    // grab the last element in our stack
   int last = s.pins[s.size - 1];

    // adjust the size accordingly
    s.size--;

    return last;
}
/*********************************************************************************************************************************************
 * END
 **********************************************************************************************************************************************/

/*********************************************************************************************************************************************
 * TODO: Linked List
 **********************************************************************************************************************************************/
 
 // data strcuture that is used for Link List
typedef struct led_node
{
        // the pin 
	int pin; 

        // the next pin
 	struct led_node* next;
}
led_node;

//  single linked list pin config
int base_pins[5] = { 1, 2, 3, 5, 6 }; 
int insert_pin = 4;

// declare the very first "led_node" in our list
led_node* first = NULL;
static struct led_node* build_node(int i)
{
    led_node* new_node = (led_node *)malloc(sizeof(led_node));
    if (new_node == NULL)
    {
        Serial.println("sll: error: Out of heap memory\n");
    }
    new_node->pin = i;
    new_node->next = NULL;
    return new_node;

}

void prepend(int i)
{
    led_node* new_node = build_node(i);

    // the first node of our list will be the second node of our new one
    new_node->next = first;

    // our new node is now going to be the first node
    first = new_node;
}

static void insert_after(led_node* n, int i)
{
    if (n != NULL)
    {
        led_node* new_node = build_node(i);
        new_node->next = n->next;
        n->next = new_node;
    }
}

bool contains(int i)
{
    for (led_node* n = first; n != NULL; n = n->next)
    {
        if (n->pin == i)
        {
            return true;
        }
    }
    return false;    
}

/*********************************************************************************************************************************************
 * END
 **********************************************************************************************************************************************/

void display_menu()
{
	int menu_digit = 0;
        int input = 0;
	Serial.println("=========MAIN MENU==========");
        Serial.println("USAGE: menu_item pin");
  	Serial.println("1. add pins 	(Linked List Only)");
	Serial.println("2. insert pins  (Linked List Only)");
	Serial.println("3. push 	(Stack Only)");
	Serial.println("4. pop  	(Stack Only)");
	Serial.println("5. enqueue 	(Queue Only)");
	Serial.println("6. dequeue 	(Queue Only)");
	Serial.println("9. bye");
	Serial.println("==========================");
	
       
	do
  	{
    	// send data only when you receive data:
     	if (Serial.available() > 0) 
     	{
      		// read the incoming byte:
      		incomingByte = Serial.read();
    		
			// assign actual digit value to variable
			menu_digit = incomingByte - '0';
			
			switch(menu_digit)
			{
				case 1:
					Serial.println("adding pins");
					// add pin
                                        display_menu();
				break;
				case 2:
					Serial.println("inserting pins");
					// remove pin
                                        display_menu();
				break;
				case 3:
					Serial.println("Pushing Pins On");
                                          display_menu();
				break;
				case 4:
					// toggle pin
					Serial.println("Popping Pins Off");
                                        display_menu();
				break;
				case 5:
					// toggle pin
					Serial.println("Enqueue Pins");
                                        display_menu();
				break;
				case 6:
					// toggle pin
					Serial.println("Dequeue Pins");
                                        display_menu();
				break;
				case 9:
					Serial.println("Bye!");
				break;
				default:
				break;
			}
		
    	}
	// continue to prompt until max pins have been reached
  	} while(menu_digit != 9);

}

void init_pinmode()
{
    for(int i=1;i<=6;i++)
        pinMode(i,OUTPUT);
}

void toggle(int pin)
{
  (digitalRead(pin) == HIGH) ? digitalWrite(pin, LOW) : digitalWrite(pin, HIGH);
}


void loop()
{
		

}

