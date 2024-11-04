# Endian

Endian-ness refers to the two  alternate methods of ordering the  bytes in a
larger unit (word, DWORD,  etc.) 

- Big-Endian
  - PPC, Sparc
  - MS byte is put at the starting address
 
- Little-Endian
  - used by Intel processors / original PCI bus
  - LS byte is put at the starting address 

> Some processors (like ARM) and busses can be configured for either big / little-endian

![[Pasted image 20241029121625.png]]

---
# Difference

| Little                                                                                                      | Big                                                                                                       |
| ----------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| makes sense if you view your  memory as starting at the bottom-right and addresses  increasing as you go up | makes sense if you view your  memory as starting at the  top-left and addresses increasing as you go down |
| ![[Pasted image 20241029121749.png]]                                                                        | ![[Pasted image 20241029121754.png]]                                                                      |

