`timescale 1ns/1ns
`include "lib/HalfAdder.v"

module Multiplier (input a0, a1, b0, b1,output c0, c1, c2, c3);
    
    wire w,x,y,z;

    and(c0, a0, b0);
    and(x, a0, b1);
    and(y, a1, b0);
    HA h1 (x, y, c1, z);
    and(w, a1, b1);
    HA h2 (w, z, c2, c3);

    

endmodule 

module Multiplier_tb;

    reg a0 = 1'b0;
    reg b0 = 1'b0;
    reg a1 = 1'b0;
    reg b1 = 1'b0;

    wire c0, c1, c2, c3;

    Multiplier h1(a0,a1,b0,b1, c0, c1, c2, c3);

    initial
    begin
        $dumpfile("Multiplier.vcd");
        $dumpvars(0, Multiplier_tb);
    end

    initial
    begin
        a1 = 1'b0;
        a0 = 1'b0;
        b1 = 1'b0;
        b0 = 1'b0;
        #10;
        a1 = 1'b0;
        a0 = 1'b0;
        b1 = 1'b0;
        b0 = 1'b1;
        #10;
        a1 = 1'b0;
        a0 = 1'b0;
        b1 = 1'b1;
        b0 = 1'b0;
        #10;
        a1 = 1'b0;
        a0 = 1'b0;
        b1 = 1'b1;
        b0 = 1'b1;
        #10;
        a1 = 1'b0;
        a0 = 1'b1;
        b1 = 1'b0;
        b0 = 1'b0;
        #10;
        a1 = 1'b0;
        a0 = 1'b1;
        b1 = 1'b0;
        b0 = 1'b1;
        #10;
        a1 = 1'b0;
        a0 = 1'b1;
        b1 = 1'b1;
        b0 = 1'b0;
        #10;
        a1 = 1'b0;
        a0 = 1'b1;
        b1 = 1'b1;
        b0 = 1'b1;
        #10;
        a1 = 1'b1;
        a0 = 1'b0;
        b1 = 1'b0;
        b0 = 1'b0;
        #10;
        a1 = 1'b1;
        a0 = 1'b0;
        b1 = 1'b0;
        b0 = 1'b1;
        #10;
        a1 = 1'b1;
        a0 = 1'b0;
        b1 = 1'b1;
        b0 = 1'b0;
        #10;
        a1 = 1'b1;
        a0 = 1'b0;
        b1 = 1'b1;
        b0 = 1'b1;
        #10;
        a1 = 1'b1;
        a0 = 1'b1;
        b1 = 1'b0;
        b0 = 1'b0;
        #10;
        a1 = 1'b1;
        a0 = 1'b1;
        b1 = 1'b0;
        b0 = 1'b1;
        #10;
        a1 = 1'b1;
        a0 = 1'b1;
        b1 = 1'b1;
        b0 = 1'b1;
        #10;
    end

    initial
    begin
        $monitor("A1 = %d\tA2 = %d\tB1 = %d\tB0 = %d\t\tC3 = %d\tC2 = %d\tC1 = %d\tC0 = %d\t",a1,a0,b1,b0,c3,c2,c1,c0);
    end

endmodule
