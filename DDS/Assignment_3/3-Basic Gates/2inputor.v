`timescale 1ns/1ns
module two_input_nander
(
    input in_a,
    input in_b, 
    output answer
);
    
    nand(answer, in_a, in_b);

endmodule

module two_input_or
(
    input in_a,
    input in_b,
    output answer
);
    two_input_nander n1(.in_a(in_a), .in_b(in_a), .answer(x));
    two_input_nander n2(.in_a(in_b), .in_b(in_b), .answer(y));
    two_input_nander n3(.in_a(x), .in_b(y), .answer(answer));

endmodule

module two_input_or_tb;
    reg in_a = 1'b0;
    reg in_b = 1'b0;
    wire answer;

    two_input_or O(.in_a(in_a), .in_b(in_b), .answer(answer));

        initial
        begin
            $dumpfile("2inputor.vcd");
            $dumpvars(0, two_input_or_tb);
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
            $display("Two input OR:");
            $monitor("A = %d\tB = %d\tAorB = %d\t", in_a, in_b, answer);
        end
    
endmodule