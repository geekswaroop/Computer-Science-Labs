module hello;
  always 
    begin
        if($time<=100) begin
            $display("Hello World!\t%d",$time);
            #10;
        end else begin
            $finish;
        end
    end
endmodule

