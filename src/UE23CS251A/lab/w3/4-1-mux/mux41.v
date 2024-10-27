module mux4(input wire [0:3] i, input wire j0, j1, output wire o);
    wire [0:1] s;
    assign s = j1 ? {j0, 1'b1} : {j0, 1'b0};
    
    assign o = (s == 2'b00) ? i[0] :
              (s == 2'b01) ? i[1] :
              (s == 2'b10) ? i[2] :
                            i[3];
endmodule
