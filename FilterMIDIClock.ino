
#include <MIDI.h>
#include <SoftwareSerial.h>

SoftwareSerial softSerial1(4, 3);                             //sets Arduino ports for SoftwareSerial library
MIDI_CREATE_INSTANCE(SoftwareSerial, softSerial1, MIDI);      //Custom instance for using SoftwareSerial library

//  MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);        Use this instance for Hardware Serial at Arduino boards

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);  // all channels
  MIDI.turnThruOff();             // MIDI Thru Off
}

void loop() {
  if (MIDI.read())                //receve msg
  {
    switch (MIDI.getType()) {     //recognize MIDI Type as MIDI Clock and MIDI Clock start, stop, continue msg's
      case midi::Clock:
        break;
      case midi::Start:
        break;
      case midi::Continue:
        break;
      case midi::Stop:
        break;
      default:                    //sends other types of msg's
        MIDI.send(
          MIDI.getType(),
          MIDI.getData1(),
          MIDI.getData2(),
          MIDI.getChannel()
          );
        break;
    }
  }
}
