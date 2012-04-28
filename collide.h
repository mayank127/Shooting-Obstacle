
//collide function calculating distance between the centers of two objects and if that is less than specified distance d than will return 0 otherwise 1.
int collide(float xb, float yb, float xo, float yo, float d)
{
	float distance = sqrt((xb-xo)*(xb-xo)+(yb-yo)*(yb-yo));
	if (distance<d)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
