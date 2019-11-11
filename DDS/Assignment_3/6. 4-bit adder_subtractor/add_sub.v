`timescale 1ns/1ns


module Half_Adder (
    input in_a, in_b,
    output sum, carry
);
    
    xor(sum, in_a, in_b);
    and(carry, in_a, in_b);

endmodule

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

module four_bit_tb;
    reg a4 = 1'b1, a3 = 1'b1, a2 = 1'b0, a1 = 1'b1;
    reg b4 = 1'b0, b3 = 1'b0, b2 = 1'b0, b1 = 1'b1;
    reg m = 1'b0;
    wire s1, s2, s3, s4;
    wire c1, c2, c3;

    Full_Adder f1(
        .in_a(a1),
        .in_b(b1),
        .in_c(m),
        .carry(c1),
        .sum(s1)
    );
    Full_Adder f2(
        .in_a(a2),
        .in_b(b2),
        .in_c(c1),
        .carry(c2),
        .sum(s2)
    );
    Full_Adder f3(
        .in_a(a3),
        .in_b(b3),
        .in_c(c2),
        .carry(c3),
        .sum(s3)
    );
    Full_Adder f4(
        .in_a(a4),
        .in_b(b4),
        .in_c(c3),
        .sum(s4)
    );


    initial
    begin
        $dumpfile("four_bit.vcd");
        $dumpvars(0, four_bit_tb);
    end

    initial
    begin
        a4 = 1'b0;
        a3 = 1'b1;
        a2 = 1'b0;
        a1 = 1'b1;
        b4 = 1'b1;
        b3 = 1'b1;
        b2 = 1'b1;
        b1 = 1'b1;

        #10;
        a4 = 1'b1;
        a3 = 1'b1;
        a2 = 1'b0;
        a1 = 1'b0;
        b4 = 1'b1;
        b3 = 1'b0;
        b2 = 1'b1;
        b1 = 1'b1;

        #10;
        a4 = 1'b0;
        a3 = 1'b0;
        a2 = 1'b1;
        a1 = 1'b0; 
        b4 = 1'b0;
        b3 = 1'b0;
        b2 = 1'b0;
        b1 = 1'b0;

        #10;
        a4 = 1'b0;
        a3 = 1'b1;
        a2 = 1'b1;
        a1 = 1'b1;   
        #10;
        a4 = 1'b1;
        a3 = 1'b0;
        a2 = 1'b0;
        a1 = 1'b0;
        #10;
        a4 = 1'b0;
        a3 = 1'b0;
        a2 = 1'b0;
        a1 = 1'b0;
        #10;
        a4 = 1'b1;
        a3 = 1'b0;
        a2 = 1'b1;
        a1 = 1'b1;
        #10;
        a4 = 1'b1;
        a3 = 1'b1;
        a2 = 1'b1;
        a1 = 1'b1;
        #10;
    end
    initial
    begin
        $monitor("%d%d%d%d + %d%d%d%d = %d%d%d%d",a4,a3,a2,a1,b4,b3,b2,b1,s4,s3,s2,s1);
    end

endmodule
