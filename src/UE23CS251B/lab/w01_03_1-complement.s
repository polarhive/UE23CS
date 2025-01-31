; week-01/3
; Write ALP to perform 1's complement only using MOV and BIC

;num to a reg R2
;save #0xFFFFFFFF to R1
;bic to obtain complement of 5
;save in R3

.text
    MOV R2, #0x05          ; Load the first number (5) into R2
    MOV R1, #0xFFFFFFFF    ; Load all bits set (0xFFFFFFFF) into R1
    BIC R1, R1, R2         ; R1 = R1 & ~R2. BIC clears the bits in R1 where R2 has 1's

    MOV R3, R1             ; Result in R3
    SWI 0x011              ; 
