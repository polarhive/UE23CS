module tb_simple_circuit;
reg A,B,C;
wire Y;
simple_circuit M1(A,B,C,Y);
initial
begin
#20
A=1'b0 ; B=1'b0 ; C=1'b0;
#20
A=1'b0 ; B=1'b0 ; C=1'b1;
#20
A=1'b0 ; B=1'b1 ; C=1'b0;
#20
A=1'b0 ; B=1'b1 ; C=1'b1;
#20
A=1'b1 ; B=1'b0 ; C=1'b0;
#20
A=1'b1 ; B=1'b0 ; C=1'b1;
#20
A=1'b1 ; B=1'b1 ; C=1'b0;
#20
A=1'b1 ; B=1'b1 ; C=1'b1;
end
initial
begin
$monitor($time, "A=%b, B=%b, C=%b,Y=%b", A,B,C,Y);
end
initial
begin
$dumpfile ("circuit1.vcd");
$dumpvars (0, tb_simple_circuit);
end
endmodule
