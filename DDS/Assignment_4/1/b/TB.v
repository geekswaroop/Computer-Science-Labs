
/* D-latch Testbench */

module D_Latch_TB();
    reg D, En;
    wire Q;

    dff dl1(D, En, Q);
    /* Generate clock */
    initial 
    begin
        En=0;
        forever 
            #5 En = ~En;
        end

    /* Stimulus */
    initial begin
        D=0;
        repeat(10)
        begin
            #1 D = ~D;
            #3 D = ~D;
            #5 D = ~D;
            
        end
        #5 $finish;
    end
    /* monitor */
    /* check if the behaviour is as expected whenever output changes */

    initial 
    begin
        $dumpfile("gate_level.vcd");
        $dumpvars(0,D_Latch_TB);
    end

    always @(Q)
    begin
        $display($time, ". D = %b. Q = %b", D, Q);
    end
endmodule

