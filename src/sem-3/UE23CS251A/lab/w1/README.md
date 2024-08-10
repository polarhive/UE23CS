# What is Icarus Verilog?

## Icarus Verilog

Icarus Verilog is a Verilog simulation and synthesis tool. It is available for Linux, Windows, and Mac OS X, and is released under the GNU General Public License. It operates as a compiler, compiling source code written in Verilog (IEEE-1364) into a target format.

## GTKWave

GTKWave is an open-source waveform viewer that displays VCD (and other) files graphically. It is a fully featured GTK+ based waveform viewer, which is used to view the simulated output of the Verilog code.

## HDL Overview

Hardware description languages (HDL) offer a way to design circuits using text-based descriptions. HDL describes hardware using keywords and expressions, such as logic expressions, truth tables, functions, and logic gates. The two primary hardware description languages are VHDL and Verilog.

## Popularity of Verilog

Verilog is a general-purpose language that is easy to learn and use. It has a syntax similar to C and is supported by most popular logic synthesis tools.

Verilog offers four levels of abstraction:

1. Circuit Level
2. Gate Level
3. Data Flow Level
4. Behavioral Level

## Module Definition

Modules are the building blocks of Verilog designs. They describe the functionality of the design and state the input and output ports. Each port is either an input or output. Modules cannot be **contained** in another module, but they can invoke other modules. The module definition follows the format:

```verilog
module module_name (port_list);
    // port declarations
    ...
    // variable declarations
    ...
    // description of behavior
endmodule
```

Note: Replace `module_name` with the actual name of the module, and `port_list` with the list of input and output ports.
