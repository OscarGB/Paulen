main {
 int z, x1;
 int x2;
 boolean y1;
 function int doble(int arg){
   int auxArg;
   auxArg = arg;
   return 2*arg ;
 }

 function boolean igual(int arg1;int arg2){
   if((arg1==arg2)){
    return true;
   }
   else{
    return false;
   }
 }

 function boolean imprime(int x1;int x2;boolean y1){
	if ( (x1 == x2) )
	{
	        if ( y1 )
	        {
	                printf 110;
	        }
	        else
	        {
	                printf 111;
	        }
	}
	else
	{
	        if ( y1 )
	        {
	                printf 10;
	        }
	        else
	        {
	                printf 11;
	        }
	}
	return true;
 }

 scanf z;
 printf doble(z);
 scanf x1;
 scanf x2;
 printf igual(x1,x2);
 scanf x1;
 scanf x2;
 scanf y1;
 printf imprime(x1,x2,y1);
}