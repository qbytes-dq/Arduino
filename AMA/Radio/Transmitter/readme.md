# Arduino Nano Transmitter

## Menus
| Startup |  
| ----- | 
| Name           | 
| Version        | 
| Voltage: xx.xxV | 
| QBytes-World   | 

| Main |  
| ----- | 
| Flight Time MM:SS|
| Mode: xxxxxxxxxxx| 
| Message: Xxxxxx (Warn or Error)| 
| Voltage: xx.xxV | 
| FPS xxxx GPS xxx| 
| Channel xxx Drop/Sec xxx|
| >Transmitter   | 
| >Model   | 

| >Transmitter |  
| ----- | 
| >Channel | 
| >EXPO    | 
| >Curves  | 
| >Setup   | 

| >>Transmitter Channel|  
| -----            | 
| >Scan for Open  | 
| >Channel Select | 

| >>Transmitter EXPO|  
| ----- | 
| per channel (10%-190%)  | 

| >>Transmitter Curves|  
| ----- | 
| per channel (Ramp/Sin)  | 

| >>Transmitter Setup|  
| ----- | 
| Min/Max controls | 
| Reverse surfaces (base on min/max movement)| 
| Button Ranges (press each for value) | 
| Battery (Set size in volts) | 
| >Reset Factory | 


| >Model |  
| ----- | 
| >Dip Switches (reverses)| 
| >PID - Roll   | 
| >PID - Pitch   | 
| >PID - YAW   | 

| Switches |  
| ----- | 
| S1a - Takeoff| 
| S1b - Land   | 
| S1c - ????   | 
| S2a - Sandbox     (Holds pilot to range of x meters and altitude)| 
| S2b - Barometer   (throttle sets altitude (0-400 feet)| 
| S2c - Manual   | 
| S3a - Follow-me |
| S3b - |
| S3c - |
| S4a -   | 
| S4a - Mission  | 
| S4a - Return Home   | 


| Mode |  
| ----- | 
| ??is this not the switches?? | 

|12345678901234567890|

### Arduino Nano Pinouts

| Connect |  Pin  | Pin   | Connect |
| ----- | ------ | ------ | ------ |
| Bluetooth RX     | TX     | Vin   | 7-12VDC  |
| Bluetooth TX     | RX     | Gnd   | Gnd      |
| Pull-up          | Reset  | Reset | Pull-up  |
| Gnd              | Gnd    | 5v0   | 5v0 Out  |
| Buzzer/LED       | D2     | ADC7  | CD4052-Y |
| CD4051/CD4052-A  | D3     | ADC6  | CD4052-X |
| CD4051/CD4052-B  | D4     | SDC   | LCD SDC  |
| CD4051       -C  | D5     | SDA   | LCD SDA  |
| CD4051 #1 (Switch)| D6    | ADC3  | Role     |
|?CD4051 #2 (Trims)?| D7     | ADC2  | Pitch    |
|?CD4051 #3 (Menu) ?| D8     | ADC1  | Yaw      |
| Nrf24 - CE       | D9     | ADC0  | Throttle |
| Nrf24 - CSN      | D10    | Aref  | 5v0      |
| Nrf24 - MOSI     | D11    | 3v3   | N/C      |
| Nrf24 - MISO     | D12    | D13   | Nrf24 - CSN|

### NRF24 with PA and antenna Pinouts
| Arduino Pin |  NRF24 Pin  | NRF24 Pin   | Arduino Pin |
| ----- | ------ | ------ | ------ |
| GND   | GND    | VCC    | 3v3    |
| D9    | CE     | CSN    | D10    |
| D13   | SCK    | MOSI   | D11    |
| D12   | MISO   | IRQ    | N/C    |


> **Transmitter performance tuned setup**
> - AutoAck = false 
> - Max power 
>   - setPALevel( RF24_PA_MAX ) ; 
> - Min speed (for better range I presume)
>   - setDataRate( RF24_250KBPS ) ; 
> - 8 bits CRC
>   - setCRCLength( RF24_CRC_8 ) ; 
> - Disable dynamic payloads 
>   - write_register(DYNPD,0); 
> - increase the delay between retries & # of retries 
>   - setRetries(15,15);
> - Add capacitor to board.

> - Modify pipeOut to be unique for your codebase

Here is what I'm using:
1. Power supply:

      a. decouple your LDO properly(it needs 1-2uF ceramic, not 100n + 100u electrolytic!). 
      
      b. use a decoupling cap next to the module (1-2 uF ceramic).
      
      c. in-line choke (coil) for 3v3 line.
      
2. Use a linear instead of a switching power supply
3. Don’t use polling over SPI to check if there is a received packet like most of the libs out there do. This increases the noise. Use the IRQ pin.
4. 250Kbps does wonders
5. Careful about cheap connectors, solder it if you can.
6. A big ground near the module is preferred, like putting it in a metal box with a good contact to antenna ground.
7. Don’t use long wires to the module, specially cheap stuff.

See here: http://www.electrobob.com/bad-wires/
