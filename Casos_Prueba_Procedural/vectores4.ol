main
{
	array boolean[3] vector1;
	array boolean[3] vector2;
	array boolean[3] vector3;

	vector1[0]=true;
	vector1[1]=false;
	vector1[2]=true;

	vector2[0]=false;
	vector2[1]=false;
	vector2[2]=false;

	vector3[0]=vector1[0] || vector2[0];
	vector3[1]=vector1[1] || vector2[1];
	vector3[2]=vector1[2] || vector2[2];

	printf vector3[0];
	printf vector3[1];
	printf vector3[2];
}