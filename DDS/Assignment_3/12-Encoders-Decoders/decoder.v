`timescale 1ns/1ns
module decoder
(
    input [3:0] K,
    input enable,
    output [15:0] out
);

    reg [15:0] temp = 16'b0000000000000000;

    always @(*)
    begin
        if(enable == 1'b1)
        begin
            case(K)
                4'b0000: temp <= 16'b0000000000000001;
                4'b0001: temp <= 16'b0000000000000010;
                4'b0010: temp <= 16'b0000000000000100;
                4'b0011: temp <= 16'b0000000000001000;
                4'b0100: temp <= 16'b0000000000010000;
                4'b0101: temp <= 16'b0000000000100000;
                4'b0110: temp <= 16'b0000000001000000;
                4'b0111: temp <= 16'b0000000010000000;
                4'b1000: temp <= 16'b0000000100000000;
                4'b1001: temp <= 16'b0000001000000000;
                4'b1010: temp <= 16'b0000010000000000;
                4'b1011: temp <= 16'b0000100000000000;
                4'b1100: temp <= 16'b0001000000000000;
                4'b1101: temp <= 16'b0010000000000000;
                4'b1110: temp <= 16'b0100000000000000;
                4'b1111: temp <= 16'b1000000000000000;
            endcase
        end
        else
        begin
            temp <= 16'bxxxxxxxxxxxxxxxx; 
        end
    end

    assign out = temp;

endmodule

module decoder_tb;
    reg [3:0] K = 4'b0000;
    reg enable = 1'b0;
    wire [15:0] D;

    decoder Dec(.K(K), .enable(enable), .out(D));
    
    initial
    begin
        $dumpfile("decoder.vcd");
        $dumpvars(0, decoder_tb);
    end

    initial 
    begin
        enable = 1'b0;
        K = 4'b0000;
        #50;

        enable = 1'b1;
        K = 4'b0001;
        #50;

        enable = 1'b1;
        K = 4'b0010;
        #50;

        enable = 1'b0;
        K = 4'b0011;
        #50;

        enable = 1'b1;
        K = 4'b0100;
        #50;

        enable = 1'b0;
        K = 4'b0101;
        #50;

        enable = 1'b1;
        K = 4'b1111;
        #50;

        enable = 1'b0;
        K = 4'b1110;
        #50;

        enable = 1'b1;
        K = 4'b1101;
        #50;

        enable = 1'b1;
        K = 4'b1100;
        #50;
    end

    initial
    begin
        $monitor("Encoded input: %b\nenable = %b\nDecoded output:\nD15 = %b\tD14 = %b\tD13 = %b\tD12 = %b\tD11 = %b\tD10 = %b\tD9 = %b\tD8 = %b\tD7 = %b\tD6 = %b\tD5 = %b\tD4 = %b\tD3 = %b\tD2 = %b\tD1 = %b\tD0 = %b\n",K, enable, D[15], D[14], D[13], D[12], D[11], D[10], D[9], D[8], D[7], D[6], D[5], D[4], D[3], D[2], D[1], D[0]);
    end

endmodule





