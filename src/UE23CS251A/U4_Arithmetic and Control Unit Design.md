# Arithmetic and Control Unit Design

# Floating point

> [!Example]
> ![[Pasted image 20241125221101.png]]

## Special Cases

![[Pasted image 20241125220955.png]]

## Range

![[Pasted image 20241125221014.png]]

![[Pasted image 20241125222638.png]]

## Rounding Modes

![[Pasted image 20241125221041.png]]

---

# Array Multiplication

![[Pasted image 20241125221326.png]]

## Implementation

- Use an Adder circuitry to do repeated addition
- Multiplication through spatial addition, requires a single n-bit adder doing addition n times.
- After every addition, the result has to be shifted right once.
- Monitor the multiplier bit to add multiplicand to the partial product.
- Repeat the add – shift right process for the number of multiplier bits.
- All the control signals has to be generated for this sequential process appropriately, by a control sequencer.
- Requires n-cycles for n times addition.

![[Pasted image 20241125221541.png]]

---

# Booth Multiplication

> Booth recoding is a technique that makes multiplication more efficient by replacing strings of 1s with 0s and recoding the multiplier to a set of digits

![[Pasted image 20241125221815.png]]