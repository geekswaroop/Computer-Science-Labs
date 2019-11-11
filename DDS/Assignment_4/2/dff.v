module dff(D, clk, Q, r);
    input D, clk, r;
    output reg Q;
    always @ (posedge clk)
    begin
        Q<=D;
        if(r)
            Q<=1'b0;
    end
endmodule
