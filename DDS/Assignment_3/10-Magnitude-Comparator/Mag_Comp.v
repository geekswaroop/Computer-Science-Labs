`timescale 1ns/1ns
module Mag_Comp
(
    input [3:0]in_a,
    input [3:0]in_b,
    output a1, a2, a3
);

    wire [3:0] x;
    
    genvar i;

    generate
    for(i=3; i>=0; i=i-1)
    begin
        assign x[i] = (in_a[i] ~^ in_b[i]);
    end
    endgenerate

    assign a1 = x[3] & x[2] & x[1] & x[0];
    assign a2 =   in_a[3] & ~(in_b[3])
                | x[3] & in_a[2] & ~(in_b[2])
                | x[3] & x[2] & in_a[1] & ~(in_b[1])
                | x[3] & x[2] & x[1] & in_a[0] & ~(in_b[0]);

    assign a3 = ~(a1 | a2);

endmodule

module Mag_Comp_tb;
    reg [3:0] in_a;
    reg [3:0] in_b;
    wire answer1, answer2, answer3;

    Mag_Comp M1(.in_a(in_a), .in_b(in_b), .a1(answer1), .a2(answer2), .a3(answer3));

    initial
    begin
        $dumpfile("Mag_Comp.vcd");
        $dumpvars(0, Mag_Comp_tb);
    end

    initial
    begin
        in_a = 4'b0110;
        in_b = 4'b0110;
        #30; 

        in_a = 4'b0101;
        in_b = 4'b1001;
        #30;

        in_a = 4'b0110;
        in_b = 4'b1110;
        #30; 

        in_a = 4'b0000;
        in_b = 4'b0000;
        #30;

        in_a = 4'b1111;
        in_b = 4'b1111;
        #30; 

        in_a = 4'b0001;
        in_b = 4'b0000;
        #30;

        in_a = 4'b1010;
        in_b = 4'b0101;
        #30; 

        in_a = 4'b1110;
        in_b = 4'b0011;
        #30;
    end

    initial
    begin
        $monitor("A = %b\tB = %b\t %b %b %b", in_a, in_b, answer1, answer2, answer3);
    end
    
endmodule