`timescale 1ns/1ns
module DeMux_16_1
(
    input [31:0] D,
    input [3:0] s,
    output [31:0] a1,
    output [31:0] a2,
    output [31:0] a3,
    output [31:0] a4,
    output [31:0] a5,
    output [31:0] a6,
    output [31:0] a7,
    output [31:0] a8,
    output [31:0] a9,
    output [31:0] a10,
    output [31:0] a11,
    output [31:0] a12,
    output [31:0] a13,
    output [31:0] a14,
    output [31:0] a15,
    output [31:0] a16
);

    reg [31:0] A1 = 32'b00000000000000000000000000000000;
    reg [31:0] A2 = 32'b00000000000000000000000000000000;
    reg [31:0] A3 = 32'b00000000000000000000000000000000;
    reg [31:0] A4 = 32'b00000000000000000000000000000000;
    reg [31:0] A5 = 32'b00000000000000000000000000000000;
    reg [31:0] A6 = 32'b00000000000000000000000000000000;
    reg [31:0] A7 = 32'b00000000000000000000000000000000;
    reg [31:0] A8 = 32'b00000000000000000000000000000000;
    reg [31:0] A9 = 32'b00000000000000000000000000000000;
    reg [31:0] A10 = 32'b00000000000000000000000000000000;
    reg [31:0] A11 = 32'b00000000000000000000000000000000;
    reg [31:0] A12 = 32'b00000000000000000000000000000000;
    reg [31:0] A13 = 32'b00000000000000000000000000000000;
    reg [31:0] A14 = 32'b00000000000000000000000000000000;
    reg [31:0] A15 = 32'b00000000000000000000000000000000;
    reg [31:0] A16 = 32'b00000000000000000000000000000000;

    always @(*)
    begin
/*
        case (s)
            4'b0000 : assign A = a1;
            4'b0001 : assign A = a2;
            4'b0010 : assign A = a3;
            4'b0011 : assign A = a4;
            4'b0100 : assign A = a5;
            4'b0101 : assign A = a6;
            4'b0110 : assign A = a7;
            4'b0111 : assign A = a8;
            4'b1000 : assign A = a9;
            4'b1001 : assign A = a10;
            4'b1010 : assign A = a11;
            4'b1011 : assign A = a12;
            4'b1100 : assign A = a13;
            4'b1101 : assign A = a14;
            4'b1110 : assign A = a15;
            4'b1111 : assign A = a16;
*/
        case (s)
            4'b0000 : A1 <= D;
            4'b0001 : A2 <= D;
            4'b0010 : A3 <= D;
            4'b0011 : A4 <= D;
            4'b0100 : A5 <= D;
            4'b0101 : A6 <= D;
            4'b0110 : A7 <= D;
            4'b0111 : A8 <= D;
            4'b1000 : A9 <= D;
            4'b1001 : A10 <= D;
            4'b1010 : A11 <= D;
            4'b1011 : A12 <= D;
            4'b1100 : A13 <= D;
            4'b1101 : A14 <= D;
            4'b1110 : A15 <= D;
            4'b1111 : A16 <= D;
        endcase
    end

    assign a1 = A1;
    assign a2 = A2;
    assign a3 = A3;
    assign a4 = A4;
    assign a5 = A5;
    assign a6 = A6;
    assign a7 = A7;
    assign a8 = A8;
    assign a9 = A9;
    assign a10 = A10;
    assign a11 = A11;
    assign a12 = A12;
    assign a13 = A13;
    assign a14 = A14;
    assign a15 = A15;
    assign a16 = A16;

endmodule

module demux_tb;
    reg [31:0] data;
    reg [3:0] s;
    wire [31:0] a1;
    wire [31:0] a2;
    wire [31:0] a3;
    wire [31:0] a4;
    wire [31:0] a5;
    wire [31:0] a6;
    wire [31:0] a7;
    wire [31:0] a8;
    wire [31:0] a9;
    wire [31:0] a10;
    wire [31:0] a11;
    wire [31:0] a12;
    wire [31:0] a13;
    wire [31:0] a14;
    wire [31:0] a15;
    wire [31:0] a16;

    DeMux_16_1 DeM
    (
        .D(data),
        .s(s),
        .a1(a1),
        .a2(a2),
        .a3(a3),
        .a4(a4),
        .a5(a5),
        .a6(a6),
        .a7(a7),
        .a8(a8),
        .a9(a9),
        .a10(a10),
        .a11(a11),
        .a12(a12),
        .a13(a13),
        .a14(a14),
        .a15(a15),
        .a16(a16)
    );

    initial
    begin
        $dumpfile("DEMUX.vcd");
        $dumpvars(0, demux_tb);
    end

    initial
    begin
        s = 4'b0010;
        data = 32'b00001100000001111101001011100100;
        #100;

        s = 4'b1001;
        data = 32'b10110011011000101101000111110111;
        #100;

        s = 4'b0010;
        data = 32'b00010001111001110000111100100010;
        #100;

        s = 4'b1010;
        data = 32'b11011011001111000110000010011101;
        #100;

        s = 4'b0000;
        data = 32'b10000010110101000000000001000110;
        #100;
        
        s = 4'b1111;
        data = 32'b01100010001010001000001110101100;
        #100;

        s = 4'b1000;
        data = 32'b00111000000110110100011001110001;
        #100;

        s = 4'b1011;
        data = 32'b10111100110100001111100100011011;
        #100;
    end

    initial
    begin
        $monitor
        (
            "data = %b\nselect = %b\na1 = %b\na2 = %b\na3 = %b\na4 = %b\na5 = %b\na6 = %b\na7 = %b\na8 = %b\na9 = %b\na10 = %b\na11 = %b\na12 = %b\na13 = %b\na14 = %b\na15 = %b\na16 = %b\n",
            data,
            s,
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            a15,
            a16
        );
    end

endmodule