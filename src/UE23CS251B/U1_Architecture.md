# Computer Architecture

> The specifications around which a computer's [[U3_Computer_Organization|organizational]] layout is defined.

- Microcontroller: Embedded all in one device. Specific tasks
- Microprocessor: Processor <-> memory / timer. More generic.

| RISC                                | CISC                     |
| ----------------------------------- | ------------------------ |
| simpler                             | complex                  |
| fixed len: '32' only                | variable len: 32, 64 bit |
| multiple reg set                    | single reg set           |
| single cycle                        | multi cycle              |
| hardware control                    | microprogram control     |
| highly [[U2_Pipelining\|pipelined]] | less pipelining          |
| only `LOAD` `STORE`                 | many memory instructions |
