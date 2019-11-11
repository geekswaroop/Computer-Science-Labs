/* Q1 part2 */

module dff(D, En, Q);
    input D, En;
    output Q;
    wire a, b, c, d, e, f;
    nand(a, d, b);
    nand(b, a, En);
    nand(c, b, En, d);
    nand(d, c, D);
    nand(Q, b, f);
    nand(f, Q, c);
endmodule
