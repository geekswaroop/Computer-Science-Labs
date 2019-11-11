//Program:Implements a pipieline consisting of 64-Bit ALU and 32b x 64b register

module aluregfile(input clock,input reset,input[4:0]address1,input[4:0]address2,
            input[4:0]address3,input[4:0]address4,
            input[3:0]ALU_Sel,input en_write,
            input eval,input read,input[63:0]idata1,input[63:0]idata2,output reg[63:0]data);

// Register file storage
reg [63:0] registers[31:0];
reg [63:0] ALU_Result;

// Read and write from register file
always @(posedge clock)
    if(!reset) begin
        if (en_write==1 && eval==0 && read==0)
                begin
                registers[address1] <= idata1;
                registers[address2] <= idata2;
                end
        if(en_write==0 && eval==1 && read==0)
                begin
                    case(ALU_Sel)
                        4'b0000: // Addition
                        ALU_Result <= registers[address1] + registers[address2] ;
                        //ALU_Result <= idata1 + idata2 ; 
                        4'b0001: // Subtraction
                        ALU_Result <= registers[address1] - registers[address2] ;
                        4'b0010: // Multiplication
                        ALU_Result <= registers[address1] * registers[address2];
                        4'b0011: // Division
                        ALU_Result <= registers[address1]/registers[address2];
                        4'b0100: // Logical shift left
                        ALU_Result <= registers[address1]<<1;
                        4'b0101: // Logical shift right
                        ALU_Result <= registers[address1]>>1;
                        4'b0110: // Rotate left
                        ALU_Result <= {registers[address1][62:0],registers[address1][63]};
                        4'b0111: // Rotate right
                        ALU_Result <= {registers[address1][0],registers[address1][63:1]};
                        4'b1000: //  Logical and 
                        ALU_Result <= registers[address1] & registers[address2];
                        4'b1001: //  Logical or
                        ALU_Result <= registers[address1] | registers[address2];
                        4'b1010: //  Logical xor 
                        ALU_Result <= registers[address1] ^ registers[address2];
                        4'b1011: //  Logical nor
                        ALU_Result <= ~(registers[address1] | registers[address2]);
                        4'b1100: // Logical nand 
                        ALU_Result <= ~(registers[address1] & registers[address2]);
                        4'b1101: // Logical xnor
                        ALU_Result <= ~(registers[address1] ^ registers[address2]);
                        4'b1110: // Greater comparison
                        ALU_Result <= (registers[address1]>registers[address2])?8'd1:8'd0 ;
                        4'b1111: // Equal comparison   
                        ALU_Result <= (registers[address1]==registers[address2])?8'd1:8'd0 ;
                        default: ALU_Result = registers[address1] + registers[address2] ; 
                    endcase
                    registers[address3] <= ALU_Result;
                end
         if(read==1 && en_write==0 && eval==0)
                data <= registers[address4];
    end
endmodule

`timescale 1ns / 1ps
module stimulus;
    reg clock;
    reg reset;
    reg [4:0] address1;
    reg [4:0] address2;
    reg [4:0] address3;
    reg [4:0] address4;
    reg [3:0] ALU_Sel;
    reg en_write;
    reg eval;
    reg read;
    reg [63:0] idata1;
    reg [63:0] idata2;
    wire [63:0] data;

    aluregfile r1(
        .clock(clock),
        .reset(reset),
        .address1(address1),
        .address2(address2),
        .address3(address3),
        .address4(address4),
        .ALU_Sel(ALU_Sel),
        .en_write(en_write),
        .eval(eval),
        .read(read),
        .idata1(idata1),
        .idata2(idata2),
        .data(data)
    );

    integer i;
 
	initial begin
	$dumpfile("alureg.vcd");
    $dumpvars(0,stimulus);
    reset = 0;
	#5 en_write=1; eval=0; read=0; address1=1; idata1= 13456789; address2=8; idata2=456787;
	#10 en_write=0; eval=0; read=1; address4=1;
    #10 en_write=0; eval=0; read=1; address4=8; 
    #10
	#10 en_write=0; eval=1; read=0; ALU_Sel=4'b0000; address3=5;
    #20 en_write=0; eval=0; read=1; address4=5;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0001; address3=15;
    #20 en_write=0; eval=0; read=1; address4=15;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0010; address3=16;
    #20 en_write=0; eval=0; read=1; address4=16;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0011; address3=17;
    #20 en_write=0; eval=0; read=1; address4=17;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0100; address3=18;
    #20 en_write=0; eval=0; read=1; address4=18;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0101; address3=19;
    #20 en_write=0; eval=0; read=1; address4=19;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0110; address3=20;
    #20 en_write=0; eval=0; read=1; address4=20;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b0111; address3=21;
    #20 en_write=0; eval=0; read=1; address4=21;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1000; address3=22;
    #20 en_write=0; eval=0; read=1; address4=22;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1001; address3=23;
    #20 en_write=0; eval=0; read=1; address4=23;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1010; address3=24;
    #20 en_write=0; eval=0; read=1; address4=24;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1011; address3=25;
    #20 en_write=0; eval=0; read=1; address4=25;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1100; address3=26;
    #20 en_write=0; eval=0; read=1; address4=26;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1101; address3=27;
    #20 en_write=0; eval=0; read=1; address4=27;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1110; address3=28;
    #20 en_write=0; eval=0; read=1; address4=28;
    #10 en_write=0; eval=1; read=0; ALU_Sel=4'b1111; address3=29;
    #20 en_write=0; eval=0; read=1; address4=29;
    end  
 
	initial begin
	clock = 0;
	for ( i =0; i <=100; i= i+1)
	#5 clock = ~clock;
    end  

endmodule


