main{
	//declaraciones
	int x, y, z ,i,res;
	boolean a, b,c, resultado;
	array int [8] A1,A2;
	function int ubica(int x ; int y)
	{
		if ((x>0)) {
			if ((y>0)) {
				return 1;
			} else {
			 	if ((y==0)) {
					return 0;
				} else {
					return 2;
				}
			}
		} else {
			if ((x==0)) {
				return 0;
			} else {
				if ((y>0)) {
					return 4;
				} else {
					if ((y==0)) {
						return 0;
					} else {
						return 3;
					}
				}
 			} 
		}
	}
	function int cuadrado(int x)
	{
		return x*x;
	}
	function int factorial(int n){
		if ((n == 1)){
			return 1;
		}else{
			return n * factorial(n-1);
		}
	}
	scanf x; //2
	scanf y; //1
	scanf z; //3
	printf x+y; //3
	printf x-y; //1
	printf x*y; //2
	printf x/y; //1
	printf -x; //-2
	printf x+y*z; //5
	printf (x+y)*z; //9
	a=true;
	b=false;
	c=false;
	resultado=(a && b);
	printf resultado; //false
	resultado=(a || b);
	printf resultado; //true
	resultado=(!a);
	printf resultado; //false
	resultado=(a || b && c);
	printf resultado; //true
	resultado=(a && b || c);
	printf resultado; //false
	resultado=(!a && b);
	printf resultado; //false
	resultado=(!(a && b));
	printf resultado;  //true
	A1[5] = 2;
	A2[2] = 8;
	printf A1[5]+A2[2]*2; //18
	z=ubica(-2,3);
	if((z == 4)){
		printf true;
	}
	printf z; //4
	x = cuadrado(z); // probar z=cuadrado(z)
	printf x; //16
	x = factorial(z); //24
	printf x;
	x = factorial(2); //2
	printf x;
	i = 0;
	//fija del 0 al 7
	while ((i < 8)){
		A1[i] = i;
		i = i+1;
	}
	i = 0;
	//imprime del 0 al 7
	while ((i < 8)){
		printf A1[i];
		i = i+1;
	}

	res = cuadrado(i) * 2;
	printf res;

	x = 4;
	x = A1[res/A1[4]/(4*x)]; //x = A1[2] = 2
	printf x;
	A1 = 5; //A1[0] = 5
	printf A1[0];
	printf A1[0];
	//cosas que deberian dar error

	//x = factorial(a); 
	//x = factorial(factorial(2));
	//x = A1[8];
	//x = A1[-1];
	//x = A1 / 0;
	//b = ((a == true));


}
