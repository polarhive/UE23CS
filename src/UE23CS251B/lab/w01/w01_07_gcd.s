; week-01/7
; Write ALP to find gcd

; num in R0
; num is saved in R1
; cmp both R0 and R1
; if eq: end exec
; if r0>r1 R0=R0-R1
; repeat steps till R0=R1 and end
; if R0<R1 R1=R1-R0


.text
    MOV R0, #3           ; no1
    MOV R1, #9           ; no2

gcd_loop:
    CMP R0, R1             ; Compare R0 and R1
    BEQ end_gcd            ; If R0 == R1, end the program (GCD found)

    BGT R0_greater         ; If R0 > R1, branch to R0_greater
    BLT R1_greater         ; If R0 < R1, branch to R1_greater

R0_greater:
    SUB R0, R0, R1         ; If R0 > R1, subtract R1 from R0
    B gcd_loop             ; Repeat the loop

R1_greater:
    SUB R1, R1, R0         ; If R1 > R0, subtract R0 from R1
    B gcd_loop             ; Repeat the loop

end_gcd:
    MOV R2, R0             ;
    SWI 0x011              ;
