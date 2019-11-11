module regi(D, clk, Q, r);
    input [31:0] D;
    input clk, r;
    output [31:0] Q;
    genvar i;

    for(i=0; i<32; i=i+1)
    begin
        dff d(D[i], clk, Q[i], r);
    end

endmodule
