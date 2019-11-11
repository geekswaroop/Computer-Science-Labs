`timescale 1ns/1ns
module three_input_nander
(
    input in_a, 
    input in_b, 
    input in_c, 
    output answer
);
    nand(answer, in_a, in_b, in_c);

endmodule

module three_input_or 
( 
    input in_a,
    input in_b,
    input in_c,
    output answer
);
    three_input_nander n1(.in_a(in_a), .in_b(in_a), .in_c(in_a), .answer(x));
    three_input_nander n2(.in_a(in_b), .in_b(in_b), .in_c(in_b), .answer(y));
    three_input_nander n3(.in_a(in_c), .in_b(in_c), .in_c(in_c), .answer(z));
    three_input_nander n4(.in_a(x), .in_b(y), .in_c(z), .answer(answer));

endmodule

module three_input_or_tb;
    reg in_a;
    reg in_b;
    reg in_c;
    wire x, y, z, answer;

    three_input_or O(.in_a(in_a), .in_b(in_b), .in_c(in_c), .answer(answer));

    initial
    begin
        $dumpfile("3inputor.vcd");
        $dumpvars(0, three_input_or_tb);
    end

    initial
    begin
        in_a = 1'b0;
        in_b = 1'b0;
        in_c = 1'b0;
        #20;
    
        in_a = 1'b0;
        in_b = 1'b0;
        in_c = 1'b1;
        #20;

        in_a = 1'b0;
        in_b = 1'b1;
        in_c = 1'b0;
        #20;

        in_a = 1'b0;
        in_b = 1'b1;
        in_c = 1'b1;
        #20;

        in_a = 1'b1;
        in_b = 1'b0;
        in_c = 1'b0;
        #20;

        in_a = 1'b1;
        in_b = 1'b0;
        in_c = 1'b1;
        #20;

        in_a = 1'b1;
        in_b = 1'b1;
        in_c = 1'b0;
        #20;

        in_a = 1'b1;
        in_b = 1'b1;
        in_c = 1'b1;
        #20;
    end

    initial
    begin
        $display("Three input OR:");
        $monitor("A = %d\tB = %d\tC = %d\tAorBorC = %d\t", in_a, in_b, in_c, answer);
    end

endmodule