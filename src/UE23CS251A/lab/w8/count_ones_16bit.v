module count_ones_16bit(
    input [15:0] data_in,
    output [4:0] ones_count
);

    wire [3:0] count0, count1, count2, count3;
    wire [4:0] sum1, sum2;

    count_ones_4bit counter0(.data_in(data_in[3:0]), .ones_count(count0));
    count_ones_4bit counter1(.data_in(data_in[7:4]), .ones_count(count1));
    count_ones_4bit counter2(.data_in(data_in[11:8]), .ones_count(count2));
    count_ones_4bit counter3(.data_in(data_in[15:12]), .ones_count(count3));

    assign sum1 = count0 + count1;
    assign sum2 = count2 + count3;
    assign ones_count = sum1 + sum2;

endmodule

module count_ones_4bit(
    input [3:0] data_in,
    output [3:0] ones_count
);
    assign ones_count = data_in[0] + data_in[1] + data_in[2] + data_in[3];
endmodule
