module fa (
  input wire i0, i1, cin,
  output wire sum, cout
);

assign sum = i0 ^ i1 ^ cin;
assign cout = (i0&i1 | (i1 & cin) | cin & i0);
endmodule

module inverter (
  input wire a,
  output wire y
);

assign y = ~a;
endmodule;

module ha (
  input wire a, b,
  output wire sum, cout
);

assign sum = a^b;
assign cout = a & b;
endmodule

module circuit3 (

  input wire [2:0] i,
  output wire so, cout
);

wire s0, c0, y;
fa full_adder (
  .i0(i[0]),
  .i1(i[1]),
  .cin(i[2]),
  .sum(s0),
  .cout(c0),
);


inverter inv (
  .a(s0),
  .y(y)
);

ha half_adder (
  .a(y),
  .b(c0),
  .sum(so),
  .cout(cout)
);
endmodule
