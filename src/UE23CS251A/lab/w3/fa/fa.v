module fulladder (
    input wire a, b, cin,
    output wire sum, cout
);

    wire t0, t1, t2;

    xor x0 (t0, a, b);
    xor x1 (sum, t0, cin);

    and a0 (t1, a, b);
    and a1 (t2, a, cin);
    and a2 (t3, b, cin);
    or o0 (cout, t1, t2, t3);

endmodule
