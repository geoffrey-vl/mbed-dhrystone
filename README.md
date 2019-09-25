# Getting started with Dhrystone on Mbed OS

This guide reviews the steps required to get dhrystone 2.2 on Mbed OS platform.

Please install [mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

## Import the example application

From the command-line, import the example:

```
mbed import git@github.com:geoffrey-vl/mbed-dhrystone.git
cd mbed-dhrystone
```

### Now compile

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the ARM Compiler 5:

```
mbed compile -m NUCLEO_L496ZG -t GCC_ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
[snip]
[Warning] @,: Compiler version mismatch: Have 7.2.1; expected version >= 6.0.0 and < 7.0.0
Building project mbed-dhrystone (NUCLEO_L496ZG, GCC_ARM)
Scan: mbed-dhrystone
Link: mbed-dhrystone
Elf2Bin: mbed-dhrystone
| Module             |     .text |    .data |      .bss |
|--------------------|-----------|----------|-----------|
| [fill]             |   142(+0) |    4(+0) |    30(+0) |
| [lib]/c.a          | 25476(+0) | 2472(+0) |    89(+0) |
| [lib]/gcc.a        |  3272(+0) |    0(+0) |     0(+0) |
| [lib]/misc         |   180(+0) |    4(+0) |    28(+0) |
| dhrystone22.o      |  2946(+0) |    0(+0) | 10242(+0) |
| main.o             |   460(+0) |    0(+0) |     0(+0) |
| mbed-os/components |    14(+0) |    0(+0) |     0(+0) |
| mbed-os/drivers    |   864(+0) |    0(+0) |     0(+0) |
| mbed-os/hal        |  3360(+0) |    8(+0) |   130(+0) |
| mbed-os/platform   |  7258(+0) |  276(+0) |   404(+0) |
| mbed-os/rtos       | 14404(+0) |  168(+0) |  6417(+0) |
| mbed-os/targets    | 20288(+0) |    4(+0) |   996(+0) |
| Subtotals          | 78664(+0) | 2936(+0) | 18336(+0) |
Total Static RAM memory (data + bss): 21272(+0) bytes
Total Flash memory (text + data): 81600(+0) bytes

Image: ./BUILD/NUCLEO_L496ZG/GCC_ARM-DEBUG/mbed-dhrystone.bin
```

### Program your board

1. Connect your Mbed device to the computer over USB.
1. Copy the binary file to the Mbed device.
1. Press the reset button to start the program.

### Program output

```
Mbed OS Version: 51304                                                       
CPU ID: 0x410fc241                                                           
CPU Type: ARM Cortex-M4 (0xc24) 
Compiler ID: 2                                                               
Compiler Version: 70200                                                      
RAM0: Start 0x20000000 Size: 0x40000                                         
RAM1: Start 0x10000000 Size: 0x10000       
ROM0: Start 0x8000000 Size: 0x100000       
Clock: 80000000Hz                          
                                           
Dhrystone Benchmark, Version C, Version 2.2
Program compiled without 'register' attribute
Using time(), HZ=1

Trying 50000 runs through Dhrystone:
Measured time too small to obtain meaningful results

Trying 500000 runs through Dhrystone:
Final values of the variables used in the benchmark:

Int_Glob:            5
        should be:   5
Bool_Glob:           1
        should be:   1
Ch_1_Glob:           A
        should be:   A
Ch_2_Glob:           B
        should be:   B
Arr_1_Glob[8]:       7
        should be:   7
Arr_2_Glob[8][7]:    550010
        should be:   Number_Of_Runs + 10
Ptr_Glob->
  Ptr_Comp:          536893672
        should be:   (implementation-dependent)
  Discr:             0
        should be:   0
  Enum_Comp:         2
        should be:   2
  Int_Comp:          17
        should be:   17
  Str_Comp:          DHRYSTONE PROGRAM, SOME STRING
        should be:   DHRYSTONE PROGRAM, SOME STRING
Next_Ptr_Glob->
  Ptr_Comp:          536893672
        should be:   (implementation-dependent), same as above
  Discr:             0
        should be:   0
  Enum_Comp:         1
        should be:   1
  Int_Comp:          18
        should be:   18
  Str_Comp:          DHRYSTONE PROGRAM, SOME STRING
        should be:   DHRYSTONE PROGRAM, SOME STRING
Int_1_Loc:           5
        should be:   5
Int_2_Loc:           13
        should be:   13
Int_3_Loc:           7
        should be:   7
Enum_Loc:            1
        should be:   1
Str_1_Loc:           DHRYSTONE PROGRAM, 1'ST STRING
        should be:   DHRYSTONE PROGRAM, 1'ST STRING
Str_2_Loc:           DHRYSTONE PROGRAM, 2'ND STRING
        should be:   DHRYSTONE PROGRAM, 2'ND STRING

Microseconds for one run through Dhrystone:       18.0 
Dhrystones per Second:                           55556 
```

### License and contributions
The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide