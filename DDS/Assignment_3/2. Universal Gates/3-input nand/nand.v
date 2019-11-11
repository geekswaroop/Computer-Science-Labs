`timescale 1ns/1ns

module NAND (
    input in_a, in_b, in_c,
    output out 
);
    nand(out, in_a, in_b, in_c);    

endmodule

module NAND_tb;
    reg in_a = 1'b0;
    reg in_b = 1'b0;
    reg in_c = 1'b0;
    wire out;

    NAND h1 (
        .in_a(in_a),
        .in_b(in_b),
        .in_c(in_c),
        .out(out)
    );


    initial
    begin
        $dumpfile("nand.vcd");
        $dumpvars(0, NAND_tb);
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
        $monitor("A = %d\tB = %d\tC = %d\tNand = %d\t", in_a, in_b, in_c, out);
    end
endmodule
