`timescale 1ns/1ns

module HA (input in_a, in_b,output Sum, Carry);
    
    and(Carry, in_a, in_b);
    xor(Sum, in_a, in_b);

endmodule

