/* Q1 part 3 */

module dff(D, En, Q);
    input D, En;
    output Q;
    reg Q;
    always @ (posedge En)
    Q <= D;
endmodule
