; week-01/2
; Write ALP to perform 2's complement only using MOV nad RSB

;num to a reg
;zero into another reg
;use rsb for (0-5)
;save in R3

.text
    MOV R0, #0x05      ; Load the first number (5) into R0
    MOV R2, #0         ; 0
    RSB R1, R0, R2     ; RSB
    MOV R3, R1         ; Store the result in R3
    SWI 0x011
