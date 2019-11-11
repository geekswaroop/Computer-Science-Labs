
/* D-latch Testbench */

module D_Latch_TB();
    reg D, En;
    wire Q;

    D_Master_Slave d(Q, D, En);
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
        $dumpfile("master_slave.vcd");
        $dumpvars(0,D_Latch_TB);
    end

    always @(Q)
    begin
        $display($time,". D = %b. Q = %b.", D, Q);
    end
endmodule

