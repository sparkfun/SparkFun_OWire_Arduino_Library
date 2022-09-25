/*
  This is a library written to simplify the control of 2-pin 
  Multi-Mode RGB LEDs (We call them 0-wire LEDs) 
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

#ifndef _SPARKFUN_OWIRE_ARDUINO_LIBRARY_H
#define _SPARKFUN_OWIRE_ARDUINO_LIBRARY_H
#include "Arduino.h"

#define OW_OFF 0b00000000
#define OW_RED 0b00000001
#define OW_GREEN 0b00000010
#define OW_YELLOW 0b00000011
#define OW_BLUE 0b00000100
#define OW_VIOLET 0b00000101
#define OW_CYAN 0b00000110
#define OW_WHITE 0b00000111
#define OW_FULLCOLOR 0b00001000
#define OW_RGW 0b00001001
#define OW_RBW 0b00001010
#define OW_SIXCOLOR 0b00001011

#define OW_SOLID 0b00000000
#define OW_8SECONDFADE 0b00010000
#define OW_WHITESPARKLES_SLOW 0b00100000
#define OW_WAVEFADE 0b00110000
#define OW_COLORSPARKLES_SLOW 0b01000000
#define OW_WHITESPARKLES_FAST 0b01010000
#define OW_COLORBLINKS 0b01100000
#define OW_COLORSPARKLES_FAST 0b01110000

class OWIRE {
  public:
    OWIRE();

    bool begin(uint8_t pin, bool invertLogic = 0);
    void setMode(uint8_t mode);
    void nextMode();
    void prevMode();
    void setColor(uint8_t color);
    void nextColor();
    void prevColor();
    void setControlByte(uint8_t controlByte);
    void setModeAndColor(uint8_t mode, uint8_t color);


    uint8_t getMode();
    uint8_t getColor();
    uint8_t getControlByte();
	
  private:
	uint8_t _pin;
    uint8_t _invertLogic;
    uint8_t _mode;
    uint8_t _color;
    uint8_t _controlByte;

    void ledTx(uint8_t controlCode, uint8_t ledPin, bool inverted);
};

#endif