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

#include "SparkFun_OWire_Arduino_Library.h"
#include "Arduino.h"

//Constructor
OWIRE::OWIRE()
{

}

//
bool OWIRE::begin(uint8_t pin, bool invertLogic)
{
  _pin = pin;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, 0);

  _invertLogic = invertLogic;
  return (true); //We're all setup!
}

//
void OWIRE::setColor(uint8_t color)
{
  _color = color;
  _controlByte &= 0b01110000;
  _controlByte |= color;
  setControlByte(_controlByte);
  return;
}

//
void OWIRE::nextColor()
{
  uint8_t color = _color;
  _controlByte &= 0b01110000;
  color++;
  if(color>12){
    color = 0;
  }
  _color = color;
  _controlByte |= color;
  setControlByte(_controlByte);
  return;
} 

//
void OWIRE::prevColor()
{
  uint8_t color = _color;
  _controlByte &= 0b01110000;
  if(color==0){
    color = 12;
  }else{
    color--;
  }
  _color = color;
  _controlByte |= color;
  setControlByte(_controlByte);
  return;
} 

//
void OWIRE::setMode(uint8_t mode)
{
  _mode = mode;
  _controlByte &= 0b00001111;
  _controlByte |= mode;
  setControlByte(_controlByte);
  return;
}

//
void OWIRE::prevMode()
{
  uint8_t mode = _mode;
  _controlByte &= 0b00001111;
  mode = mode >> 4;
  if(mode==0){
    mode = 8;
  }else{
    mode--;
  }
  mode = mode << 4;
  _mode = mode;
  _controlByte |= mode;
  setControlByte(_controlByte);
  return;
} 

//
void OWIRE::nextMode()
{
  uint8_t mode = _mode;
  _controlByte &= 0b00001111;
  mode = mode >> 4;
  mode++;  
  if(mode > 7){
    mode = 0;
  }
  mode = mode << 4;
  _mode = mode;
  _controlByte |= mode;
  setControlByte(_controlByte);
  return;
} 

//
void OWIRE::setModeAndColor(uint8_t mode, uint8_t color)
{
  _mode = mode;
  _color = color;
  _controlByte = color | mode;
  setControlByte(_controlByte);
  return;
}

//
void OWIRE::setControlByte(uint8_t controlByte)
{
  _controlByte = controlByte;
  ledTx(_controlByte, _pin, _invertLogic);
  return;
}

//
uint8_t OWIRE::getMode()
{
  _mode = _controlByte & 0b01110000;
  return _mode;
}

//
uint8_t OWIRE::getColor()
{
  _color = _controlByte & 0b00001111;
  return _color;
}

//
uint8_t OWIRE::getControlByte()
{
  return _controlByte;
}

//
void OWIRE::ledTx(uint8_t controlCode, uint8_t ledPin, bool inverted)
{
  for(uint8_t i = 7; i > 0; i--)
  {
    digitalWrite(ledPin, inverted);
    delayMicroseconds(200);
    digitalWrite(ledPin, !inverted);
    if((controlCode & (1 << i-1)) != 0){
      delayMicroseconds(15000);
    }else{
      delayMicroseconds(5000);
    }
  }
  digitalWrite(ledPin, inverted);
  delayMicroseconds(200);
  digitalWrite(ledPin, !inverted);
}