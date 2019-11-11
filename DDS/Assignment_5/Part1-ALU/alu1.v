


//64 Bit alu


`timescale 1ns/1ns
module alu(a,b,operation,carry_in,Result,flag,carry_out);

      input [63:0] a;
      input [63:0] b;
	input [63:0] carry_in;
      input [3:0] operation;
      output [63:0]Result;
      output flag,carry_out;
      reg Result,flag,carry_out;

      always@(a or b or operation)
          begin
               case (operation)
                 4'b0000:  Result = a & b;   // AND
                 4'b0001:  Result = a | b;   // OR
                 4'b0010:  Result = a + b +carry_in;    // addition
                 4'b0110:  Result = a - b - carry_in;    // subtraction
		 4'b1101:  Result = !(a & b); //nand
		 4'b1100:  Result = !(a | b); //nor
               endcase

		begin
			if(operation[0]==0 && operation[1]==1 && operation[2]==0 && operation[3]==0)
			carry_out= a&b;
			else if(operation[0]==0 && operation[1]==1 && operation[2]==1 && operation[3]==0)
			carry_out= (~a)&b;
		end
		begin
			if(Result ==0 && carry_out==0)
			assign flag=1;
			else
			assign flag=0;
		end
           end 
		
endmodule	


module alu_tb;
	reg [63:0]a;
	reg [63:0]b;
	reg [63:0] carry_in;
	reg [3:0] operation;
	wire [63:0]Result;
	wire carry_out;

initial begin
	$dumpfile("alu1.vcd");
	$dumpvars(0,alu_tb);	
	$monitor ("a=%b, b=%b, operation=%b%b%b%b, carry_out=%b, Result=%b flag=%b ",a,b,operation[3],operation[2],operation[1],operation[0],carry_out,Result,flag);
	a=0;
	b=0;
	carry_in=0;
	operation[0]=0;
	operation[1]=0;
	operation[2]=0;
	operation[3]=0;
	
	#20 a=2;
	operation[0]=1;
	#20 b=3;
	#20 operation[0]=0;
	#20 operation[1]=1;
	#20 operation[2]=1;
	#20 a=1024;
	#20 operation[2]=0;
	carry_in=1;
	#20 operation[1]=1;
	#20 operation[3]=1;
	#20 b=120;
	#20 a=9;
	#20 operation[0]=1;

	#20 b=22;

	
	#10 $finish;
end

alu c(
	.a(a),
	.b(b),
	.operation(operation),
	.carry_in(carry_in),
	.Result(Result),
	.flag(flag),
	.carry_out(carry_out)
);
endmodule

