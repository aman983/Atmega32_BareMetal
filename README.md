# Atmega32 HAL(Hardware Abstraction Layer) 
A HAL Library developed for Atmega32 to Provide Fast and Reliable Prototyping.

# Directory Structure

```bash
Atmega32_Baremetal
│
├── avr # Contains all the board sppecfic Macros
│ 
├── src
│ │
│ ├── Examples # To Demonstrate HAL Usage
│ │ ├── ADC
│ │ ├── Display
│ │ ├── GPIO
│ │ ├── I2C
│ │ └── UART
│ │
│ ├── Lib # The HAL
│   ├── ADC
│   ├── LCD16x2
│   ├── DS3231
│   ├── GPIO
│   ├── I2C
│   └── UART
│ 
├── Template # Base Template on which a new project is created
│   ├── include # Folder used for your HAL Library
│   ├── main.c 
│   ├── Makefile # Used for compling and Programming Board
│   └── README.md
│
├── CreatePrj.sh # used to Create new Projects
│  
└── Atmega32_Datasheet.pdf

```
## How to Create a New Project ?
- Run <code>./CreatePrj,sh</code> in the Terminal
- This will appear <code>user@os$ Enter the Name of the Project to Create</code>
- Then Enter the project Name and a folder will be created with the requested name.

## How to Import HAL in Project ?
- To import HAL Library in a new project you must copy the nessary <code>.h</code> & <code>.c</code> files from <code>src/lib</code> in your project's <code>include</code> directory.
- Once the files have been included then you can include them in the main.c freely.

## How to used HAL Components ?
- If you want to use any componets such as (GPIO, ADC, UART etc) then you must a specific struct must be declared befor initalising the component.
- Suppose you want to use GPIO in your firmware then you must include the <code>GPIO.h</code> and use the following to enable GPIO.
```c
// Before using the GPIO always make a valid PORT configuration this helps to keep the code in order
Port_config_t config_PortA = {
        .DDRx = &DDRA,
        .PINx = &PINA,
        .PORTx = &PORTA
    };

Pin_Init(&config_PortA, PIN_OUTPUT, 7); // configuring PIN 7 of PORTA as output 
```
## How to Compile Code and Dump Firmware ?
Run the following Make Commands in the Project Directory:
- Run <code>make</code> -> To Compile Code. 
- Run <code>make clean</code> -> To Clean / remove old binary files.
- Run <code>make flash</code> -> To Flash firmware to Board
