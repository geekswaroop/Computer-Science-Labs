`timescale 1ns/1ns

module BCDtoExcess3 (a, b, c, d, w, x, y, z);
    input a, b, c, d;
    output w, x ,y ,z;
    wire e,f;

    or(e,c,d);
    and(f,b,e);
    or(w,a,f);

    xor(x,b,e);

    not(z,d);

    xnor(y,c,d);
    

endmodule 

module BCDtoExcess3_tb;

    reg a = 1'b0;
    reg b = 1'b0;
    reg c = 1'b0;
    reg d = 1'b0;

    wire w, x, y, z;

    BCDtoExcess3 h1(a,b,c,d,w,x,y,z);

    initial
    begin
        $dumpfile("BCDtoExcess3.vcd");
        $dumpvars(0, BCDtoExcess3_tb);
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
    end

    initial
    begin
        $monitor("A = %d\tB = %d\tC = %d\tD = %d\t\tW = %d\tX = %d\tY = %d\tZ = %d\t",a,b,c,d,w,x,y,z);
    end

endmodule