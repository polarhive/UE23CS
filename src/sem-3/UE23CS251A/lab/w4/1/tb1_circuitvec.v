`define TESTVECS 6

module tb;
  reg [2:0] i1;
  reg i2;
  wire sum1,cout1;
  
  reg [3:0] test_vecs [0:(`TESTVECS-1)];
  integer i;
  initial begin $dumpfile("circuit_3.vcd");    
  $dumpvars(0,tb); 
  end
 
 
  initial begin
    test_vecs[0][3:1] = 3'b000; 	test_vecs[0][0:0] = 1'b0;
    test_vecs[1][3:1] = 3'b001;	test_vecs[1][0:0] = 1'b1;
    test_vecs[2][3:1] = 3'b010;	test_vecs[2][0:0] = 1'b0;
    test_vecs[3][3:1] = 3'b011;	test_vecs[3][0:0] = 1'b1; 
    test_vecs[4][3:1] = 3'b010;	test_vecs[4][0:0] = 1'b0;
    test_vecs[5][3:1] = 3'b011;	test_vecs[5][0:0] = 1'b1; 
    end


  initial {i1, i2} = 0;
  circuit3 circuit3_0 (i1,i2,sum1, cout1);
  initial begin
       for(i=0;i<`TESTVECS;i=i+1)        
       begin #10 {i1,i2}=test_vecs[i]; 
       end   
  
  end
endmodule
