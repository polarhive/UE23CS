module NOT_TEST;
    reg a;
    wire y;
    not NOT_TEST(y, a);
    initial begin
        #0 a = 0;
        #5 a = 1;
    end
    initial begin
        $monitor($time, "a = %b, y = %b", a, y);
    end
    initial begin
        $dumpfile("NOT.vcd");
        $dumpvars(0, NOT_TEST);
    end
endmodule