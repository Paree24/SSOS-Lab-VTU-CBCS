%{
  #include "y.tab.h"
%}

%%
a {return A;}
b {return B;}
[c-zC-z] {return 0;}
[\n] return '\n';
%%
int yywrap(void) {}
