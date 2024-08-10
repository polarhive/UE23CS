module OR_TEST;
    reg a, b;
    wire y;
    or OR_TEST (y, a, b);
    initial begin
        #0 a = 0; b = 0;
        #5 a = 0; b = 1;
        #10 a = 1; b = 0;
        #15 a = 1; b = 1;
    end
    initial begin
        $monitor($time, "a = %b, b = %b, y = %b", a, b, y);
    end
    initial begin
        $dumpfile("OR.vcd");
        $dumpvars(0, OR_TEST);
    end
endmodule
