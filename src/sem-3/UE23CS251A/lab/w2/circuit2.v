module simple_circuit(A2,B2,C2,Y);
    input A2,B2,C2;
    output Y;
    wire w1,w2,w3;
    and G1 (w1, C, B);
    or G2 (w2, A, w1);
    and G3 (w3, B, A);
    or G4 (Z, w2, w3);
endmodule
