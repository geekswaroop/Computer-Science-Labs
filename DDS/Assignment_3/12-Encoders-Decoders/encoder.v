`timescale 1ns/1ns
module encoder
(
    input [15:0] D,
    input enable,
    output [3:0] out
);

    reg [3:0] temp = 4'b0000;

    always @(*)
    begin
        if(enable == 1'b1)
        begin 
            if(D[15] == 1'b1)
            begin
                temp <= 4'b1111;
            end

            else if(D[14] == 1'b1)
            begin
                temp <= 4'b1110;
            end

            else if(D[13] == 1'b1)
            begin
                temp <= 4'b1101;
            end

            else if(D[12] == 1'b1)
            begin
                temp <= 4'b1100;
            end

            else if(D[11] == 1'b1)
            begin
                temp <= 4'b1011;
            end

            else if(D[10] == 1'b1)
            begin
                temp <= 4'b1010;
            end

            else if(D[9] == 1'b1)
            begin
                temp <= 4'b1001;
            end

            else if(D[8] == 1'b1)
            begin
                temp <= 4'b1000;
            end

            else if(D[7] == 1'b1)
            begin
                temp <= 4'b0111;
            end

            else if(D[6] == 1'b1)
            begin
                temp <= 4'b0110;
            end

            else if(D[5] == 1'b1)
            begin
                temp <= 4'b0101;
            end

            else if(D[4] == 1'b1)
            begin
                temp <= 4'b0100;
            end

            else if(D[3] == 1'b1)
            begin
                temp <= 4'b0011;
            end

            else if(D[2] == 1'b1)
            begin
                temp <= 4'b0010;
            end

            else if(D[1] == 1'b1)
            begin
                temp <= 4'b0001;
            end

            else if(D[0] == 1'b1)
            begin
                temp <= 4'b0000;
            end
        end
        else 
        begin
            temp <= 4'bxxxx;
        end
    end

    assign out = temp;
    
endmodule

module encoder_tb;
    reg [15:0] D = 16'b00000000;
    reg enable = 1'b0;
    wire [3:0] answer;

    encoder E(.D(D), .enable(enable), .out(answer));

    initial
    begin
        $dumpfile("encoder.vcd");
        $dumpvars(0, encoder_tb);
    end

    initial
    begin
        enable = 1'b1;
        D = 16'b0100010110100101;
        #50;
                
        enable = 1'b1;        
        D = 16'b0110010101010101;
        #50;        
        
        enable = 1'b0;
        D = 16'B1100100111010110;
        #50;

        enable = 1'b0;        
        D = 16'b0100101111100010;
        #50; 

        enable = 1'b1;        
        D = 16'b0001000000001110;
        #50; 

        enable = 1'b1;        
        D = 16'b0000111110000010;
        #50;         
        
        enable = 1'b1;
        D = 16'b1110101101011000;
        #50;
        
        enable = 1'b0;
        D = 16'b0101000011001111;
        #50; 
        
        enable = 1'b1;
        D = 16'b0000000000000001;
        #50;

        enable = 1'b0;
        D = 16'b0000000000110101;
        #50;

        enable = 1'b1;        
        D = 16'b0000000101110101;
        #50;        
        
        enable = 1'b1;
        D = 16'B1100111001000101;
        #50;

        enable = 1'b0;        
        D = 16'b0000000000000010;
        #50; 

        enable = 1'b1;        
        D = 16'b0000000100011110;
        #50; 

        enable = 1'b1;        
        D = 16'b0000000010100010;
        #50;         
        
        enable = 1'b0;
        D = 16'b1110101100001100;
        #50;
        
        enable = 1'b0;
        D = 16'b0110001011011110;
        #50; 
        
        enable = 1'b1;
        D = 16'b1001010011010101;
        #50;
    end

    initial
    begin
        $monitor("\nD15 = %b\tD14 = %b\tD13 = %b\tD12 = %b\tD11 = %b\tD10 = %b\tD9 = %b\tD8 = %b\tD7 = %b\tD6 = %b\tD5 = %b\tD4 = %b\tD3 = %b\tD2 = %b\tD1 = %b\tD0 = %b\tenable = %b\nEncoded output = %b", D[15], D[14], D[13], D[12], D[11], D[10], D[9], D[8], D[7], D[6], D[5], D[4], D[3], D[2], D[1], D[0], enable, answer);
    end

endmodule