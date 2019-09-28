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
mbed compile -m NUCLEO_L496ZG -t GCC_ARM --profile=release
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
[Warning] @,: Compiler version mismatch: Have 7.2.1; expected version >= 6.0.0 and < 7.0.0
Building project mbed-dhrystone (NUCLEO_F429ZI, GCC_ARM)
Scan: mbed-dhrystone
Link: mbed-dhrystone
Elf2Bin: mbed-dhrystone
| Module             |     .text |    .data |      .bss |
|--------------------|-----------|----------|-----------|
| [fill]             |   136(+0) |    7(+0) |    37(+0) |
| [lib]\c.a          | 25588(+0) | 2472(+0) |    89(+0) |
| [lib]\gcc.a        |  3272(+0) |    0(+0) |     0(+0) |
| [lib]\misc         |   180(+0) |    4(+0) |    28(+0) |
| dhrystone22.o      |  1904(+0) |    0(+0) | 10270(+0) |
| main.o             |   404(+0) |    0(+0) |    56(+0) |
| mbed-os\components |    64(+0) |    0(+0) |     0(+0) |
| mbed-os\drivers    |   398(+0) |    0(+0) |     0(+0) |
| mbed-os\events     |  1554(+0) |    0(+0) |  3108(+0) |
| mbed-os\features   |  1884(+0) |    0(+0) | 12724(+0) |
| mbed-os\hal        |  1490(+0) |    4(+0) |    66(+0) |
| mbed-os\platform   |  3244(+0) |  260(+0) |   289(+0) |
| mbed-os\rtos       |  9732(+0) |  168(+0) |  5973(+0) |
| mbed-os\targets    |  9522(+0) |    5(+0) |   680(+0) |
| Subtotals          | 59372(+0) | 2920(+0) | 33320(+0) |
Total Static RAM memory (data + bss): 36240(+0) bytes
Total Flash memory (text + data): 62292(+0) bytes

