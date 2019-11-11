`timescale 1ns/1ns

module GraytoBinary (a, b, c, d, w, x, y, z);
    input a, b, c, d;
    output w, x ,y ,z;
    wire e,f;

    assign w = a;
    xor(e, a, b);
    assign x = e;
    xor(f, e, c);
    assign y = f;
    xor(z, f, d);
    

endmodule 

module GraytoBinary_tb;

    reg a = 1'b0;
    reg b = 1'b0;
    reg c = 1'b0;
    reg d = 1'b0;

    wire w, x, y, z;

    GraytoBinary h1(a,b,c,d,w,x,y,z);

    initial
    begin
        $dumpfile("GraytoBinary.vcd");
        $dumpvars(0, GraytoBinary_tb);
    end

    initial
    begin
        a = 1'b0;
        b = 1'b0;
        c = 1'b0;
        d = 1'b0;
        #10;
        a = 1'b0;
        b = 1'b0;
        c = 1'b0;
        d = 1'b1;
        #10;
        a = 1'b0;
        b = 1'b0;
        c = 1'b1;
        d = 1'b0;
        #10;
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
        a = 1'b1;
        b = 1'b1;
        c = 1'b0;
        d = 1'b1;
        #10;
        a = 1'b1;
        b = 1'b1;
        c = 1'b1;
        d = 1'b0;
        #10;
        a = 1'b1;
        b = 1'b1;
        c = 1'b1;
        d = 1'b1;
        #10;
    end

    initial
    begin
        $monitor("A = %d\tB = %d\tC = %d\tD = %d\t\tW = %d\tX = %d\tY = %d\tZ = %d\t",a,b,c,d,w,x,y,z);
    end

endmodule