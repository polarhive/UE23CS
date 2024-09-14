module alu(input [1:0] op, input [15:0] i0, input [15:0] i1, output reg [15:0] o, output reg cout);

  always @* begin
    case (op)
      2'b00: begin
        o = i0 & i1;
        cout = 0;
      end

      2'b01: begin
        o = i0 | i1;
        cout = 0;
      end

      2'b10: begin
        {cout, o} = i0 + i1;
      end

      2'b11: begin
        {cout, o} = i0 - i1;
        cout = (i0 < i1);
      end

      default: begin
        o = 16'b0;
        cout = 0;
      end

    endcase
  end
endmodule
