module simple_circuit (A, B, C, Y);
    input A, B, C;
    output Y;
    wire w1;
    and G1 (w1, B, C);
    or G2 (Y, A, w1);
endmodule