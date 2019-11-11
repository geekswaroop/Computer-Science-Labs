/* D-Latch Module */

module D_Latch(Q, D, En);
    input D, En;
    output Q;
    reg Q;

    always @(D, En)
    begin
        if(En==1) Q<=D;
    end
endmodule
