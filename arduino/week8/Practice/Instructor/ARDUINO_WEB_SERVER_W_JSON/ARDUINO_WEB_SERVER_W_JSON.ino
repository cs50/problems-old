/****************************************************************************
 * ARDUINO_WEB_SERVER_W_JSON
 *
 * Computer Science 50
 * Christopher Bartholomew
 * 
 * This is web server code to help students build web pages that interact with the arduino.
 *
 * Demonstrates use of HTTP GET Request Headers in text/html and application/json
 * 
 * BONUS:
 * 1. Add some more functionality !!
 ***************************************************************************/

#include <SPI.h>
#include <Ethernet.h>
#define MAX_COLORS 5

// set up your LEDs
typedef struct color 
{
  String value;
  int pin;
} 
color;
 
// On the bottom of every Ethernet Card is a MAC Address enter that address.
// You will want to make sure this setting is correctly setup.
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x2A, 0x04 };

// Tell your server what port it must start listening on - in this case http 80
EthernetServer server(80);

// this string is used to capture our query string
String requestHeaderQS;

// these are the predefined colors
String led_colors[] = {"red","orange","yellow","green","blue"}; 

// this is a global array of colors
struct color colors[MAX_COLORS];

void setup()
{
  // loads the colors
  load_colors();
  
  // enables the pins
  enablePins();
  
  // Assume the connection will fail and set the connection loop counter to 0
  bool DHCP = false;
  int i = 0;
 
  // Try to connect to the DHCP server 10 times waiting 5 seconds between each
  // connection attempt.
  while(DHCP == 0 && i<10)
  {
     if(Ethernet.begin(mac) == 1)
     {
        DHCP = true;
        i = 10;
     }
     i++;
     delay(5000);
  }
  //If the network connection failed, print out to serial and enter into
  // an infinite loop
  if(!DHCP)
  {
     Serial.println("DHCP FAILED");
     for(;;);
  }
  
  //Otherwise, DHCP succeeded and we can start the web server.
  server.begin();
    
  // Serial
  Serial.begin(9600);
}
 
void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) 
  {
    requestHeaderQS = "";
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean readQueryString = false;
    while (client.connected()) 
    {
      if (client.available()) 
      {
        char c = client.read();
        
        if(c == '?')
           readQueryString = true;
             
        // begin query string
        while(readQueryString)
        {
          //read query string
          
          c = client.read();
          // store our request 
          requestHeaderQS += c;
          Serial.print(c);
          
          if(c == ' ')
            readQueryString = false;          
        }
        
        // extract the color from the query string
        struct color this_color = getColor(requestHeaderQS);
        
        // check if it's json as well
        boolean isJSON = (requestHeaderQS.indexOf("jsonp=true") > 0) ? true : false;   
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) 
        {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          
          // if jsonp is true - send back json header of struct
          if(!isJSON)
          {
            client.println("Content-Type: text/html");          
            client.println();
             // output the value of each analog input pin
            client.print("You picked the color: ");
            client.print("<label style='color:");
            client.print(this_color.value);
            client.print("'>");
            client.print(this_color.value);
            client.print("</label><br>");
            client.print("The led is now: ");
            client.print((toggleLED(this_color)) ? "On!" : "Off!");
          }
          else
          {
            client.println("Content-Type: application/json");
            client.println();
            String led_status = (toggleLED(this_color)) ? "On!" : "Off!";
            String data = buildJSON(this_color, led_status);
            client.print(data);
          }
  
          // break out
          break;
        }
                
        if (c == '\n') 
        {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') 
        {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
        
      }
    }
    // give the web browser time to receive the data
    delay(2);
    // close the connection:
    client.stop();
  }
}

struct color getColor(String queryString)
{ 
  struct color default_color;
  
  default_color.value = "No color found";
  default_color.pin   = 0;
  
  for(int i=0;i<MAX_COLORS;i++)
    if(queryString.indexOf(colors[i].value) > 0)
      return colors[i];
  
  return default_color;
}


void load_colors()
{
  int pin_counter = 5;  
  for(int i=0;i<MAX_COLORS;i++)
  {
    struct color new_color;
    new_color.value = led_colors[i];
    new_color.pin = pin_counter++;   
    colors[i] = new_color; 
  }  
}

/* enablePins()
 * This function will set all arduino pins to output
 * it will also write them to "off" or zero.
 */
void enablePins()
{
  for(int i=0;i<MAX_COLORS;i++)
  {
    // enable the pins
    pinMode(colors[i].pin,OUTPUT);
    // ensure they are all off
    digitalWrite(colors[i].pin,LOW);
  }
}

/* toggleLED(struct color this_color)
 * This function will toggle the LED on and off
 * returns the status of the LED
 */
boolean toggleLED(struct color this_color)
{ 
  boolean isOn = false;
  
  if(this_color.pin != 0)
  {
    if(digitalRead(this_color.pin) == LOW)
    {
      isOn = true;
      digitalWrite(this_color.pin,HIGH);
    }
    else
    {
      isOn = false;
      digitalWrite(this_color.pin,LOW);
    }
  }
  
  return isOn;
}

/* buildJSON()
 * This function will build a json string to return to the calling service
 */
String buildJSON(struct color this_color, String led_status)
{
  
  String data = "Arduino : { color: #COLOR# , status: #STATUS# }";
  data.replace("#COLOR#",this_color.value);
  data.replace("#STATUS#",led_status);
  
  return data;  
}
