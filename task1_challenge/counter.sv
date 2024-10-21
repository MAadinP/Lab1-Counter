module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic clk, //clock
    input logic rst, //reset
    input logic en, //counter enable
    output logic [WIDTH-1:0] count //counter output
);

//asynchronous reset because the posedge of the reset signal is in the sensitivity list
//means that independant of the clk signal, the posedge of the rst will activate the statement.
always_ff @( posedge clk, posedge rst)
    if(rst) count <= {WIDTH{1'b0}};
    else count <= count + {{WIDTH-1{1'b0}}, en};

endmodule
