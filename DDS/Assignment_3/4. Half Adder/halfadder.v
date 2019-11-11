`timescale 1ns/1ns

module Half_Adder (
    input in_a, in_b,
    output sum, carry
);
    
    xor(sum, in_a, in_b);
    and(carry, in_a, in_b);

endmodule

module half_adder_tb;
    reg in_a = 1'b0;
    reg in_b = 1'b0;
    wire sum, carry;

    Half_Adder h1 (
        .in_a(in_a),
        .in_b(in_b),
        .sum(sum),
        .carry(carry)
    );


    initial
    begin
        $dumpfile("half_adder.vcd");
        $dumpvars(0, half_adder_tb);
    end

    initial
    begin
        in_a = 1'b0;
        in_b = 1'b0;
        #10;
        in_a = 1'b1;
        in_b = 1'b0;
        #10;
        in_a = 1'b0;
        in_b = 1'b1;
        #10;
        in_a = 1'b1;
        in_b = 1'b1;
        #10;
    end
    
    initial
    begin
        $monitor("A = %d\tB = %d\tSum = %d\tCarry = %d\t", in_a, in_b, sum, carry);
    end
endmodule