Image: .\BUILD\NUCLEO_F429ZI\GCC_ARM-RELEASE\mbed-dhrystone.bin
```

### Program your board

1. Connect your Mbed device to the computer over USB.
1. Copy the binary file to the Mbed device.
1. Press the reset button to start the program.

### Program output

```
********************************************
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
DMIPS:                                              32
```

### Results

- **Dhrystones per second** : the number of iterations of the main code loop per second. It is the absolute performance result for integer calculations.
- **DMIPS** : the order of magnitude that the tested machine outperforms the VAX 11/780 (the reference 1 MIPS machine). The *Dhrystone Million of Instruction per Second* (DMIPS) is often used to compare absolute (integer) performance of CPU's.
- **Efficiency per MHz** : the relative performence per CPU core tick is the DMIPS devided by the CPU frequency. It allows comparing CPU's running at different clock rates.

```
+---------------------------+-----------------------------+-----------------------+------------+--------------------+
| DEVICE                    | CPU                         | Dhrystones per Second |      DMIPS | Efficiency per MHz |
+===========================+=============================+=======================+============+====================+
| STM32 NUCLEO L496ZG       | 1 x ARM CORTEX M4 @ 80MHz   |                116009 |         66 |               0.83 +
+---------------------------+-----------------------------+-----------------------+------------+--------------------+
| STM32 NUCLEO F429ZI       | 1 x ARM CORTEX M4 @ 168MHz  |                291460 |        166 |               0.99 +
+---------------------------+-----------------------------+-----------------------+------------+--------------------+
| STM32 NUCLEO F429ZI       | 1 x ARM CORTEX M4 @ 180MHz  |                312324 |        178 |               0.99 +
+---------------------------+-----------------------------+-----------------------+------------+--------------------+
```

The benchmark does not (yet) fully support multicore system and will only take 1 core.

### "DHRYSTONE" Benchmark Program, Version "C, Version 2.2"

```
 Repository: https://github.com/Keith-S-Thompson/dhrystone
 Author:     Reinhold P. Weicker
             Siemens Nixdorf, Paderborn/Germany
             weicker@specbench.org
 Date:       May 25, 1988
 Modified:	Steven Pemberton, CWI, Amsterdam; Steven.Pemberton@cwi.nl
 Date:       October, 1993; March 1995
             Included both files into one source, that gets compiled
             in two passes. Made program auto-compiling, and auto-running,
             and generally made it much easier to use.
 
             Original Version (in Ada) published in
             "Communications of the ACM" vol. 27., no. 10 (Oct. 1984),
             pp. 1013 - 1030, together with the statistics
             on which the distribution of statements etc. is based.
 
             In this C version, the following C library functions are used:
             - strcpy, strcmp (inside the measurement loop)
             - printf, scanf (outside the measurement loop)
             In addition, Berkeley UNIX system calls "times ()" or "time ()"
             are used for execution time measurement. For measurements
             on other systems, these calls have to be changed.
 
 Collection of Results:
             Reinhold Weicker (address see above) and
             
             Rick Richardson
             PC Research. Inc.
             94 Apple Orchard Drive
             Tinton Falls, NJ 07724
                     Phone:  (201) 389-8963 (9-17 EST)               
                     Usenet: ...!uunet!pcrat!rick
 
     Please send results to Rick Richardson and/or Reinhold Weicker.
     Complete information should be given on hardware and software used.
     Hardware information includes: Machine type, CPU, type and size
     of caches; for microprocessors: clock frequency, memory speed
     (number of wait states).
     Software information includes: Compiler (and runtime library)
     manufacturer and version, compilation switches, OS version.
     The Operating System version may give an indication about the compiler;
     Dhrystone itself performs no OS calls in the measurement loop.
 
     The complete output generated by the program should be mailed
     such that at least some checks for correctness can be made.
 
 ************************************************************************
 
 Defines:     The following "Defines" are possible:
     -DREG          (default: Not defined)
             As an approximation to what an average C programmer
             might do, causes the "register" storage class to be applied
             - for local variables, if they are used (dynamically)
               five or more times
             - for parameters if they are used (dynamically)
               six or more times
             Note that an optimal "register" strategy is
             compiler-dependent, and that "register" declarations
             do not necessarily lead to faster execution.
     -DNOSTRUCTASSIGN        (default: Not defined)
             Define if the C compiler does not support
             assignment of structures.
     -DNOENUMS               (default: Not defined)
             Define if the C compiler does not support
             enumeration types.
     -DTIMES                 (default)
     -DTIME
             The "times" function of UNIX (returning process times)
             or the "time" function (returning wallclock time)
             is used for measurement. 
             For single user machines, "time ()" is adequate. For
             multi-user machines where you cannot get single-user
             access, use the "times ()" function. If you have
             neither, use a stopwatch in the dead of night.
             "printf"s are provided marking the points "Start Timer"
             and "Stop Timer". DO NOT use the UNIX "time(1)"
             command, as this will measure the total time to
             run this program, which will (erroneously) include
             the time to allocate storage (malloc) and to perform
             the initialization.
     -DHZ=nnn
             In Berkeley UNIX, the function "times" returns process
             time in 1/HZ seconds, with HZ = 60 for most systems.
             CHECK YOUR SYSTEM DESCRIPTION BEFORE YOU JUST APPLY
             A VALUE.
 
 ************************************************************************
 
 History:	Version C/2.1 was made for two reasons:
 
 	1) There was an obvious need for a common C version of
     Dhrystone, since C is at present the most popular system
     programming language for the class of processors
     (microcomputers, minicomputers) where Dhrystone is used most.
     There should be, as far as possible, only one C version of
     Dhrystone such that results can be compared without
     restrictions. In the past, the C versions distributed
     by Rick Richardson (Version 1.1) and by Reinhold Weicker
     had small (though not significant) differences.
 
     1) As far as it is possible without changes to the Dhrystone
     statistics, optimizing compilers should be prevented from
     removing significant statements.
 
     This C version has been developed in cooperation with
     Rick Richardson (Tinton Falls, NJ), it incorporates many
     ideas from the "Version 1.1" distributed previously by
     him over the UNIX network Usenet.
     I also thank Chaim Benedelac (National Semiconductor),
     David Ditzel (SUN), Earl Killian and John Mashey (MIPS),
     Alan Smith and Rafael Saavedra-Barrera (UC at Berkeley)
     for their help with comments on earlier versions of the
     benchmark.
 
 Changes:    In the initialization part, this version follows mostly
     Rick Richardson's version distributed via Usenet, not the
     version distributed earlier via floppy disk by Reinhold Weicker.
     As a concession to older compilers, names have been made
     unique within the first 8 characters.
     Inside the measurement loop, this version follows the
     version previously distributed by Reinhold Weicker.
 
     At several places in the benchmark, code has been added,
     but within the measurement loop only in branches that 
     are not executed. The intention is that optimizing compilers
     should be prevented from moving code out of the measurement
     loop, or from removing code altogether. Since the statements
     that are executed within the measurement loop have NOT been
     changed, the numbers defining the "Dhrystone distribution"
     (distribution of statements, operand types and locality)
     still hold. Except for sophisticated optimizing compilers,
     execution times for this version should be the same as
     for previous versions.
 
     Since it has proven difficult to subtract the time for the
     measurement loop overhead in a correct way, the loop check
     has been made a part of the benchmark. This does have
     an impact - though a very minor one - on the distribution
     statistics which have been updated for this version.
 
     All changes within the measurement loop are described
     and discussed in the companion paper "Rationale for
     Dhrystone version 2".
 
     Because of the self-imposed limitation that the order and
     distribution of the executed statements should not be
     changed, there are still cases where optimizing compilers
     may not generate code for some statements. To a certain
     degree, this is unavoidable for small synthetic benchmarks.
     Users of the benchmark are advised to check code listings
     whether code is generated for all statements of Dhrystone.
 
     Version 2.1 is identical to version 2.0 distributed via
     the UNIX network Usenet in March 1988 except that it corrects
     some minor deficiencies that were found by users of version 2.0.
     The only change within the measurement loop is that a
     non-executed "else" part was added to the "if" statement in
     Func_3, and a non-executed "else" part removed from Proc_3.
 
 Version C/2.2, Steven Pemberton, October 1993
 	Functionally, identical to version 2.2; the changes are in
 	how you compile and use it:
 	- Everything is in one file now, but compiled in 2 passes
 	- Compile (and run) by running the file through the shell: 'sh dhry.c"
 	- Uses the system definition of HZ if one can be found
 	- HZ must be defined, otherwise it won't compile (no defaults here)
 	- The (uninteresting) output is printed to stderr (dhry2 > /dev/null)
 	- The number of loops is passed as a parameter, rather than read
 	  (dhry2 500000)
 	- If the number of loops is insufficient to get a good result,
 	  it repeats it with loops*10 until it is enough (rather than just
 	  stopping)
 	- Output says which sort of clock it is using, and the HZ value
 	- You can use -DREG instead of the -DREG=register of previous versions
 	- Some stylistic cleanups.
 		
 ************************************************************************
 
 Compilation model and measurement (IMPORTANT):
 
 The following "ground rules" apply for measurements:
 - Separate compilation
 - No procedure merging
 - Otherwise, compiler optimizations are allowed but should be indicated
 - Default results are those without register declarations
 See the companion paper "Rationale for Dhrystone Version 2" for a more
 detailed discussion of these ground rules.
 
 For 16-Bit processors (e.g. 80186, 80286), times for all compilation
 models ("small", "medium", "large" etc.) should be given if possible,
 together with a definition of these models for the compiler system used.
 
 ***********************************************************************
 
 Dhrystone (C version) statistics:
 
 [Comment from the first distribution, updated for version 2.
  Note that because of language differences, the numbers are slightly
  different from the Ada version.]
 
 The following program contains statements of a high level programming
 language (here: C) in a distribution considered representative:           
 
   assignments                  52 (51.0 %)
   control statements           33 (32.4 %)
   procedure, function calls    17 (16.7 %)
 
 103 statements are dynamically executed. The program is balanced with
 respect to the three aspects:                                             
 
   - statement type
   - operand type
   - operand locality
        operand global, local, parameter, or constant.                     
 
 The combination of these three aspects is balanced only approximately.    
 
 1. Statement Type:                                                        
 -----------------             number
 
    V1 = V2                     9
      (incl. V1 = F(..)
    V = Constant               12
    Assignment,                 7
      with array element
    Assignment,                 6
      with record component
                               --
                               34       34
 
    X = Y +|-|"&&"|"|" Z        5
    X = Y +|-|"==" Constant     6
    X = X +|- 1                 3
    X = Y *|/ Z                 2
    X = Expression,             1
          two operators
    X = Expression,             1
          three operators
                               --
                               18       18
 
    if ....                    14
      with "else"      7
      without "else"   7
          executed        3
          not executed    4
    for ...                     7  |  counted every time
    while ...                   4  |  the loop condition
    do ... while                1  |  is evaluated
    switch ...                  1
    break                       1
    declaration with            1
      initialization
                               --
                               34       34
 
    P (...)  procedure call    11
      user procedure      10
      library procedure    1
    X = F (...)
            function  call      6
      user function        5                                         
      library function     1                                               
                               --                                          
                               17       17
                                       ---
                                       103
 
   The average number of parameters in procedure or function calls
   is 1.82 (not counting the function values aX *
 
 2. Operators
 ------------
                         number    approximate
                                   percentage
 
   Arithmetic             32          50.8                                 
 
      +                     21          33.3                              
      -                      7          11.1                              
      *                      3           4.8
      / (int div)            1           1.6
 
   Comparison             27           42.8
 
      ==                     9           14.3
      /=                     4            6.3
      >                      1            1.6
      <                      3            4.8
      >=                     1            1.6
      <=                     9           14.3
 
   Logic                   4            6.3
 
      && (AND-THEN)          1            1.6
      |  (OR)                1            1.6
      !  (NOT)               2            3.2
 
                          --          -----
                          63          100.1
 
 
 3. Operand Type (counted once per operand reference):
 ---------------
                         number    approximate
                                   percentage
 
    Integer               175        72.3 %
    Character              45        18.6 %
    Pointer                12         5.0 %
    String30                6         2.5 %
    Array                   2         0.8 %
    Record                  2         0.8 %
                          ---       -------
                          242       100.0 %
 
 When there is an access path leading to the final operand (e.g. a record
 component), only the final data type on the access path is counted.       
 
 
 4. Operand Locality:                                                      
 -------------------
                               number    approximate
                                         percentage
 
    local variable              114        47.1 %
    global variable              22         9.1 %
    parameter                    45        18.6 %
       value                        23         9.5 %
       reference                    22         9.1 %
    function result               6         2.5 %
    constant                     55        22.7 %
                                ---       -------
                                242       100.0 %
 
 The program does not compute anything meaningful, but it is syntactically
 and semantically correct. All variables have a value assigned to them
 before they are used as a source operand.
 
 There has been no explicit effort to account for the effects of a
 cache, or to balance the use of long or short displacements for code or
 data.
```
 
### License and contributions
The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide