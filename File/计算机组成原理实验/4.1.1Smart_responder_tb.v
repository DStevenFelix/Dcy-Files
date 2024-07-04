`timescale 1ns / 1ps
module Smart_responder_tb;
    reg clk,rst_n;
    reg [3:0]btn;
    
    wire [3:0] an;
    wire [7:0] seg_code;
    initial begin
        clk = 1'b0;
        rst_n = 1'b0;
        btn = 4'd0;
        #5.87 rst_n = 1'b1;   //采用学号后三位作为延迟时间

        #5.87 btn = 4'd1; 
        #5.87 btn = 4'd3;
        #5.87 btn = 4'd0;
        
        #5.87 rst_n = 1'b0;
        #5.87 rst_n = 1'b1;

        #5.87 btn = 4'd2;
        #5.87 btn = 4'd6;
        #5.87 btn = 4'd0;        
    end
    always #5 clk <= ~clk;

    Smart_responder Smart_responder(
        .clk( clk ),
        .rst_n( rst_n ),
        .btn( btn ),
        .an( an ),
        .seg_code( seg_code )
    );
endmodule
