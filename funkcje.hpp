struct vector2D {
	double x;
	double y;
	};
	
struct planet{
	vector2D pos;
	vector2D vel;
	double mass;

	};
	
	
vector2D *gravityForce(const planet &c1, const planet &c2);
	
