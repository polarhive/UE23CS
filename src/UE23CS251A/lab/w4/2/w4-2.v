module invert (
    input wire i,
    output wire o
);
    assign o = !i;
endmodule

module and2 (
    input wire i0, i1,
    output wire o
);
    assign o = i0 & i1;
endmodule

module or2 (
    input wire i0, i1,
    output wire o
);
    assign o = i0 | i1;
endmodule

module xor2 (
    input wire i0, i1,
    output wire o
);
    assign o = i0 ^ i1;
endmodule

module nand2 (
    input wire i0, i1,
    output wire o
);
    wire t;
    and2 and2_0 (i0, i1, t);
    invert invert_0 (t, o);
endmodule

module nor2 (
    input wire i0, i1,
    output wire o
);
    wire t;
    or2 or2_0 (i0, i1, t);
    invert invert_0 (t, o);
endmodule

module xnor2 (
    input wire i0, i1,
    output wire o
);
    wire t;
    xor2 xor2_0 (i0, i1, t);
    invert invert_0 (t, o);
endmodule

module and3 (
    input wire i0, i1, i2,
    output wire o
);
    wire t;
    and2 and2_0 (i0, i1, t);
    and2 and2_1 (i2, t, o);
endmodule

module or3 (
    input wire i0, i1, i2,
    output wire o
);
    wire t;
    or2 or2_0 (i0, i1, t);
    or2 or2_1 (i2, t, o);
endmodule

module nor3 (
    input wire i0, i1, i2,
    output wire o
);
    wire t;
    or2 or2_0 (i0, i1, t);
    nor2 nor2_0 (i2, t, o);
endmodule

module nand3 (
    input wire i0, i1, i2,
    output wire o
);
    wire t;
    and2 and2_0 (i0, i1, t);
    nand2 nand2_1 (i2, t, o);
endmodule

module xor3 (
    input wire i0, i1, i2,
    output wire o
);
    wire t;
    xor2 xor2_0 (i0, i1, t);
    xor2 xor2_1 (i2, t, o);
endmodule

module fa (
    input wire i0, i1, cin,
    output wire sum, cout
);
    wire t0, t1, t2;
    xor3 x0 (i0, i1, cin, sum);   // XOR gate for sum
    and2 a0 (i0, i1, t0);         // AND gate for carry-out part 1
    and2 a1 (i1, cin, t1);        // AND gate for carry-out part 2
    and2 a2 (cin, i0, t2);        // AND gate for carry-out part 3
    or3 o0 (t0, t1, t2, cout);    // OR gate to combine carry-out
endmodule

module ha (
    input wire a, b,
    output wire sum, cout
);
    xor2 x0 (a, b, sum);    // XOR gate for sum
    and2 a0 (a, b, cout);   // AND gate for carry-out
endmodule

module circuit3 (
    input wire [2:0] i,
    input wire y,
    output wire S1, Cout
);
    wire S0, C0, y_inv;

    fa fa_1 (i[0], i[1], i[2], S0, C0);
    invert inv_1 (y, y_inv);
    ha ha_1 (S0, y_inv, S1, Cout);
endmodule
