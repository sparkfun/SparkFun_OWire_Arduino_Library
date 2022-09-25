SparkFun OWire Arduino Library
========================================

![AnimatedGIFofFlashingLEDs](https://github.com/sparkfun/SparkFun_OWire_Arduino_Library/raw/main/img/OWireDemo.gif)

Have you ever seen those strings of fairy lights, or pre-lit Christmas trees, that change colors with a little remote? Have you ever noticed that they only have two wires? How do they do that? Well it turns out that this is how: Special LEDs! These 4mm LEDs are like a compromise between color cycling LEDs and fully addressable LEDs. While you aren't able to individually address each LED in the chain, you _can_ change the color and mode of _all_ LEDs in the chain. We call these "OWire" LEDs because there's no "signal" wire, just power and ground. In order to change modes you wiggle the power LED in in a 7-bit pattern depending on the mode/color you want. Don't worry, we've written an Arduino library! A single LED will run just fine from a GPIO pin, but if you want to put a lot of LEDs in parallel, you'll want to use a MOSFET to signal the power rail. Check the documentation for an example schematic. 

Repository Contents
-------------------

* **/img** - Images for this README document
* **/examples** - Example code 
* **/src** - Related software for the SparkFun Qwiic 6DoF ISM330DHCX breakout board

Documentation
--------------
* **[Installing an Arduino Library Guide](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)** - Basic information on how to install an Arduino library.
* **[OWire LED Datasheet](https://cdn.sparkfun.com/assets/4/6/6/f/4/0-Wire_RGB_LED_Datasheet.pdf)** - Electrical Characteristics for OWire LEDs
* **[OWire LED Signaling Protocol](https://cdn.sparkfun.com/assets/9/f/1/c/6/CZineLight_0-Wire_Communication_Protocol.pdf)** - Explanation of the 7-bit Signalling Schema for OWire LEDs
* **[Example Schematic](https://cdn.sparkfun.com/assets/7/9/e/1/3/OWire_Example.pdf)** - Example Electrical Schematics for Parallel Strings

Products that use this Library
----------------

* [COM-21209](https://www.sparkfun.com/products/21209) - 

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact technical support on our [SparkFun forums](https://forum.sparkfun.com/viewforum.php?f=152).

Distributed as-is; no warranty is given.

- Your friends at SparkFun.

_<COLLABORATION CREDIT>_
