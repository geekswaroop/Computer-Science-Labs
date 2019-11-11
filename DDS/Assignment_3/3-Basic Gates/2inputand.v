`timescale 1ns/1ns
module two_input_norer
(
    input in_a,
    input in_b, 
    output answer
);
    
    nor(answer, in_a, in_b);

endmodule

module two_input_and
(
    input in_a,
    input in_b,
    output answer
);
    two_input_norer n1(.in_a(in_a), .in_b(in_a), .answer(x));
    two_input_norer n2(.in_a(in_b), .in_b(in_b), .answer(y));
    two_input_norer n3(.in_a(x), .in_b(y), .answer(answer));

endmodule

module two_input_and_tb;
    reg in_a = 1'b0;
    reg in_b = 1'b0;

    two_input_and A(.in_a(in_a), .in_b(in_b), .answer(answer));

        initial
        begin
            $dumpfile("2inputand.vcd");
            $dumpvars(0, two_input_and_tb);
        end

        initial
        begin
            in_a = 1'b0;
            in_b = 1'b0;
            #20;
        
            in_a = 1'b0;
            in_b = 1'b1;
            #20;
        
            in_a = 1'b1;
            in_b = 1'b0;
            #20;
        
            in_a = 1'b1;
            in_b = 1'b1;
            #20;
        end
    
        initial
        begin
            $display("Two input AND:");
            $monitor("A = %d\tB = %d\tAandB = %d\t", in_a, in_b, answer);
        end
    
endmodule