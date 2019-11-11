module regi_TB();
    reg [31:0] D;
    reg En, r;
    wire [31:0] Q;
    regi R1(D, En, Q, r);
    initial
    begin
        En = 0;
        forever
        #5 En = ~En;
    end
    initial begin
        D = 0;
        r = 0;
        repeat (7) begin
            #5 r=~r; D = $random;
            #6 r=~r; D = $random;
            #7 r=~r; D = $random;
        end
        #5 $finish;
    end
    initial
    begin
        $dumpfile("regi.vcd");
        $dumpvars(0, regi_TB);
    end
    always @ (Q) begin
        $display($time, ". Pass. D = %b, Q = %b, r: %b", D, Q, r);
    end
endmodule
