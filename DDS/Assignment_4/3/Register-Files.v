
module regfile(input clock,input reset, input [4:0] address,
               input en_write, input [31:0] idata,output [31:0] data);

// Register file storage
reg [31:0] registers[31:0];
reg [31:0] out_val;

// Read and write from register file
always @(posedge clock)
    if(!reset) begin
        if (en_write)
                registers[address] <= idata;
        else
                out_val <= registers[address];
    end

assign data = en_write ? 32'bx : out_val;

endmodule

`timescale 1ns / 1ps
module stimulus;
    reg clock;
    reg reset;
    reg [4:0] address;
    reg en_write;
    reg [31:0] idata;
    wire [31:0] data;

    regfile r1(
        .clock(clock),
        .reset(reset),
        .address(address),
        .en_write(en_write),
        .idata(idata),
        .data(data)
    );

    integer i;
 
	initial begin
	$dumpfile("regfile.vcd");
    $dumpvars(0,stimulus);
    reset = 0;
	#5 en_write=1; address=1; idata= 13456789;
	#5 en_write=0; address=1; 
    #10
	#5 en_write=1; address=8; idata= 45678;	
	#5 en_write=0; address=8; 
    #10	
    #5 en_write=1; address=1; idata=23456787;
	#5 en_write=0; address=1; 
    #10
    #5 en_write=1; address=15; idata= 876545122;
	#5 en_write=0; address=15; 
    #10
	#5 en_write=1; address=22; idata= 76543235678;	
	#5 en_write=0; address=22; 	
    #10
    #5 en_write=1; address=31; idata =134567;
	#5 en_write=0; address=31; 
    #10
    #5 en_write=1; address=22; idata= 1102983746;
	#5 en_write=0; address=22; 
    #10
	#5 en_write=1; address=18; idata= 45678;	
	#5 en_write=0; address=18; 	
    #5 en_write=1; address=13; idata =23456787;
	#5 en_write=0; address=13; 	
    #10;
    end  
 
	initial begin
	clock = 0;
	for ( i =0; i <=10; i= i+1)
	#5 clock = ~clock;
    end  
 
 
	initial begin
		$monitor("clock=%d,reset=%d,address=%d,en_write=%d,idata=%d,data=%d \n",clock,reset,address,en_write,idata,data);
	end

endmodule
