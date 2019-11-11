`timescale 1ns/1ns

module Excess3toBCD (a, b, c, d, w, x, y, z);
    input a, b, c, d;
    output w, x ,y ,z;
    wire e,f;

    and(e,c,d);
    or(f,b,e);
    and(w,a,f);

    xnor(x,b,e);

    not(z,d);

    xor(y,c,d);
    

endmodule 

module Excess3toBCD_tb;

    reg a = 1'b0;
    reg b = 1'b0;
    reg c = 1'b0;
    reg d = 1'b0;

    wire w, x, y, z;

    Excess3toBCD h1(a,b,c,d,w,x,y,z);

    initial
    begin
        $dumpfile("Excess3toBCD.vcd");
        $dumpvars(0, Excess3toBCD_tb);
    end

    initial
    begin
        a = 1'b0;
        b = 1'b0;
        c = 1'b1;
        d = 1'b1;
        #10;
        a = 1'b0;
        b = 1'b1;
        c = 1'b0;
        d = 1'b0;
        #10;
        a = 1'b0;
        b = 1'b1;
        c = 1'b0;
        d = 1'b1;
        #10;
        a = 1'b0;
        b = 1'b1;
        c = 1'b1;
        d = 1'b0;
        #10;
        a = 1'b0;
        b = 1'b1;
        c = 1'b1;
        d = 1'b1;
        #10;
        a = 1'b1;
        b = 1'b0;
        c = 1'b0;
        d = 1'b0;
        #10;
        a = 1'b1;
        b = 1'b0;
        c = 1'b0;
        d = 1'b1;
        #10;
        a = 1'b1;
        b = 1'b0;
        c = 1'b1;
        d = 1'b0;
        #10;
        a = 1'b1;
        b = 1'b0;
        c = 1'b1;
        d = 1'b1;
        #10;
        a = 1'b1;
        b = 1'b1;
        c = 1'b0;
        d = 1'b0;
        #10;
    end

    initial
    begin
        $monitor("A = %d\tB = %d\tC = %d\tD = %d\t\tW = %d\tX = %d\tY = %d\tZ = %d\t",a,b,c,d,w,x,y,z);
    end

endmodule