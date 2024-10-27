module halfadder (
    input wire a, b,
    output wire sum, cout
);

xor x0 (sum, a, b);
and a0 (cout, a, b);
endmodule
