/*
  This example is intended to control the 2-pin 
  Multi-Mode RGB LEDs (We call them "OWire" or "0-wire" LEDs) 
  SparkFun sells these at its website: www.sparkfun.com
  Do you like this library? Help support SparkFun.
  https://www.sparkfun.com/products/21209

  Written by Nick Poole @ SparkFun Electronics, September 23rd, 2022

  https://github.com/sparkfun/SparkFun_0Wire_LED_Arduino_Library

  Development environment specifics:
  Arduino IDE 1.8.7

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <SparkFun_OWire_Arduino_Library.h>

/*
 * The following keywords can be passed as colors to
 * the setColor() and setModeAndColor() methods:
 * 
 * OW_OFF // The LED turns off
 * OW_RED 
 * OW_GREEN 
 * OW_YELLOW 
 * OW_BLUE 
 * OW_VIOLET 
 * OW_CYAN 
 * OW_WHITE 
 * OW_FULLCOLOR // Each LED randomly selects one of the above colors 
 * OW_RGW // Each LED randomly selects either RED GREEN or WHITE
 * OW_RBW // Each LED randomly selects either RED WHITE or BLUE
 * OW_SIXCOLOR // Each LED randomly selects from FULLCOLOR except CYAN 
 * 
 * The following keywords can be passed as modes to
 * the setMode() and setModeAndColor() methods:
 * 
 * OW_SOLID
 * OW_8SECONDFADE // Fade on and off in 8s cycles in unison
 * OW_WHITESPARKLES_SLOW // Solid color with 0.5s white flashes every 4s
 * OW_WAVEFADE // Fade on and off in 2s cycles, randomly
 * OW_COLORSPARKLES_SLOW // Off with 0.5s color flashes every 4s
 * OW_WHITESPARKLES_FAST // Solid color with 0.125s white flashes every 1s
 * OW_COLORBLINKS // Solid color with 0.5s off flashes every 4s
 * OW_COLORSPARKLES_FAST // Off with 0.125s color flashes every 1s
 * 
 */

// Create an instance of the OWIRE object for each LED or parallel string
// of LEDs. The class is called "OWIRE" and not "0WIRE" because it can't 
// begin with a number
OWIRE myLED; 

void setup() {

    // The begin() method assigns a pin number to the LED and specifies 
    // whether the logic output should be inverted. If a parallel string 
    // of LEDs are switched using a P-Channel MOSFET or PNP Transistor then
    // inverted logic should be "true" 
    myLED.begin(9, false); 
    
    Serial.begin(9600);

}

void loop() {

  // Whenever the setMode(), setColor(), setControlByte(), or setModeAndColor()
  // methods are called, a full control code is sent to the LED. In order to 
  // avoid unintended behavior your first call should be to the setModeAndColor()
  // or setControlByte() methods...
  myLED.setModeAndColor(OW_SOLID, OW_CYAN);
  delay(1000);

  // ...however, subsequent calls can be made to either the setMode() or setColor()
  // method to change these respective properties. 
  myLED.setColor(OW_WHITE);
  delay(1000);

  // The last known state of the LED is remembered by the library and can be
  // recalled using the getColor(), getMode(), and getControlByte() methods
  Serial.print("The LED is currently ");
  Serial.println(myLED.getColor(), BIN);

  // ...however, this method returns only a byte containing the color or mode
  // portion of the 7-bit control code. If you want to test what color the LED
  // was last set to, you can compare them to the defined keywords
  Serial.print("The LED is");
  if(myLED.getColor() != OW_WHITE){
    Serial.print(" not");
    }
  Serial.println(" White");

  Serial.print("The LED is");
  if(myLED.getColor() != OW_RED){
    Serial.print(" not");
    }
  Serial.println(" Red");

  // The last set color, mode, or complete 7-bit control code can be retrieved by 
  // there respective methods regardless of how the property was set. For instance: 
  byte lastControlCode = myLED.getControlByte();
  myLED.setMode(OW_WAVEFADE);
  Serial.println(lastControlCode == myLED.getControlByte()); // evaluates FALSE (0)
  delay(5000);

  // There are also convenience methods for incrementing and decrementing either
  // the color or the mode. All of these methods will overflow cyclicly, so that
  // repeated calls to nextMode(), for instance, will cycle through all modes 
  // repeatedly:
  for(int i = 0; i < 12; i++){
    myLED.nextColor();
    delay(1000);
  }
  for(int i = 0; i < 11; i++){
    myLED.prevColor();
    delay(1000);
  }
  for(int i = 0; i < 8; i++){
    myLED.nextMode();
    delay(2000);
  }
  for(int i = 0; i < 8; i++){
    myLED.prevMode();
    delay(2000);
  }

  // Certain color modes will cause each LED to choose from a list of colors,
  // beginning in a random position. Repeated calls to these color modes will cause
  // the LEDs to increment through the list, resulting in "random" color patterns:
  myLED.setMode(OW_SOLID);
  for(int i = 0; i < 20; i++){
    myLED.setColor(OW_SIXCOLOR);
    delay(200);
  }

  myLED.setModeAndColor(OW_WAVEFADE, OW_WHITE);

  while(1){}
   
}
