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
 * 1. Create one using a Hash Table / Hash Function - however you must force one collision and handle it using a linked list!
 ***************************************************************************/
 
#include <stdlib.h>
#include <avr-libc.h>
#include <arduino.h>
#define MAX_PINS 6
#define EMPTY 0

// global variable used for serial read
int incomingByte = 0;  

// the counter that is used as the loader
int load_counter = 0;

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

// queue pin config - optional - use for loading pins
int queue_pins[MAX_PINS] = { 2, 3, 4, 5, 6, 7 };

// declare a queue (as a global variable)
queue q;

/*
 * used to enqueue a number
 */  
bool enqueue(int num)
{
    /* Remove Me
    
    // TODO!
    // if we're at capacity, we can't add anything more to our queue - what should we return?

    // calculate the index of the "last" slot in the queue
    // TODO!

    // add the new element to our queue
    // TODO!
    
    // toggle the light
    toggle(num);
    
    // adjust the size appropriately
    // TODO!
    
    */
    return true;
}

/*
 * used to dequeue a number
 */  
bool dequeue(void)
{
    /* Remove Me
    // TODO!
    // if nothing's in our queue, we can't retrieve anything!
    
    // TODO!
    // grab the "first" element in our queue
     
     
    // FREE FOR YOU!
    // adjust the head of our queue to point to the next element
    // wrap back to the beginning if necessary
    q.head = (q.head + 1) % MAX_PINS;
    
    // toggle the light
    toggle(first)
    
    // TODO!
    // adjust the size appropriately
    
    return first;
    */
 
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
int stack_pins[MAX_PINS] = { 2, 3, 4, 5, 6, 7 };

// declare a stack (as a global variable)
stack s;

/*
 * used to "push" on to the top of the stack
 */  
bool push(int num)
{
    /* Remove Me
    // TODO! 
    // if we're at capacity, we can't add anything more to our stack
    
    // TODO!
    // add the new element to our stack
    
    // toggle the light
    toggle(num);
    
    // TODO!
    // adjust the size appropriately
    */
    return true;
}

/*
 * used to "pop" off the top of the stack
 */  
int pop()
{  
     /* Remove Me
    // TODO! 
    // if nothing's in our stack, we can't retrieve anything!
    
    // FREE FOR YOU!
    // grab the last element in our stack
    int last = s.pins[s.size - 1];
    
    // toggle the light
    toggle(last);
   
    // TODO 
    // adjust the size accordingly
    
        return last;
    */

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
int base_pins[5] = { 2, 3, 5, 6, 7 }; 

// for "insert after" set the previous pin
int previous_pin = 3;

// the pin you want to insert
int insert_pin   = 4;

// declare the very first "led_node" in our list
led_node* first = NULL;

/*
 * used to build a node!
 */  
static struct led_node* build_node(int i)
{
    
    /* Remove Me
    // TODO!
    // malloc a new led_node defined as "new_node" that is the size of a led_node
    // NOTE: You must "cast" malloc's return to a (led_node*) type (arduino only))
    
    if (new_node == NULL)
    {
        Serial.println("sll: error: Out of heap memory\n");
    }
    
    new_node->pin  = i;
    new_node->next = NULL;
    return new_node;
    */

}

/*
 * used to build a node and place it at the beginning of the list
 */  
void prepend(int i)
{
   /* Remove Me
    led_node* new_node = build_node(i);

    // the first node of our list will be the second node of our new one
    new_node->next = // what node should this be?;
    
    // TODO!
    // toggle light
    
    // our new node is now going to be the first node
    first = // which means what node should this be?;
    */
}

/*
 * used to check the length of the linked list
 */
int length(void)
{
    /* Remove Me
    int length = 0;
    
    // TODO!
    // for each led_node - starting with first; and as long as the led node is not null, the next increament should be equal to the next node :)
    // i.e. not all for-loops HAVE to be ints :)
    for ()
    {
        // TODO!
        // what should be incremented here?
    }
    return length;
    */
}

/*
 * used to build a node and insert it after a node that exists already
 */  
static void insert_after(led_node* n, int i)
{
    /* Remove Me
    if (n != NULL)
    {
        led_node* new_node = build_node(i);
        
        // TODO!
        // point the new node's next member to n's next node
        
        // TODO!
        // point the current node's next member to the new node
        
        // toggle light
        toggle(i);
    }
    */
}

/*
 * used to append to the last part of the list
 */
void append(int i)
{
  
    /* Remove Me
    // track the previous node to the current one as well, since it's
    // otherwise impossible to insert *before* the current node
    led_node* prev = NULL;
    
    // TODO!
    // for each led_node; and as long as the led node is not null, the next increament should be equal to the next node :)
    // i.e. not all for-loops HAVE to be ints :)
    for ()
    {
        // make sure to update the prev pointer on every iteration!
        prev = cur;
    }

    // if prev is NULL, that means that the element belongs first
    if (prev == NULL)
    {
        prepend(i);
    }
    else
    {
        // aren't you glad that you already wrote this one? ;-)
        insert_after(prev, i);   
    }
    */
   
}

/*
 * used to check if a matching data structure pin is there - if so - return the address
 */
struct led_node* contains(int pin)
{
    /* Remove Me
    // TODO!
    // for each led_node - starting with first; and as long as the led node is not null, the next increament should be equal to the next node :)
    // i.e. not all for-loops HAVE to be ints :)
    for ()
    {
      
        // if the node's pin is equal to "pin" - what should you return?
    }
    
    return NULL;    
    */
}




/*********************************************************************************************************************************************
 * END
 **********************************************************************************************************************************************/

void display_menu()
{
	int menu_digit = 0;
        int input = 0;
	Serial.println("=========MAIN MENU==========");
  	Serial.println("1. add pins 	(Linked List Only)");
	Serial.println("2. insert pins  (Linked List Only)");
	Serial.println("3. push 	(Stack Only)");
	Serial.println("4. pop  	(Stack Only)");
	Serial.println("5. enqueue 	(Queue Only)");
	Serial.println("6. dequeue 	(Queue Only)");
        Serial.println("7. Reset 	(Stack & Queue Only)");
        Serial.println("9. free nodes   (Linked List Only");
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
					Serial.println("Adding Pins");
					// use this to create first node if length is zero
                                        
                                        if(length() == base_pins[load_counter])
                                        {
                                           prepend(base_pins[load_counter]);
                                           load_counter++;
                                        } 
                                        else
                                        {
                                           append(base_pins[load_counter]);
                                           load_counter++;
                                        }
                                        // use this to add additional nodes
                                        //
                                        display_menu();
				break;
				case 2:
					Serial.println("Inserting Pins");
                                        // contains will send back a led_node structure
                                        if(contains(previous_pin) != NULL)
                                        {
                                          // insert the the new pin after the previous pin
					  insert_after(contains(previous_pin), insert_pin);
                                        }
    
                                        display_menu();
				break;
				case 3:
					Serial.println("Pushing Pins On");
                                        if(push(stack_pins[load_counter]))
                                        {
                                          Serial.println("SUCCESS!");
                                          if(load_counter != 7)
                                          {
                                            load_counter++;
                                          }
                                        } 
                                        else
                                       {
                                          Serial.println("AT MAX!");                                      
                                       }
                                        Serial.println(load_counter);
                                        display_menu();
				break;
				case 4:
					Serial.println("Popping Pins Off");
                                        pop();
                                        display_menu();
				break;
				case 5:
					Serial.println("Enqueue Pins");                                      
                                        if(enqueue(queue_pins[load_counter]))
                                        {
                                          Serial.println("SUCCESS!");
                                          if(load_counter != 7)
                                          {
                                            load_counter++;
                                          }
                                        } 
                                        else
                                       {
                                          Serial.println("AT MAX!");                                      
                                       }
                                        Serial.println(load_counter);
                                        display_menu();
				break;
				case 6:
					// toggle pin
					Serial.println("Dequeue Pins");
                                        dequeue();
                                        display_menu();
				break;
				case 6:
					// toggle pin
					Serial.println("Reset");
                                        reset();
                                        display_menu();
				break;
				case 9:
					Serial.println("Free Nodes (Linked List)!");
                                        // linked list only
                                        free_nodes();
				break;
				default:
				break;
			}
		
    	}
	// continue to prompt until max pins have been reached
  	} while(menu_digit != 9);

}

/*
 * sets pins to output
 */
void init_pinmode()
{
    for(int i=1;i<=7;i++)
        pinMode(i,OUTPUT);
}

/*
 * toggles the led on and off
 */
void toggle(int pin)
{
  (digitalRead(pin) == HIGH) ? digitalWrite(pin, LOW) : digitalWrite(pin, HIGH);
}

/*
 * used for linked list
 */
void free_nodes()
{
    // toggle the first pin before freeing it
    toggle(first->pin);
    
    while (first != NULL)
    {
        // get the node
        led_node* next = first->next;      
        // toggle the light 
        toggle(next->pin);
        // free the memory
        free(first);
        // make the "next" node the "first" node
        first = next;
    }
}

/*
 * used to reset counters
 */
void reset()
{ 
  // shut down all pins
  for(int i=1;i<=7;i++) 
  {
    digitalWrite(pin, LOW);
  } 
  // reset counter
  load_counter = 0;
}

void loop()
{
		

}

