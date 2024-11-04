module testbench;

    reg [15:0] data_in;
    wire [4:0] ones_count;

    count_ones_16bit uut (
        .data_in(data_in),
        .ones_count(ones_count)
    );

    initial begin
        $monitor("Input: %b, Number of 1's: %d", data_in, ones_count);
        data_in = 16'b0000000000000000; #10;
        data_in = 16'b1111111111111111; #10;
        data_in = 16'b0101010101010101; #10;
        data_in = 16'b1100101010010110; #10;
        data_in = 16'b0001000000001001; #10;
        data_in = 16'b1011110110111110; #10;

        $finish;
    end

endmodule
