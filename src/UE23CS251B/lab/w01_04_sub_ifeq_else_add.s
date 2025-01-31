; week-01/4
; Write ALP to subtract if numbers eq, else add them

;num to a reg R0
;num to a reg R1
;compare the nums, if eq: branch to L1
;save to R2 and end
;not eq? add the two
;save res and end execution

.text
    MOV R0, #0x06          ; Load the first number into R0
    MOV R1, #0x05          ; Load the second number into R1

    CMP R0, R1             ; Compare R0 and R1
    BEQ L1                 ; Branch to L1 

    ADD R2, R0, R1         ; Add R0 and R1, store in R2
    B L2                   ; Jump to the end

L1:
    SUB R2, R0, R1         ; Subtract R1 from R0, store in R2

L2:
    ;(either sum or difference)
    SWI 0x011
