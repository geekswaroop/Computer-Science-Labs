`timescale 1ns/1ns

module Half_Adder (
    input in_a, in_b,
    output sum, carry
);
    
    assign sum = in_a ^ in_b;
    assign carry = in_a & in_b;

endmodule

module Full_Adder (
    input a, b, cin,
    output fsum, cout
);
    wire s1, c1, c2;
    Half_Adder HA1(.in_a(a), .in_b(b), .sum(s1), .carry(c1));
    Half_Adder HA2(.in_a(s1), .in_b(cin), .sum(fsum), .carry(c2));
    assign cout = c1 | c2;

endmodule

module Carry_Lookahead_Adder(
    input [3:0] A, B,
    output [3:0] S,
    output c
);

    wire [4:0] C;
    wire [3:0] P, G;
    assign C[0] = 1'b0;

    genvar i;

    generate

    for(i=0; i<4; i=i+1)
    begin
        Half_Adder HA(.in_a(A[i]), .in_b(B[i]), .sum(P[i]), .carry(G[i]));
        assign C[i+1] = G[i] | (P[i] & C[i]);
    end

    for(i=0; i<4; i=i+1)
        Full_Adder FA(.a(A[i]), .b(B[i]), .cin(C[i]), .fsum(S[i]));

    endgenerate

    assign c = C[4];

endmodule

module Carry_Lookahead_tb;
    reg [3:0] A, B;
    wire [3:0] S;
    wire c;

    Carry_Lookahead_Adder Add (
        .A(A),
        .B(B),
        .S(S),
        .c(c)
    );


    initial
    begin
        $dumpfile("Carry_Lookahead.vcd");
        $dumpvars(0, Carry_Lookahead_tb);
    end

    initial
    begin
        A = 4'b0000;
        B = 4'b0110;
        #50;
        A = 4'b1010;
        B = 4'b0001;
        #50;
        A = 4'b0111;
        B = 4'b1010;
        #50;
        A = 4'b0101;
        B = 4'b1111;
        #50;
        A = 4'b1100;
        B = 4'b1101;
        #50;
        A = 4'b0111;
        B = 4'b1001;
        #50;
        A = 4'b0001;
        B = 4'b1111;
        #50;
        A = 4'b0101;
        B = 4'b1010;
        #50;
        A = 4'b1111;
        B = 4'b1010;
        #50;
        A = 4'b1010;
        B = 4'b0011;
        #50;
        A = 4'b1000;
        B = 4'b0111;
        #50;
        A = 4'b0101;
        B = 4'b0001;
        #50;
        A = 4'b0101;
        B = 4'b1111;
        #50;
        A = 4'b1011;
        B = 4'b1001;
        #50;
        A = 4'b0001;
        B = 4'b0010;
        #50;
        A = 4'b1101;
        B = 4'b1111;
        #50;
    end
    
    initial
    begin
        $monitor("A = %b\tB = %b\tSum = %b\tCarry = %d", A, B, S, c);
    end

endmodule