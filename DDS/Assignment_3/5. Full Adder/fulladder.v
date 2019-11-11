`timescale 1ns/1ns
`include "lib/halfadder.v"

module Full_Adder (
    input in_a, in_b, in_c,
    output sum, carry 
);
    wire x,y,z;
    Half_Adder h1(
        .in_a(in_a),
        .in_b(in_b),
        .sum(x),
        .carry(y)
    );

    Half_Adder h2(
        .in_a(x),
        .in_b(in_c),
        .sum(sum),
        .carry(z)
    );

    or(carry, z, y);

endmodule

module full_adder_tb;
    reg in_a = 1'b0;
    reg in_b = 1'b0;
    reg in_c = 1'b0;
    wire sum, carry;

    Full_Adder h1 (
        .in_a(in_a),
        .in_b(in_b),
        .in_c(in_c),
        .sum(sum),
        .carry(carry)
    );


    initial
    begin
        $dumpfile("full_adder.vcd");
        $dumpvars(0, full_adder_tb);
    end

    initial
    begin
        in_a = 1'b0;
        in_b = 1'b0;
        in_c = 1'b0;
        #10;
        in_a = 1'b0;
        in_b = 1'b0;
        in_c = 1'b1;
        #10;
        in_a = 1'b0;
        in_b = 1'b1;
        in_c = 1'b0;
        #10;
        in_a = 1'b0;
        in_b = 1'b1;
        in_c = 1'b1;
        #10;
        in_a = 1'b1;
        in_b = 1'b0;
        in_c = 1'b0;
        #10;
        in_a = 1'b1;
        in_b = 1'b0;
        in_c = 1'b1;
        #10;
        in_a = 1'b1;
        in_b = 1'b1;
        in_c = 1'b0;
        #10;
        in_a = 1'b1;
        in_b = 1'b1;
        in_c = 1'b1;
        #10;
    end
    
    initial
    begin
        $monitor("A = %d\tB = %d\tC = %d\tSum = %d\tCarry = %d\t", in_a, in_b, in_c, sum, carry);
    end
endmodule
