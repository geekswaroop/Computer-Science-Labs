
module D_Master_Slave(Q, D, Clk);
    input Clk, D;
    output Q;
    wire Y, Z;
    assign Z = ~Clk;
    D_Latch d1(Y,D,Clk), d2(Q,Y, Z);

endmodule

