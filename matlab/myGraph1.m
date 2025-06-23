function [] = myGraph1(a, b)
    %x = a:pi/1000:b;
    %y = x.*sin(x);
    x = -10:1:10;
    y1=x-5;
    y2=x-4;
    y3=x-3;
    y4=x-2;
    y5=x-1;
    y6=x;
    y7=x+1;
    y8=x+2;
    y9=x+3;
    y10=x+4;
    plot(x,y1,"+--",x,y2,"o",x,y3,"*",x,y4,".",x,y5,"x",x,y6,"s",x,y7,"-.",x,y8,"^",x,y9,"p",x,y10,"h");
    title("x*sin(x) Graph");
    legend("plus","circle","asterisk");
    xlabel("x");
    ylabel("y");
end