module bcd_adder(a,b,carry_in,sum,carry);

    input [3:0] a,b;
    input carry_in;
    output [3:0] sum;
    output carry;
    
    reg [4:0] sum_temp;
    reg [3:0] sum;
    reg carry;  

    always @(a,b,carry_in)
    begin
        sum_temp = a+b+carry_in; //add all the inputs
        if(sum_temp > 9)    begin
            sum_temp = sum_temp+6; //add 6, if result is more than 9.
            carry = 1;  //set the carry output
            sum = sum_temp[3:0];    end
        else    begin
            carry = 0;
            sum = sum_temp[3:0];
        end
    end     

endmodule

module bcdadder_tb;

    // Inputs
    reg [3:0] a;
    reg [3:0] b;
    reg carry_in;

    // Outputs
    wire [3:0] sum;
    wire carry;

    // Instantiate the Unit Under Test (UUT)
    bcd_adder uut (
        .a(a), 
        .b(b), 
        .carry_in(carry_in), 
        .sum(sum), 
        .carry(carry)
    );

initial
    begin
        $dumpfile("bcdadder.vcd");
        $dumpvars(0, bcdadder_tb);
    end

    initial begin
        // Apply Inputs
        a = 0;  b = 1;  carry_in = 0;   #100;

        a = 3;  b = 4;  carry_in = 1;   #100;
       
        a = 8;  b = 3;  carry_in = 0;   #100;
      
    end
      
      initial
    begin
        $monitor("A = %d\tB = %d\t carryin=%d\t Sum = %d\t Carry = %d\t", a, b, carry_in, sum, carry);
    end

endmodule
